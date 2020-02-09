<img src="img/cppIcon.png" alt="cpp icon" style="width:200px;">

__"C makes it easy to shoot yourself in the foot; <br>
C++ makes it harder, but when you do it, it blows your whole leg off."__

~ _Bjarne Stroustrup_ ~


## Bevezetés

A <strong>C++</strong> egy általános célú, magas szintű programozási nyelv. Gyakori tévhit, hogy alacsony szintű (hardver közeli) nyelv. Noha lehetőséget biztosít arra, hogy alacsony szinten programozzunk, számos absztrakciós lehetőséget tartalmaz. Támogatja a __procedurális, objektumorientált és a generikus programozást__ valamint az __adatabsztrakciót__. Legtöbb nyelvhez képest abban emelkedik ki, hogy az itt megvalósított absztrakcióknak ritkán van futási idejű költsége.

A C++ nyelv fejlesztését még a 80-as években __Bjarne Stroustrup__ kezdte el a C programozási nyelv kiterjesztéseként, más nyelvekből véve át megoldásokat. Az első szabányát a nyelvnek 1998-ban hagyták jóvá, így ez is lett az elő hivatalos szabványa a nyelvnek. Alapvetően a nyelv két összetevőből áll. Az aktuális szabványból és annak implementációjából. A szabvány az, ami meghatározza a nyelv nyelvtanját, valamint a szemantikáját (mit jelentenek a leforduló programok).

Eddigi C++ szabványok:

* c++98
* c++03
* c++11
* c++14
* c++17
* (c++2a)

A szabvány nevében a számok a szabvány elfogadásának évét jelentik.

Számos fordító létezik a C++ kódok fordítására, amelyek különböző mértékben támogatják az aktuális C++ szabványt:

* MSVC
* GCC
* Clang

__Érdekesség__: Andrei Alexandrescu azt nyilatkozta, hogy amikor a Facebooknak a back-end kódján 1%-ot sikerült optimalizálni, több mint 10 évnyi fizetését spórolta meg a cégnek havonta csak az áramköltségen.

A C++ filozófiájának fontos eleme, hogy ha nem használunk egy adott nyelvi eszközt, akkor annak ne legyen negatív hatása a program teljesítményre. Magyarán mondva csak azért "fizessünk", amit használunk is. Fontos, hogy a C++ alapvetően nem objektumorientált nyelv. Ahogy fentebb láttuk, kíválóan alkalmas a generatív programozáson keresztül a deklaratív stílusig sok paradigmát támogatni. A nyelv nem próbál meg ráerőltetni a programozóra egy megközelítést, ellenben próbál minél gazdagabb eszköztárat biztosítani, hogy a megfelelő problémát a megfelelő megközelítéssel lehessen megoldani. Még akkor is, ha ez a különböző paradigmák keverését vonja maga után. Ezért a nyelvet gyakran muldiparadigmás programozási nyelvnek is szokás nevezni.

## Alapok

### C++ adattípusok

Az összes változó adattípust használ a deklaráció során a tárolni kívánt adatok típusának korlátozására. Ezért azt mondhatjuk, hogy az adattípusokat arra használják, hogy megmondják a változóknak, hogy milyen típusú adatot tárolhatnak. Ha egy változót a C++-ban definiálnak, a fordító memóriát allokál ehhez a változóhoz azon adattípus alapján, amellyel azt deklarálják. Minden adattípushoz eltérő mennyiségű memória szükséges.

Adattípusok C / C++-ban

* __Primitív__: ezek az adattípusok beépített vagy előre meghatározott adattípusok, és a felhasználó közvetlenül felhasználhatja a változók deklarálására. példa: ```int```, ```char```, ```float```, ```bool``` stb. A C ++-ban rendelkezésre álló primitív adattípusok a következők:
	* __integer__: Az egész adattípusokhoz használt kulcsszó ```int```. Az egész számok általában __4 bájt__ memóriahelyet igényelnek, és -2147483648-tól 2147483647-ig terjednek.
	* __character__: A karakter adattípus a karakterek tárolására szolgál. A karakter adattípushoz használt kulcsszó ```char```. A karakterek általában __1 bájt__ memóriahelyet igényelnek, és -128 és 127 vagy 0 és 255 között változhatnak.
	* __boolean__: A logikai adattípus a logikai vagy logikai értékek tárolására szolgál. A logikai változó valódi vagy hamis értékeket tárolhat. A logikai adattípushoz használt kulcsszó a ```bool```.
	* __floating point__: A lebegőpontos adattípus a tizedes értékek tárolására szolgál (single precision). A lebegőpontos adattípushoz használt kulcsszó ```float```. Általában __4 bájt__ memóriahelyet igényelnek.
	* __double floating point__: A dupla lebegőpontos adattípus dupla pontosságú lebegőpontos vagy tizedes értékek tárolására szolgál (double precision). A kettős lebegőpontos adattípushoz használt kulcsszó ```double```. Általában __8 bájt__ memóriahelyet igényelnek.
	* __void__: azt jelenti: érték nélkül. Az ```void``` adattípus értéktelen entitást jelent. A ```void``` adattípust azoknál a függvényeknél használják, amelyek nem adnak vissza értéket.
	* __wide character__: szintén egy karakter adattípus, de ennek az adattípusnak a mérete meghaladja a normál 8 bites adattípust. A ```wchar_t``` képviseli. Általában __2 vagy 4 bájt__ hosszú.
* __Származtatott__: az primitív vagy beépített adattípusokból származó adattípusokat származtatott adattípusoknak nevezzük. Ezek négyféle lehetnek, nevezetesen:
	* function
	* array
	* pointer
	* reference
* __Felhasználó által definiált__: ezeket az adattípusokat maga a felhasználó határozza meg. Például egy osztály meghatározása a C++-ban vagy egy struktúra. A C ++ a következő felhasználó által definiált adattípusokat tartalmazza:
	* class
	* structure
	* union
	* enum
	* typedef

### Adattípus módosítók

Ahogy a neve is sugallja, az adattípus-módosítókat a beépített adattípusokkal használják az adatok hosszának módosítására, amelyet egy adott adattípus képes tárolni.

__előjeles__ (signed)

* integer
* char
* long - prefix

__előjel nélküli__ (unsigned)

* integer
* char
* short - prefix

__long__

* integer
* double  

__short__

* integer

![data types size](img/datatypessize.png)

// TODO sizeof() operator


Ezen adatok tudatában nézzük meg az első C++ programunkat. Tekintsük az alábbi programot. Legyen a neve _main.cpp_:

```cpp
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) 
{ 
  cout << "Hello World!" << endl;
  return 0;
}
```

A _main.cpp_ meghatároz egy __fordítási egységet__ (compilation unit). A fordítás folyamata során fordítási egységeket fordítunk gépi kódra. Egy fordítási egységben az a kód található, amelyhez a fordító a fordítás során hozzáfér.

A kód legfelső sorában található az ```#include <iostream>```. A kettős kereszttel (```#```) jelzet sorok az __előfordítónak__ (precompiler) szóló utasítások. Ezek az úgynevezett preprocesszor direktívák. Az ```include``` utasítás behelyettesíti a hívás helyére a megadott fájl tartalmát. Ez a helyettesítés __fordítási idő__ben történik. Az ```iostream``` fejállomány (header file vagy egyszerűen csak header) tartalmazza a megfelelő I/O (Input/Output) utasításokat a kiíratáshoz. Ez maga is ugyanúgy C++ kódot tartalmaz, melyet mi magunk is írunk. Két különböző elérési útvonallal tudjuk megadni az include-okat:

* ```#include <...> // előre bekonfigurált include útvonalban keresi a fájlt```
* ```#include "..." // az útvonal relatív az aktuális fájlokhoz képest```

### Mik az előnyei az ```iostream```-nek a ```cstdio```-val szemben C++-ban?

Típusbiztonságot növel, csökkenti a hiba lehetőségek számát, lehetővé teszi a bővíthetőséget és az örökölhetőséget. A ```printf()``` vitathatatlanul jól működik és a ```scanf()``` is működik annak ellenére, hogy nem túl nagy a hibatűrő képessége. Mindazon által mindkettő korlátozzott a C++ I/O-val szemben. Ha szeretnénk összehasonlítani a C++ I/O ```<<``` és ```>>``` operátorai nagyjából megfelelnek a C-s ```printf()``` és ```scanf()``` függvényeinek. Azonban több előnyük is van ezekkel a függvényekkel szemben:

* __Típus biztosabb__: az ```<iostream>``` esetén az objektumok típusai fordítási időben ismertek a fordító számára. Ezzel szemben az ```<cstdio>``` ```%``` mezőket használ a típusok dinamikus meghatározásához.
* __Kevesebb hibalehetőség__: az ```<iostream>``` használatakor nincsenek redundáns ```%``` tokenek, amelyeknek konzisztensnek kell lenniük az I/O-zni kívánt objektumokkal. Ezen redundancia eltávolítása a hibák eltávolítását is jelenti.
* __Bővíthető__: a C++ ```<iostream>``` lehetővé teszi az új, felhasználó által definiált típusok I/O-zását, anélkül, hogy brámi problémát okozna a már meglévő kódban.
* __Örököltethető__: A C++ ```<iostream>``` mechanizmus olyan valós osztályokból épül fel, mint az ```std::ostream``` vagy az ```std::istream```. A ```<cstdio> FILE*```-al ellentétben ezek valódi osztályok, ezért örököltethetőek. Ez azt jelenti, hogy más felhasználók által definiált dolgok is viselkedhetnek __stream__-ként. Automatikusan használhatjuk a rengeteg soros I/O kódot, amelyet más felhasználók ítak, akik nem is tudják és nem is kell tudniuk a saját magunk által kiterjesztett __stream__ osztályról.

Ez alatt található a ```using namespace std;``` sor. A standard (std) névté globális használata. Ennek hatására az ```std``` névtérben található típusok, függvények és változók oly módon is elérhetővé válnak, mintha a globális névtérben lettek volna deklarálva. A standard könyvtárban található implementációk az ```std``` névtérben találhatók. Ennek az az oka, hogy a standard könyvtár gazdag eszközkészletet biztosít, amelynek során szmos gyakran használt nevet is felhasznál mint pl. __find, max__ stb. Ha nem az ```std``` névtérben lennének ezeke a nevek, akkor bizonyos kontextusokban nem használhatnánk fel ezeket a neveket a saját programunkban. Éppen ezért gyakran kihagyjuk ezt a sort a programunkból. A standard könyvtárbeli elemekre minősített nevek megadásával hivatkozhatunk:

```cpp
#include <iostream>

int main(int argc, const char* argv[])
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
```

__FONTOS__: a ```using namespace ...``` SOHA nem kerülhet header állományba. Ezzel ugyanis a header állomány összes felhasználójánál potenciálisan nevütközéseket okozunk. frntebb explicit módon jeleztük a fordítónak, hogy az ```std``` névtérben keresse a ```cout``` és az ```endl``` változókat. Létezik úgynevezett _névtelen névtér_ (unnamed namespace), amit arra használhatunk, hogy ne szemeteljük tele a globális névteret, ezáltal megvédjük magunkat a többértelműségtől.

```cpp
namespace 
{
  // amit el akarunk keríteni
}
```
 Ilyenkor csak a deklarált fájlon belül érhetjük el a névtelen névtérben deklarált változókat a __hatókör operátor__ (scope operátor) ```::``` segítségével.
 

A ```main``` egy függvény, ez a program belépési pontja (entry point). Minden C++ nyelven írt programnak tartalmazni kell PONTOSAN egyet. Ez az egyetlen olyan függvény, amit nem lehet túlterhelni. Paraméterei küzöl az ```argc``` a parancssori paraméterek számát adja meg, míg az ```argv[]``` egy nullpointerrel terminált, karaktermutatókat tartalmazó tömb, amelyben a paraméterek vannak C-stílusú string-ként. A C++-ban a tömböket 0-tól indexeljük, az ```argv[]``` nulladik eleme a futtatható állomány neve, első eleme pedig az első paraméter.

__./program elso masodik (vagy program.exe elso masodik) <br>
argv[0] == "program" <br>
argv[1] == "elso" <br>
argv[2] == "masodik"__

A két kapcsos zárójel (```{ }```) közti részt blokknak nevezzük. A ```cout``` a C++ standard kimenete. Az ```endl``` pedig beilleszt egy newline karaktert a kiírandó sor végére. Felmerülhet a kérdés, hogy mi a különbség az ```endl``` és a ```\n``` között? Nos,

* az ```\n``` csak egy string aminek a hossza egy és ez adódik hozzá azt ```std::out```-hoz.
* az ```std::endl``` ezzel szemben egy objektum, ami a newline karakter hozzáadásához vezet ÉS ezek után flush-olja az ```std::out``` buffert. Ezért ez több számítással jár. Az ```std::endl``` meghívja az ```os.put(os.widen('\n'))``` függvényt, majd ezt követően az ```os.flush()``` függvényt.


A ```return``` kulcsszó visszaadja a vezérlést az őt hívó függvénynek, jelen esetben ez a program befejezését jelenti, ezért az operációs rendszernek. A ```return``` mögé írt szám visszatérési értéke 0. Ez általában azt jelenti, hogy a program rendben lefutott. A ```main()```-ben ez nem kötelező, ha elhagyjuk, akkor automatikusan 0-t ad vissza, továbbá nem muszáj kiírni az ```int argc, const char* argv[]``` bemeneti paramétereket sem. A fordító ezeket automatikusan legenerálja. Ezért a következő program ekvivalens az előzőkkel:

```cpp
#include <iostream>

int main() { std::cout << "Hello World!" << std::endl; }
```

A __right shift__ operátor (```<<```) alternatív szintaxissal is meghívható:

```cpp
#include <iostream>

int main() { operator<<(std::cout, "Hello World!"); }
```

Ebből is látható hogy az operátorok tulajdonképpen függvények, tehát a szintaxisuktól eltekintve ugyanazon nyelvi szabályok fognak vonatkozni rájuk, mint a többi függvényre.

__Függvény deklaráció__nak nevezzük, amikor a függvény használatáról adunk információt. Ennek része a paraméterek típusa, visszatérési érték típusa és a függvény neve.

__Függvény definíció__nak nevezzük azt, amikor leírjuk a függvény törzsét is, ezzel meghatározva, hogy mit csináljon. Ez egyben deklaráció is, hiszen a paraméterekről és visszatérési értékről is tartalmazza a szükséges információt.

Egy függvényhez több deklaráció is tartozhat, ha nem mondanak egymásnak ellent.

```cpp
int main; // deklaráció

int main() // deklaráció és definíció
{
  std::cout << "Hello World!" << std::endl;
}
```

## Fordító működése, fordítás parancssori eszközökkel, több forrásfájl, object, linkelés

A fordítás 3 fő lépésből all:

* __Preprocesszálás__ (előfeldolgozás)
* __Fordítés__ (a tárgykód létrehozása)
* __Linkelés__ (szerkesztés)

A fordítás a __preprocesszor__ parancsok végrehajtásával kezdődik, mint például a __header__ fájlok beillesztése a ```.cpp``` fájlokba, az így kapott fájlokat hívjuk fordítási egységeknek (translation unit). A fordítási egységek külön-külön fordulnak __tárgykóddá__ (object file). Ezekben a gépi utasítások már megvannak, de hiányoznak belőle a hivatkozások, például változók vagy függvények, melyek más fájlokban vannak emgvalósítva. Ahhoz, hogy a tárgykódból __futtatható állományt__ (executable file) lehessen készíteni, össze kell linkelni őket. A __szerkesztő__ (linker) feladata, hogy ki töltse a tárgykódban hiányzó referenciákat. A linkelés lehet __statikus__, amikor a fordító tölti fel a hiányzó referenciákat, vagy __dinamikus__, amikor fordítási időben, jellemzően egy másik fájlból (pl: .dll) tölti be a hiányzó kódot. Utóbbi akkor praktikus, ha egy modult több, különálló program használ.

![compilation](img/compilation.png)


### Preprocesszálás

Az __előfeldolgozó__ (preprocesszor) használata a legtöbb esetben kerülendő. Ez alól kivételek a __header__ állományok ```include```-olása. A preprocesszor primitív szabályok alapján dolgozik és __nyelvfüggetlen__. Mivel semmit nem tud a C++-ról, ezért sokszor meglepő viselkedést okoz a használata a fejlesztő számára. Emiatt nem egyszerű meghatározni az általa okozott hibákat. Továbbá az automatikus refaktoráló eszközök használatát is megnehezíti a túlzott használata.

A következőkben nézzünk meg pár preprocesszor direktívát. Minden direktívá ```#``` jellel kezdődik.

```cpp
#define NUMBER 5

NUMBER NUMBER NUMBER

// a #define NUMBER 5 parancs azt jelenti, 
// hogy minden NUMBER szót ki kell cserélni a fájlban 5-re.

#define NUMBER

#ifndef NUMBER
  std::cout << "Is defined";
#else
  std::cout << "Not defined";
#endif
```

A fent leírtakon kívül a ```#define``` hatására a preprocesszor az első argumentumot defináltnak fogja tekinteni. A fenti kódban megvizsgáljuk, hogy a ```NUMBER``` makró definiálva van-e (```#ifdef``` parancs), és mivel ezt megtettük, az ```#else```-ig minden beillesztésre kerül, kimenetben csak annyi fog szerepeni, hogy __"Is defined"__.

```cpp
#define NUMBER
#undef NUMBER

#ifndef NUMBER
  std::cout << "Is defined";
#else
  std::cout << "Not defined";
#endif
```

Az ```#undef``` parancssal a paraméterként kapott makrót a preprocesszor nem tekinti tivábbé makrónak, így a kimenetben a __"Not defined"__ fog szerepelni. Definiálni függvényeket is tudunk.

```cpp
#include <iostream>

#define MAX(x, y) (x > y ? x : y)

int main()
{
  std::cout << MAX(10, 12) << std::endl;
}
```

Látható, hogy a preprocesszort kódrészletek kivágására is lehet használni. Felmerülhet a kérdés, hogy ha az eredeti forrásszövegből a preprocesszor kivág, illetve beilleszt részleteket, akkor a fordító honnan tudja, hogy a hiba jelentésekor melyik sorra jelezze a hibát? Hiszen az előfeldolgozás előtti és utáni sorszámok egymáshoz képest eltérnek. Ennek a problémának a kiküszöbölése érdekében a preprocesszpr beszúr sorokat a fordító számára, amik hordozzák azt az információt, hogy a feldolgozás előtt az adott sor melyik fájl hányadik sorában volt megtalálható. 

Ezeknek a preprocesszor direktíváknak a használata legtöbb esetben kerülendő, mert gyakran nem azt a viselkedést produkálja amire számítunk. Tekintsük az alábbi kódrészletet:

```cpp
#include <iostream>

#define add(x, y) ((x+y) + (x+y))

int main()
{
  int i = 1;
  int j = 2;
  std::cout << add(++i,++j); // 12
  i = 1;
  j = 2;
  std::cout << add(++i,j++); // 10
  i = 1;
  j = 2;
  std::cout << add(i++,j++); // 8
  return 0;
}
```

Rekurzív include-oknál a preprocesszpr egy bizonyos mélységi limit után leállítja az előfeldolgozást. Ezt egy trükk segítségével megakadályozhatjuk, hogy ugyan az a fájl többször is beillesztésre kerüljön többszörös include esetén.

```cpp
#ifndef __H_HPP__
#define __H_HPP__
  SYMBOL
#endif

#include "h.hpp"
#include "h.hpp"
#include "h.hpp"
#include "h.hpp"
```

Ellenőrizzük, hogy a ```__H_HPP__``` szimbólum definiálva van-e? Ha nincs, akkor definiáljuk. A második ```#include "h.hpp"```-nál nem fogjuk újra beilleszteni a ```SYMBOL```-t, mert az ```#ifndef __H_HPP__``` kivágja azt a szövegrészt, mivel már egyzer definiálásra került. Ez az úgynevezett __header guard__ vagy __include guard__ technológia. Megvédi a header-t a többszörös include-tól.

Réges régen egy messzi-messzi galaxisban szükséges volt makrókat használni, hogy megvédjük a header fájlokat a többszörös include-tól. Ez nem csak azzal a kockázattal jár, hogy névbeli konfliktusok léphetnek a használt makrók kapcsán, de a fordítónak semmi fogalma sincs a programozó szándékáról, ezért néha nem képes optimalizálni a viselkedést. Van azonban egy ```#pragma once``` amelyet a modern fordítók támogatnak és amelynek a célja az volt, hogy megakadályozza a header-ök többszöri beillesztését egy fordítási egységbe. A fordítók ezt nagyon hatékony és biztonságos módon valósítják meg. Felgyorsítja a fordítási időt, különösen nagy projektek esetén, és elkerüli a névütközések konfliktusának kockázatát. 

```cpp
#pragma once

// program kód
```

* Olvashatóbbá teszi a kódot a felesleges kódsorok elhagyásával.
* Elkerüli a névütközéseket más könyvtárakkal és fejlécekkel.
* Felgyorsítja a fordítási időt.

__Megjegyzés__: C-ben a globális konstansok definiálsára használták. Ez C++-ban kerülendő. Használjuk a ```const``` kulcsszót és kössük minél jobban a scope-hoz a változóinkat.


### Linkelés

Tekintsük az alábbi fordítási egységeket:

```cpp
// symbol.cpp
void symbol() {}

// main.cpp
int main() { symbol(); }
```

Fordítsuk le őket az alábbi sorrendben:

```clang++ main.cpp```

```clang++ symbol.cpp```

__Megjegyzés__: ```clang++``` helyett használhatjuk a ```g++```-t is, ami nem összekeverendő a ```gcc```-vel, ami C fájlok fordítására alkalmas.

Fordítási hibát fogunk kapni, hiszen vagy csak a ```main.cpp```-ből létrejövő fordítási egységet, vagy a ```symbol.cpp```-ből létrejövő fordítási egységet fogja látni a fordító, egyszerre a kettőt nem. Megoldás az, ha __forward deklarál__unk, azaz ```void symbol();```-t beillesztünk a ```main()``` függvény fölé, mely jelzi a fordítónak, hogy a ```symbol()``` az egy függvény, visszatérési értékének a típusa ```void``` (azaz nema d vissza semmit) és nincs paramétere.

```cpp
// symbol.cpp
void symbol() {}

// main.cpp
void symbol(); // forward deklaráció

int main() { symbol(); }
```

Ekkor a ```clang++ main.cpp``` paranccsal történő fodítás során a linkelés fázisánál kapunk hibát, mert a linker nem fogja megtalálni a ```void symbol()``` függvény definícióját. Ezt úgy tudjuk megoldani, ha a ```main.cpp```-ből és a ```symbol.cpp```-ből először tárgykódot készítünk, majd ksőbb összelinkeljük őket. Ekkor a  ```main.cpp```-ben lesz egy hivatkozás a ```void symbol();``` függvényre, és a ```symbol.cpp``` fogja tartalmazni a függvény definícióját.

```clang++ -c main.cpp```

```clang++ -c symbol.cpp```

A ```-c``` parancs (compile) segítségével jelezzük a fordítónak, hogy még ne linkeljek csak tárgykódot állítsa elő. Majd a 

```clang++ main.o symbol.o```

parancs segítségével az eredményül kapott tárgykódot tudjuk össze linkelni.

Rövidebb, ha egyből a ```.cpp``` fájlokat adjuk meg a fordítónak.

```clang++ main.cpp symbol.cpp```

Egy adott függvényt (objektumot, osztályt) akárhányszor deklarlhatunk, azonban, ha a deklarációk ellentmondanak egymásnak, akkor fordítási hibát kapunk. Definiálni viszont a legtöbb esetben pontosan egyszer szabad. Több definíció vagy épp a definíció hiánya problémát okozhat. Ezt az elvet szokás __One Definition Rule__-nak vagy röviden __ODR__-nek nevezni.

Ha egy ```.cpp```-ben több függvény is van, akkor nem célszerű ezeket egyesével forward deklarálni minden egyes fájlban, ahol használni szeretnénk. Ennél egyszerűbb egy header fájl megírása, amiben deklaráljuk a függvényünket.

```cpp
// symbol.hpp
#ifndef _SYMBOL_H_
#define _SYMBOL_H_
  void symbol();
#endif
```

Ilyenkor elég a ```symbol.hpp```-t include-olni. Szokás a ```symbol.hpp```-t a ```symbol.cpp```-ben is include-olni, mert ha véletlenül ellent mondana egymásnak a definíció a ```cpp``` fájlban és a deklaráció a ```hpp``` fájlban, akkor a fordító hibát fog jelezni (pl.: eltérő visszatérési érteket adunk meg).

Tekintsük az alábbi kódrészletet:


```cpp
// symbol.hpp
#ifndef _SYMBOL_H_
#define _SYMBOL_H_
  void symbol() {}
#endif
```

Abban az esetben, ha több fordítási egységből álló programot fordítunk, melyek tartalmazzák a ```symbol.hpp``` header-t, akkor a preprocesszor több ```symbol()``` függvény definíciót csinál és linkeléskor a linker azt látja, hogy egy függvény többször van definiálva, és ez linkelési hibához vezet, ugyanis a fordító nem fogja tudni eldönteni determinisztikusan, hogy melyiket is kellene használnia.

__Megjegyzés__: header fájlokban általában nem szabad definíciót írni, kivételek lehetnek a __template__ és az __inline__ függvények.


Hasznos kapcsolók fordításnál:

* ```-Wall -Wextra``` - warningok megjelnítése
* ```-std=c++xx``` - xx helyett bármelyik C++ szabvány szám elfogadott [98, 03, 11, 13, 17, 2a]
* ```-fsanitize=address``` - létrehoz ellenőrzéseket, amik azelőtt észrevesznek bizonyos nem definiált viselkedéseket, mielőtt azok megtörténnek.
* ```-O2``` - kettes szintű optimalizációt kapcsolja be. Alapértelmezetten nincs bekapcsolva (```-O0```), egészen ```-O3```-ig lehet fokozni.


### A C++ nyelvi elemei

Minden C++ kód tokenekből áll. A token a legkisebb nyelvi egység, ami még értelmes a fordító számára. Tokeneknek az alábbiakat tekntjük:

* __Kulcsszavak__: _int_, _return_
* __Azonosítók__: _number_ - lényegében azok a nevek, melyeket mi hozunk létre. Függvények, osztályok, változó nevei. Ez csak betűkből és számokból állhat, nem kezdődhet számmal es nem lehet kulcsszó. Fontos egjegyezni, hogy a C++ nyelv különbséget tesz kis- és nagybetűk között (case sensitive).
* __Literálok__:
	* egész számliterálok: 0xa23
	* karakterliterálok: 'a'
	* lebegőpontos számliterálok: 0.12
	* konstans szövegliterálok: "Hello"
* __Operátorok__: ```<<```, ```::```
* __Szeparátorok__: ```;```, ```{```, ```}```


![alt tokenek](img/tokens.png)

### Viselkedések kategorizálása C++-ban

Reménytelen megközelítés lenne a szabványban minden szintaktikusan (nyelvtanilag) helyes kódhoz pontos szemantikát (működést) adni. Ezért a C++ szabvány néhány esetben nem vagy csak részben definiálja egy adott program működését.

#### Nem definiált viselkedés

```cpp
int main()
{
  int i = 0;
  std::cout << ++i << i++ << std::endl;
}
```

Fordítás és futtatás után különböző fordítókkal különböző eredményeket kaphatunk. Az, hogy mikor értékelődik ki a ```++i``` és az ```i++``` a kifejezésen belül, __nem specifikált__. Amikor a szabvány nem tér ki arra, hogy pontosan milyen viselkedésű kódot generáljon a fordító, akkor a fordító bármit választhat. Ez többek között lehetőséget ad a fordítónak arra, hogy __optimalizáljon__.

A C++-ban vannak úgynevezett __szekvenciapontok__. A szabvány annyit mond ki, hogy a szekvenciapot előtti kód hamarabb kerüljön kiértékelésre mint az utána levő. Mivel itt az ```i``` értékadása után és csak az ```std::endl``` után van szekvenciapont, így az, hogy milyen sorrendben történjen a kettő közötti kifejezés részkifejezéseinek a kiértékelése,a fordítóra van bízva.

A C++-ban nem meghatározott, hogy két szekvenciapont között mi a kifejezések és részkifejezések kiértékelésének a sorrendje. Az adatfüggőségek azonban definiálnak egy sorrenet.

```cpp
int main() { std::cout << f(); }
```

Bár a fenti kódban csak az ```f()``` meghívása után található szekvenciapont, a függvény eredményének a kiírása előtt ki kell számolni az eredményét, különben nem tudnánk, hogy mit írjunk ki. Tehát a fenti kódban garantált, hogy az ```f()``` az eredmény kiírása előtt fog lefutni.

Az, hogy két részkifejezés szekvenciaponttal történő elválasztása nélkül ugyanazt a memóriaterületet módosítja, __nem definiált__ viselkedést eredményez. Ilyenkor a fordító vagy a futó program bármit csinálhat. A szabvány semmiféle megkötést nem tesz. 

__Megjegyzés__: az a program, amely nem definiált viselkedéseket tartalmaz, __hibás__.


### Nem specifikált viselkedés

Amennyiben aszabvány definiál néhány lehetséges opciót, de a fordítóra bízza, hogy az melyiket választja, akkor __nem specifikált__ viselkedésről beszélünk. A nem specifikált viselkedés csak akkor probléma, ha a program végeredményét befolyásolhatja a fordtó választása.

```cpp
int main()
{
  int i = 0;
  int j = 0;
  std::cout << ++i << j++ << std::endl; // 11
}
```

Bár azt továbbra se tudjuk, hogy a ```++i``` vagy a ```++j``` értékelődik ki előbb (nem specifikált), azt biztosan tudjuk, hogy 11-et fog kiírni (a program végeredménye jól definiált).

### Implementáció által definiált viselkedés

A szabvány nem köti meg, hogy egy ```int``` egy adott platformon mennyi byte-ból álljon. Ez állandó, egy adott platformon egy adott fordító mindig ugyanakkorát hoz létre, de platform/fordító váltás esetén ez változhat. Ennek az az oka, hogy különböző platformokon különböző választás eredményez hatékony programokat. Ennek köszönhetően hatékony kódot tud generálni a fordító, viszont a fejlesztő dolga, hogy megbizonyosodjon róla, hogy az adott platformon a primitív típúsok méretei megfelelnek a program által elvárt követelményeknek.

### Globális változók

Ténxleg igaz, hogy a program futása a ```main()``` függvény végrehajtásával kezdődik?

```cpp
#include <iostream>

std::ostream& os = std::cout << "Hello";

int main() { std::cout << " world!" << std::endl; }
```

Kimenet: Hello world!

A program végrehajtásánál az első lépés az úgynevezett __globális változók__ inicializálása. Ennek az oka az, hogy a globális változók olyan objektumok, melyekre a program bármely pontján hivatkozni lehet. Ebből kifolyólag, ha ```os```-t szeretnénk használni a ```main()``` függvény első sorában, akkor ezt meg lehessen tenni. Az inicializálastlan változó használata nem definiált viselkdes, ezért fontos már a ```main()``` előtt inicializálni a globális változókat.


### Globális változók definíciója és deklarációja

Globális változókat úgy tudunk létrehozni, hogy kezvetlenül egy névtéren belül definiáljuk őket.

```cpp
// main.cpp
int x;
int main() {}
```

```x``` egy globális változó. Azonban mit lehet tenni, ha nem csak a ```main.cpp```-ben szeretnénk használni, hanem egy másik fordítási egységben is?

```cpp
// other.cpp
int x;
void f() { x = 0; }
```

Abban az esetben, ha a ```main.cpp```-t és az ```other.cpp```-t együtt fordítjuk, fordítási hibát kapunk, ugyanis megsértettük az __ODR__-t, hiszen ```x``` kétszer van definiálva. Ezt úgy tudjuk megoldani, ha forward deklarájuk ```x```-et az ```extern``` kulcsszó segítségével.

```cpp
// other.cpp
extern int x;
void f() { x = 0; }
```

Egy globális változó deklarációja hasonlít a függvényekéhez, információval látja el a fordítót arról hogy az adott szimbólum egy globális változó, és milyen a típusa.

__Megjegyzés__: a globális változók deklarációit érdemes külön header fájlba gyűjteni.

### Globális változók inicilizációja

Amennyiben egy lokális ```int```-et hozunk létre és nem adunk neki kezdőértéket, annak értéke nem definiált lesz (memóriaszemét).

```cpp
int x;
int main() { std::cout << i << std::endl; } // 0
```

Az eredmény azonban mindig 0 lesz. Ennek az oka az, hogy a globális változók mindig 0-ra inicilaizálódnak (legalábbis az ```int```-ek). A globális változókat csak egyszer hozzuk létre a program futásakor, így érdemes jól definiált kezdőértéket adni neki. A __stack__en rengetegszer létre kell hozni változókat, nem csak egyszer, így ott nem éri meg minden alkalommal egy jól definiált kezdőértékkel inicializálni. Sokkal nagyobb lenne a hatása a futási időre.

A 0-ra való inicializálás oka globális változók esetén az, hogy ezt a modern processzorok gyorsan tudják kivitelezni a legtöbb platformon.

### Problémák a globális változókkal

Vajon a linkelés befolyásolja a program megfigyelhető viselkedését? Tekintsük az alábbi kódot:

```cpp
// main.cpp
#include <iostream>

std::ostream& os = std::cout << "Hello";
int main() { }

// other.cpp
std::ostream os2 = std::cout << " World";
```

Itt nem specifikált a két globális változó inicializációs sorrendje, és ha más sorredben linkeljük a
fordítási egységekből keletkező tárgykódot, mást ír ki.

```clang++ main.cpp other.cpp != clang++ other.cpp main.cpp```

__Megjegyzés__: ez a példa nem számít jó kódnak, mert nem specifikált viselkedése van a programnak, kimenete nem definiált. Ez egy jó elrettentő példa, miért nem érdemes globális változókat használni. Ezen kívül számos egyéb problémát is felvetnek a globális változók: átláthatatlanabb kód, mivel bárhol hozzá lehet férni nem lehetünk biztosak benne, hogy az érték, amit kiolvasunk valaki más nem módosította-e előttünk.

### Hatókör, láthatóság, élettartam

__Hatókör__: Deklarációkor a programozó összekapcsol egy entitást (pl. egy változót vagy egy függvényt) egy névvel. A hatókör alatt a forrásszöveg azt a részét értjük, amíg ez az összekapcsolás érvényben van. Ez általában annak a blokknak a végéig tart, amely tartalmazza az adott deklarációt

__Láthatóság__: a hatókör részhalmaza, a programszöveg azon része, ahol a deklarált névhet a megadott entitás tartozik. Mivel az egymásba ágyazott blokkokban egy korábban már bevezetett nevet más entitáshoz kapcsolhatunk, ezért ilyenkor a külső blokkban deklarált entitás a nevével már nem elérhető. Ezt nevezzük a láthatóság elfedésének.

#### Automatikus, statikus és dinamikus élettartam

__Automatikus élettartam__: a blokkokban deklarált lokális változók automatikus élettartamúak, ami azt jelenti, hogy a deklarációtól a tartalmazó blokk végéig tart, azaz egybeesik a hatókörrel. A helyfoglalás szmukra a végrehajtási verem aktuális aktivációs rekordjában történik meg.

__Statikus élettartam__: a globális változók, illetve egyes nyelvekben a __statikus__ként deklarált változók statikus élettartamúak. Az ilyen változók élettartama a program teljes végrehajtási idejére kiterjed, számukra a helyfoglalás már a fordítási időben megtörténhet.

__Dinamikus élettartam__: a dinamikus élettartamú változók esetén a programozó foglla helyet számukra a dinamikus tárterületen (heap), és a programozó feladata gondoskodni árról is, hogy ezt a tárterületet később felszabadítsa. Amennyiben ez utóbbiról megfeledkezik, azt nevezzük __memória szivárgás__nak (_memory leak_). A dinamikus élettartam esetén a hatókör semmilyen módon nem kapcsolódik össze az élettartammal, az élettartam szűkebb vagy tágabb is lehet a hatókörnél.

Tekintsük az alábbi kódrészletet és figyeljük meg mikor tudunk az ```x``` változóra hivatkozni.

```cpp
#include <iostream>

int x;

int main() 
{
  int x = 1;
  {
    int x = 2;
    std::cout << x << std::endl; // 2
  }
}
```

A ```main()``` elején létrehozott ```x``` az utána következő blokkban teljesen elérhetetlen - nincs olyan szabványos nyelvi eszköz, amivel tudnánk rá hivatkozni. Ezt a folyamatot nevezzük __leárnyékolás__nak (_shadowing_). Azonban a külső globális ```x```-re bármikor tudunk hivatkozni a már korábban említett scope operátor (```::```) segítségével.

```cpp
#include <iostream>

int x;

int main() 
{
  int x = 1;
  {
    int x = 2;
    std::cout << ::x << std::endl; // 0
  }
}
```

### Jobb- és balérték

A láthatóság és élettartam fogalmával szoros összeköttetésben áll a __jobb- és balérték__ fogalma. Egy objektumot __balérték__-nek (_left value_, röviden _lvalue_) nevezzük, ha van a címképző operátorral (```&```) le tudjuk kérni a memóriabeli címét, és __jobbérték__-nek (_right value_, röviden _rvalue_) ha nem. A jobbértékek többnyire ideiglenes objektumok, mint pl. az érték szerint visszatérő függvény visszatérési értéke és a literálok. Lévén ezek az objektumok csak ideiglenesen szerepelnek a memóriában ezért hiba lenne a memóriacímükre hivatkozni, így a fordító nem is engedi. Példaképp:

```cpp
int main()
{
  int* p, r;
  &p; // ok, p pointer memóriacímére mutat
  &r; // ok, r memóriacímére mutat
  &1; // nem ok, 1 jobbérték
  &"Hello"; //nem ok, a "Hello" jobbérték
  5 = r; // nem ok, jobbértéknek nem lehet értéket adni
}
```


