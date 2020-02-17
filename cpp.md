<img src="img/cppIcon.png" alt="cpp icon" width="200">


__"C makes it easy to shoot yourself in the foot; <br>
C++ makes it harder, but when you do it, it blows your whole leg off."__

~ _Bjarne Stroustrup_ ~


## Bevezetés

A __C++__ egy általános célú, magas szintű programozási nyelv. Gyakori tévhit, hogy alacsony szintű (hardver közeli). Noha lehetőséget biztosít arra, hogy alacsony szinten programozzunk, számos absztrakciós lehetőséget tartalmaz. Támogatja a __procedurális__, __objektumorientált__ és a __generikus programozást__ valamint az __adatabsztrakciót__. Legtöbb nyelvhez képest abban emelkedik ki, hogy az itt megvalósított absztrakcióknak ritkán van futási idejű költsége.

__Érdekesség__: [Andrei Alexandrescu](https://en.wikipedia.org/wiki/Andrei_Alexandrescu) azt nyilatkozta, hogy amikor a Facebook-nak a back-end kódján 1%-ot sikerült optimalizálnia, több mint 10 évnyi fizetését spórolta meg a cégnek havonta csak az áramköltségen.

A C++ nyelv fejlesztését még a '80-as években __Bjarne Stroustrup__ kezdte el a C programozási nyelv kiterjesztéseként, más nyelvekből véve át megoldásokat. Az első hivatalos szabványa a nyelvnek 1998-ban jelent meg. Alapvetően a nyelv két összetevőből áll. Az aktuális szabványból és annak implementációjából. A szabvány az, ami meghatározza a nyelv nyelvtanját, valamint a szemantikáját (mit jelentenek a leforduló programok).

Eddigi C++ szabványok:

* C++98
* C++03
* C++11
* C++14
* C++17
* (C++2a) (Egyelőre még nem hivatalos ezért is a 2a nevet kapta, de 2020-ban várható)

A szabvány nevében a számok a szabvány elfogadásának évét jelentik.

Számos fordító létezik a C++ kódok fordítására, amelyek különböző mértékben támogatják az aktuális C++ szabványt:

* MSVC
* GCC
* Clang


### C++ filozófia

A C++ filozófiájának fontos eleme, hogy ha nem használunk egy adott nyelvi eszközt, akkor annak ne legyen negatív hatása a program teljesítményre. Magyarán mondva csak azért "fizessünk", amit használunk is. Fontos megjegyezni, hogy a C++ alapvetően nem objektumorientált nyelv. Ahogy fentebb olvashattuk, kíválóan alkalmas mas programozási paradigmák használatára is. A nyelv nem próbál meg ráerőltetni a programozóra egy megközelítést, ellenben próbál minél gazdagabb eszköztárat biztosítani, hogy a megfelelő problémát a megfelelő megközelítéssel lehessen megoldani. Még akkor is, ha ez a különböző paradigmák keverését vonja maga után. Ezért a nyelvet gyakran multiparadigmás programozási nyelvnek is szokás nevezni.


## Alapok


### C++ adattípusok

A C++ szigorúan típusos nyelv, ami azt jelenti, hogy már fordítási időben ismert kell a változók típusát. Az összes változó adattípust használ a deklaráció során a tárolni kívánt adatok típusának korlátozására. Ezért azt mondhatjuk, hogy az adattípusokat arra használják, hogy megmondják a változóknak, hogy milyen típusú adatot tárolhatnak. Ha egy változót a C++-ban definiálnak, a fordító memóriát allokál ehhez a változóhoz azon adattípus alapján, amellyel azt deklarálják. Minden adattípushoz eltérő mennyiségű memória szükséges.

Adattípusok C++-ban:

* __Primitív__: ezek az adattípusok beépített vagy előre meghatározott adattípusok, és a felhasználó közvetlenül felhasználhatja a változók deklarálására. példa: ```int```, ```char```, ```float```, ```bool``` stb. A C++-ban rendelkezésre álló primitív adattípusok a következők:
	* __Integer__ (```int```): az egész számok tárolására használják. Általában __4 bájt__ memóriahelyet igényelnek, és -2147483648-tól 2147483647-ig terjednek.
	* __Character__ (```char```): karakterek tárolására szolgál. A karakterek általában __1 bájt__ memóriahelyet igényelnek, és -128 és 127 vagy 0 és 255 között változhatnak.
	* __Boolean__ ```bool```: logikai értékek tárolására szolgál. A logikai változó igaz (```true```) vagy hamis (```false```) értékeket tárolhat.
	* __Floating point__ (```float```): egyszeri pontosságú (__single precision__) tizedes értékek tárolására szolgál. Általában __4 bájt__ memóriahelyet igényelnek. 1 bit az előjelnek, 8 bit a szám egész részének és 23 bit a tizedes résznek van fenntartva, azaz 7 tizedesjegy pontossággal képes tárolni az adatokat.
	* __Double floating point__ (```double```): dupla pontosságú (__double precision__) tizedes értékek tárolására szolgál. Általában __8 bájt__ memóriahelyet igényelnek. 1 bit az előjelnek, 11 bit a szám egész részének és 52 bit a tizedes résznek van fenntartva, azaz 15 tizedesjegyig képes tárolni az adatokat.
	* __Void__ (```void```): azt jelenti: érték nélkül. A ```void``` adattípus értéktelen entitást jelent. Azoknál a függvényeknél használják, amelyek nem adnak vissza értéket.
	* __Wide character__ (```wchar_t```): szintén egy karakter adattípus, de ennek az adattípusnak a mérete meghaladja a normál 8 bites adattípust. Általában __2 vagy 4 bájt__ hosszú.
* __Származtatott__: az primitív vagy beépített adattípusokból származó adattípusokat származtatott adattípusoknak nevezzük. Ezek négyféle lehetnek, nevezetesen:
	* __Function__
	* __Array__
	* __Pointer__
	* __Reference__
* __Felhasználó által definiált__: ezeket az adattípusokat maga a felhasználó határozza meg. Például egy osztály  vagy egy struktúra meghatározása a C++-ban. A C++ a következő felhasználó által definiált adattípusokat tartalmazza:
	* __class__
	* __structure__
	* __union__
	* __enum__
	* __typedef__

A primitív típusok méretének megadásánál azért szerepel mindenhol az _általában_, mert a C++ szabvány nem határozza meg pontosan az egyszerű típusok méretét, így azok fordítótól és hardverkörnyezettől függően eltérőek lehetnek különböző rendszereken. A rendszerünkön érvényes méreteket, tartományokat a ```sizeof()``` operátorral tudjuk meghatározni. 
A ```sizeof()``` operátor megadja a paraméterként megkapott típus, vagy objektum esetében annak típusának méretét. Mindenesetre abban biztosak lehetünk, hogy ezek a megkötések minden rendszeren érvényesek C++-ban:

* ```1``` == ```sizeof(char)``` <= ```sizeof(short int)``` <= ```sizeof(int)``` <= ```sizeof(long int)```
* ```1``` <= ```sizeof(bool)``` <= ```sizeof(long int)```
* ```sizeof(char)``` <= ```sizeof(wchar_t)``` <= ```sizeof(long int)``` <= ```sizeof(long long int)```
* ```sizeof(float)``` <= ```sizeof(double)``` <= ```sizeof(long double)```
* ```sizeof(int)``` == ```sizeof(signed int)``` == ```sizeof(unsigned int)``` és ugyanez ```short int```, ```long int```, valamint ```long long int``` esetén is érvényes.

Fontos megjegyezni, hogy az ```1``` == ```sizeof(char)``` kifejezésben az 1 nem feltétlenül 1 bájtot jelent, hanem egy egységet, ami bizonyos rendszereken lehet például 2 vagy 4 bájt.

__Megjegyzés__: a ```sizeof(type)``` kifejezés helyett használható a ```std::numeric_limits<type>::digits```. Ennek használatához azonban szükség van a ```<limits>``` header include-olására.


### Adattípus módosítók

Ahogy a neve is mutatja, az adattípus-módosítókat a beépített adattípusokkal használják az adatok hosszának módosítására, amelyet egy adott adattípus képes tárolni.

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


## Fordító működése, fordítás parancssori eszközökkel, több forrásfájl, object, linkelés

A fordítás 3 fő lépésből áll:

* __Preprocesszálás__ (_előfeldolgozás_)
* __Fordítás__ (_tárgykód létrehozása_)
* __Linkelés__ (_szerkesztés_)

A fordítás a __preprocesszor__ parancsok végrehajtásával kezdődik, mint például a __header__ fájlok beillesztése a ```.cpp``` fájlokba, az így kapott fájlokat hívjuk __fordítási egységeknek__ (_translation unit_). A fordítási egységek külön-külön fordulnak __tárgykóddá__ (_object file_). Ezekben a gépi utasítások már megvannak, de hiányoznak belőle a hivatkozások, például változók vagy függvények, melyek más fájlokban vannak megvalósítva. Ahhoz, hogy a tárgykódból __futtatható állományt__ (_executable file_) lehessen készíteni, össze kell linkelni őket. A __szerkesztő__ (_linker_) feladata, hogy kitöltse a tárgykódban hiányzó referenciákat. A linkelés lehet __statikus__, amikor a fordító tölti fel a hiányzó referenciákat, vagy __dinamikus__, amikor fordítási időben, jellemzően egy másik fájlból (pl: .dll) tölti be a hiányzó kódot. Utóbbi akkor praktikus, ha egy modult több, különálló program használ.

![compilation](img/compilation.png)


### Preprocesszálás

Az __előfeldolgozó__ (_preprocesszor_) használata a legtöbb esetben kerülendő. Ez alól kivételek a __header__ állományok ```include```-olása. A preprocesszor primitív szabályok alapján dolgozik és __nyelvfüggetlen__. Mivel semmit nem tud a C++-ról, ezért sokszor meglepő viselkedést okoz a használata a fejlesztő számára. Emiatt nem egyszerű meghatározni az általa okozott hibákat. Továbbá az automatikus refaktoráló eszközök használatát is megnehezíti a túlzott használatuk.

A következőkben nézzünk meg pár preprocesszor direktívát. Minden direktíva ```#``` jellel kezdődik.

```cpp
#define NUMBER 5

// a #define NUMBER 5 parancs azt jelenti, 
// hogy minden NUMBER szót ki kell cserélni a fájlban 5-re.

#ifndef NUMBER
  std::cout << "Is defined";
#else
  std::cout << "Not defined";
#endif
```

A fent leírtakon kívül a ```#define``` hatására a preprocesszor az első argumentumot defináltnak fogja tekinteni. A fenti kódban megvizsgáljuk, hogy a ```NUMBER``` makró definiálva van-e (```#ifndef``` parancs), és mivel ezt megtettük, az ```#else```-ig minden beillesztésre kerül.

```cpp
#define NUMBER
#undef NUMBER

#ifndef NUMBER
  std::cout << "Is defined";
#else
  std::cout << "Not defined";
#endif
```

Az ```#undef``` parancssal a paraméterként kapott makrót a preprocesszor nem tekinti továbbá makrónak.

Definiálni függvényeket is tudunk.

```cpp
#include <iostream>

#define MAX(x, y) (x > y ? x : y)

int main()
{
  std::cout << MAX(10, 12) << std::endl;
}
```

Látható, hogy a preprocesszort kódrészletek kivágására is lehet használni. Felmerülhet a kérdés, hogy ha az eredeti forrásszövegből a preprocesszor kivág, illetve beilleszt részleteket, akkor a fordító honnan tudja, hogy a hiba jelentésekor melyik sorra jelezze a hibát? Hiszen az előfeldolgozás előtti és utáni sorszámok egymáshoz képest eltérnek. Ennek a problémának a kiküszöbölése érdekében a preprocesszpr beszúr sorokat a fordító számára, amik hordozzák azt az információt, hogy a feldolgozás előtt az adott sor melyik fájl hányadik sorában volt megtalálható. 

További indok a preprocesszor direktívák kerülésére, hogy gyakran nem azt a viselkedést produkálják amire számítunk. 

Tekintsük az alábbi kódrészletet:

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
}
```

> kimenet: 12 10 8

Rekurzív ```include```-oknál a preprocesszor egy bizonyos mélységi limit után leállítja az előfeldolgozást. Ezt egy trükk segítségével megakadályozhatjuk, hogy ugyan az a fájl többször is beillesztésre kerüljön többszörös include esetén.

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

Ellenőrizzük, hogy a ```__H_HPP__``` szimbólum definiálva van-e. Ha nincs, akkor definiáljuk. A második ```#include "h.hpp"```-nál nem fogjuk újra beilleszteni a ```SYMBOL```-t, mert az ```#ifndef __H_HPP__``` kivágja azt a szövegrészt, mivel már egyszer definiálásra került. Ez az úgynevezett __header guard__ vagy __include guard__ technológia. Megvédi a header-t a többszörös include-tól.

A fenti kódban látható makrók használata olyan kockázattal jár, hogy névbeli konfliktusok léphetnek a használt makrók kapcsán, de a fordítónak semmi fogalma sincs a programozó szándékáról, ezért néha nem képes optimalizálni a viselkedést. Van azonban egy ```#pragma once``` nevezetű makró, amelyet a modern fordítók támogatnak és amelynek a célja az volt, hogy megakadályozza a header-ök többszöri beillesztését egy fordítási egységbe. A fordítók ezt nagyon hatékony és biztonságos módon valósítják meg. Felgyorsítja a fordítási időt, különösen nagy projektek esetén, és elkerüli a névütközések konfliktusának kockázatát. 

```cpp
#pragma once

// program kód
```

* Olvashatóbbá teszi a kódot a felesleges kódsorok elhagyásával.
* Elkerüli a névütközéseket más könyvtárakkal és fejlécekkel.
* Felgyorsítja a fordítási időt.

__Megjegyzés__: C-ben a globális konstansok definiálására használták a makrókat. Ez C++-ban kerülendő. Használjuk a ```const``` kulcsszót és a változóinkat kössük minél jobban ahhoz a scope-hoz amelybe tartoznak.


### Linkelés

Tekintsük az alábbi fordítási egységeket:

```cpp
// symbol.cpp
void symbol() {}

// main.cpp
int main() { symbol(); }
```

Fordítsuk le őket az alábbi sorrendben:

>$ clang++ main.cpp

>$ clang++ symbol.cpp

__Megjegyzés__: ```clang++``` helyett használhatjuk a ```g++```-t is, ami nem összekeverendő a ```gcc```-vel, ami __C__ fájlok fordítására alkalmas.

Fordítási hibát fogunk kapni, hiszen vagy csak a ```main.cpp```-ből létrejövő fordítási egységet, vagy a ```symbol.cpp```-ből létrejövő fordítási egységet fogja látni a fordító, egyszerre a kettőt nem. Megoldás az, ha __forward deklarálunk__, azaz ```void symbol();```-t beillesztjün a ```main()``` függvény elé, mely jelzi a fordítónak, hogy a ```symbol()``` az egy függvény, visszatérési értékének a típusa ```void``` (azaz nem ad vissza semmit) és nincs paramétere.

```cpp
// symbol.cpp
void symbol() {}

// main.cpp
void symbol(); // forward deklaráció

int main() { symbol(); }
```

A fodítás során a linkelés fázisánál kapunk hibát, mert a linker nem fogja megtalálni a ```void symbol()``` függvény definícióját. Ezt úgy tudjuk megoldani, ha a ```main.cpp```-ből és a ```symbol.cpp```-ből először tárgykódot készítünk, majd később összelinkeljük őket. Ekkor a  ```main.cpp```-ben lesz egy hivatkozás a ```void symbol();``` függvényre, és a ```symbol.cpp``` fogja tartalmazni a függvény definícióját.

>$ clang++ -c main.cpp

>$ clang++ -c symbol.cpp

A ```-c``` (compile) kapcsoló segítségével jelezzük a fordító számára, hogy még ne linkeljek csak a tárgykódot állítsa elő. Majd a 

>$ clang++ main.o symbol.o

parancs segítségével az eredményül kapott tárgykódot tudjuk össze linkelni.

Rövidebb, ha egyből a ```.cpp``` fájlokat adjuk meg a fordítónak.

>$ clang++ main.cpp symbol.cpp

Egy adott függvényt (objektumot, osztályt) akárhányszor deklarálhatunk, azonban, ha a deklarációk ellentmondanak egymásnak, akkor fordítási hibát kapunk. Definiálni viszont a legtöbb esetben pontosan egyszer szabad. Több definíció, vagy épp a definíció hiánya problémát okozhat. Ezt az elvet szokás __One Definition Rule__-nak vagy röviden __ODR__-nek nevezni.

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
* __Azonosítók__: _number_ - lényegében azok a nevek, melyeket mi hozunk létre. Függvények, osztályok, változók nevei. Ez csak betűkből és számokból állhat, nem kezdődhet számmal es nem lehet kulcsszó. Fontos megjegyezni, hogy a C++ nyelv különbséget tesz kis- és nagybetűk között (case sensitive).
* __Literálok__:
	* egész számliterálok: 0xa23
	* karakterliterálok: 'a'
	* lebegőpontos számliterálok: 0.12
	* konstans szövegliterálok: "Hello"
* __Operátorok__: ```<<```, ```::```
* __Szeparátorok__: ```;```, ```{```, ```}```

![alt tokenek](img/tokens.png)


## Viselkedések kategorizálása C++-ban

Reménytelen megközelítés lenne a szabványban minden szintaktikusan (nyelvtanilag) helyes kódhoz pontos szemantikát (működést) adni. Ezért a C++ szabvány néhány esetben nem, vagy csak részben definiálja egy adott program működését.


### Nem definiált viselkedés

```cpp
int main()
{
  int i = 0;
  std::cout << ++i << i++ << std::endl;
}
```

Fordítás és futtatás után különböző fordítókkal különböző eredményeket kaphatunk. Az, hogy mikor értékelődik ki a ```++i``` és az ```i++``` a kifejezésen belül, __nem specifikált__. Amikor a szabvány nem tér ki arra, hogy pontosan milyen viselkedésű kódot generáljon a fordító, akkor a fordító bármit választhat. Ez többek között lehetőséget ad a fordítónak arra, hogy __optimalizáljon__.

A C++-ban vannak úgynevezett __szekvenciapontok__. A szabvány annyit mond ki, hogy a szekvenciapot előtti kód hamarabb kerül kiértékelésre, mint az utána levő. Mivel itt az ```i``` értékadása után és csak az ```std::endl``` után van szekvenciapont, így az, hogy milyen sorrendben történjen a kettő közötti kifejezés részkifejezéseinek a kiértékelése,a fordítóra van bízva.

A C++-ban nem meghatározott, hogy két szekvenciapont között mi a kifejezések és részkifejezések kiértékelésének a sorrendje. Az adatfüggőségek azonban definiálnak egy sorrenet.

```cpp
int main() { std::cout << f(); }
```

Bár a fenti kódban csak az ```f()``` meghívása után található szekvenciapont, a függvény eredményének a kiírása előtt ki kell számolni az eredményét, különben nem tudnánk, hogy mit írjunk ki. Tehát a fenti kódban garantált, hogy az ```f()``` az eredmény kiírása előtt fog lefutni.

Az, hogy két részkifejezés szekvenciaponttal történő elválasztása nélkül ugyanazt a memóriaterületet módosítja, __nem definiált__ viselkedést eredményez. Ilyenkor a fordító vagy a futó program bármit csinálhat. A szabvány semmiféle megkötést nem tesz. 

__Megjegyzés__: az a program, amely nem definiált viselkedéseket tartalmaz, __HIBÁS__.


### Nem specifikált viselkedés

Amennyiben a szabvány definiál néhány lehetséges opciót, de a fordítóra bízza, hogy az melyiket választja, akkor __nem specifikált__ viselkedésről beszélünk. A nem specifikált viselkedés csak akkor probléma, ha a program végeredményét befolyásolhatja a fordtó választása.

```cpp
int main()
{
  int i = 0;
  int j = 0;
  std::cout << ++i << j++ << std::endl; // 11
}
```

Bár azt továbbra se tudjuk, hogy a ```++i``` vagy a ```++j``` értékelődik ki előbb (_nem specifikált_), azt biztosan tudjuk, hogy 11-et fog kiírni (a program végeredménye _jól definiált_).


### Implementáció által definiált viselkedés

A szabvány nem köti meg, hogy egy ```int``` egy adott platformon mennyi bájtból álljon. Ez állandó, egy adott platformon egy adott fordító mindig ugyanakkorát hoz létre, de platform/fordító váltás esetén ez változhat. Ennek az az oka, hogy különböző platformokon különböző választás eredményez hatékony programokat. Ennek köszönhetően hatékony kódot tud generálni a fordító, viszont a fejlesztő dolga, hogy megbizonyosodjon róla, hogy az adott platformon a primitív típúsok méretei megfelelnek a program által elvárt követelményeknek.


# Első C++ program

Ezen információk tudatában megnézhetjük az első C++ programunkat. Tekintsük az alábbi kódot. A forrásfájl neve legyen ```main.cpp```:

```cpp
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) 
{ 
  cout << "Hello World!" << endl;
  return 0;
}
```

A _main.cpp_ meghatároz egy __fordítási egységet__ (_compilation unit_). A fordítás folyamata során fordítási egységeket fordítunk gépi kódra. Egy fordítási egységben az a kód található, amelyhez a fordító a fordítás során hozzáfér.

A kód legfelső sorában található az ```#include <iostream>```. A kettős kereszttel (```#```) jelzett sorok az __előfordítónak__ (_precompiler_) szóló utasítások. Ezek a már korábban említett  preprocesszor direktívák. Az ```include``` utasítás behelyettesíti a hívás helyére a megadott fájl tartalmát. Ez a helyettesítés __fordítási időben__ történik. 

Az ```iostream``` fejállomány (_header file_ vagy egyszerűen csak _header_) tartalmazza a megfelelő I/O (Input/Output) utasításokat a kiíratáshoz. Ez maga is ugyanúgy C++ kódot tartalmaz, melyet mi magunk is írunk. Két különböző elérési útvonallal tudjuk megadni az include-okat:

* ```#include <...> // előre bekonfigurált útvonalban keresi a fájlt```
* ```#include "..." // az útvonal relatív az aktuális fájlokhoz képest```


## Mik az előnyei az ```iostream```-nek a ```cstdio```-val szemben C++-ban?

Típusbiztonságot növel, csökkenti a hiba lehetőségek számát, lehetővé teszi a bővíthetőséget és az örökölhetőséget. A ```printf()``` vitathatatlanul jól működik és a ```scanf()``` is működik annak ellenére, hogy nem túl nagy a hibatűrő képessége. Mindazon által mindkettő korlátozzott a C++ I/O-val szemben. Ha szeretnénk összehasonlítani a C++ I/O ```<<``` és ```>>``` operátorai nagyjából megfelelnek a C ```printf()``` és ```scanf()``` függvényeinek. Azonban több előnyük is van ezekkel a függvényekkel szemben:

* __Típus biztosabb__: az ```<iostream>``` esetén az objektumok típusai fordítási időben ismertek a fordító számára. Ezzel szemben az ```<cstdio>``` ```%``` mezőket használ a típusok dinamikus meghatározásához.
* __Kevesebb hibalehetőség__: az ```<iostream>``` használatakor nincsenek redundáns ```%``` tokenek, amelyeknek konzisztensnek kell lenniük az I/O-zni kívánt objektumokkal. Ezen redundancia eltávolítása a hibák eltávolítását is jelenti.
* __Bővíthető__: a C++ ```<iostream>``` lehetővé teszi az új, felhasználó által definiált típusok I/O-zását, anélkül, hogy bármi problémát okozna a már meglévő kódban.
* __Örököltethető__: A C++ ```<iostream>``` mechanizmus olyan valós osztályokból épül fel, mint az ```std::ostream``` vagy az ```std::istream```. A ```<cstdio> FILE*```-al ellentétben ezek valódi osztályok, ezért örököltethetőek. Ez azt jelenti, hogy más felhasználók által definiált dolgok is viselkedhetnek __stream__-ként. Automatikusan használhatjuk a rengeteg soros I/O kódot, amelyet más felhasználók írtak, akik nem is tudják és nem is kell tudniuk a saját magunk által kiterjesztett __stream__ osztályról.


## Kiírás és beolvasás, C vs C++

C-ben a kiírásra és beolvasásra elsősorban a ```printf()``` és ```scanf()``` függvényeket használjuk. Ezkellel két fő probléma lehet:

* nincs típus ellenőrzés
* nem tudjuk megtanítani, hogyan kell a felhasználók által definiált típusokat kiírni illetve beolvasni.

A ```scanf()``` használatánál arra is oda kell figyelni, hogy cím szerint kell kapnia a változókat, könnyű a ```&``` karaktert lefelejteni, vagy olyankor is kitenni, amikor nincs rá szükség, pl. ```string```-eknél.

```c
#include <stdio.h>

int main()
{
  int a;
  scanf("%s", a);
}
```

Ilyenkor a fordító nem ellenőrzi a paraméterek típusát, így lefordul a kód, pedig nyilvánvalóan helytelen. A ```scanf()``` ```string```-et fog beolvasni, ```char*``` paramétert vár és ```int*```-ot fog kapni egyetlen ```int```-nyi hellyel. Hosszabb ```string```-nél a kapott helyet túlírja és a következő memóriaterület sérül, vagy összeomlik a program. Az újabb fordítók erre már figyelmeztetést adnak.

Mindkét problémára megoldást nyújt a C++ megoldása. Kiíratásra az ```std::cout``` (C-ben az ```stdout```), beolvasásra az ```std::cin``` (C-ben az ```stdin```), míg hiba kezelésére a C-s ```stderr```-hez hasonlóan az ```std::cerr``` való. Használatukhoz az ```iostream``` header szükséges. Sor vége karakter kiírható akár az ```std::endl``` használatával is (kicsit bővebben az ```std::endl``` és a ```\n```-ről később).

Az ```std::cin``` a ```scanf()```-től eltérően képes referencia szerint átvenni a változókat, így nincs probléma a címképzéssel. Az ```std::cin```, ```std::cout``` és minden azonos típusú objektum automatikusan tud konvertálódni igaz vagy hamis logikai értékekre, attól függően, hogy volt-e hiba.

Mindezek az előnyök eltörpülnek amellett, hogy az ```std::cin``` és az ```std::cout``` megtanítható arra, hogyan kezelje a felhasználók által definiált típusokat.


## Névterek

A ```using namespace std;``` segítségével a standard névtér globális használatát tesszük lehetővé. Ennek hatására az ```std``` névtérben található típusok, függvények és változók oly módon is elérhetővé válnak, mintha a globális névtérben lettek volna deklarálva. A standard könyvtárban található implementációk az ```std``` névtérben találhatók. Ennek az az oka, hogy a standard könyvtár gazdag eszközkészletet biztosít, amelynek során számos gyakran használt nevet is felhasznál mint pl. ```find()```, ```max()``` stb. Ha nem az ```std``` névtérben lennének ezek a nevek, akkor bizonyos kontextusokban nem használhatnánk fel ezeket a neveket a saját programunkban. Éppen ezért gyakran kihagyjuk ezt a sort a programunkból. A standard könyvtárbeli elemekre minősített nevek megadásával hivatkozhatunk:

```cpp
#include <iostream>

int main(int argc, const char* argv[])
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
```

__FONTOS__: a ```using namespace ...;``` SOHA nem kerülhet header állományba. Ezzel ugyanis a header állomány összes felhasználójánál potenciálisan nevütközéseket okozunk. Fentebb explicit módon jeleztük a fordítónak, hogy az ```std``` névtérben keresse a ```cout``` és az ```endl``` változókat. 
 

### Névtelen névtér (_unnamed namespace_) 

Létezik úgynevezett __névtelen névtér__ (_unnamed namespace_), amit arra használhatunk, hogy ne szemeteljük tele a globális névteret, ezáltal megvédjük magunkat a többértelműségtől.
A modul szintű hatókörben a névtelen névterekben hozhatunk létre olyan változókat és függvényeket, amelyek a fordítási egységen kívül nem érhetőek el. Azonban a modulon belül minden korlátozás nélkül felhasználhatók a __hatókör operátor__ (_scope operátor_) ```::``` segítségével.

```cpp
namespace 
{
  int i = 0;
}

int main(int argc, const char* argv[])
{
  int i = ::i; // hivatkozunk a névtelen névtérben lévő i változóra
  return 0;
}
```


### Egymásba ágyazott névterek (_nested namespaces_)

A programozónak lehetősége van arra, hogy a névtrekben újabb névtereket hozzon létre, vagyis egymásba ágyazza őket. Ezzel a megoldással a globális neveket is strukturált rendszerbe tudjuk szervezni.

```cpp
namespace A
{
  namespace B
  {
    int i = 0;
  }
}
```

Ebben az esetben az ```i``` változót a következő módon tudjuk elérni: ```A::B::i```. C++17 óta lehetőség van egymásba ágyazott névtereket egy rövidebb formában írni:

```cpp
A::B { int i = 0; }
```

A két kódrészlet funkcionalitásban teljesen megegyezik.


## A ```main()``` függvény

Ez a program __belépési pontja__ (_entry point_). Minden C++ nyelven írt programnak tartalmazni kell __PONTOSAN__ egyet. Ez az egyetlen olyan függvény, amit nem lehet túlterhelni. Paraméterei küzöl az ```argc``` a parancssori paraméterek számát adja meg, míg az ```argv[]``` egy nullpointerrel terminált, karaktermutatókat tartalmazó tömb, amelyben a parancssori paraméterek vannak C-stílusú string-ként. A C++-ban a tömböket 0-tól indexeljük, így az ```argv[]``` nulladik eleme a futtatható állomány neve, első eleme pedig az első paraméter.

```./program first second (vagy program.exe first second)```

```argv[0] == "program"```

```argv[1] == "first"```

```argv[2] == "second"```

A két kapcsos zárójel (```{ }```) közti részt blokknak nevezzük. A ```cout``` a C++ standard kimenete. Az ```endl``` pedig beilleszt egy newline karaktert a kiírandó sor végére. Felmerülhet a kérdés, hogy mi a különbség az ```endl``` és a ```\n``` között? Nos,

* a ```\n``` csak egy string aminek a hossza egy és ez adódik hozzá azt ```std::out```-hoz.
* az ```std::endl``` ezzel szemben egy objektum, ami a newline karakter hozzáadásához vezet ÉS ezek után flush-olja az ```std::out``` buffert. Ezért ez több számítással jár. Az ```std::endl``` meghívja az ```os.put(os.widen('\n'))``` függvényt, majd ezt követően az ```os.flush()``` függvényt.

A ```return``` kulcsszó visszaadja a vezérlést az őt hívó függvénynek, jelen esetben ez a program befejezését jelenti, ezért az operációs rendszernek. A ```return``` mögé írt szám visszatérési értéke 0. Ez általában azt jelenti, hogy a program rendben lefutott. A ```main()```-ben ez nem kötelező, ha elhagyjuk, akkor automatikusan 0-t ad vissza, továbbá nem muszáj kiírni az ```int argc, const char* argv[]``` bemeneti paramétereket sem. A fordító ezeket automatikusan legenerálja. Ezért a következő program ekvivalens az előzőkkel:

```cpp
#include <iostream>

int main() { std::cout << "Hello World!" << std::endl; }
```

A __bitshift left__ operátor (```<<```) alternatív szintaxissal is meghívható:

```cpp
#include <iostream>

int main() { operator<<(std::cout, "Hello World!"); }
```

Ebből is látható hogy az operátorok tulajdonképpen függvények, tehát a szintaxisuktól eltekintve ugyanazon nyelvi szabályok fognak vonatkozni rájuk, mint a többi függvényre.

__Függvény deklarációnak__ nevezzük, amikor a függvény használatáról adunk információt. Ennek része a paraméterek típusa, visszatérési érték típusa és a függvény neve.

__Függvény definíciónak__ nevezzük azt, amikor leírjuk a függvény törzsét is, ezzel meghatározva, hogy mit csináljon. Ez egyben deklaráció is, hiszen a paraméterekről és visszatérési értékről is tartalmazza a szükséges információt.

Egy függvényhez több deklaráció is tartozhat, ha nem mondanak egymásnak ellent.

```cpp
int foo(); // deklaráció

int foo() // deklaráció és definíció
{
  std::cout << "Hello World!" << std::endl;
}
```


## Globális változók

Tényleg igaz, hogy a program futása a ```main()``` függvény végrehajtásával kezdődik?

```cpp
#include <iostream>

std::ostream& os = std::cout << "Hello";

int main() { std::cout << " world!" << std::endl; }
```

> Kimenet: "Hello world!"

A program végrehajtásánál az első lépés az úgynevezett __globális változók__ inicializálása. Ennek az oka az, hogy a globális változók olyan objektumok, melyekre a program bármely pontján hivatkozni lehet. Ebből kifolyólag, ha ```os```-t szeretnénk használni a ```main()``` függvény első sorában, akkor ezt meg lehessen tenni. Az inicializálatlan változó használata nem definiált viselkedés, ezért fontos már a ```main()``` előtt inicializálni a globális változókat.


### Globális változók definíciója és deklarációja

Globális változókat úgy tudunk létrehozni, hogy közvetlenül egy névtéren belül definiáljuk őket.

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

Egy globális változó deklarációja hasonlít a függvényekéhez. Információval látja el a fordítót arról, hogy az adott szimbólum egy globális változó, és milyen a típusa.

__Megjegyzés__: a globális változók deklarációit érdemes külön header fájlba gyűjteni.


### Globális változók inicilizációja

Amennyiben egy globális ```int```-et hozunk létre és nem adunk neki kezdőértéket, annak értéke nem definiált lesz (memóriaszemét).

```cpp
int x;
int main() { std::cout << i << std::endl; } // 0
```

Az eredmény azonban mindig 0 lesz. Ennek az oka az, hogy a globális változók mindig 0-ra inicilaizálódnak (legalábbis az ```int```-ek). A globális változókat csak egyszer hozzuk létre a program futásakor, így érdemes jól definiált kezdőértéket adni neki. A stacken rengetegszer létre kell hozni változókat, nem csak egyszer, így ott nem éri meg minden alkalommal egy jól definiált kezdőértékkel inicializálni. Sokkal nagyobb lenne a hatása a futási időre.

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
fordítási egységekből keletkező tárgykódot, más eredményt kapunk.

```clang++ main.cpp other.cpp ≠ clang++ other.cpp main.cpp```

__Megjegyzés__: ez a példa nem számít jó kódnak, mert nem specifikált viselkedése van a programnak, kimenete nem definiált. Ez egy jó elrettentő példa, miért nem érdemes globális változókat használni. Ezen kívül számos egyéb problémát is felvetnek a globális változók: átláthatatlanabb kód, mivel bárhol hozzá lehet férni nem lehetünk biztosak benne, hogy az érték, amit kiolvasunk valaki más nem módosította-e előttünk.


# Hatókör, láthatóság, élettartam

__Hatókör__: Deklarációkor a programozó összekapcsol egy entitást (pl. egy változót vagy egy függvényt) egy névvel. A hatókör alatt a forrásszöveg azt a részét értjük, amíg ez az összekapcsolás érvényben van. Ez általában annak a blokknak a végéig tart, amely tartalmazza az adott deklarációt

__Láthatóság__: a hatókör részhalmaza, a programszöveg azon része, ahol a deklarált névhet a megadott entitás tartozik. Mivel az egymásba ágyazott blokkokban egy korábban már bevezetett nevet más entitáshoz kapcsolhatunk, ezért ilyenkor a külső blokkban deklarált entitás a nevével már nem elérhető. Ezt nevezzük a láthatóság elfedésének.


## Automatikus, statikus és dinamikus élettartam

__Automatikus élettartam__: a blokkokban deklarált lokális változók automatikus élettartamúak, ami azt jelenti, hogy a deklarációtól a tartalmazó blokk végéig tart az élettartamuk, ami jelen esetben  egybeesik a hatókörrel. A helyfoglalás számukra a végrehajtási verem aktuális aktivációs rekordjában történik meg.

__Statikus élettartam__: a globális változók, illetve egyes nyelvekben a __statikusként__ deklarált változók statikus élettartamúak. Az ilyen változók élettartama a program teljes végrehajtási idejére kiterjed, számukra a helyfoglalás már a fordítási időben megtörténhet.

__Dinamikus élettartam__: a dinamikus élettartamú változók esetén a programozó foglal helyet számukra a dinamikus tárterületen (_heap_, bővebben a heapről a későbbiekben lesz szó), és a programozó feladata gondoskodni árról is, hogy ezt a tárterületet később felszabadítsa. Amennyiben ez utóbbiról megfeledkezik, azt nevezzük __memória szivárgásnak__ (_memory leak_). A dinamikus élettartam esetén a hatókör semmilyen módon nem kapcsolódik össze az élettartammal, az élettartam szűkebb vagy tágabb is lehet a hatókörnél.

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

A ```main()``` elején létrehozott ```x``` az utána következő blokkban teljesen elérhetetlen - nincs olyan szabványos nyelvi eszköz, amivel tudnánk rá hivatkozni. Ezt a folyamatot nevezzük __leárnyékolásnak__ (_shadowing_). Azonban a külső globális ```x```-re bármikor tudunk hivatkozni a már korábban említett scope operátor (```::```) segítségével.

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

Tekintsük a következő programot:

```cpp
#include <iostream>

int x = 1;

namespace
{
  int x = 2;
}

int main() 
{
  std::cout << ::x << std::endl;
}
```

> kimenet: 2

Ilyen esetekben, ha azonos nevű változó szerepel a globális névtérben és egy névtelen névtérben a scope operátor __mindig__ a névtelen névtérbeli változóra fog hivatkozni.


## Jobb- és balérték

A láthatóság és élettartam fogalmával szoros összeköttetésben áll a __jobb- és balérték__ fogalma. Egy objektumot __balérték__-nek (_left value_, röviden _lvalue_) nevezzük, ha van a címképző operátorral (```&```) le tudjuk kérni a memóriabeli címét, és __jobbérték__-nek (_right value_, röviden _rvalue_) ha nem. A jobbértékek többnyire ideiglenes objektumok, mint pl. az érték szerint visszatérő függvény visszatérési értéke és a literálok. Lévén ezek az objektumok csak ideiglenesen szerepelnek a memóriában ezért hiba lenne a memóriacímükre hivatkozni, így a fordító nem is engedi. Példaképp:

```cpp
int main()
{
  int* p, r;
  &p; // ok, p mutató memóriacímét tartalmazza
  &r; // ok, r memóriacímét tartalmazza
  &1; // nem ok, 1 jobbérték
  &"Hello"; //nem ok, a "Hello" jobbérték
  5 = r; // nem ok, jobbértéknek nem lehet értéket adni
}
```


# A C++ memóriamodellje

A C++ szabvány több memóriatípust különít el. Mégpedig:

* __stack__
* __globális/statikus__
* __heap/free store__


## Stack

A __stacken__ létrehozott változókat szokás __automatikus változóknak__ (_automatic variable_) is hívni. A stacken létrehozott változók kezelése nagyon kényelmes, mert jól látható, mikor jönnek létre, illetve mikor semmisülnek meg. Ez az alapértelmezett tárolási osztály lokális változók esetén. Az itt létrehozott változók élettartama a definíciójuktól az adott blokk végéig tart. 

```cpp
#include <iostream>

int main()
{
  int x = 0; // x létrejön
  {
    int y = 1; // y létrejön
  } // y megsemmisül
} // x megsemmisül
```

__Megjegyzés__: A stacken létrehozott változók elérése gyorsabb, mint a heapen létrehozottaké. A stack egy __FILO__ (_first in last out_) adatszerkezet, ami annyit jelent, hogy amit először raktunk bele azt fogjuk utoljára kivenni.


## Globális / statikus tárhely

Tekintsük az alábbi kódot:

```cpp
void foo()
{
  static int x = 0;
  ++x;
  std::cout << x << std::endl;
}

int main()
{
  for (int i = 0; i < 5; ++i)
  {
    foo();
  }
}
```

> Kimenet: 1 2 3 4 5

Ebben az esetben a függvény első hívásától a program futásának végéig benne marad a memóriában az ```x``` változó, így egyre nagyobb számot ad majd vissza a ```foo()``` függvény hívása. Az ```x``` inicializációja egyszer történik meg, a függvény első hívásakor.

__Megjegyzés__: a __statikus__ változók használata - akárcsak a globálisoké - kerülendő.

A globális változók és a statikus változók a memória ugyanazon területein jönnek létre. Ezért hívjuk ezt a területet globáis/statikus tárhelynek.Ide tarotznak továbbá a konstansnak deklarált változók is. A program indulásakor le van foglalva számukra a tárterület.

Abban az esetben, ha azt szeretnénk, hogy ```x``` ne semmisüljön meg a blokk végén, de ne is maradjon a program futásának a végéig memóriában a programozó feladata a memória kezelése.


## Heap / free store

A __heapen__ létrehozott változókat __dinamikus változóknak__ (_dynamic variable_) is szokás nevezni. A heap segítségével nagy szabadságra tehetünk szert, de ez a szaabdság nagy felelősséggel is jár.

```cpp
int main()
{
  int* ptr = new int(0);
  delete p;
}
```

A fenti pédában láthatjuk, hogyan tudunk tárhelyet allokálni egy ```int```-nek a heapen. Fontos, hogy a stacket nem kerültük meg, mert szükségünk van egy mutatóra, amely a heapen lefoglalt memória címére mutat (```ptr```). A mutató által mutatott területet a ```delete``` operátorral tudjuk felszabadítani.

A heapen nincs a lefoglalt területeknek nevük, így mindig szükségünk lesz egy mutatóra, hogy tudjunk rá hivatkozni. __Ha egyszer lefoglalunk valamit a heapen, gondoskodni kell arról, hogy fel is szabadítsuk__. Az egyik leggyakoribb hiba a dinamukis memóriakezelésnél, ha a memóriát nem szabadítjuk fel, ilyenkor a lefoglalt memóriaterületre hivatkozni már nem tudunk, de lefoglalva marad, ezt nevezzük __memória szivárgásnak__ (_memory leak_).

Bár az operációs rendszer megpróbál minden, a program által lefoglalt memóriát felszabadítani a futás befejeztével, de nem mindenható. Előfordulhat, hogy egyes platformokon újraindításig nem szabadul fel a memória. Emelett, addig amíg a program fut, több memóriát használ fel, mint amennyire szükség van.

A dinamikusan lefoglalt memória szabályos felszabadítsát számos dolog nehezíti. Jó példa erre a kivételkezelés, melynél hamarabb megszakadhat a függvény végrehajtása, mint ahogy felszabadítaná a memóriát. Előfordulhat, hogy egy memória területet kétszer (vagy többször) szeretnénk felszabadítani, ekkor nem definiált viselkedése lesz a programunknak.

Lehetésges olyan eset, hogy egy már felszabadított memóriaterületet akarunk írni vagy onnan szeretnénk olvasni. Ilyen jellegű hibát könnyű véteni, hisz a ```delete``` a ```ptr``` által mutatott memóriaterületet, nem pedig a ```ptr```-t fogja törölni.

__Megjegyzés__: nullpointer törlésekor nem történik semmi. (nullpointer-rel bővebben a mutató fejezet foglalkozik)

Láthatjuk, hogy a heap használata hibalehetőségekkel teli, ráadásul az allokálás (memória lefoglalás)
még lassabb is, mint a stacknél. Felmerülhet a kérdés, hogy akkor miért is használjuk?
Ha meg lehet oldani, hogya stacken tudjunk tárolni valamit, tegyük azt. A stack azonban véges, hamar be tud telni (stack overflow), illetve kötött a változók élettartama. A heap-en e téren sokkal nagyobb a szabadságunk.


# A ```const``` kulcsszó

A C++ lehetőséget ad a programozó számára, hogy olyan értékeket definiáljon, amelyek a program futása során nem változtathatják meg az értéküket. Kvázi egy _read-only_ változókként tekinthetük rájuk. Konstansokat C++-ban a ```const``` kulcsszó segítségével adhatunk meg. 

__Fontos__, hogy már deklaráláskor értéket kell adnunk nekik, azaz definiálnunk is kell őket. Amennyiben ezt nem tesszük meg fordítási idejű hibát fogunk kapni.

```cpp

int main()
{
  const int i = 1; // i változó értéke nem változtatható meg.
}
```

Rossz példa:

```cpp
int main()
{
  const int i;
  i = 0; // fordítási idejű hiba
}
```

Mivel a konstansok már fodítási időben kirétékelődnek, nem köthetjük futási idejű kiértékeléshez az értéküket. Ha ezt megtehetnénk serülne a __konstans korrektség__, amely kimondja, hogy egy konstans változó értéke nem módosulhat a program végrehajtása alatt.


# Mutatók (_pointers_)

Olyan nyelvi elemek, melyek egy adott típusú memóriaterületre mutatnak. Segítségükkel anélkül is tudunk hivatkozni egy adott objektumra (nem csak a masolatára!), hogy közvetlenül az objektummal dolgoznánk.

```cpp
int main()
{
  int x = 5;
  int* xPtr = &x;
}
```

A fenti példában ```xPtr``` egy mutató, amely egy ```int``` típusra mutat. Ahhoz, hogy értéket tudjunk adni egy mutatónak, egy memóriacímet kell értékül adni, ezt a  __címképző operátor__ (```&```) segítségével tehetjük meg. Ha a mutató által _mutatott értéket_ szeretnénk módosítani, akkor dereferálnunk kell mutatót a __dereferáló operátor__ (```*```) segítségével.

```cpp
int main()
{
  int x = 7;
  int* xPtr = &x; // referájuk x-et
  *xPtr = 1; // dereferáljuk xPtr-t, majd módosítjuk a memóriaterületet, ahová mutat
             // x változó érétke ettől kezdve 1 lesz
}
```

Egy mutató mutathat változóra, másik mutatóra, vagy sehova. Azokat a mutatókat amelyek sehova nem mutatnak __null pointernek__ nevezzük. Következő képpen hozhatjuk létre őket:

```*ptr = 0; *ptr = NULL; *ptr = nullptr;```

__Megjegyzés__: a ```nullptr``` kulcsszót csak a C++11-es szabvány vezette be, így az előtte lévő fordítók (C++98, C++03) nem ismerik fel ezt az operátort. Bevezetésének oka nagyon egyszerű. A ```0``` vagy a ```NULL``` típusok egész számmá konvertálódnak ez ```NULL``` esetén egy 0 lesz. Tekintsük a következő kódrészletet:

```cpp
#include <iostream>

void f(char* b) { std::cout << "char" << std::endl; }

void f(bool i) { std::cout << "bool" << std::endl; }

int main()
{
    f(NULL);
}
```

> Kimenet: _error: call of overloaded ‘f(NULL)’ is ambiguous_. Fordítási idejű hiba.

```cpp
#include <iostream>

void f(char* b) { std::cout << "char" << std::endl; }

void f(bool i) { std::cout << "bool" << std::endl; }

int main()
{
    f(nullptr);
}
```

> Kimenet: "char".

```nullptr``` esetén explicit megtudja határozni a fordító, hogy azt a függvényt kell meghívni amely bemenetként egy mutató típust vár.


## Mutatóra mutató mutató

```cpp
int main()
{
  int i = 1;
  int* iPtr = &i;
  int** piPtr = &iPtr; // mutatóra mutató mutató
}
```

Példaképp ```q```-n keresztül meg tudjuk változni, hogy ```p``` hova mutasson.

```cpp
int main()
{
  int i, j;
  int* p = &i;
  int** q = &p;
  *q = &j;
}
```

```cpp
int main()
{
  int i, j;
  int* p = &i;
  int* const * q = &p;
  *q = &j; // forditási hiba
}
```

Mivel ```q``` egy ```int```-re mutató konstans mutatóra mutató mutató, így csak egy olyan mutatóval tudunk rámutatni, ami egy ```int```-re mutató konstans mutatóra mutató mutatóra mutató konstans mutató.

```cpp
int main()
{
  int i, j;
  int* p = &i;
  int* const* q = &p;
  int* const **const r = &q;
}
```


# Referenciák

A referencia egy létező objektum alternatív neve. Definiálásakor meg kell adni azt az objektumot is, amelyet alternatív névvel látunk el. A referencia nem egy változó, mint a mutató, hanem csak egy azonosító, ezért nem is változtatható meg, amíg a referencia létezik mindig ugyan oda referál. Már létrehozásakor értéket kell adnunk neki, ami a program futása során nem változhat. Két leggyakoribb felhasználása:

* függvény bemeneti paraméter
* függvény visszatérési érték

Mindkét esetben lehet konstans és nem konstans.

```cpp
int main()
{
  int i = 1;
  int& rI = i; // rI változó egy alias az i változóra
}
```


# Konstans korrektrség (_const-correctness_)

A konstans korrektség egy szabály a C++ nyelvben: ha egy értéket konstansnak jelölünk, azt nem módosíthatjuk a program futása során.

```cpp
int main()
{
 const int i = 1;
 int* iPtr = &i;
}
```

A fenti kód fordítási idejű hibát fog adni. Miért lehet ez? A válasz az, hogy mivel ```i``` változót konstansnak deklaráltuk viszont ```iPtr``` nem egy konstansra mutató mutató, azaz ha ```iPtr```-el hozzáférnénk ```i``` memóriacíméhez, akkor a mutatón keresztül módosítani tudnánk a mutatott értéket (ami jelen esetben konstans), ergo sérülne a konstans korreketésg.

Megoldás: deklaráljuk ```iPtr``` mutatót, hogy konstans értékre mutasson:

```cpp
int main()
{
  const int i = 1;
  const int* iPtr = &i;
}
```

```iPtr``` ettól kezdve egy konstanra mutató mutató, így már lehetőségünk van, hogy rámutassunk vele konstans adattagokra is. Konstanra mutató mutatón keresztül bár elérjük a mutatott értéket, de megváltoztatni nem tudjuk.

Annak függvényében, hogy a ```*``` jobb vagy bal oldalán használjuk a ```const``` kulcsszót megkülönböztetünk __konstans__ mutatót, illetve __konstansra__ mutató mutatót. 


## Konstansra mutató mutató

Abban az esetben, ha a ```*``` bal oldalán van a ```const``` kulcszsó, akkor __konstansra mutató mutatóról__ beszélünk. Ekkor a mutatón keresztül nem tudjuk módosítani a mutatott értéket, viszont a mutatót magát át tudjuk állítani, hogy egy másik memóriacímre mutasson. Deklarálásakor nem kell kezdőértéket adnunk neki, ilyenkor a fordító automatikusan ```nullptr``` étéket fog adni neki.

```cpp
int main()
{
  // a két változat ugyan azt a viselkedést produkálja, a fordító nem tesz különbséget
  // aközött, hogy az int*-ot vagy a const kulcsszót írjuk ki előbb
  const int* i = nullptr;
  int* const ii = nullptr;
}
```

Konstansra mutató mutatóval rátudunk mutatni konstans, illetve nem konstans adattagra is. Egy konstansra mutató mutató nem azt jelenti, hogy a mutatott érték sosem változhat meg. Csupán annyit jelent, hogy a mutatott értéket ezen a mutatón keresztül nem lehet megváltoztatni.


## Konstans mutató

Konstans mutatóról abban az esetben beszélünk, amikor a ```const``` kulcsszó a ```*``` karakter jobb oldalán van. Ilyenkor tudjuk módosítani a mutatott értéket a mutatón keresztül, viszont nem tudjuk át állítani a mutatót egy másik memóriacímre. 

__Fontos__: már deklaráláskor meg kell adnunk a memóriacímet, amire szeretnénk vele mutatni és ez a program futása során nem módosulhat. Magyarán mondva, ahova inicializáljuk csak oda fog mutatni.

```cpp
int main()
{
  int i = 1;
  int* const cPtrI = &i;
}
```


## Konstansra mutató konstans mutató

Fennállhat olyan helyzet is, amikor egy mutató lehet egy konstansra mutató konstans mutató is, amin keresztül nem lehet megváltoztatni a mutatott értéket és a mutatót sem lehet máshova átállítani.

```cpp
int main()
{
  int i = 1;
  const int* const ccPtrI= &i;
}
```


# Tömbök (arrays)

A tömb a C++ egy beépített adatszerkezete, mellyel több azonos típusú elemet tárolhatunk és kezelhetünk egységesen. 

__Fontos__: a tömbök sorfolytonosan helyezkednek el a memóriában.

```cpp
int main()
{
  int array[] = {1,2,3,4,5};
}
```

Ebben az esetben, ha nem adjuk meg expliciten a ```[]``` operátorok között a tömb méretét a fordító ki fogja következtetni a példányosításból. Az ```array``` egy 5 elemű tömb. Nézzük meg mekkora a mérete bájtokban.

__Figyelem__: ez implementáció függő!

```cpp
int main()
{
  std::cout << sizeof(array) << std::endl;
  std::cout << sizeof(int) << std::endl;
}
```

Mivel az ```array```-ben egész számokat tárolunk - egészen pontosan 5 darabot - láthatjuk, hogy az ```array``` mérete pontosan az ötszöröse az ```int```-nek ezért mondhatjuk, hogy a tömbök tiszta adatok.

Próbáljuk meg kiíratni a tömb 6. elemét. Ehhez használjuk az __indexelő operátort__ (```[]```). A tömb elemeinek elérésével bővebben a következő fejezet foglalkozik.

__Megjegyzés__: ez konstans idejű (```O(1)```) elem elérést tesz lehetővé.

```cpp
int main()
{
  std::cout << array[6] << std::endl;
}
```

Szemmel látható, hogy túl fogunk indexelni, ez pedig nem definiált viselkedéshez vezet. Várhatóan memóriaszemetet fogunk kiolvasni az utolsó elem helyett, de ezt nem tudhatjuk pontosan. Fordítási időben ezt a hibát nem veszi észre a fordító. Mivel több memóriához nyúlunk hozzá, mint amihez kellene, nagyobb az esély arra, hogy futási idejű hibába ütközzünk. A programunk ilyen esetekben __szegmentálási hibával__ (_segmentation fault_) állhat le. Ezen hibák elkerülése érdekében használhatunk __sanitizereket__. Ezek létrehoznak ellenőrzéseket, amik azelőtt észrevesznek bizonyos nem definiált viselkedéseket, mielőtt azok megtörténnének.

>$ clang++ main.cpp -fsanitize=address

A sanitizerek csak abban az esetben találnak meg egy hibát, ha a probléma előfordul (azaz futási időben, nem fordítási időben ellenőriz).
