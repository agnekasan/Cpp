#include <iostream>

#define log(x) std:: cout << x << std::endl

// névtereket azért használhatunk a legtöbb esteben, hogy elkerüljük a név ütközést
namespace A
{
    int i = 1;
}

namespace B
{
    int i = 2;
}

// using namespace A;
// using namespace B;

// ha mindkét namespace-t, amelyben azonos nevű változók, függvények stb. vannak using-oljuk
// akkor amikor a hivatkozni szeretnénk a névtérben lévő változóra a main fv-en belül pl. std::cout << i;
// fordítási idejű hibát fogunk kapni, mégpedig azért, mert kétértelmű hivatkozás lesz az i változóra és a
// fordítóprogram nem tudja eldönteni, hogy az A vagy a B namespace-ből szeretnénk-e használni az i változót
// ezért ne használjunk a using namespace ...; -t, helyette a scope operátor (::) segítésgével és a névtér nevével
// hivatkozzunk a használi kívánt változóra pl. std::cout << A::i << " " << B::i;

// egymásba ágyazott namespace-ek, az i változót a következő képpen tudjuk elérni C::D::i
namespace C
{
    namespace D
    {
        int i = 3;
    }
}
// C++17 óta a következőképpen is jelölhetjük C::D { ... }, a két jelölés ekvivalens

int n; // globális változó, fordítási időben értékelődik ki egyszer, ha nem
       // inicializáljuk akkor 0-ra fog inicializálódni, ennek pedig az az oka,
       // hogy a modern processzorok gyorsabban tudják kivitelezni a legtöbb platformon
       // globális változók használata kerülendő

// példa egy helytelen swap fv-re, érték szerinti átadásnal az átadott értékek lemásolódnak, nem az eredeti módosul,
// az új a és b a swap végén törlődik a memőriából
void swapWrong(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swapPtr(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapRef(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// a függvény leírása a 136. sortól
const std::string& refRet(const std::string& str_)
{
    // str_[0] = 'A'; fordítási idejű hiba, konstans referenciakénr kapjuk az str_-t ezért a függvényen belül nem megengedett annak a módosítása
    return str_;
}

int main() {
    
    int q = 1;
    int w = 2;
    std::cout << "Eredeti: " << q << " " << w << std::endl;
    swapWrong(q, w);
    std::cout << "swapWrong után: " << q << " " << w << std::endl;
    swapPtr(&q, &w); // mivel mutatókat vár a függvény, referenciaként kell átadni a válatozókat
    std::cout << "swapPtr után: " << q << " " << w << std::endl;
    swapRef(q, w); // nem adjuk át a változót csak egy aliast amivel hivatkozunk az eredeti változóre, nem történik másolás
    std::cout << "swapRef után: " << q << " " << w << std::endl;
    
    std::cout << C::D::i;
    
    int n = 1; // lokális változó a STACK-en, élettartama a hatókör végéig tart
    { // újabb scope kezdete
        int n = 2; // lokális változó a belső scope-ban
        std::cout << n << ::n << std::endl; // 20 - a main elején létrehozott n az utána következő blokkban
                                            // teljesen elérhetetlen - nincs olyan nyelvi eszköz, amivel
                                            // tudnánk rá hivatkozni, ezt hívjuk shadowing-nak vagy leárnyékolásnak
                                            // scope operátorral (::) tudunk hivatkozni a globális változóra
    }
    
    int i = 0;
    int k = 0;
    std::cout << i++ << i++ << std::endl; // mi a kimenet? GCC 01 Clang 10. Nem eldönthető, ugyanis a program ezen pontján nem definiált viselkedés látható
                                          // az hogy két részkifejezés szekvenciaponttal törtnő elválasztás nélkül ugyan azt a memóriaterületet módosítja
                                          // nem definiált viselkedést eredményez az, hogy mikor értékelődik ki a két i++ nem specifikált, azaz a szabvány
                                          // nem terjed ki arra, hogy milyen kódot generáljon a fordító, amennyiben a szabvány definiál néhány lehetséges opciót,
                                          // de a fordítóra bizza, hogy melyiket választja, akkor nem specifikált viselkedésről beszélünk, ez csak
                                          // akkor probléma, ha a program végeredményét befolyásolja. Egy ideje Warning-ot adnak a fordítók.
                                          // implementáció által definiált viselkedés - szabvány nem köti meg, hogy egy int egy adott platformon mennyi byte-ból álljon
                                          // MEGOLDÁS!! használjunk szekvenciapontot - a szabvány annyit mond ki, hogy a szekvencia pont előtti kód hamarabb kerüljön
                                          // végrehajtásra, mint az utána következő, azaz biztosak lehetünk abban, hogy az összes változó ami a szekvencia pont előtt szerepel
                                          // már kiértékelésre került. Szekvenciapont pl.: ;, &&, ||
    
    const int j = 1; // j egy konstans változó ami annyit jelent, hogy az értéke nem módosulhat a program futása során, a konstansok már fodítási időben kiértékelődnek és
                     // mindig inicializálni kell őket kezdőértékkel, ha módosíthatnánk az értéküket akkor sérülne a  konstans korrektség
    
    int* pN = &n; // int-re mutató mutató, ami mutat az n változóra
    std::cout << pN << " " << *pN << std::endl; // az első érték az n változó memória címét adja vissza a második
                                                // pedig magát a mutatott értéket (1)
    // megkülönböztetünk konstansra mutató mutatót és azt amikor maga a mutató konstans. (Lásd jegyzet).
    // ha a * oeprátor bal oldalán van a const kulcsszó akkor konstansra mutató mutatóról beszélünk, ha a jobb oldalán akkor konstans mutatóról,
    // ha pedig mindkettőn akkor konstansra mutató konstans mutató. (Jegyzetben hosszabb leírás a mutatókról és referenciákról)
    
    //pN = &j; HELYTELEN, fordítási idejű hiba, ugyanis nem konstansra mutató mutatóval nem tudunk rámutatni konstans adattagra. Miért? Mert, ha rátundánk az azt jelentené
    // hogy egy olyan mutatóval amin keresztül képesek vagyunk módosítani a mutatott értéket rátudunk mutatni egy konstans változó memóriacmére, akkor a mutatón keresztül
    // módosíthatnánk egy konstans változót, ezáltal sérülne a konstans korrektség. Megoldás, használjunk konstansra mutató mutatót.
    // megjegyzés const int* ekvivalens a int* const - al
    const int* cpI = &j; // HELYES, mivel a mutató is konstansra mutat ergo, nem tudjuk rajta keresztül módosítani a mutatott értéket. Konstanra mutató mutató lehet nullptr
                         // konstans mutató azonban kell, hogy értéket kapjon amikor deklaráljuk
    int* const pcI = &i;
    // pcI = &k; - HELYTELEN, konstans mutatót nem állíthatunk át, hogy másik változóta mutasson, csak amivel inicializáltuk.
    int** ppI; // mutatóra mutató mutató értékül adhatjuk neki egy másik mutató memóriacímét, kiíráskor kétszer kell dereferálni, hogy a mutatott értéket kapjuk
    const int * const *  b; // b egy konstans int-re mutató konstans mutatóra mutató mutató
    const int * const * const * const a = &b; // a egy konstans int-re mutató konstans mutatóra mutató konstans mutatóra mutató konstans mutató
                                              // ami mutat egy konstans int-re mutató mutatóra konstans mutatóra mutató mutatóra
    // megjegyzés: mutatóknál a * nem számít, hogy hol szerepel pl int* a vagy int *a, vagy int * a mind a három ugyan azt jelenti
    // potenciális vizsgakérdés, helyes-e az alábbi kód? Ha igen miért? Ha nem miért?
    /*
    const int c = 1;
    const int& rC = c;
    int const* ppC = &rC;
    const int * const * const ppccC = &ppC;
    */
    
    // Függvény visszatérési éréke referenciával vagy konstans referenciával, konstnas referencia függvény paraméter. Mit jelent az első és mit a második const kulcsszó?
    // az első const a függvény visszatérési értékénél azt mondja hogy a vissza adott értéken nem változtathatunk, a második const arra szolgál, hogy a paraméterül kapott változó a függvény
    // belsejében nem módosulhat. Miért hasznos? Ha nagy adatstruktúrákkal dolgozunk pl. egy 10000000 elemű vektort vagy egy osztályt aminek rengeteg adattagja van és ezt szeretnénk
    // a függvénynek átadni, ezeknek érték szerinti átadása nagyon sok számításba kerülne (tárhely allokáció, másolás, felszabadítás...) ezért ikább csak egy  aliast adjunk át, így
    // elkerüljük a felesleges másolásokat. Az, hogy a bemeneti paraméter konstans miért lehet hasznos? Képzeljük el, hogy szeretnénk megszámolni egy 10000000 elemű tömbben hány olyan szám van
    // ami osztható 3-al és 11-el is, viszont magán a tömbön nem szeretnénk módosítani. Erre jó, ha konstans a bemeneti paraméter , hogy még véletlenül se tudjuk elkövetni azt a hibát,
    // hogy megváltoztatunk egy elemet, mert lehet, hogy a későbbiekben valaki más még szeretné használni ezt a vektort
    
    std::string greeting = "Hello World";
    log(refRet("Hello World"));
    log(refRet(greeting));
    // refRet("Hello World")[0] = 'h'; fordítási idejű hiba, mivel a vissza adott referencia konstans, ezért nem engedélyezett annak a megváltoztatása
    // ha nem konstansként adnánk át a függvénynek a "Hello World"-öt fordítási idejű hibát kapnánk, ekkor célszerű egy változóhoz kötni a stringet és
    //úgy átadni a függvénynek. refRet(greeting); - működik ha konst ref-et vár a függvény és akkor is ha ref-et.
    
}
