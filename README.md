<img src="img/cppIcon.png" alt="cpp icon" width="200">


__"C makes it easy to shoot yourself in the foot; <br>
C++ makes it harder, but when you do it, it blows your whole leg off."__

~ _Bjarne Stroustrup_ ~


## Bevezetés


A __C++__ egy általános célú, magas szintű programozási nyelv. Gyakori tévhit, hogy alacsony szintű (hardver közeli). Noha lehetőséget biztosít arra, hogy alacsony szinten programozzunk, számos absztrakciós lehetőséget tartalmaz. Támogatja a __procedurális__, __objektumorientált__ és a __generikus programozást__ valamint az __adatabsztrakciót__. Legtöbb nyelvhez képest abban emelkedik ki, hogy az itt megvalósított absztrakcióknak ritkán van futási idejű költsége.

__Érdekesség__: [Andrei Alexandrescu](https://en.wikipedia.org/wiki/Andrei_Alexandrescu) azt nyilatkozta, hogy amikor a Facebook-nak a back-end kódján 1%-ot sikerült optimalizálnia, több mint 10 évnyi fizetését spórolta meg a cégnek havonta csak az áramköltségen.

A C++ nyelv fejlesztését még a '80-as években [Bjarne Stroustrup](https://hu.wikipedia.org/wiki/Bjarne_Stroustrup) kezdte el a C programozási nyelv kiterjesztéseként, más nyelvekből véve át megoldásokat. Az első hivatalos szabványa a nyelvnek 1998-ban jelent meg. Alapvetően a nyelv két összetevőből áll. Az aktuális szabványból és annak implementációjából. A szabvány az, ami meghatározza a nyelv nyelvtanját, valamint a szemantikáját (mit jelentenek a leforduló programok).

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
* __Származtatott__: a primitív vagy beépített adattípusokból származó adattípusokat származtatott adattípusoknak nevezzük. Ezek négyféle lehetnek, nevezetesen:
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

A fordítás a __preprocesszor__ parancsok végrehajtásával kezdődik, mint például a __header__ fájlok beillesztése a ```.cpp``` fájlokba, az így kapott fájlokat hívjuk __fordítási egységeknek__ (_translation unit_). A fordítási egységek külön-külön fordulnak __tárgykóddá__ (_object file_). Ezekben a gépi utasítások már megvannak, de hiányoznak belőle a hivatkozások, például változók vagy függvények, melyek más fájlokban vannak megvalósítva. Ahhoz, hogy a tárgykódból __futtatható állományt__ (_executable file_) lehessen készíteni, össze kell linkelni őket. A __szerkesztő__ (_linker_) feladata, hogy kitöltse a tárgykódban hiányzó referenciákat. A linkelés lehet __statikus__, amikor a fordító tölti fel a hiányzó referenciákat, vagy __dinamikus__, amikor futási időben, jellemzően egy másik fájlból (pl: .dll) tölti be a hiányzó kódot. Utóbbi akkor praktikus, ha egy modult több, különálló program használ.

![compilation](img/compilation.png)


### Preprocesszálás


Az __előfeldolgozó__ (_preprocesszor_) használata a legtöbb esetben kerülendő. Ez alól kivételek a __header__ állományok ```include```-olása. A preprocesszor primitív szabályok alapján dolgozik és __nyelvfüggetlen__. Mivel semmit nem tud a C++-ról, ezért sokszor meglepő viselkedést okoz a használata a fejlesztő számára. Emiatt nem egyszerű meghatározni az általa okozott hibákat. Továbbá az automatikus refaktoráló eszközök használatát is megnehezíti a túlzott használatuk.

A következőkben nézzünk meg pár preprocesszor direktívát. Minden direktíva ```#``` jellel kezdődik.

```cpp
#define NUMBER 5

// a #define NUMBER 5 parancs azt jelenti,
// hogy minden NUMBER szót ki kell cserélni a fájlban 5-re.

#ifdef NUMBER
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

Látható, hogy a preprocesszort kódrészletek kivágására is lehet használni. Felmerülhet a kérdés, hogy ha az eredeti forrásszövegből a preprocesszor kivág, illetve beilleszt részleteket, akkor a fordító honnan tudja, hogy a hiba jelentésekor melyik sorra jelezze a hibát? Hiszen az előfeldolgozás előtti és utáni sorszámok egymáshoz képest eltérnek. Ennek a problémának a kiküszöbölése érdekében a preprocesszor beszúr sorokat a fordító számára, amik hordozzák azt az információt, hogy a feldolgozás előtt az adott sor melyik fájl hányadik sorában volt megtalálható. 

További indok a preprocesszor direktívák kerülésére, hogy gyakran nem azt a viselkedést produkálják amire számítunk. 

Tekintsük az alábbi kódrészletet:

```cpp
#include <iostream>

#define add(x, y) ((x+y) + (x+y))

int main()
{
  int i = 1;
  int j = 2;
  std::cout << add(++i,++j);
  i = 1;
  j = 2;
  std::cout << add(++i,j++);
  i = 1;
  j = 2;
  std::cout << add(i++,j++);
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

> $ clang++ main.cpp

> $ clang++ symbol.cpp

__Megjegyzés__: ```clang++``` helyett használhatjuk a ```g++```-t is, ami nem összekeverendő a ```gcc```-vel, ami __C__ fájlok fordítására alkalmas.

Fordítási hibát fogunk kapni, hiszen vagy csak a ```main.cpp```-ből létrejövő fordítási egységet, vagy a ```symbol.cpp```-ből létrejövő fordítási egységet fogja látni a fordító, egyszerre a kettőt nem. Megoldás az, ha __forward deklarálunk__, azaz ```void symbol();```-t beillesztjün a ```main()``` függvény elé, mely jelzi a fordítónak, hogy a ```symbol()``` az egy függvény, visszatérési értékének a típusa ```void``` (azaz nem ad vissza semmit) és nincs paramétere.

```cpp
// symbol.cpp
void symbol() {}

// main.cpp
void symbol(); // forward deklaráció

int main() { symbol(); }
```


#### Forward deklaráció


Elődeklarálunk egy függvényt, amihez csak a program egy kesőbbi pontján fogunk működést definiálni.

A fodítás során a linkelés fázisánál kapunk hibát, mert a linker nem fogja megtalálni a ```void symbol()``` függvény definícióját. Ezt úgy tudjuk megoldani, ha a ```main.cpp```-ből és a ```symbol.cpp```-ből először tárgykódot készítünk, majd később összelinkeljük őket. Ekkor a  ```main.cpp```-ben lesz egy hivatkozás a ```void symbol();``` függvényre, és a ```symbol.cpp``` fogja tartalmazni a függvény definícióját.

> $ clang++ -c main.cpp

> $ clang++ -c symbol.cpp

A ```-c``` (compile) kapcsoló segítségével jelezzük a fordító számára, hogy még ne linkeljek csak a tárgykódot állítsa elő. Majd a 

> $ clang++ main.o symbol.o

parancs segítségével az eredményül kapott tárgykódot tudjuk össze linkelni.

Rövidebb, ha egyből a ```.cpp``` fájlokat adjuk meg a fordítónak.

> $ clang++ main.cpp symbol.cpp

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

A C++-ban nem meghatározott, hogy két szekvenciapont között mi a kifejezések és részkifejezések kiértékelésének a sorrendje. Az adatfüggőségek azonban definiálnak egy sorrendet.

```cpp
int main() { std::cout << f(); }
```

Bár a fenti kódban csak az ```f()``` meghívása után található szekvenciapont, a függvény eredményének a kiírása előtt ki kell számolni az eredményét, különben nem tudnánk, hogy mit írjunk ki. Tehát a fenti kódban garantált, hogy az ```f()``` az eredmény kiírása előtt fog lefutni.

Az, hogy két részkifejezés szekvenciaponttal történő elválasztása nélkül ugyanazt a memóriaterületet módosítja, __nem definiált__ viselkedést eredményez. Ilyenkor a fordító vagy a futó program bármit csinálhat. A szabvány semmiféle megkötést nem tesz. 

__Megjegyzés__: az a program, amely nem definiált viselkedéseket tartalmaz, __HIBÁS__.


### Nem specifikált viselkedés


Amennyiben a szabvány definiál néhány lehetséges opciót, de a fordítóra bízza, hogy az melyiket választja, akkor __nem specifikált__ viselkedésről beszélünk. A nem specifikált viselkedés csak akkor probléma, ha a program végeredményét befolyásolhatja a forídtó választása.

```cpp
int main()
{
  int i = 0;
  int j = 0;
  std::cout << ++i << ++j << std::endl;
}
```

> kimenet: 11

Bár azt továbbra se tudjuk, hogy a ```++i``` vagy a ```++j``` értékelődik ki előbb (_nem specifikált_), azt biztosan tudjuk, hogy 11-et fog kiírni (a program végeredménye _jól definiált_).


### Implementáció által definiált viselkedés


A szabvány nem köti meg, hogy egy ```int``` egy adott platformon mennyi bájtból álljon. Ez állandó, egy adott platformon egy adott fordító mindig ugyanakkorát hoz létre, de platform/fordító váltás esetén ez változhat. Ennek az az oka, hogy különböző platformokon különböző választás eredményez hatékony programokat. Ennek köszönhetően hatékony kódot tud generálni a fordító, viszont a fejlesztő dolga, hogy megbizonyosodjon róla, hogy az adott platformon a primitív típusok méretei megfelelnek a program által elvárt követelményeknek.


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

* __Típus biztosabb__: az ```<iostream>``` esetén az objektumok típusai fordítási időben ismertek a fordító számára. Ezzel szemben a ```<cstdio>``` ```%``` mezőket használ a típusok dinamikus meghatározásához.
* __Kevesebb hibalehetőség__: az ```<iostream>``` használatakor nincsenek redundáns ```%``` tokenek, amelyeknek konzisztensnek kell lenniük az I/O-zni kívánt objektumokkal. Ezen redundancia eltávolítása a hibák eltávolítását is jelenti.
* __Bővíthető__: a C++ ```<iostream>``` lehetővé teszi az új, felhasználó által definiált típusok I/O-zását, anélkül, hogy bármi problémát okozna a már meglévő kódban.
* __Örököltethető__: A C++ ```<iostream>``` mechanizmus olyan valós osztályokból épül fel, mint az ```std::ostream``` vagy az ```std::istream```. A ```<cstdio> FILE*```-al ellentétben ezek valódi osztályok, ezért örököltethetőek. Ez azt jelenti, hogy más felhasználók által definiált dolgok is viselkedhetnek __stream__-ként. Automatikusan használhatjuk a rengeteg soros I/O kódot, amelyet más felhasználók írtak, akik nem is tudják és nem is kell tudniuk a saját magunk által kiterjesztett __stream__ osztályról.


## Kiírás és beolvasás, C vs C++


C-ben a kiírásra és beolvasásra elsősorban a ```printf()``` és ```scanf()``` függvényeket használjuk. Ezekkel két fő probléma lehet:

* nincs típus ellenőrzés
* nem tudjuk megtanítani, hogyan kell a felhasználók által definiált típusokat kiírni illetve beolvasni.

A ```scanf()``` használatánál arra is oda kell figyelni, hogy cím szerint kell kapnia a változókat, könnyű a ```&``` karaktert lefelejteni, vagy olyankor is kitenni, amikor nincs rá szükség, pl. ```string```-eknél.

```c
#include <stdio.h>

int main()
{
  int a;
  scanf("%s", &a);
}
```

Ilyenkor a fordító nem ellenőrzi a paraméterek típusát, így lefordul a kód, pedig nyilvánvalóan helytelen. A ```scanf()``` ```string```-et fog beolvasni, ```char*``` paramétert vár és ```int*```-ot fog kapni egyetlen ```int```-nyi hellyel. Hosszabb ```string```-nél a kapott helyet túlírja és a következő memóriaterület sérül, vagy összeomlik a program. Az újabb fordítók erre már figyelmeztetést adnak.

Mindkét problémára megoldást nyújt a C++ megoldása. Kiíratásra az ```std::cout``` (C-ben az ```stdout```), beolvasásra az ```std::cin``` (C-ben az ```stdin```), míg hiba kezelésére a C-s ```stderr```-hez hasonlóan az ```std::cerr``` való. Használatukhoz az ```iostream``` header szükséges. Sor vége karakter kiírható akár az ```std::endl``` használatával is (kicsit bővebben az ```std::endl``` és a ```\n```-ről később).

Az ```std::cin``` a ```scanf()```-től eltérően képes referencia szerint átvenni a változókat, így nincs probléma a címképzéssel. Az ```std::cin```, ```std::cout``` és minden azonos típusú objektum automatikusan tud konvertálódni igaz vagy hamis logikai értékekre, attól függően, hogy volt-e hiba.

Mindezek az előnyök eltörpülnek amellett, hogy az ```std::cin``` és az ```std::cout``` megtanítható arra, hogyan kezelje a felhasználók által definiált típusokat.


## Névterek


Egy függvény vagy osztály írásakor könnyen előfordulhat, hogy az általunk választott név ütközik egy meglevővel. Különösen igaz ez, ha más fejlesztők kódjával dolgozunk. A problémára a megoldást a __névterek__ (_namespace_) alkalmazása jelenti. A névterek felhasználásával különböző (függvény, osztály, típus (typedef), globális változó és konstans) definíciók névhierarchiába szervezhetők. Így nem csak a névüzközés kerülhető el, de megvalósítható a definíciók _logikai_ csoportosítása is. Ez természetesen akkor nyer létjogosultságot, ha több fejlesztő nagyobb projekten dolgozik. A névterekkel tetszőleges mélységű névtér-hierarchia alakítható ki.


### Bevezetés a névterek használatába


Tekintsük meg az alábbi névtér definíciókat:

```cpp
namespace A
{
  class MyClass {};
}

namespace B
{
  class MyClass {};
  typedef int* PInt;
}

namespace C
{
  namespace D
  {
    void sort(void* p) {}
  }
}

int main()
{
  A::MyClass mcA1;
  B::MyClass mcB2;
  // ...
  C::D::sort(data)
}
```

Névtér definíciót a ```namespace``` kulcsszóval kell kezdeni, ezt követően kell megadni a névtér nevét, majd ```{}``` között a névtérbe tartozó definíciókat.

A példában a ```MyClass``` osztály az ```A``` és a ```B``` névtérben is definiált, de ez nem okoz névütközést, hiszen a tartalmazó névtér különböző. A ```sort()``` függvény definíciója beágyazott névtér-definícióra mutat példát: a ```C``` névtér tartalmaz egy ```D``` névteret, a ```sort()``` pedig ebben definiált.

A névterekben lévő definíciók felhasználása során a ```::``` hatókör operátor (_scope operator_) felhasználásával meg kell adni a teljes "elérési utat", vagyis a definíció __minősített nevét__ (_qualified name_). Erre a ```main()``` függvényben láthatunk példát. Amennyiben egy névtérből több definíciót is kívánunk használni, körülményes minden esetben a névtér megadása. Ekkor a ```using namespace névtérnév``` direktívával a névtérben levő definíciókat az adott __deklarációs régió__-ban (_declaration region_) közvetlenül elérhetővé tehetjük. Nézzünk példát a _using namespace_ használatrára:

```cpp
using namespace B;
using namespace C::D;

int main()
{
  MyClass mc1; // B::MyClass-nak felel meg
  A::MyClass mc2;
  PInt pI; // B::PInt-nek felel meg
  // ...
  sort(data); // C::D::sort-nak felel meg
}
```

A ```using namespace``` használata nem zárja ki a minősített nevek használatát az egyértelműség vagy jobb olvashatóság érdekében. Sőt, ha a példánkban az ```A``` névteret a ```using namespace``` utasítással elérhetővé tettük volna, akkor a ```MyClass mc1;``` sor névütközéshez vezetne, mely esetben csak a minősített nevek használatával fejezhetnénk ki egyértelműen a szándékunkat.

A javasolt kódszervezést (osztálydefiníciók ```.h``` fejléc-, tagfüggvények definíciója ```.cpp``` forrásfájlokban) követve felmerül a kérdés, hogy a ```using namespace```-t a fejléc, vagy pedig a forrásfájlba tegyük. Az irányelv a következő:
__Kerüljük a ```using namespace``` fejlécfájlokban való alkalmazását__

A ```using namespace``` fejlécfájlokba való alkalmazásával a következő a probléma: soha nem tudhatjuk előre, hogy az adott fejlécfájl mely forrásfájlokba kerül utólag az ```include``` alkalmazásával. Az ```include``` által közvetve beágyazott ```using namespace``` következtében az adott forrásfájlban a névtérben lévő definíciók közvetlenül elérhetővé válnak, ami nem várt névütközésekhez vezethet.

A ```using namespace``` hatása az adott __deklarációs régió__-ra terjed ki. Globálisan alkalmazott ```using namespace``` esetén a deklaráció sorától a forrásfájl végéig, lokálisan pedig az adott függvénytörzs (_scope_) végéig terjed ki.

Ha egy névtérbe több fájlban is teszünk definíciókat, akkor a felhasználás során csak azok a névtérbeli elemek érhetőek el, amelyeket deklarálunk: ez számunkra általában azt jelenti, hogy a megfelelő definíciókat/deklarációkat tartalmazó fejlécfájlokat ```include```-olnunk kell. például:

```cpp
// sorter.h
namespace Math
{
  class Sorter { ... };
}

// finder.h
namespace Math
{
  class Finder { ... };
}

// main.cpp
#include "Sorter.h"

using namespace Math;

int main()
{
  Sorter sorter; // OK
  Finder dinder; // fordítási hiba, használatához include-olni kell
                 // a "finder.h" fejlécfájlt
}
```


### Globális hatókör elérése


Tekintsük az alábbi kódrészletet:

```cpp
class MyClass {};

namespace A
{
  class MyClass {};

  void f()
  {
    MyClass mc1; // A::MyClass
    ::MyClass mc2; // globális MyClass
  }
}
```

Az ```f()``` függvény az ```A``` névtérben található. Ennek első sorában a ```MyClass``` típushivatkozás az ```A``` névtérben lévő ```MyClass``` definíciót jelenti. A globális ```MyClass``` osztály eléréséhez a ```::``` hatókör operátort a típus neve elé kell írni:

```cpp
::MyClass mc2;
```

A hatókör operátor ebben a formában bármilyen esetben felhasználható, amikor egyértelművé kívánjuk tenni, hogy  az adott definíció a globális hatókörre vonatkozik, vagy csak a kódunkat szeretnénk kifejezőbbé tenni.


### Tagfüggvények definiálasa


Tekintsük az alábbi programot:

```cpp
// myclass.h
#ifndef MYCLASS_H
#define MYCLASS_H

namespace MyNameSpace
{
  class MyClass
  {
    void f();
  }
}
#endif
```

A tagfüggvények megadásának legegyszerűbb módja:

```cpp
// myclass.cpp

#include "myclass.h"

namespace MyNameSpace
{
  void MyClass::f() { ... }
}
```

Alternatív megoldásként használhatjuk a ```using namespace``` utasítást a forrásfájlban:

```cpp
// myclass.cpp

#include "myclass.h"

using namespace MyNameSpace;

void MyClass::f() { ... }
```

A következő megoldás is megfelelő, bár több tagfüggvény esetén körülményesebb a használata:

```cpp
// myclass.cpp

#include "myclass.h"

void MyNameSpace::MyClass::f() { ... }
```


### Using deklarációk


A ```using namespace``` lehetővé teszi a névtérben található valamennyi definíció közvetlen elérését. A ```using``` önmagában is használható a nnévtérben levő egyedi nevek közvetlenül elérhetővé tételéhez. A ```using``` ezen használatát __using deklaráció__-nak nevezzük. Például:

```cpp
namespace NA
{
  void f() { ... }
}

namespace NB
{
  void f() { ... }
}

using NA::f;

int main()
{
  f(); // NA::f-nek felel meg
  using NB::f;
  f(); // NB::f-nek felel meg
}
```

Az ```f()``` függvény az ```NA``` és ```NB``` névterekben is definiált. A ```using NA::f;``` sor az ```NA``` névtérből az ```f()``` függvényt az adott deklarálási régióban közvetlenül elérhetővé teszi. Így a ```main()``` függvény első sorában az ```f()``` az ```NA::f``` függvényt jelenti. Az ezt követő sorban a ```using NB::f;``` utasítással az ```f()``` szimbólum jelentését az adott deklarálási régióra felüldefiniáljuk, így az utolsó sorban ```f()``` az ```NB::f``` függvényt jelenti.


### Argumentumfüggő névfeloldás


Az __argumentumfüggő (Koening) névfeloldás__ (_Koening lookup_) lényegét a következő példában szemléltetjük:

```cpp
namespace NS
{
  struct X
  {
    ...
  };

  void f(X& x_) { ... }
}

int main()
{
  NS::X x;
  NS::f(x); // OK
  f(x); // OK
}
```

Az ```NS``` névtérben egy ```X``` nevű struktúrát és egy ```X&``` paraméterrel rendelkező, ```f()``` nevű függvényt definiáltunk. A ```main()``` függvény második sorában az ```f()``` függvényt minősített nevével, az utolsó sorában pedig közvetlen névmegadással használjuk. Az utolsó sornak fordítási hibát kellene eredményeznie, hiszen az ```f()``` függvényt nem tettük a ```using namespace``` vagy a ```using``` használatával közvetlenül elérhetővé.  A C++ nyelv által támogatott argumentumfüggő névfeloldásnak köszönhetően azonban az ```f()``` függvénynév minősítés nélkül is használható, mert az ```x``` paramétere az ```NS``` névtérben definiált, így az ```f()``` szimbólum felhasználásakor a fordító az ```NS``` névtérben is végez keresést.

Az argumentumfüggő névfeloldás előnyei az operátorok használatakor válnak nyilvánvalóvá.



A ```using namespace std;``` segítségével a standard névtér globális használatát tesszük lehetővé. Ennek hatására az ```std``` névtérben található típusok, függvények és változók oly módon is elérhetővé válnak, mintha a globális névtérben lettek volna deklarálva. A standard könyvtárban található implementációk az ```std``` névtérben találhatók. Ennek az az oka, hogy a standard könyvtár gazdag eszközkészletet biztosít, amelynek során számos gyakran használt nevet is felhasznál, mint pl. ```find()```, ```max()``` stb. Ha nem az ```std``` névtérben lennének ezek a nevek, akkor bizonyos kontextusokban nem használhatnánk fel ezeket a őket a saját programunkban. Éppen ezért gyakran kihagyjuk ezt a sort a programunkból. A standard könyvtárbeli elemekre minősített nevek megadásával hivatkozhatunk:

```cpp
#include <iostream>

int main(int argc, const char* argv[])
{
  std::cout << "Hello World!";
  return 0;
}
```

Argumentumfüggő névfeloldás hiányában a következő formában lehetne megadni a fenti kifejezést:

```cpp
std::operator<<(std::cout, "Hello World!");
```


### Névtér alias


Ritkán, de előfordulhat, hogy egy hosszú névtérnév, illetve hosszú, egymásba ágyazott névtérnevek helyett egy rövid nevet kívánunk bevezetni. Erre van mód a __namespace új-névtér = meglévő-hosszú-névtérnév__ alkalmazásával. Például:

```cpp
namespace LongLongOuterNamespaceName
{
  namespace LongInnerNamespaceName
  {
    void f() {}
  }
}

namespace NS = LongLongOuterNamespaceName::LongInnerNamespaceName;

int main()
{
  NS::f();
}
```


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


A programozónak lehetősége van arra, hogy a névterekben újabb névtereket hozzon létre, vagyis egymásba ágyazza őket. Ezzel a megoldással a globális neveket is strukturált rendszerbe tudjuk szervezni.

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
namespace A::B { int i = 0; }
```

A két kódrészlet funkcionalitásban teljesen megegyezik.


## A ```main()``` függvény


Ez a program __belépési pontja__ (_entry point_). Minden C++ nyelven írt programnak tartalmazni kell __PONTOSAN__ egyet. Ez az egyetlen olyan függvény, amit nem lehet túlterhelni. Paraméterei közül az ```argc``` a parancssori paraméterek számát adja meg, míg az ```argv[]``` egy nullpointerrel terminált, karaktermutatókat tartalmazó tömb, amelyben a parancssori paraméterek vannak C-stílusú string-ként. A C++-ban a tömböket 0-tól indexeljük, így az ```argv[]``` nulladik eleme a futtatható állomány neve, első eleme pedig az első paraméter.

```./program first second (vagy program.exe first second)```

```argv[0] == "program"```

```argv[1] == "first"```

```argv[2] == "second"```

A két kapcsos zárójel (```{ }```) közti részt blokknak nevezzük. A ```cout``` a C++ standard kimenete. Az ```endl``` pedig beilleszt egy newline karaktert a kiírandó sor végére. Felmerülhet a kérdés, hogy mi a különbség az ```endl``` és a ```\n``` között? Nos,

* a ```\n``` csak egy string aminek a hossza egy és ez adódik hozzá az ```std::cout```-hoz.
* az ```std::endl``` ezzel szemben egy objektum, ami a newline karakter hozzáadásához vezet ÉS ezek után flush-olja az ```std::cout``` buffert. Ezért ez több számítással jár. Az ```std::endl``` meghívja az ```os.put(os.widen('\n'))``` függvényt, majd ezt követően az ```os.flush()``` függvényt.

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

Abban az esetben, ha a ```main.cpp```-t és az ```other.cpp```-t együtt fordítjuk, fordítási hibát kapunk, ugyanis megsértettük az __ODR__-t (_One Definition Rule_), hiszen ```x``` kétszer van definiálva. Ezt úgy tudjuk megoldani, ha forward deklarájuk ```x```-et az ```extern``` kulcsszó segítségével.

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
#include <iostream>

int x;

int main() 
{ 
  std::cout << x << std::endl; 
}
```

> kimenet: 0

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

__Láthatóság__: a hatókör részhalmaza, a programszöveg azon része, ahol a deklarált névhez a megadott entitás tartozik. Mivel az egymásba ágyazott blokkokban egy korábban már bevezetett nevet más entitáshoz kapcsolhatunk, ezért ilyenkor a külső blokkban deklarált entitás a nevével már nem elérhető. Ezt nevezzük a láthatóság elfedésének.


## Automatikus, statikus és dinamikus élettartam


__Automatikus élettartam__: a blokkokban deklarált lokális változók automatikus élettartamúak, ami azt jelenti, hogy a deklarációtól a tartalmazó blokk végéig tart az élettartamuk, ami jelen esetben  egybeesik a hatókörrel. A helyfoglalás számukra a végrehajtási verem aktuális aktivációs rekordjában történik meg.

__Statikus élettartam__: a globális változók, illetve egyes nyelvekben a __statikusként__ deklarált változók statikus élettartamúak. Az ilyen változók élettartama a program teljes végrehajtási idejére kiterjed, számukra a helyfoglalás már a fordítási időben megtörténhet.

__Dinamikus élettartam__: a dinamikus élettartamú változók esetén a programozó foglal helyet számukra a dinamikus tárterületen (_heap_, bővebben a heapről a későbbiekben lesz szó), és a programozó feladata gondoskodni arról is, hogy ezt a tárterületet később felszabadítsa. Amennyiben ez utóbbiról megfeledkezik, azt nevezzük __memória szivárgásnak__ (_memory leak_). A dinamikus élettartam esetén a hatókör semmilyen módon nem kapcsolódik össze az élettartammal, az élettartam szűkebb vagy tágabb is lehet a hatókörnél.

Tekintsük az alábbi kódrészletet és figyeljük meg mikor tudunk az ```x``` változóra hivatkozni.

```cpp
#include <iostream>

int x;

int main() 
{
  int x = 1;
  {
    int x = 2;
    std::cout << x << std::endl;
  }
}
```

> kimenet: 2

A ```main()``` elején létrehozott ```x``` az utána következő blokkban teljesen elérhetetlen - nincs olyan szabványos nyelvi eszköz, amivel tudnánk rá hivatkozni. Ezt a folyamatot nevezzük __leárnyékolásnak__ (_shadowing_). Azonban a külső globális ```x```-re bármikor tudunk hivatkozni a már korábban említett scope operátor (```::```) segítségével.

```cpp
#include <iostream>

int x;

int main() 
{
  int x = 1;
  {
    int x = 2;
    std::cout << ::x << std::endl;
  }
}
```

> kimenet: 0

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

> kimenet: 1

Ilyen esetekben, ha azonos nevű változó szerepel a globális névtérben és egy névtelen névtérben a scope operátor __mindig__ a globális névtérbeli változóra fog hivatkozni.


## Jobb- és balérték


A láthatóság és élettartam fogalmával szoros összeköttetésben áll a __jobb- és balérték__ fogalma. Egy objektumot __balérték__-nek (_left value_, röviden _lvalue_) nevezzük, ha a címképző operátorral (```&```) le tudjuk kérni a memóriabeli címét, __jobbérték__-nek (_right value_, röviden _rvalue_) ha nem. A jobbértékek többnyire ideiglenes objektumok, mint pl. az érték szerint visszatérő függvény visszatérési értéke és a literálok. Lévén ezek az objektumok csak ideiglenesen szerepelnek a memóriában ezért hiba lenne a memóriacímükre hivatkozni, így a fordító nem is engedi. Példaképp:

```cpp
int main()
{
  int* p, r;
  &p; // ok, p mutató memóriacímét tartalmazza
  &r; // ok, r memóriacímét tartalmazza
  &1; // nem ok, 1 jobbérték
  &"Hello"; // nem ok, a "Hello" jobbérték
  5 = r; // nem ok, jobbértéknek nem lehet értéket adni
}
```


# A C++ memóriamodellje


A C++ szabvány több memóriatípust különít el. Mégpedig:

* __stack__ (_verem_)
* __globális / statikus__
* __heap / free store__ (_kupac_)


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


A __heapen__ létrehozott változókat __dinamikus változóknak__ (_dynamic variable_) is szokás nevezni. A heap segítségével nagy szabadságra tehetünk szert, de ez a szababdság nagy felelősséggel is jár.

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


## A ```new``` és a ```delete``` operátorok


A dinamikus változóknak a ```new``` operátorral foglalunk helyet a memóriában, megadva annak típusát.

```cpp
int* ptr = new int(1);
```

Dinamikusan lefoglalt változók felszabadításáról a ```delete``` operátor gondoskodik.

```cpp
delete ptr;
```

A C-ben megszokott ```malloc()``` és ```free()``` műveletek függvényhívások voltak, ám a C++-ban ezek operátorként vannak megadva. További különbség, hogy a ```malloc()``` függvény visszatérési értéke ```void*``` típusú, azaz tetszőleges memóriaterületre mutathatott. A kapott értéket egy __explicit cast__ segítségével szokás konvertálni. Így azonban lehetőség lenne értelmetlen foglalásokra is, mint pl:

```cpp
int* p = malloc(sizeof(char));
```

Mivel a C / C++ szabvány csak annyit követel meg, hogy a ```char``` mérete legalább 8 bit, az ```int``` pedig minimum 16 bit legyen, ezért nincs arra garancia, hogy a hívás után a ```*p``` mutató "elég nagy" memóriaterületre mutat.

C++-al ezzel szemben a ```new``` operátor már típusozott - így az

```cpp
int* p = new char;
```

utasítás nem fordul le, mivel a típusok nem egyeznek.

További előnye a ```new``` operátornak, hogy a memória lefoglaláson kívül az adott típus (struktúra / osztály) konstruktorát is meghívja, így egyből inicializálni is lehet az adott értéket. Ezzel párban a ```delete``` operátor a destruktort fogja meghívni az adott objektumon. (Konstruktorról és a destruktorról az osztályoknál lesz bővebben szó.)

Abban az esetben, ha egy _n_ elemű tömbnek szeretnénk dinamikusan helyet foglalni a ```new``` operátorral, jeleznünk kell a fordítónak, mégpedig az ```[]``` operátor segítségével.

```cpp
int* pArray = new int[5];
```

Ebben az esetben, ha a

```cpp
delete pArray;
```

kifejezést használjuk még mindig memóriaszivárgás lesz a programunkban. Miért? Mert a ```pArray``` nevű változó egy mutató, ami a tömb első elemére mutat, így az egyszerű ```delete pArray;``` nem elég az egész tömb törlésére.

__Megoldás__: jelezzük a fordítónak, hogy nem csak egy elemet, hanem egy egész tömböt szeretnénk törölni. Ezt szintén az ```[]``` operátor segítségével tehetjük meg.

```cpp
delete[] pArray;
```


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

Mivel a konstansok már fodítási időben kirétékelődnek, nem köthetjük futási idejű kiértékeléshez az értéküket. Ha ezt megtehetnénk sérülne a __konstans korrektség__, amely kimondja, hogy egy konstans változó értéke nem módosulhat a program végrehajtása alatt.


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

> Kimenet: _error: call of overloaded ‘f(NULL)’ is ambiguous_.

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
  *q = &j; // fordítási idejű hiba
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


# Konstans korrektség (_const-correctness_)


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
  // aközött, hogy az int-et vagy a const kulcsszót írjuk ki előbb
  const int* i = nullptr;
  int const* ii = nullptr;
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


# Tömbök (_arrays_)


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
  int array[] = {1,2,3,4,5};
  std::cout << sizeof(array) << ' ' << sizeof(int);
}
```

>  kimenet: 20 4

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

__Fontos__: a tömbön való túlindexelés nem definált viselkedés.

> $ clang++ main.cpp -fsanitize=address

A sanitizerek csak abban az esetben találnak meg egy hibát, ha a probléma előfordul (azaz futási időben, nem fordítási időben ellenőriz).


## Tömbök méretének meghatározása


Mint azt korábban láthattuk a tömb tiszta adat. A ```sizeof()``` operátor segítségével megtudjuk határozni a méretét. Egy olyan tömbben amelyben _n_ darab _T_ típusú elemet tárolunk a tömb mérete _n * sizeof(T)_. Ezt már csak le kellene osztanunk _sizeof(T)_-vel, azaz a tömbben tárol típus méretével tehát a képlet: ```sizeof(array) / sizeof(T)```. Azonban nem biztos, hogy tudjuk, hogy milyen elemek vannak az ```array``` tömbben, így kicsit generikusabban megfogalmazva az előző képletet a _sizeof(T)_ helyett osztjunk le a tömb első elemének méretével, _sizeof(array[0])_. Ezt megtehetjük, mert tudjuk, hogy a tömb azonos típusú elemeket tartalmaz. Tehát a helyes képlet a következő:

```sizeof(array) / sizeof(array[0]);```


## Tömb elemeinek elérése


Egy tömb adott elemére többféle módon is hivatkozhatunk:

```*(p+3)``` == ```*(3+p)``` == ```p[3]``` == ```3[p]```

Ahhoz, hogy megértsük a fentebb látható egyenlősséget tudni kell, hogy a tömbök nevei C++-ban konvertálódnak a tömb első elemére mutató mutatóra és, mivel - ahogy az fentebb említettük - a tömbök sorfolytonosan helyezkednek el a memóriában ezért tudunk a ```+``` operátor segítségével ugrálni az adattagjaikon.

__Megjegyzés__: a fentebb látható egyenlősséget nevezzük __pointer aritmetikának__.

Tekintsük az alábbi két dimenziós tömböt:

```cpp
int main()
{
  int t[][3] = {{1,2,3}, {4,5,6}};
}
```

Az első ```[]``` jelek között nincs megadva méret, mert a fordító az inicializáció alapján meg tudja állapítani. A második dimenzió méretének megadása kötelező! A pointer aritmetika ekvivalencia mátrixok esetén is érvényes, azaz fennállnak az alábbi egyenlősségek:

```t[1][0]``` == ```*(*(t+1)+0)``` == ```*(1[t]+0)``` == ```0[1[t]]``` == ```0[*(t+1)]``` == ```*(t+1)[0]``` == ```1[t][0]```


# Paraméter átadási mód, visszatérési érték


A C++ három különféle paraméter átadási módot különböztet meg:

* __érték szerint__ (_pass by value_)
* __referencia szerint__ (_pass by reference_)
* __mutató szerint__ (_pass by pointer_)

Az értékek átadásának demonstrálásához a ```swap()``` függvényt fogjuk használni.


## Érték szerinti paraméter átvétel


C++-ban ez az alapértelmezett paraméterátadási mód. Tekintsük a következő kódot:

```cpp
#include <iostream>

void swapWrong(int a, int b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int main()
{
  int c = 1, d = 2;
  std::cout << c << ", " << d << std::endl;
  swapWrong(c, d);
  std::cout << c << ", " << d << std::endl;
}
```

> kimenet:
>
> 1 2
>
> 1 2

Megfigyelhető, hogy az első kiírás eredménye ugyanaz, mint a második kiírásé. Ez azonban egy teljesen jól definiált viselkedés. Ennek oka nem más mint, hogy __érték__ szerint vettük át a paramétereket. Képzeljük el, hogy a stackbe a program berakja a ```c``` és ```d``` változókat. Ezután meghívja a ```swapWrong()``` függvényt, melyben létrehozott ```a``` és ```b``` paraméterek értékét megcseréli, de a függvényhívás után ezeket ki is törli a stackből. Az eredeti ```c``` és ```d``` változók értéke nem változott a függvényhívás során.

A stack tartalma érték szerinti paraméterátadás esetén.

![passByValueStack](img/passByValueStack.png)


## Mutató szerinti paraméter átadás


Írjuk meg helyesen a ```swap()``` függvényt.

```cpp
#include <iostream>

void swapPointer(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main()
{
  int c = 1, d = 2;
  std::cout << c << ", " << d << std::endl;
  swapPointer(&c, &d);
  std::cout << c << ", " << d << std::endl;
}
```

> kimenet:
>
> 1 2
>
> 2 1

Amennyiben ezt a függvényt hívjuk meg, valóban megcserélődik a két változó értéke. De ehhez fontos, hogy ne ```swapPointer(c, d)```-t írjunk, az ugyanis fordítási idejű hibához vezetne, hiszen ```c``` és ```d``` változók típusa ```int``` és nem ```int*```, márpedig mi mutatót adtunk meg bemenetként, amiben pedig referenciákat tudunk tárolni, így a helyes választás a ```&c``` és ```&d``` változók referenciája lesz.

A stack tartalma mutató szerinti paraméterátadás esetén.

![passByPointerStack](img/passByPointerStack.png)

```cpp
#include <iostream>

void swapPointerWRONG(int* a, int* b)
{
  int *tmp = a;
  a = b;
  b = tmp;
}

int main()
{
  int c = 1, d = 2;
  std::cout << c << ", " << d << std::endl;
  swapPointerWRONG(&c, &d);
  std::cout << c << ", " << d << std::endl;
}
```

> kimenet:
>
> 1 2
>
> 1 2

Ebben a példában nem a mutatók által mutatott értéket, hanem magukat a mutatókat cseréljük meg. Itt az fog történni, hogy a függvény belsejében ```a``` és ```b``` mutató másra fog mutatni. A mutatott értékek viszont nem változnak.

A stack tartalma rossz mutató állítása esetén.

![passbyPointerWrongSwapStack](img/passByPointerWrongSwapStack.png)


## Referencia szerinti paraméter átadás


Az előző példában láthattuk, hogy nem változtattuk meg, hogy mire mutassanak a mutatók, így azokat akár konstansként is definiálhattuk volna. Emlékezzünk vissza a konstans mutatók módosíthatják a mutatott értéket, de nem lehet őket átállítani egy másik memória címre.

```cpp
void swap(int* const a, int* const b)
{
  // ...
}
```

Egy kis szintaktikai cukorkával megúszhatjuk azt, hogy folyton kiírjuk a ```* const```-ot, mivel nem akarjuk megváltoztatni, hogy ilyen esetben a mutató hova mutasson. Erre való a referencia szerinti paraméter átadás. A referencia hasonlóan működik, mintha egy konstans mutató lenne, csak nem lehet sehova se mutató referenciát létrehozni, azaz nullreferenciát.

```cpp
#include <iostream>

void swapReference(int& a, int& b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int main()
{
  int c = 1, d = 2;
  std::cout << c << ", " << d << std::endl;
  swapReference(c, d);
  std::cout << c << ", " << d << std::endl;
}
```

> kimenet:
>
> 1 2
>
> 2 1

Vegyük észre, hogy ilyenkor nem kell jelezni, hogy memóriacímet akarunk átadni, ezért ```swapReference(c, d)```-t kell írnunk. Hátulütője a dolognak, hogy ha más valaki által írt függvényt akarunk használni, aminek nem ismerjük a szignatúráját nem tudjuk explicit megállapítani a hívásból, hogy az átadott paraméterek refenrecia vagy érték szerint lesznek átadca. C#-ban ennek a jelzésére van a ```ref``` kulcsszó.

__Megjegyzés__: bár referencia szerinti értékátadásnak nevezzük, de itt is történik másolás, a memóriacímet itt is érték szerint vesszük át.

__Ökölszabály__: ahol lehet ott használjunk referenciákat, ahol muszáj ott mutatót.


## Paraméter átadási módok használata


__érték szerinti__: ```f(int x)```

* a függvény nem módosíthatja a paramétert
* használd ezt, ha __könnyű másolni__
* Ökölszabály: ha a paraméter mérete legfeljebb 2- vagy 3 szó (word), azaz 32-bit, akkor érdemes érték szerint átadni
	* egyszerű primitív típusok esetén ajánlott, mint pl.: ```int```, ```double```, ```char```, ```bool```, stb. 
	* Komplex típusok, saját osztályok, ```std::string``` és a különböző STL konténerek nem ajánlottak (továbbiakban ezeket a példákban T -vel jelöljük)

__mutató szerinti__: ```f(T* x)```

* a függvény __módosíthatja a paramétert__,
* használd ezt, __ha költséges a másolás__,
* továbbá ha a __NULL lehet valid érték__

__konstans mutató szerinti__: ```f(const * T x)```

* a függvény __nem módosíthatja a mutató által mutatott értéket__,
* használd ezt, __ha költséges a másolás__,
* továbbá ha a __NULL lehet valid érték__

__referencia szerinti__: ```f(T& x)```

* a függvény __módosíthatja a paramétert__
* használd ezt, ha __költséges a másolás__,
* továbbá ha a __NULL NEM lehet valid érték__

__konstans referencia szerinti__: ```f(const T& x)```

* függvény __nem módosíthatja a paramétert,__
* használd ezt, ha __költséges a másolás__
* továbbá ha a __NULL NEM lehet valid érték__
	* próbáljuk mindig ezt a változatot használni saját osztályokhoz, ```std::string```-hez és STL adatszerkezetekhez, ha paramétert nem akarjuk módosítani
		* copy konstruktorok, copy assignmentek paraméterei


__Megjegyzés__: függvények bemeneti paramétereinek adhatunk alapértelmezett (default) értéket.

```cpp
int f(int i = 0) { std::cout << i; }

int main()
{
  f();
  f(1);
}
```

> kimenet: 01

Ilyenkor, ha meghívjuk az ```f()``` függvényt és nem adunk neki bemeneti értéket, akkor az alapértelmezett értéket fogja használni. Ha nem adtunk volna az ```f()```-nek alapértelmezett bemeneti paraméter értéket az első hívás szabálytalan lenne, mert nem találna a fordító olyan ```f()``` függvényt, melynek a szignatúrája megfelel annak a hívásnak.


# Visszatérési érték problémája


Nem primitív típusoknál gyakran megeshet, hogy egy adott típushoz tartozó mutató mérete kisebb, mint magának az objektumé, így megérheti mindentől függetlenül a paramétert referencia szerint átvenni. Ezen felbátorodva mondhatnánk azt is, hogy referenciával is térjünk vissza.

```cpp
#include <iostream>

std::string& concat(std::string& str_)
{
  str_ += " world";
  return str_;
}

int main()
{
  std::string str = "Hello ";
  std::cout << concat(str) << std::endl;
}
```

> kimenet: "Hello world"

Olyan típusoknál amelyeknél nagyon költésges a másolás (pl. ```std::string```), célszerű referenciával átvenni és visszaadni a változókat. Primitív típusoknál nem érdemes referenciával átvenni adattagokat.

Tekintsük az alábbi programot:

```cpp
#include <iostream>

std::string& concat(std::string& str_)
{
  std::string str = str_ + " world";
  return str;
}

int main()
{
  std::string str = "Hello ";
  std::cout << concat(str) << std::endl;
}
```

Mi ezzel a programmal a baj?

Ha jobban megnézzük a ```concat()``` függvény az ```str``` lokális változó referenciájával tér vissza. Ám, mint azt már tudjuk az ```str``` számára a stacken került foglalásra a memóriaterület, így függvény végén fel fog szabadulni, azaz törlődni fog a stackről. Így, amikor visszaadjuk a referenciáját, egy törölt változó referenciáját fogjuk visszaadni, ami valami memóriaszemét lesz. Ilyen esetekben a fordító egy figyelmeztetést ad: olyan objektumra hivatkozó referenciát adunk vissza, amely ```concat()```-on belül lokális. Ez azt jelenti, hogy amint a vezérlés visszatér a ```main()``` függvényhez az ```str``` megsemmisül, és a ```main()``` függvény pedig az ```str```-hez tartozó címen lévő értéket próbálná meg lemásolni. Mivel viszont az ```str``` már ezen a ponton megsemmisült, semmi nem garantálja, hogy azon a memóriaterületen ne követekezett volna be módosítás.

Az olyan memóriaterületre való hivatkozás, mely nincs a program számára lefoglalva, __nem definiált viselkedést__ eredményez.

__Megjegyzés__: mutatóknál ugyan ez a probléma áll fent.


# Függvény átadása paraméterként


C++-ban lehetőségünk van arra is, hogy függvényeket adjunk át paraméterként. Ezeket az objektumokat __függvény mutatóknak__ (_function pointer_) nevezzük. A függvénymutató egy függvény memóriacímét tároló változó, melyen a függvényhívás művelete (```()```) hajtható végre. Mikor lehetnek hasznosak? Nos, előfordulhat az a helyzet, hogy egy osztály ugyanazt a hívást sokféle objektum felé meg szeretné tenni, ám ezeknek __nincs közös őse__. Annak értekében, hogy csökkentsük a függőségeket az osztályok között, nem hozunk létre egy közös őst, hanem függvénymutatókat használunk az osztályban.

```cpp
#include <iostream>

int multiply(int a, int b)
{
  return a * b;
}

void helper(int a, int b, int(*fptr)(int, int))
{
  std::cout << fptr(a,b) << std::endl;
}

int main()
{
  helper(1, 5, &multiply);
}
```

> kimenet: 5

Itt a ```helper()``` utolsó paraméterként egy olyan paramétert vár, amely igazából egy függvény, amely ```int```-et ad vissza, és bemeneti paraméterül két ```int```-et vár. Az ```fptr``` egy olyan függvényre mutató mutató, melynek két ```int``` paramétere van és a visszatérési értek is ```int```.

Egy függvény átadásakor csak függvénypointert tudunk átadni. Egy függvénypointeren a függvény hívása az egyetlen értelemes művelet. Így az ```&``` jel elhagyható a függvény hívásakor és az ```fptr``` elől is elhagyható a ```*``` karakter a paramétereknél.

```cpp
// ...
void helper(int a, int b, int fptr(int, int))
{
  // ...
}

int main()
{
  helper(1, 5, multiply);
}
```

> kimenet: 5

Függvény mutatókat értékül adhatunk változóknak is.

```cpp

int multiply (int a, int b)
{
  return a * b;
}

int main()
{
  void (*mult)(int, int) = multiply;
  mult(1,2);
}
```

__Megjegyzés__: C++11 óta a ```void (*mult)(int, int)``` helyett használható az ```auto``` kulcsszó, amely fordítási időben végez típus kikövetkeztetést (_type deduction_), annak alapján mivel példányosítottuk az adott változót.

Az ```auto```-tól egy régebbi megoldás a ```typedef``` használata.

```cpp
// ...
int main()
{
  typedef void(*Multiply)(int, int);

  Multiply mult = multiply;
  mult(1,2);
}
```
A ```typedef``` egy speciális tárolási osztály, amely lehetővé teszi, hogy már létező típusokhoz újabb szinonim neveket rendeljünk.

A ```typedef``` helyett egy modernebb nyelvi eszköz C++11 óta a ```using``` kulcsszó. Az előző programot ennek a segítségével a következőképpen lehet leírni:

```cpp
// ...
int main()
{
  using Multiply = void(*)(int, int);

  Multiply mult = multiply;
  mult(1,2);
}
```

Olvashatóbb kódot eredményez és template-ekkel is jobban használható.


# Tömb, mint függvény paraméter


Próbáljunk meg egy tömböt érték szerint átadni egy függvénynek.

```cpp
#include <iostream>

void f(int arr[])
{
  std::cout << sizeof(arr) << std::endl;
}

int main()
{
  int array[] = {1,2,3,4,5};
  std::cout << sizeof(array) << std::endl;
  f(array);
}
```

> kimenet: 20 8 (implementáció függő)

Amikor érték szerint próbálunk meg átadni egy tömböt, az átkonvertálódik a tömb első elemére mutató mutatóra. Emlékezzünk a pointer aritmetikánál tanultakra, azaz ebben az esetben az ```f``` függvényben található ```sizeof(arr)``` egy ```int*``` méretét fogja kiírni.

Hiába is próbálnánk megadni méretet a függvény bemeneti paraméterében

```cpp
void f(int arr[8]) { std::cout << sizeof(arr) << std::endl; }
```

a kimenet akkor is egy mutató méretét fogja tartalmazni. Annak oka, hogy ez így működik visszanyúlik a C-vel való kompatibilitáshoz.

__Megjegyzés__: a szabvány szerint tömböt értékül adni nem is szabad.

Korábban már megismerkedtünk egy módszerrel, amely segítségével megtudjuk állapítani egy tömb méretét, elemszámát.

```cpp
#include <iostream>

void f(int arr[], size_t arrSize) // arrSize-ban tároljuk a tömb méretét
{
  std::cout << sizeof(arr) << std::endl;
}

int main()
{
  int array[] = {1,2,3,4,5};
  std::cout << sizeof(array) << std::endl;
  f(array, sizeof(array) / sizeof(array[0]));
}
```

__Megjegyzés__: Amennyiben C++11-ben programozunk, érdemes az ```std::array```-t használni, ami rendelkezik a tömb tulajdonságaival, viszont nem tud pointerré konvertálódni és mindig tudja a méretét.

Ha szeretnénk egy tömböt egy darab paraméterként átadni, megpróbálhatunk egy tömbre mutató mutatót létrehozni. Azonban figyelni kell a szintaktikára, ha ```int* t[5]```-t írunk, egy öt elemű ```int```-re mutató mutatókat tároló tömböt kapunk.

Ha tömbre mutató mutatót szeretnénk, akkor a következőt írjuk:

```cpp
void f(int (*arr)[5]) { std::cout << sizeof(arr) << std::endl; }
```

Azonban ez még mindig egy mutató méretét fogja kiírni, mert az ```arr``` az egy sima mutató! Ahhoz, hogy megkapjuk, mire mutat, dereferálnunk kell, így a ```sizeof``` paraméterének ```*arr```-t kell megadni, ha a tömb méretére vagyunk kíváncsiak. Ha eltérő méretű tömböt próbálunk meg átadni, akkor nem fordul le a kód, mert nem tud egy 5 elemű tömbre mutató mutatóra konvertálódni például egy 6 elemű tömb.

Ahhoz, hogy egy olyan függvényt írjunk, ami minden méretű tömböt elfogad paraméterül, a legegyszerűbb megoldás, ha hagyjuk, hogy a tömb átkonvertálódjon egy első elemre mutató mutatóra, és átadjuk külön paraméterben a tömb méretét, ahogy azt fentebb tettük.

A tömbök átvétele paraméterként azért ilyen körülményes, mert egy tömbnek a méretét fordítási időben ismernünk kell. Ha változó méretű tömböt várnánk paraméterül, az szembemenne ezzel a követelménnyel.

Könnyű azt hinni (_hibásan_), hogy a mutatók ekvivalensek a tömbökkel. A tömb típusa tartalmazza azt az információt, hogy hány elemű a tömb. Egy mutató típusa csak azt az információt tartalmazza, hogy a mutatott elem mekkora. Számos más különbség is van. A tévhit oka az, hogy tömb könnyen konvertálódik első elemre mutató mutatóra.


# Statikus változók / függvények


Statikus változókat, függvényeket a ```static``` kulcsszó segítségével hozhatunk létre. A ```static``` kulcsszónak számos jelentése van, annak függvényében, hogy milyen kontextusban írjuk egy változó vagy függvény elé. Statikus változók a statikus globális tárterületen jönnek létre. Élettartamuk attól függ, hogy hol deklaráljuk őket és a program futásának végéig tart. Nem szükséges kezdőértékkel el látni őket csak abban az esetben, ha konstansok.

```cpp
int main()
{
  static int i;       // ok
  static const int j; // nem ok, konstansoknak kezdőértéket kell adnunk
                      // emlékezzünk a konstans korrektségre
}
```


## Fordítási egységre lokális változók


A függvényeken és osztályokon kívül deklarált statikus változók az adott fordítási egységre lokálisak – élettartamuk a futás elejétől futás végéig tart, és kizárólagosan az adott fordítási egységben láthatóak.

```cpp
// main.cpp
static int x;

int main() { x = 1; }

// other.cpp
static int x;

int main() { x = 2; }
```

Ha ezt a két fájlt együtt fordítjuk, nem kapunk linkelési hibát, ugyanis a ```main.cpp```-ben lévő ```x``` egy teljesen más változó, mint ami az ```other.cpp```-ben van.

Csak úgy, mint a globális változókra, fordítási egységen belül bármikor hivatkozhatunk egy statikus változóra, és hasonló módon inicializálódnak.

```cpp
#include <iostream>

static int x;

int main()
{
  int x = 2;
  std::cout << ::x << std::endl;
}
```

> kimenet: 0


## Függvényen belüli statikus változók


Azokat a változókat, melyek függvényen belül vannak a ```static``` kulcsszóval definiálva, __függvényszintű változónak__ is szokás hívni. Élettartamuk a függvény első hívásától a program futásának végéig tart, míg láthatóságuk csak az adott függvényen belül van. A hagyományos lokális változókkal ellenben nem semmisülnek meg, amikor az adott függvény futása befejeződik. 
A következő kódrészlet szemlélteti ezt a viselkedést.

```cpp
#include <iostream>

int f() {
  static int x = 0;
  return ++x;
}

int main() {
  for (int i = 0; i < 5; i++)
    std::cout << f() << ’ ’;
}
```

> kimenet: 1 2 3 4 5

Ahogy az megfigyelhető, ```x``` csak egyszer inicializálódik, majd a későbbi függvényhívások után egyre növekszik az értéke.


## Fordítási egységre lokális függvények


Nem csak változókat, függvényeket is deklarálhatunk statikusnak, melyek a fordítási egységre lokálisak.

```cpp
#include <iostream>

static int f() { return 0; }

int main()
{
  std::cout << f();
}
```

> kimenet: 0

Ezek a függvények csak az adott fordítási egységen belül érhetőek el.


## Függvény túlterhelés (_function overloading_)


A C++ lehetőséget ad a __függvények túlterhelésére__ (_overloading_), vagyis azonos nevű, de eltérő szignatúrájú függvények definiálására. Az ilyen függvénycsoportok hivásakor, a fordító a hívás szignatúrájából határozza meg, hogy melyik függvény hívódjon meg.

A C++ az alábbi attribútumokat érti bele egy függvény szignatúrájába:

* függvény neve
* osztály neve (tagfüggvényeknél)
* template argumentumok típusa (template függvényeknél)
* argumentumok típusa
* ```const``` típusmódosító (tagfüggvényeknél, tagfüggvényeket konstanság alapján is túl lehet terhelni).

Vegyük észre, hogy a szignatúrába a visszatérési érték típusa nem tartozik bele, vagyis ha két függvénydeklaráció pusztán visszatérési értékében különbözik, az nem számít túlterhelésnek, csak felüldefiniálásnak, és mint olyan legtöbbször fordítási hibát generál.

Tekintsük újra a ```swap()``` függvényt.

```cpp
void swap(int& a, int& b)
{
  tmp = a;
  a = b;
  b = tmp;
}
```

Ez a függvény egészen addig jól működik, amíg csak ```int```-eket használunk. Mi a helyzet, ha két ```std::string```-et szeretnénk megcseréli? A megoldás egyszerű, terheljük túl a ```swap()``` függvényt.

```cpp
void swap(std::string& a, std::string& b)
{
  std::string tmp = a;
  a = b;
  b = tmp;
}
```

## Operátor túlterhelés (operator overloading)


A közönséges függvényekhez hasonlóan a legtöbb operátort is túl lehet terhelni, amely a felhasználói típusok kényelmesebb használatát teszi lehetővé (jellemző például az ```<<``` operátor túlterhelése).

Programozás során gyakran használunk operátorokat a programban elvégzendő feladatok, tömör, olvasható kifejezésére.

Az operátorok beépített típusok kezelésére kitűnően használhatóak, a programozó által létrehozott típusok, osztályok kezelésére azonban természetesen nem alkalmasak változatlan formában. A szabványos C++ operátorokhoz előre definiált úgynevezett operátor-függvények tartoznak. Amikor tehát C++-ban definiált műveleti jel értelmezését ki szeretnénk terjeszteni egy saját adattípusra, akkor a kérdéses operárot operátor-függvényére adunk meg egy újabb paraméter szignatúrájú változatot.

Túlterheléssel a programozó meghatározhatja, hogy mi történjék az általa létrehozott típusokkal az egyes operátorok hatására.

__Fontos__: túlterhelés során megváltoztathatjuk az egyes operátorok jelentését, de:

* nem hozhatunk létre új operátorokat
* nem változtathatjuk meg az operátorok aritását
* nem változtathatjuk meg az operátorok precedenciáját

Túlterhelhető operátorok: ```+```, ```-```, ```*```, ```/```, ```%```, ```^```, ```&```, ```|```, ```~```, ```!```, ```=```, ```<```, ```>```, ```+=```, ```-=```, ```*=```, ```/=```, ```%=```, ```^=```, ```&=```, ```|=```, ```<<```, ```>>```, ```>>=```, ```<<=```, ```==```, ```!=```, ```<=```, ```>=```, ```&&```, ```||```, ```++```, ```--```, ```->*```, ```,```, ```->```, ```[]```, ```()```, ```new```, ```new[]```, ```delete```, ```delete[]```.

Az ```=``` (értékadó), ```&``` (címképző) és a ```,``` (kiválasztó) operátorok túlterhelés nélkül is érvényesek.

Nem túlterhelhető operátorok: ```::```, ```.```, ```.*```, ```? :```, ```sizeof```, ```typeid```


Ezeknek az operátoroknak a túlterhelése nemkívánatos mellékhatásokkal járna, ezért nem lehet őket túlterhelni.

Túlterhelés menete:

A túlterhelés során az operátort megvalósító utasításokat függvényként adjuk meg. A függvény nevében az ```operator``` kulcsszót maga az operátor követi. Az operátor argumentumai a függvény argumentumai és visszatérési értéke, amelyek beépített típusok, objektumok (kis méret esetén) vagy referenciák (nagy méret esetén) lehetnek.

Az operátorok túlterhelésére használt függvények argumentumai lehetnek objektumok, de ez nem szerencsés nagyméretű objektumok esetében. Mutatókat nem használhatunk argumentumként, mert a mutatókra alkalmazott operátorok nem terhelhetők túl. A referenciák argumentumként használva lehetővé teszik a nagyméretű objektumok kezelését anélkül, hogy lemásolnánk őket.


## Literálok


### Karakterlánc literálok


Mi lesz a __"Hello"__ literál típusa?

Egy konstans karakterekből álló _6_ méretű tömb (```const char[6]```). Azért 6 elemű, mert a karakterlánc literál végén el van tárolva a végét jelző ```\0``` karaktert.

__Megjegyzés__: változó típusát a ```typeid(variable).name()``` segítségével tudjuk lekérdezni.

![characterLiterals](img/charLiteral.png)

```cpp
int main()
{
  char* hello = "Hello";
  hello[0] = 'B';
}
```

A fenti kódban megsértettük a konstans korrektséget, mert egy nem konstansra mutató mutatóval mutatuk egy konstans karakterlánc literál első elemére. Ennek ellenére, a fenti kód lefordul. Ennek az az oka, hogy az eredeti C-ben nem volt ```const``` kulcsszó, a kompatibilitás miatt ezért C++-ban lehet konstans karakterlánc literál elemire nem konstansra mutató mutatóval mutatni.

__Megjgyzés__: ezt a fajta kompatibilitás miatt meghagyott viselkedés __kerülendő__. A kód lefordul ugyan, de kapunk rá warningot.

Ha módosítani próbáljuk a karakterlánc literál értékét, az _nem definiált viselkedéshez_ vezet.
Linux operációs rendeszer futtatáskor futási idejű hibát kapunk, egészen pontosan szegmentálási hibát. Ennek oka, hogy a konstansok értékei __readonly__ memóriában vannak tárolva, aminek a módosítását nem engedi az operációs rendszer.


### Szám literálok


Függően attól, hogy hogyan írunk egy szám literált C++-ban, más lehet a jelentése.

![numberLiterals](img/numberLiteral.png)

Létezik C++-ban ```signed``` kulcsszó -- erről korábban a 'C++ adattípusok - adattípus módosítók-nál olvashattunk -- , mely a ```char``` miatt lett bevezetve. A ```char``` is egész számokat tartalmaz, de az implementáció függő, hogy a ```char``` ```singed``` vagy ```unsigned``` értéket tartalmaz-e.

Természetesen leggyakrabban egész számoknál használják. Alapértelmezetten minden ```int``` egy ```signed int```, amennyiben egy előjel nélküli egész számra van szükségünk, ```unsigned int```-et vagy röviden ```unsigned```-ot kell írnunk. Megállapíthatjuk tehát, hogy az ```unsigned``` típusok ugyanannyi számjegyet tudnak tárolni, ám értékben kétszer akkorát.

Míg a túlcsordulás ```signed``` típusoknál _nem definiált viselkedés_, addig ```unsigned``` típusoknál definiált. Ekkor ugyanis a maximális érték (mely implementációfüggő) utáni inkrementálás 0-ra állítja a változót. Értelemszerűen, ez a determinisztikus viselkedés futási idejű költséggel jár.

C++-ban tizedes vessző helyett pontot kell írni ha lebegőpontos számot szeretnénk definiálni. Ennek ellenére az alábbi kód mégis helyesen lefordul:

```cpp
int pi = 3,14;
```

Miért van ez?

Az ok az, hogy a vessző operátor  (```,```) egy szekvenciapont is, így a fordító az egyenlőség bal oldalát amikor kiértékeli, először rendre kiértékeli a ```3``` számliterált, majd eldobja és utána kiértékeli a ```14```-et, és értékül adja ```pi```-nek.

A lebegőpontos számok másik veszélye, az összehasonlítás. __Minden lebegőpontos szám tartalmazhat egy kis pontatlanságot__.

```cpp
for(double d = 0; d != 1; d += 0.1)
{
  std::cout << i << ' ';
}
```

Az elvárt kimenet az lenne, hogy:

> 0 0.1 0.2 ... 1.0

de legnagyobb valószínűséggel végtelen ciklusba futunk. Ez azért van, mert a 0.1 (várhatóan) tartalmaz egy kis pontatlanságot, és így hiába írja ki a programunk hogy ```d``` értéke 1, az várhatóan csak nagyon közel lesz hozzá.

__Megjegyzés__: Viszonylag kevés esetben éri meg ```float```-ot használni ```double``` helyett. Ennek oka, hogy a odern CPU-k ugyanolyan hatékonysággak képesek dolgozni mind a kettővel, így érdemesebb a pontosabbat választani. (Ha a GPU-t programozzuk, az lehet egy kivétel.)

__Megjegyzés__: Érdemes mindig ```int```-et használni, ha nincs különösebben jó okunk arra, hogy mást használjunk. Az ```int```-el általában a leghatékonyabb a processzor.


## Struktúrák mérete


### Primitív típusok mérete


Mint azt már korábban láttuk a ```sizeof(char)``` mindig 1-et ad vissza. A karakter mérete mindig az egység. Minden más típusra a ```sizeof()``` függvény azt adja vissza, hogy paraméterül megadott objektum vagy típus mérete hányszorosa a ```char```-nak.

Attól, hogy ```sizeof(char)``` == ```1```, a ```char``` mérete bájtokban még mindig __implementáció függő__.

A char méretén túl minden másnak a mérete implementációfüggő, bár a szabvány kimond pár relációt (bővebben a [C++ adattípusok](#c-adatt%c3%adpusok) fejezetben olvashatunk erről):

```sizeof(X)``` == ```sizeof(signed X)``` == ```sizeof(unsigned X)```

```sizeof(float)``` ≤ ```sizeof(double)``` ≤ ```sizeof(long double)```

```sizeof(short)``` ≤ ```sizeof(int)``` ≤ ```sizeof(long)```

```sizeof(char)``` ≤ ```sizeof(bool)```


### Nem primitív típusok mérete


Egy áltlaunk megalkotott típus mérete több szabálytól is függhet.

```cpp
#include <isotream>

struct Student
{
  double weight;
  int age;
  int height;
};

int main()
{
  std::cout << sizeof(double) << std::endl;
  std::cout << sizeof(int) << std::endl;
  std::cout << sizeof(Student) << std::endl;
}
```
A ```double``` mérete 8 bájt, az ```int``` mérete 4 bájt, ```Student```-é 16, tehát a fenti kód lefuttatása után láthatjuk, hogy a ```Student``` struktúra tiszta adat.

Rendezzük egy kicsit át mezők sorrendjét a következő módon

```cpp
struct Student
{
  int age;
  double weight;
  int height;
};
```

A kód újbóli lefutása érdekes eredményt adhat. Ebben az esetben a ```Student``` már 24 bájtot foglal. Ennek az oka az, hogy míg az első esetben így volt eltárolva a memóriában: (ne feledjük, ez még mindig implementációfüggő !)

![sizeOfStruct](img/sizeOfStruct.png)

A ```weight```, illetve az ```age``` és a ```height``` pont efértek 1-1 gépi szóban. Viszont, ha megcseréljük a sorrendet, ez már nem lesz igaz:

![sizeOfStructBad](img/sizeOfStructBad.png)

Itt a ```weight``` két különböző gépi szóba kerülne. Ez a ma használt processzorok számára nem hatékony, hiszen a ```weight``` értékének kiolvasásához vagy módosításához két gépi szót is olvasni vagy módosítani kéne (a legtöbb processzor csak szóhatárról tud hatékonyan olvasni).


![sizeOfStructPadded](img/sizeOfStructPadded.png)

A fenti elrendezés hatékonyabb, bár 3 gépi szót használ. Ebben az esetben a fordító úgynevezett __padding__-et illeszt be a mező után. Ennek hatására hatékonyan olvasható és módosítható minden mező. Cserébe több memóriát foglal a struktúra.

A szabvány kimondja, hogy egy ```struct``` mérete az adottagok méreteinek összegénél nagyobb vagy egyenlő.

Az, hogy egy gépi szó mekkora, __implementációfüggő__.


## OOP - Objektum-Orientált Programozás (_Object Oriented Programming_)


Az objektum-orientált programozás az objektumokat és köztük fennálló kölcsönhatásokat használja alkalmazások és számítógépes programok tervezéséhez. Négy dolog szükséges ahhoz, hogy egy programozási nyelvről azt mondhassuk, hogy támogatja az OOP-t:

* Adatrejtés (_data hiding_)
* Egységbezárás (_encapsulation_)
* Öröklődés (_inheritance_)
* Polimorfizmus - többalakúság (_polymorphism_)


### Alapelemek


#### Osztály (_class_)


Az osztály meghatározza egy objektum elvont jellemzőit, beleértve az objektum jellemvonásait (attribútumok, mezők, tulajdonságok) és az objektum viselkedését (amit az objektum meg tud tenni, metódusok, műveletek, funkciók).

Azt mondhatjuk, hogy az osztály egy tervrajz, amely leírja valaminek a természetét. Például, egy Autó osztálynak tartalmazni kell az autók közös jellemzőit (gyártó, motor, fékrendszer, maximális terhelés stb.), valamint a fékezés, a balra fordulás stb. képességeket (viselkedés).

Osztályok önmagukban biztosítják a modularitást és a strukturáltságot az objektum-orientált számítógépes programok számára. Az osztálynak értelmezhetőnek kell lennie a probléma területén jártas, nem programozó emberek számára is, vagyis az osztály jellemzőinek „beszédesnek” kell lenniük. Az osztály kódjának viszonylag önállónak kell lennie (egysébezárás – encapsulation). Az osztály beépített tulajdonságait és metódusait egyaránt az osztály tagjainak nevezzük (C++-ban adattag, tagfüggvény).


#### Objektum (_object_)


Az osztály az objektum mintája. Az Autó osztály segítségével minden lehetséges autó típust megadhatunk, a tulajdonságok és a viselkedési formák felsorolásával. 


#### Példány (_instance_)


Az objektum szinonimájaként az osztály egy adott példányáról is szokás beszélni. A példány alatt a futásidőben létrejövő aktuális objektumot értjük. Így elmondhatjuk, hogy az énAutóm az Autó osztály egy példánya. Az aktuális objektum tulajdonságértékeinek halmazát az objektum állapotának (_state_) nevezzük. Ezáltal minden objektumot az osztályban definiált állapot és viselkedés jellemez.


#### Metódus (_method_)


A metódusok felelősek az objektumok képességeiért. Mivel az énAutóm egy Autó, rendelkezik a fékezés képességével, így a Fékez() ez énAutóm metódusainak egyike. Természetesen további metódusai is lehetnek. A programon belül egy metódus használata általában csak egy adott objektumra van hatással. Bár minden autó tud fékezni, a Fékez() metódus hívásával csak egy adott járművet szeretnénk lassítani. C++ nyelven a metódus szó helyett a tagfüggvény kifejezést használjuk.


### Alapvető elvek


#### Adatrejtés, egységbe zárás - data hiding, encapsulation


A fentiekben láttuk, hogy az osztályok alapvetően állapotokból és metódusokból  épülnek fel. Azonban az objektumok állapotát és viselkedését két csoportba osztjuk. Lehetnek olyan jellemzők és metódusok, melyeket elfedünk más objektumok elől, mintegy belső, privát (_private_) vagy védett (_protected_) állapotot és viselkedést létrehozva. Másokat azonban nyilvánossá (_public_) teszünk. Az OOP alapelveinek megfelelően az állapotjellemzőket privát eléréssel kell megadnunk, míg a metódusok többsége nyilvános lehet. Szükség esetén a privát jellemzők ellenőrzött elérésére nyilvános metódusokat készíthetünk.

Általában is elmondhatjuk, hogy egy objektum belső világának ismeretére nincs szüksége annak az objektumnak, amelyik használja. Például, az Autó rendelkezik a Fékez() metódussal, amely pontosan definiálja, miként megy végbe a fékezés. Az énAutóm vezetőjének azonban nem kell ismernie, hogyan is fékez a kocsi.

Minden objektum egy jól meghatározott interfészt biztosít a külvilág számára, amely megadja, hogy kívülről mi érhető el az objektumból. Az interfész rögzítésével az objektumot használó, ügyfél alkalmazások számára semmilyen problémát sem jelent az osztály belső világának jövőbeli megváltoztatása.


#### Öröklődés - inheritance


Öröklés során egy osztály specializált változatait hozzuk létre, amelyek öröklik a szülőosztály (alaposztály) jellemzőit és viselkedését, majd pedig sajátként használják azokat. Az így keletkező osztályokat szokás alosztályoknak (_subclass_), vagy származtatott (_derived_) osztályoknak hívni.

Például, az Autó osztályból származtathatjuk a Ferrari és a Mercedes alosztályokat. Az énAutóm ezentúl legyen a Mercedes osztály példánya! Tegyük fel továbbá, hogy az Autó osztály definiálja a Fékez() metódust és az fékrendszer tulajdonságot! Minden ebből származtatott osztály örökli ezeket a tagokat, így a programozónak csak egyszer kell megírnia a hozzájuk tartozó kódot. Az alosztályok meg is változtathatják az öröklött tulajdonságokat. A származtatott osztályokat új tagokkal is bővíthetjük.

Az öröklés valójában „egy” (__is-a__) kapcsolat.

A többszörös öröklés (_multiple inheritance_) folyamán a származtatott osztály, több közvetlen ősosztály tagjait örökli. Például, egymástól teljesen független osztályokat definiálhatunk Autó és Hajó néven. Ezekből pedig örökléssel létrehozhatunk egy Kétéltű osztályt, amely egyaránt rendelkezik a teherautók és hajók jellemzőivel és viselkedésével. A legtöbb programozási nyelv (Java, C#) csak az egyszeres öröklést támogatja, azonban a C++-ban mindkét módszer alkalmazható.


#### Polimorfizmus - polymorphism


A polimorfizmus lehetővé teszi, hogy az öröklés során bizonyos (elavult) viselkedési formákat (metódusokat) a származtatott osztályban új tartalommal valósítsunk meg, és az új, lecserélt metódusokat a szülő osztály tagjaiként kezeljük.

Példaként tegyük fel, hogy az Autó és a Kerékpár osztályok öröklik a Jármű osztály Gyorsít() metódusát. A Teherautó esetén a Gyorsít() parancs a GáztAd() műveletet jelenti, míg Kerékpár esetén a Pedáloz() metódus hívását. Ahhoz, hogy a gyorsítás helyesen működjön, a származtatott osztályok Gyorsít() metódusával felül kell bírálnunk (_override_) a Jármű osztálytól örökölt Gyorsít() metódust. Ez a felülbíráló polimorfizmus.

A legtöbb OOP nyelv a parametrikus polimorfizmust is támogatja, ahol a metódusokat típusoktól független módon, mintegy mintaként készítjük el a fordító számára. A C++ nyelven sablonok (templates) készítésével alkalmazhatjuk ezt a lehetőséget.


## Struktúrák (```struct```)


A C++ nyelven a struktúra (```struct```) típus több tetszőleges típusú (kivéve ```void``` és a függvénytípus) adatelem együttese. Ezek az adatelemek, melyek szokásos elnevezése __struktúraelem__ vagy __adattag__ (_data member_), csak a struktúrán belül érvényes nevekkel rendelkeznek. (A más nyelveken a mező (field) elnevezést alkalmazzák, mely elnevezést azonban a bitstruktúrákhoz kapcsolja a C++ nyelv.)
Struktúrák záró kapcsos zárójele után mindig kell pontosvesszőt rakni (```;```).

Alapértelmezett módon a struktúrák adattagjai és metódusai publikusak a külvilág számára és a pont operátor (```.```) segítségével hivatkozhatunk rájuk a struktúrából létrehozott objektumpéldány nevén keresztül.


### C stílusú struktúrák

```cpp

typedef struct
{
  const char* name;
  int age;
  double salary;
} Person;

int main()
{
  Person person; // objektumpéldány létrehozása

  // adattagok inicializálása
  person.name = "Jack";
  person.age = 26;
  person.salary = 1500.50;
}
```

### C++ stílusú struktúrák

```cpp

struct Person
{
  std::string name;
  int age;
  double salary;
};

int main()
{
  Person person; // objektumpéldány létrehozása

  // adattagok inicializálása
  person.name = "Jack";
  person.age = 26;
  person.salary = 1500.50;
}
```

Mivel a struktúráknak tetszőleges adattagjaik lehetnek, így lehetőségünk van több struktúra egymásba ágyazására.

__Feladat__: láncolt listák

A következőkben egy láncolt listát fogunk implementálni, amely jól mutatja majd a dinamikus memóriakezelés veszélyeit.

A láncolt lista nevéből eredendően nem tömbszerűen (egymás melletti memóriacímeken) tárolja az objektumokat, hanem egymástól független memóriacímeken. Ezt úgy oldja meg, hogy minden adathoz rendel egy mutatót is, mellyel a következő listalemet lehet elérni. A lista utolsó elemében a mutató a rákövetkező elem memóriacíme helyett ```nullpointer``` értéket vesz fel.

![linkedList](img/linkedList.png)

```cpp
struct List
{
  int data;
  List* next;
};

int main()
{
  List* head = new List;
  head->data = 9; // (*head.)data == head->data
  head->next = new List;

  head->next->data = 16;
  head->next->next = new List;
  head->next->next->data = 4;
  head->next->next->next = NULL; // modern C++-ban nullptr
  
  delete head;
  delete head->next;
  delete head->next->next;
}
```

Mondhatnánk, hogy készen is vagyunk, implementáltuk a láncolt listát - noha a használata nem túl kényelmes. Sajnos azonban ez a program hibás. A törlés sorrendje rossz: először töröljük a fejelemet (mely az első elemre mutat), viszont az első elem segítségével tudnánk a többi elemet elérni, így mikor a második listaelemet törölnénk, ```head``` már egy felszabadított memóriaterületre mutat. Ezt törlés utáni használatnak (_use after delete_ vagy _use after free_) szokás nevezni és nem definiált viselkedés. A helyes megoldás:

```cpp
int main()
{
  // ...
  delete head->next->next;
  delete head->next;
  delete head;
}
```

__Fontos__: a heap-en arra is figyelnünk kell, hogy jó sorrendben szabadítsuk fel a memóriát. Ha rossz sorrendben szabadítjuk fel az objektumokat, könnyen a fentihez hasonló hibát vagy memória szivárgást okozhatunk.

Ez a "láncolt lista” eddig elég szegényesen néz ki. A fő gond az, hogy nagyon sokat kell írni a használatához. Ezzel megszegjük a __DRY__ programozás elvét: __Don't Repeat Yourself__. Itt sokszor írjuk le közel ugyanazt a kifejezést. Erre találnunk kell egy egyszerűbb megoldást. Írjunk egy függvényt, melynek segítségével új listaelemet hozhatunk létre.

```cpp
List* add(List* head, int data)
{
  if (head == 0)
  {
    List *ret = new List;
    ret->data = data;
    ret->next = 0;
    return ret;
  }

  head->next = add(head->next, data);
  return head;
}
```

Ez egy olyan rekurzív függvény, mely addig hívja saját magát, míg a paraméterként kapott lista végére nem ér (azaz a head egy nullpointer). Amikor oda elér, létrehoz egy új listaelemet és azt visszaadja. A rekurzió felszálló ágában a lista megfelelő elemeit összekapcsolja.


Írjunk egy újabb függvényt, amely segítségével lehetőségünk lesz felszabadítani a lista által birtokolt memóriát.

```cpp
void free(List* head)
{
  if (head == 0)
  {
    return;
  } 

  free(head->next); 
  delete head;
}
```

Itt a rekurzió szintén a lista végéig megy. A rekurzió felszálló ágában történik a listaelemek felszabadítása. Ennek az oka, hogy a felszabadítás a megfelelő sorrendben történjen meg.

__Megjegyzés__: a rekurzív függvények nem olyan hatékonyak, mint az iteratív (pl. ```for``` vagy ```while``` ciklus) társaik. Továbbá a sok függvényhívás könnyen stack overflow-hoz vezetnek. Egy rekurzív függvényt mindig át lehet írni iteratívvá.

Beszéljünk arról, mennyi a teher a felhasználón. Eddig tudnia kellett, milyen sorrendben kell felszabadítani az elemeket a listán belül, de most már elég arra figylenie, hogy a lista használata után meghívja a ```free()``` függvényt. A felhasználó így kisebb eséllyel követ el hibát. __Legyenek a függvényeink és osztályaink olyanok, hogy könnyű legyen őket jól használni, és nehéz legyen rosszul.__


## Osztályok (```class```)


C++ nyelvben speciális típusok, az osztályok szolgálnak arra, hogy az adatokat és a hozzájuk rendelt függvényeket egy egységként, egy objektumként kezeljük.

A C++ nyelvben a ```class``` típus a C nyelv struktúratípusának kiterjesztése. Mindkét struktúra tartalmazhat adatmezőket (adattag – data members), azonban a C++-ban ezen adattagokhoz különféle műveleteket, ún. tagfüggvényeket (member function) is megadhatunk. A C++-ban egy osztály típusú tárolási egység függvényeket kombinál adatokkal, és az így létrejött kombinációt elrejtjük, elzárjuk a külvilág elől. Ezt értjük egységbezárás alatt. Egy osztály deklarációja sokban hasonlít a jól ismert struktúra deklarációjához.

__Megjegyzés__: lehetőségünk van készíteni ún. __inline class__-okat. Inline class-nak nevezzük azt, amikor egy osztály definícióját egy másik osztályban vagy függvényben írjuk meg.

```cpp
class ClassName
{
  // members
public:
  // methods
};
```

A hagyományos C-s struktúrák (```struct```) és a C++ osztályok (```class```) között a fő különbség a tagokhoz való hozzáférésben keresendő. A C-ben egy struktúra adattagja (megfelelő érvényességi tartományon belül) szabadon elérhetők, míg C++-ban egy ```struct``` vagy ```class``` minden egyes tagjához való hozzáférés önállóan kézben tartható azáltal, hogy __nyilvánosnak__ (```public```), __privátnak__ (```private```) vagy __védettnek__ (```protected```) deklaráljuk. Ezeket nevezzük hozzáférési azonosítóknak (__access specifiers__).

A ```class``` kulcsszóval definiált osztályban az adatmezők alapértelmezés szerint __privát__ hozzáférésűek, míg egy ```struct``` esetén __publikus__-ak.


### Konstruktor (_constructor_, _ctor_)


A C++ programokban az objektumok inicializálását speciális tagfüggvények, a konstruktorok végzik. A konstruktor neve azonos az osztályéval, nincs visszatérési értéke, még ```void``` se. Feladata a dinamikus adattagok létrehozása és az adattagok kezdőértékkel való inicializálása. 

4 féle konstruktor típust különböztetünk meg:

* __paraméter nélküli__, __alapértelmezett__ (_default_) konstruktor törzsében az adattagoknak kezdő értéket adunk.
```cpp
class MyClass
{
public:
  MyClass() { _x = 1; _y = 1; }
private:
  int _x;
  int _y;
};
```

* __paraméteres konstruktornak__ az a feladata, hogy azoknak az adattagoknak adjon értéket, amelyek a feladat végrehajtásához szükségesek. Ehhez megfelelő darabszámú és típusú paraméter listát kell kialakítanunk.
```cpp
class MyClass
{
public:
  MyClass(int x, int y) { this->x = x; this->y = y; }
private:
  int x;
  int y;
};
```

__Megjegyzés__: ha a bemeneti paraméternek és az osztály adattagjának ugyan az a neve, akkor a ```this``` kulcsszóval hivatkozhatunk az adattagra, ellenkező esetben a bemeneti paraméter értékét fogjuk saját magának értékül adni.

* __másoló konstruktor__ (_copy constructor_) használatával egy objektumpéldánynak kezdőrétéket adhatunk egy már létező és inicializált objektumpéldánnyal. 
```cpp
class MyClass
{
public:
  MyClass(const MyClass& rhs_) { _x = rhs_._x; _y = rhs_._y; }
private:
  int _x;
  int _y;
};
```

* __move konstruktor__ (C++ 11 óta)
```cpp
class MyClass
{
public:
  MyClass (int&& x_) { _x(std::move(x_)); }
private:
  int _x;
};
```

Az osztálynak több konstruktora is lehet, és mindig az argumentumlista alapján dől el, hogy melyik változatot kell meghívni. Ha mi magunk nem definiálunk konstruktort akkor a C++ fordító biztosít egy alapértelmezett és egy másoló konstruktort. Ha valamilyen saját konstruktort készítünk, ahhoz az alapértelmezett konstruktort is definiálnunk kell, amennyiben szükségünk van rá.

__Fontos__: konstruktor nem lehet virtuális, de lehet privát.


### Implicit és explicit konstruktor


```explicit``` kulcsszó azt mondja ki, hogy a konstruktor explicit, ami azt jelenti, hogy nem használható implicit átalakítás és másolás inicilalizáció (copy-initialization).

```cpp
class A
{
public:
  A(int) { }
  A(int, int) { }
};

class B
{
public :
  explicit B(int) { }
  explicit B(int, int) { }
};

int main()
{
  A a1 = 1; // OK, copy-initialization A::A(int)
  A a2(2); // OK, direct-initialization A::A(int)
  A a3{4, 5}; // OK, direct-list-initialization A::A(int, int)
  A a4 = {4, 5}; // OK, copy-list-initialization A::A(int, int)
  A a5 = (A)1; // OK, explicit cast

  B b1 = 1; // Error, copy-initialization figyelmen kívül hagyja a B::B(int)
  
  B b2(2); // OK, direct-initialization B::B(int)
  B b3{4, 5}; // OK, direct-list-initialization B::B(int, int)
  B b4 = {4, 5}; // Error, copy-list-initialization nem veszi figyelembe B::B(int, int)
  B b5 = (B)1; // OK, explicit cast
}
```


### Adattag inicializációs lista - Member initializer list


Segítségével elkerülhető az alapértelmezett konstruktor felesleges hívása. Tekintsük az alábbi példát:

```cpp
class A
{
public:
  A() { x = 0; }
  A(int x_) { x = x_; }
  int x;
};

class B
{
public:
  B() { _a.x = 3; }
private:
  A _a;
};
```

Ebben az esetben a ```B``` osztály konstruktora először az ```A``` osztály alapértelmezett konstruktorát fogja meghívni, és utána állítja be az ```a.x``` értékét 3-ra. Egy jobb megoldás, ha a ```B``` osztály direktben meghívja az ```A``` osztály konstruktorát egy inicializációs listában.

```cpp
B() : a(3) { }
```

Ebben az esetben az ```A```-nak már csak az ```int``` paraméteres konstruktorát fogja meghívni. Megspórolunk egy felesleges konstruktor hívást, ami abban az esetben nagy előny, ha pl. az ```A``` osztály alapértelmezett konstruktorában még egy dinamikus memóriafoglalás is lenne.

További előnyei, ha konstans adattagoknak vagy referenciáknak szeretnénk értéket adni.

```cpp
class A
{
public:
  A(int x_, int y_) { _x = x_;  _y = y_; }
private:
  const int _x;
  int& _y;
};

int main()
{
  int i = 1;
  int j = 2;
  A(i, j);
}
```

> kimenet:
>
> error: uninitialized const member in ‘const int’
>
> error: uninitialized reference member in ‘int&’
>
> error: assignment of read-only member ‘A::_x’

Láthatjuk, hogy így több hibát is kapunk, miszerint nem inicializálzunk egy konstans változót, egy referenciát és írni próbálunk egy read-only értéket. Írjuk meg helyesen ezt a programot.

```cpp
class A
{
public:
  A(int x_, int y_) :
    _x{x_},
    _y{y_}
  { }
private:
  const int _x;
  int& _y;
};

int main()
{
  int i = 1;
  int j = 2;
  A(i, j);
}
```

Ez a program lefordul és le is fut helyesen.

__Fontos__: konstans adattagoknak és referencia változónak csak így tudunk értéket adni.

A változók kiértékelése mindig a deklarálásuk sorrendjében történik. Inicializációs listában törekedjünk arra, hogy az osztály adattagjaival ne inicializáljunk másik adattagokat, mert ha nem figyelünk eléggé, akkor az adattag amivel inicializálni szeretnénk még lehet, hogy nem kapott kezdőértéket. Ez pedig nem definiált viselkedés.

```cpp
class A
{
public:
  A(int x_,) :
    _y(_z), _x(x_), _z(1) 
  { }
private:
  int _x, _y, _z;
}
```


### Másoló konstruktor (_copy constructor_, _cctor_)


A fordító alapértelmezetten sok kódot generál az osztályokba, struktúrákba. Konstruktoron és destruktoron kívül még másoló konstruktort is. 

A másoló konstruktor egy olyan konstruktor, melynek egyetlen paramétere egy, az osztállyal azonos típusú objektum. Ez alapértelmezetten minden adattagot lemásol az adott adattag másoló konstruktora segítségével. Primitív típusoknál ez bitről bitre való másolást jelent. Azonban, ha az osztályunk dinamikusan létrehozott adattagokat is tartalmaz a fordító által generált másoló konstruktor már nem fogja tudni rendesen elvégezni a feladatát. Ugyanis nem fogja dinamikusan létrehozni az új változót csak egy mutatót, ami az eredeti objektum dinamikus változójára fog mutatni. Ennek pedig az a következménye, hogy az egyik objektumból képesek leszünk egy másik objektum privát adattagját módosítani, továbbá, ha az egyik osztálynak lefut a destruktora, ami felszabadítja a dinamikus változó által foglalt tárhelyet, amikor a következő osztály destruktora is lefut szintén megpróbál felszabadítani egy már felszabadított tárhelyet, ami nem definiált viselkedéshez vezet. 

Ez azért van mert a fordító által létrehozott másoló konstruktor csak egy úgynevezett __sekély másolatot__ (_shallow copy_) fog készíteni, azaz a dinamikus foglalású változóknak nem az értéke csak a hivatkozása lesz lemásolva. Az ilyen esetek elkerülése érdekében saját másoló konstruktor írása szükséges, ami __mély másolatot__ (_deep copy_) készít.

__Fontos__: a másoló konstruktor NEM értékadó operátor!

```cpp
class A
{
public:
  A() : _i(new int(1)) { }
  A(int i_) : _i(new int(i_)) { }
  ~A() { delete _i; }
private:
  int* _i;
};

int main()
{
  A a1(1);
  A a2(a1); // másoló konstruktor hívása
}
```

> kimenet: Error: double free or corruption

Itt egy sekély másolat fog készülni, ami azt jelenti, hogy a dinamikusan lefoglalt adattagok nem fognak újra létrejönni, hanem hivatkozni fognak az eredeti változóra, és amikor az ```a2```-nek lefut a destruktora törölni fogja a dinamikusan lefoglat értéket, ezért amikor az ```a1``` destruktora fog lefutni már egy nem létező változó értékét akarja majd törölni, ami nem definiált viselkedés. Írjunk hát saját másoló konstrukort.

```cpp
class A
{
public:
  A() : _i(new int(1)) { }
  A(int i_) : _i(new int(i_)) { }
  ~A() { delete _i; }

  A(const A& rhs_) { _i = new int(*rhs_._i); }
private:
  int* _i;
};

int main()
{
  A a1(1);
  A a2(a1); // másoló konstruktor hívása
}
```


### Az értékadó operátor (_assignmet operator_)


Hasonló a helyzet, mint a másoló konstruktor esetében, az alapértelmezetten létrehozott értékadó operátor is meghívja az egyes tagok értékadó operátorait, amik a primitív típusok esetén bitről bitre másolnak. Dinamikus típusok másolásához szükség van saját értékadó operátor írására. Az értékadó operátornak azonban van visszatérési értéke, mégpedig egy osztály típusú referencia, ami a többszörös értékadás miatt szükséges.


Tekintsük az előző programot, de a ```main()```-t módosítsuk kicsit.

```cpp
class A
{
public:
  A() : _i(new int(1)) { }
  A(int i_) : _i(new int(i_)) { }
  ~A() { delete _i; }

  A(const A& rhs_) { _i = new int(*rhs_._i); }
private:
  int* _i;
};

int main()
{
  A a1(1);
  A a2;
  a2 = a1; // értékadó operátor hívása
}
```

> kimenet: Error: double free or corruption

Hasonló a helyzet, mint a másoló konstruktor esetében, ezért hát írjunk saját értékadó operátort.

```cpp
class A
{
public:
  A() : _i(new int(1)) { }
  A(int i_) : _i(new int(i_)) { }
  ~A() { delete _i; }

  A(const A& rhs_) { _i = new int(*rhs_._i); }

  A& operator=(const A& rhs_)
  {
    // régi memória felszabadítása
    delete _i;

    // ellenőrzés, hogy nem önértékadást csináltunk-e
    if (this != &rhs_)
    {
      _i = new int(*rhs_._i); }
    }
    return *this;
  }
private:
  int* _i;
};

int main()
{
  A a1(1);
  A a2;
  a2 = a1; // értékadó operátor hívása
}
```

Gyakori hiba, hogy összekeverik a másoló konstruktor hívást az értékadó operátor hívásával.

```cpp
int main()
{
  A a1;
  A a2(a1); //cctor
  A a3 = a2; // cctor
  A a4;
  a4 = a3; // értékadó operátor
}
```

Látható, hogy ha az értékadó operátort szeretnénk meghívi előbb létre kell hozni az objektum példányt, majd egy új sorban értékül adni neki egy már létező objektumpéldány értékeit.


### Destruktor (_destructor_, _dtor_)


Gyakran előfordul, hogy egy objektum létrehozása során dinamikus erőforrásokat is (memória, állomány stb.) lefoglalunk, amelyeket az objektum megszűnésekor fel kell szabadítanunk. Ellenkező esetben ezek az erőforrások elvesznek a programunk számára.

A C++ nyelv biztosít egy speciális tagfüggvényt – a __destruktort__ – amelyben gondoskodhatunk a lefoglalt erőforrások felszabadításáról. A destruktor nevét a hullám karakterrel (```~```) egybeépített osztály névként kell megadni. A destruktor a konstruktorhoz hasonlóan nem rendelkezik visszatérési típussal, nincsenek paraméterei, csak egy lehet belőle az osztályon belül. Ha magunk nem definiálunk destruktort, akkor a fordító a saját alapértelmezése szerinti változatot használja. 

```cpp
class A
{
public:
  A() { };  // konstruktor
  ~A() { }; // destruktor
};
```

__Fontos__: destruktor lehet virtuális, de nem lehet privát.

Minden tagfüggvény, még a paraméter nélküliek is rendelkeznek egy nem látható (implicit) paraméterrel: ```this```, amelyben a hívás során az aktuális objektumpéldányra mutató mutatót ad át a C++, és minden adattag hivatkozás automatikusan ```this->dataMember``` kifejezésként kerül a kódba.


### Vexing parse


A __vexing parse__ a szintaktikai félreérthetőség speciális formája a C++ programozási nyelnek. Ez akkor történik, amikor véletlenül függvénydeklarációt csinálunk függvény definíció helyett a default konstruktornál.

Tekintsük az alábbi programot:

```cpp
class A()
{
public:
  A() { }
}

int main()
{
  A a();
}
```

Jelen esetben nem konstruktorhívást végzünk, hanem egy függvény deklarációt csinálunk. Az ```A a();``` sor egy ```a``` nevű, bemeneti paraméternélküli, ```A``` visszatérési típusú függvény lesz.


### __RAII (Resource Acquisition is Initialization)__

Ha olyan struktúrát, osztályt írtunk, amely gondoskodik arról, hogy minden dinamikusan lefoglalt területet felszabadít, mindent csak egyszer töröl, azt is jó sorrendben, akkor egy RAII struktúrát vagy osztályt írtunk. Ennek lényege, hogy az adott osztály a megfelelő erőforrásokat lefoglalja magának, majd a destruktor gondoskodik az erőforrások felszabadításáról. Minden erőforrást egy stack-en lévő objektumhoz kötünk, mivel azok garantáltan automatikusan fel fognak szabadulni, azaz destruktoruk le fog futni.

Bjarne Stroustrup híres mondása, hogy a C++ szemétgyűjtéssel rendelkező nyelv, mert nem generál szemetet.


### ```const``` kulcsszó metódusok esetében


Korábban már láthattuk a ```const``` kulcsszó kettő lehetséges felhasználási módját függvények esetében.

* konstans visszatérési érték. Ebben az esetben a visszatérési értéken nem tudunk változtatni.

```cpp
const std::string& f() { };
```

* konstans bemeneti paraméter. Ebben az esetben a bemeneti paraméter értéke nem módosulhat a függvényen belül.

```cpp
void f(const std::string& i_) { }
```

Harmadik eset pedig amikor a metódust definiáljuk konstansnak

```cpp
void f() const { }
```

Ez annyit jelent, hogy az ```f()``` függvényen belül az osztály adattagjainak értéke nem változhat meg. Továbbá fontos megjegyezni, hogy ha konstans objektumpéldányt hozunk létre, akkor annak csak konstans metódusait tudjuk elérni, ellenkező esetben módosítani tudnánk az adattagjait egy konstans objektumpéldánynak és így megsértenénk a konstans korrektséget. Továbbá konstans objektumpéldányok létrehozás esetében mindig kell, hogy legyen legalább egy, a felhasználó által definiált konstruktor.

```cpp
class MyClass
{
public:
  A() { _counter = 0; }
  int getCounter() const { std::cout << 1; }
  int getCounter() { std::cout << 2; }
private:
  int _counter;
};

int main()
{
  const MyClass mc;
  mc.getCounter();
  
  MyClass mc2;
  mc2.getCounter();
}
```

> kimenet: 11

Ilyen esetekben a fordító mindig a konstans metódust fogja választani.


### ```friend``` mechanizmus


A friend mehcanizmus lehetővé teszi, hogy az osztály ```private``` és ```protected``` tagjait nem saját tagfüggvényből is elérjük. A friend deklarációt az osztályon belül kell elhelyezni tetszőleges elérésű részben. "barát" lehet egy külső függvény, egy mási osztály adott tagfüggvénye, de akár egy egész osztály is (vagyis annak minden tagfüggvénye).

```cpp
class MyClass
{
public:
  friend int getCounter(const MyClass&);
  // friend int getCounter() const; -> hiba, non-member function cannot have a const qualifier.
private:
  int _counter;
};

int getCounter(const MyClass& mc_) { return mc_._counter; }

int main()
{
  MyClass mc;
  getCounter(mc)
}
```


### ```inline``` tagfüggvények


Az ```inline``` megoldás nagy előnye, hogy a teljes osztályt egyetlen fejállományban tárolhatjuk, és az osztály tagjait könnyen át tekinthetjük. Általában kisebb méretű függvények esetén alkalmazható hatékonyan. Ilyenkor nem függvényhívás történik, hanem magának a függvénynek a kódja beillesztésre kerül a hívások helyein. Nagyobb méretű kód: a függvény törzse több helyen szerepel, több optimalizálási lehetőség miatt azonban lehet mégis rövidebb. Megspórolja a függvényhívás idejét. Rekurzív függvények esetében nem használható, mert a fordító nem fogja tudni hányszor ágyazza egymásba az inline-olt kódot. Megadhatjuk explicit módon az ```inline``` kulcsszó segítségével vagy akár implicit módon is.

```cpp
class MyClass
{
public:
  int getNumberI() const { return _i; } // implicit inline
  inline int getNumberJ() const { return _j; } // explicit inline
  // int inline és inline int között a fordító nem tesz különbséget
private:
  int _i;
  int _j;
};
```

Tekintsük azt a példát, amikor a ```void f() {}``` függvényt is beillesztjük a headerbe: ha több fordítási egységet fordítanánk egyszerre, melyben ez a header be van illesztve, linkelési hibát kapnánk, mert ```f()``` többször lesz definiálva. Ez azonban megkerülhető az inline kulcsszó használatával, segítségével ugyanis kiküszöbölhető a linkelési hiba: minden azonos nevű, visszatérési értékű, és paraméter listájú inline-ként definiált függvény definícióval együtt beilleszthető több különböző fordítási egységbe, és nem fog fordítási hibát okozni.

Ez úgy oldható meg, hogy a fordító a linkelés folyamán a definíciók közül egyet tetszőlegesen kivá- laszt. Az osztályon belül kifejtett függvények implicit inline-ok, így sose okozhatnak fordítási hibát.

![inlineProblem](img/inlineProblem.png)

Az fent látható ábra jól demonstrálja a problémát. ```f()``` egy ún. __strong reference__-el jön létre ha nem inline, így a linker hibát dob ha több fordítási egységben definiálva van. Ha azonban inline-ként adjuk meg, akkor __weak reference__-ként értelmezi, a meglevő definíciók közül tetszőlegesen kerül egy kiválasztásra. Ez nyilván azt is jelenti, hogy minden ilyen függvény definíciójának meg kell egyeznie, hisz kellemetlen meglepetés érhet minket, ha különböző definíciók közül olyat választ a fordító, melyre nem számítanánk (és ez egyben nem definiált viselkedés is).

__Megjegyzés__: a legtöbb fordítónál be lehet kapcsolni egy ún. __LTO__ (_link time optimalization_) funkciót, amely a linkelésnél optimalizál, többek között ott végzi az inline-olást. Az inline függvények hajlamosak erősen megnövelni a bináris kódot, így az erőltetett használatuk nem javasolt. Az inline kulcsszó egy javaslat a fordító számára nem pedig parancs. Nem inline függvények lehetnek inline-ok, és inline-ként definiált függvények lehet mégsem lesznek azok.


## ```static``` az  osztályon belül


C++-ban az osztályszintű változókat és függvényeket a ```static``` prefixel kell ellátni. Ezek nem fognak létrejönni minden egyes objektum példánynál, mint az adattagok, hanem csak egyszer. Statikus adattagok kezdőértékkel való inicilizálása csak az osztályon kívül megengedett, kivétel az az eset, amikor konstans statikus adattagokról van szó. Ebben az esetben az osztályon belül tudunk nekik kezdőértéket adni. __Konstruktor és destruktor SOHA nem lehet statikus__.

Nem statikus metódusokból elérhetőek statikus és nem statikus adatagok is. Statikus metódosukból csak statikus adattagokra tudunk hivatkozni. Ennek oka, hogy ezek már fordítási időben létrejönnek, míg a nem statikus adattagok csak akkor, amikor példányosítjuk az osztályt. 

```cpp
class MyClass
{
public:
  int f() { return _i; } // helyes
  static int g() { return _k; } // hibás -> a return k; az implicit return this->k;
                                // hívásnak felelne meg, ám az osztályszintű metódus
                                // esetében nincs értelmezve a this mutató, hiszen
                                // nincs objektum, amin értelmezhetnénk. Statikus metódus
                                // eléréséhez használjuk az osztály neévt és a scope 
                                // operátort. MyClass::g()
private:
  int _k;
  static int _i; // osztályon kívül kell inicializálni
  const static int _j = 0; // lehet osztályon belül inicializálni, mert konstans
};

int A::_i = 0; // _i változó osztályon kívüli inicializálása
```


## Öröklődésről bővebben


Mint azt már láthattuk a problémák objektum orientált feldolgozása során használatos az öröklődés. Lehetővé teszi, hogy már egy létező osztály vagy osztályok adatait és műveleteit új megközelítésben alkalmazzuk, illetve a feladat igényeinek megfelelően módosítsuk, bővítsük. Így nem egyetlen (nagy) osztállyal, hanem osztályok egymásra épülő rendszerével oldjuk meg a problémákat.

Az öröklődés az OO C++ nyelv egyik legfőbb sajátossága. Az öröklés során az új osztály örökli a meglévő osztály(ok) nyilványos (_public_) és védett (_protected_) adattagjait és tagfüggfényeit, amelyeket aztán annak sajátjaként használhatunk. Az új osztállyal bővíthetjük is a meglévő osztály(oka)t, új adattagokat és tagfüggvényeket definiálhatunk, illetve újra értelmezhetjük az örökölt, de működésükben elavult tagfüggvényket. Ez utóbbit nevezzük __override__-olásnak.

```cpp
class Base
{
  // ...
};

class Derived: public Base
{
  // ...
}
```

![singleInheritance](img/inheritanceDiagram.png)

A C++ támogatja a többszörös öröklődést (_multiple inheritance_), mely során valamely új osztály több ősosztályból származik. Ez nem összekeverendő a több osztályon keresztüli örökléssel.

```cpp
class Base1
{
public:
  int a;
};

class Base2
{
public:
  int b;
};

class Derived: public Base1, public Base2
{
public:
  int c;
}
```

![multipleInheritance](img/multipleInheritanceDiagram.png)

Az ábrán a ```Derived``` osztálynak két őse van: ```Base1``` és ```Base2```. Egy osztálynak természetesen kettőnél több őse is lehet. 

Nézzük meg, hogy a leszármazott ```Derived``` osztály objektumai hogyan néznek ki a memóriában.

![multipleInheritanceMemoryMap](img/multipleInheritanceMemoryMap.png)

A ```d``` egy ```Derived``` osztálybeli objektum. Az objektumban először az örökölt tagváltozók foglalnak helyet, mégpedig a ```Derived``` osztály definíciójában megadott ősosztály listában balról jobbra haladva kerülnek be az objektumba: a ```Base1``` osztályból ```a```, majd a ```Base2``` osztályból ```b```. Ezt követik a leszármazott osztály tagváltozói, jelen esetben ```c```.

Többszörös öröklés esetén is érvényes az a szabály, hogy leszármazott osztálybeli objektumra lehet ősosztály típusú mutatóval vagy referenciával hivatkozni. Természetesen itt is igaz, hogy ekkor úgy tekintünk az objektumra, mintha az adott őszosztálybeli lenne, ennek következtében csak az adott ősosztálybeli tagváltozók és tagfüggvények érhetőek el, illetve azok amelyeket az ősosztály örökölt a saját szüleitől. Tekintsük az alábbi kódot:

```cpp
Derived d; //Derived őse Base1 és Base2
Derived* pd = &d;
Base1* pb1 = &d;
Base2* pb2 = &d;

pb1->a = 10;  // OK
pb1->b = 10;  // Fordítási hiba
pb2->a = 10   // Fordítási hiba
pb2->b = 10;  // OK 
```

Bár az ```a``` és ```b``` változók jelen vannak a ```Derived``` osztályban, ettől függetlenül egy ősosztály típusú mutatóval csak azokat tudjuk elérni, melyek az adott ősosztályban is jelen vannak.

![multipleInheritanceMemoryMapPointer](img/multipleInheritanceMemoryMapPointer.png)

A legfontosabb tanulság a következő: __minden mutató a mutató típusának megfelelő rész elejére mutat az objektumban__. Első pillantásra talán kicsit furcsának tűnhet, hogy a ```pb2``` mutató nem az objektum elejére mutat, hiszen ```Base2```-ből örökölt részek nem itt kezdődnek. Ennek fő következménye az, hogy __mutató konverzió esetén a mutató által tartalmazott cím megváltozhat.__

A származtatott osztály olyan osztály, amely adattagjait és függvényeit egy vagy több előzőleg definiált osztálytól örökli. A származtatott osztály szintén lehet alaposztálya további osztályoknak, lehetővé téve ezzel az osztályhierarchia kialakítását.

A származtatott osztály az alaposztály minden tagját örökli, azonban az alaposztályból csak a publikus és a védett tagokat éri el sajátként. A tagfüggvényeket általában publikus vagy védett hozzáféréssel adjuk meg, míg az adattagok esetén a védett vagy privát elérést alkalmazzuk. Öröklés során megadhatjuk a származtatás módját (__public__, __protected,__, __private__).

Az alaposztálybeli elérhetőségüktől függetlenül nem öröklődnek a konstruktorok, destruktorok, az értékadó operátor valamint a _friend_ viszonyok.

![inheritance](img/inheritanceCpp.png)

A publikus származtatás során az örökölt tagok megtartják az alaposztálybeli elérhetőségüket, míg privát származtatás során az örökölt tagok a származtatott osztály privát tagjaivá válnak. Védett öröklés esetén az örökölt tagok védettek lesznek az új osztályban.


## Behelyettesíthetőség


Tekinstük az alábbi programot

```cpp
#include <iostream>

class Person
{
public:
  Person(const std::string& name_, int age_):
    _name(name_),
    _age(age_)
  { }

  void print() { std::cout << _name << _age; }
protected:
  std::string _name;
  int _age;
};

class Employee: public Person
{
public:
  Employee(const std::string& name_, int age_, int employmentYear_):
    Person(name_, age_),
    _employmentYear(employmentYear_)
  { }

  void print() { Person::print(); std::cout << _employmentYear; }
private:
  int _employmentYear;
};

int main()
{
  Person person("Jack", 34);
  Employee employee("John", 28, 3);

  person.print(); // OK, meghívódik a Person::print()
  employee.print(); // OK, meghívódik az Employee::print();
}
```
A fenti példában nincs semmi meglepő. A tagfüggvényekhez objektumváltozókon keresztül férünk hozzá, így a változó típusa meghatároz egy tagfüggvényt, és az hívódik meg.

Mutatók esetén nem mindig ilyen egyértelmű a helyzet. Ilyenkor ugyanis két típus is szerepet játszik:

* a mutató típusa
* mutatott területen található változó típusa

Amikor ez a kettő különbözik, akkor a műveleteket a mutató típusa határozza meg.

Mutassunk rá egy __Employee__ típusú objektumra egy __Person__ típusú mutatóval.

```cpp
Employee employee("John", 28, 3);
Person* pPerson = &employee;
```

Nézzük meg a két típus memóriabeli reprezentációját.

![personEmployeeObjectMemoryModel](img/personEmployeeObjectMemoryModel.png)

Jól látható, hogy az __Employee__ típusú objektum eleje megegyezik egy __Person__ típusú objektummal és a __pPerson__ mutató valóban az __Employee__ objektum __Person__ típusú részére mutat. A mutatón keresztüli hozzáférés szempontjából az __Employee__ osztály kompatibilis a __Person__ osztállyal. Ez általában is igaz: ha egy osztály csak egy osztályból örököl, akkor  mindig kompatibilis az ősosztállyal. Ekkor a __pPerson__ mutatón keresztül minden olyan függvényhez hozzáférünk az __Employee__ osztályban, amik megtalálhatóak a __Person__-ban is. A többihez viszont nincs hozzáférésünk a mutatón keresztül. Ezt nevezzük az objektum ledarabolódásának vagy __object slicing__-nak.

Érdekes kérdés lehet, hogy ebben az esetben a ```print()``` metódus hívása mit eredményez, ha a __pPerson__ mutatón keresztül hívjuk meg. Mivel a műveletet a mutató típusa határozza meg és nem a mutatott memóriaterületen elhelyezkedő objektum típusa, így a ```Person::print()``` függvény fog meghívódni. Ha ehhez hozzávesszük, hogy mindezek nem csak mutatóra, hanem referenciára is igazak, kimondhatjuk a behelyettesíthetőség C++-beli megvalósításának lényegét:

__Egy ősosztály típusú mutatónak mindig értékül adhatunk egy leszármazott típusú mutatót vagy leszármazott típusú objektum címét. Referencia esetén ez azt jelenti, hogy egy ősosztály típusú referenciát inicializálhatunk leszármazott típusú objektummal is. Az ősosztály típusú mutatón, illetve referencián keresztül csak az ősosztálybeli tagváltozók, illetve tagfüggvények érhetőek el.__

Ennek következménye, hogy egy ősosztály típusú mutató esetében mi rejtőzik a mutató mögött. Ősosztály vagy származtatott osztály egy objektuma. Azt a jelenséget, hogy egy ősosztály típusú mutató mutathat bármelyik leszármazott típus példányára is, __polimorfizmusnak__ nevezzük, a mutatót pedig __polimorfnak__.

Ha azt szeretnénk elérni, hogy ha egy ősosztály mutató mögött valamelyik leszármazott található, ne az ősosztály tagfüggvénye hívódjon meg, hanem a leszármazotté, akkor a ```virtual``` kulcsszót kell használnunk, melynek alkalmazásával az egyes tagfüggvények virtuálissá tehetők.

```cpp
class Person
{
public:
  Person(const std::string& name_, int age_):
    _name(name_),
    _age(age_)
  { }

  virtual void print() { std::cout << _name << _age; }
protected:
  std::string _name;
  int _age;
};
```

__A virtuális függvény (_virtual function_) azt jelenti, hogyha:__

* __az ősosztályban virtuálisnak deklarálunk egy tagfüggvényt, és__
* __a leszármazott osztályban létezik egy ugyanolyan nevű, argumentumlistájú és visszatérési értékű függvény, továbbá,__
* __ezt a függvényt egy leszármazott osztályra mutató, ősosztály típusú mutatón/referencián keresztül hívjuk meg,__

__akkor a leszármazottbeli tagfüggvény fog meghívódni.__

A ```virtual``` kulcsszót csak nem statikus tagfüggvényekre alkalmazhatjuk. Ha a leszármazott osztályban írunk egy ugyanolyan nevű, argumentumlistájú és visszatérési értékű függvényt, mint az ősosztály egy virtuális  függvénye, akkor az ősosztály függvényét felülírjuk (__override__).

A leszármazott osztályban jelezni tudjuk, hogy egy ősosztálybeli függvényt írunk felül az ```override``` kulcsszó segítségével. 

```cpp
class Employee: public Person
{
public:
  Employee(const std::string& name_, int age_, int employmentYear_):
    Person(name_, age_),
    _employmentYear(employmentYear_)
  { }

  void print() override { Person::print(); std::cout << _employmentYear; }
private:
  int _employmentYear;
};
```

__Megjegyzés__: az ```override``` kulcsszavat nem muszáj kiírni, viszont, ha kiírjuk figyeljünk oda, hogy csak olyan függvény esetében használhatjuk, amelyet az ősosztályban virtuálisnak jelöltünk.

Abban az esetben, ha az ősosztálybeli függvény annyira általános lenne, hogy nem tudunk neki viselkedést megadni, viszont mégis kell hogy szerepeljen az ősosztályban, érdemes __tisztán virtuális__ (_pure virtual_) függvényként megadni.

```cpp
class Person
{
public:
  Person(const std::string& name_, int age_):
    _name(name_),
    _age(age_)
  { }

  virtual void print() = 0;
protected:
  std::string _name;
  int _age;
};
```

Ilyenkor a függvénytörzs helyett egy ```= 0```-át írunk. Ezzel azt jelezzük a fordítónak, hogy nem kívánunk megadni függvénytörzset csak a leszármazott osztályban. Ha ezek után szeretnénk példányosítani a __Person__ osztályt, és meghívnánk a ```Person::print()``` tagfüggvényt, a fordító bajban lenne, hiszen nem adtunk meg törzset a függvénynek, ezért a __Person__ osztályt nem lehet példányosítani.

A legalább egy tisztán virtuális függvényt tartalmzató osztályt __absztrakt osztálynak__ (_abstract class_) nevezzük. Az absztrakt osztályokat nem lehet példányosítani.

Ha egyszer egy függvényt virtuálisnak deklarálunk, akkor az összes leszármazottbeli osztályban virtuális lesz. A virtuális lánc nem megszakítható!

A csak tisztán virtuális függvényeket tartalmazó osztályt __interfésznek__ (_interface_) nevezzük. Ha örökölünk egy ilyen vagy egy absztrakt osztályból, biztosítanunk kell a fordítót, hogy a tisztán virtuális tagfüggvényekhez működést rendelünk.


## Virtuális destruktor


Tekintsük az alábbi programot:

```cpp
#include <iostream>

class Base
{
public:
  Base() { std::cout << "Base ctor" << '\n'; }
  ~Base() { std::cout << "Base dtor" << '\n'; }
};

class Derived : public Base
{
public:
  Derived() { std::cout << "Derived ctor" << '\n'; }
  ~Derived() { std::cout << "Derived dtor" << '\n'; }
};

int main()
{
  Base* p = new Derived();
  delete p;
}
```

Mi ezzel a probléma?

> kimenet:
>
> Base ctor
>
> Derived ctor
>
> Base dtor

Mint láthatjuk a származtatott osztály destruktora nem hívódott meg, ami abban az esetben, ha dinamikus adattagokat használtunk volna benne memóriaszivárgást jelentene. Erre a problémára nyújt megoldást, ha a destruktort is virtuálissá tesszük.

```cpp
#include <iostream>

class Base
{
public:
  Base() { std::cout << "Base ctor" << '\n'; }
  virtual ~Base() { std::cout << "Base dtor" << '\n'; }
};
```

> kimenet:
>
> Base ctor
>
> Derived ctor
>
> Derived dtor
>
> Base dtor

Ha az alaposztály destruktora virtuális, akkor minden ebből származtatott osztály destruktora is virtuális lesz. Ezáltal biztosak lehetünk abban, hogy a megfelelő destruktor hívódik meg, amikor az objektum megszűnik, még akkor is, ha valamelyik alaposztály típusú mutatóval vagy referenciával hivatkozunk a leszármazott osztály példányára. 


## Virtuális függvények megvalósítása


A nem virtuális függvények esetében az a cím, amelyre a függvény hívásakor ugrani kell, fordítási időben határozódik meg. Egy virtuális függvény mutatón, illetve referencián keresztüli hívásakor azonban az a függvénycím, amelyre ugrani kell, csak futási időben dől el, a fordító nem "égeti be" egyik függvény címét se. A fordítók ilyen esetekben indirekciót használnak. Minden olyan osztály, amelynek van legalább egy virtuális függvénye (akár definiált, akár örökölt), rendelkezik egy táblázattal a virtuális függvények ugrási címeivel. Ezt szokás virtuális ugrótáblának nevezni. A tábla annyi címet tartalmaz, ahány virtuális függvénye az adott osztálynak van.

Az osztály minden objektumának van egy mutatója az osztályának virtuális ugrótáblájához. A mutatóra a __vfptr__ (_virtual function table pointer_) a leggyakrabban alkalmazott jelölés. A mutató minden objektumban ténylegesen jelen van és helyet foglal. Tekintsük az alábbi kódrészletet:

```cpp
class A
{
public:
  virtual void f1() {}
private:
  int _x:
};

int main()
{
  A a1;
  A a2;
}
```

A memóriakép a következő lesz:

![virtualFunctionMemoryModel](img/virtualFunctionMemoryModel.png)

Virtuális függvények öröklődés esetén:

![virtualFunctionMemoryModelMultipleInheritance](img/virtualFunctionMemoryModelMultipleInheritance.png)


## STL - Standard Template Library


### Bevezetés az STL-be


A C++ nyelv Szabványos Sablonkönyvtára (STL) osztály- és függvénysablonokat tartalmaz, amelyekkel elterjedt adatstruktúrákat (vektor, sor, lista stb.) és algoritmusokat (rendezés, keresés, összefésülés stb.) építhetünk be a programunkba.

A sablonos megoldás lehetővé teszi, hogy az adott néven szereplő osztályokat és függvényeket (majdnem) minden típushoz felhasználhatjuk, a program igényeinek megfelelően.

Az STL alapvetően három csoportra épül, a __konténerekre__ (tárolókra), az __algoritmusokra__ és az __iterátorokra__ (bejárókra). Egyszerűen megfogalmazva az algoritmusokat a konténerekben tárolt adatokon hajtjuk végre az iterátorok felhasználásával.

A végrehajtott algoritmus működésének eredményét többféleképpen is megkaphatjuk (konténerben, iterátorként vagy valamilyen egyéb adatként).

![STLStructure](img/STLStructure.png)

A konténerek, az iterátorok és az algoritmusok kiegészítéseként az STL-ben további szabványos elemeket is találunk: helyfoglalókat (_allocators_), adaptereket (_adaptors_), függvényobjektumokat (_function objects – functors_)


### Függvényobjektumok - funktorok (_functors_, _function objects_)


Az STL sok szabványos algoritmust biztosít a programozók számára, amelyek feldolgozzák a konténerekben tárolt adatokat. Az algoritmusok működése függvényobjektumok (function objects, functors) megadásával testre szabható. Ily módon meghatározhatjuk, hogy milyen műveletek hajtódjanak végre a kollekció elemein. A függvényobjektum hagyományos függvénymutató is lehet, azonban az esetek többségében objektumokat alkalmazunk.

A függvényobjektum olyan típus, amely megvalósítja a függvényhívás (```()```) operátorát. Két lényeges előnye van a közönséges függvényekhez képest:

1. megőrizheti a működés állapotát
2. mivel a függvényobjektum egy típus, megadhatjuk sablon paraméterként

Amikor az egyoperandusú (_unáris_) függvényobjektum ```bool``` típusú értéket ad vissza __predikátum__-nak nevezzük. __Bináris predikátum__-ról akkor beszélünk, ha egy kétoperandusú függvényobjektum ad vissza __bool__ típusú értéket, a két paraméter összevetésének eredményeképp.

A C++11-től használt [lambda](#lambda-kifejez%c3%a9sek) kifejezések tulajdonképpen névetlen függvénybjektumok.

A függvényobjektumokkal kapcsolatos STL osztálysablonokat a ```<functional>``` fejállományban találjuk. Egy egyszerű példa a funktorokra:

```cpp
#include <iostream>

struct Add()
{
  int x;
  int operator()(int y) const { return x + y; }
};

int main()
{
  Add a1;
  a1.x = 1;
  std::cout << a1(2) << std::endl;
}
```
> kimenet: 3

A későbbiekben nézni fogunk arra is példát, hogy hogyan lehet funktorok segítségével pl. konténert rendezni.


### Konténerek


A konténerek olyan objektumok, amelyekben más, azonos típusú objektumokat tárolhatunk. A tárolás módja alapján a konténereket három csoportba sorolhatjuk:

1. __szekvenciális__ (_sequence_) tárolóról beszélünk, amikor az elemek sorrendjét a tárolás sorrendje határozza meg.
2. __asszociatív__ (_associative_) konténerek ezzel szemben az adatokat egy kulcssal azonosítva tárolják, melyeket tovább csoportosíthatunk kulcs alapján
   1. __rendezett__ (_ordered_) és
   2. __nem rendezett__ (_unordered_) tárolókra.

A konténerek sokféleképpen különböznek egymástól:
* a memóriahasználat hatékonysága
* a tárolt elemek elérési ideje
* az új elem beszúrásának, illetve valamely elem törlésének időigénye
* új elem konténer elejére, illetve végére történő beillesztésének ideje
* stb


### Szekvenciális tárolók


Jellemzőjük, hogy megőrzik az elemek beviteli sorrendjét, azaz a beszúrás ideje határozza meg az elemek sorrendjét. Az ```array``` kivételével tetszőleges pozícióba beszúrhatunk elemet, illetve törölhetünk onnan. Ezek a műveletek általában a tárolók végein a leggyorsabbak.

[```array```](https://en.cppreference.com/w/cpp/container/array) - a sablonparaméterben megadott konstans elemszámmal létrejövő, egydimenziós tömbök osztálysablonja.

![stdArrayMemoryMap](img/stdArrayMemoryMap.png)

```cpp
#include <array>

int main()
{
  std::array<int, 5> arr1{{1, 2, 3, 4, 5}};
  std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
}
```
___

[```vector```](https://en.cppreference.com/w/cpp/container/vector) - a vektor __dinamikus tömbben__ tárolódik sorfolytonos memóriaterületen, amely a végén növekedhet, viszont azt már tudjuk, hogy egy tömb mérete nem növelhető. Ezt az ```std::vector``` a következő képpen oldja meg: ha több elemet szerenénk beszúrni, mint amennyi az adott vektor kapacitása, akkor lefoglal egy nagyobb memóriaterületet - általában kétszer akkorát - és minden elemet egyesével átmásol erre a memória területre. Ezért a vketor végéhez való elem hozzáadásának műveletigénye amortizált konstans: általában konstans, de ha új memóriaterületet kell lefoglalni és a meglevő elemet átmásolni, akkor lineáris.

Az elemeket indexelve is elérhetjük konstans (_O(1)_) idő alatt. Elemek eltávolítása a (```pop_back()```), illetve hozzáadása (```push_back()```) a vektor végéhez szintén konstans (_O(1)_) idő alatt lehetséges, míg az elején vagy a közepén ezek a műveletek (```insert()```, ```erase()```) lineáris (_O(n)_) végrehajtású idejűek. Rendezetlen vektorban egy elem megkeresésének ideje szintén lineáris (_O(n)_).

![stdVectorMemoryMap](img/stdVectorMemoryMap.png)

```cpp
#include <vector>

int main()
{
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2 = {1, 2, 3};
}
```
___

[```deque```](https://en.cppreference.com/w/cpp/container/deque) - __kettősvégű sor__-t megvalósító adatszerkezet, amely mindkét végén növelhető, egydimenziós tömböket tartalmazó listában tárolódik. Elemeket mindkét végén konstans (_O(1)_) idő alatt adhatunk (```push_front()```, ```push_back()```) a kettősvégű sorhoz, illetve távolíthatunk el onnan (```pop_front()```, ```pop_back()```). Az elemek index segítségével konstans időben (_O(1)_) is elérhetőek.

![stdDequeMemoryMap](img/stdDequeMemoryMap.png)

```cpp
#include <deque>

int main()
{
  std::deque<int> deq1{1, 2, 3, 4, 5};
  std::deque<int> deq2 = {1, 2, 3};
}
```
___

[```forward_list```](https://en.cppreference.com/w/cpp/container/forward_list) (C++11 óta) - __egyszeres láncolású lista__, melyet csak az elején lehet bővíteni. Azonos elemtípus esetén az elemek helyigénye kisebb, mint a kettős láncolású listáé. Az elemek beszúrása (```insert_after()```) és törlése (```erase_after()```) konstans (_O(1)_) időt igényel.

![stdForwardListMemoryMap](img/stdForwardListMemoryMap.png)

```cpp
#include <forward_list>

int main()
{
  std::forward_list<int> myflist1{1, 2, 3};
  std::forward_list<int> myflist2 = {3, 2, 1, 4};
}
```
___

[```list```](https://en.cppreference.com/w/cpp/container/list) - __kettős láncolású lista__, melynek elemei nem érhetőek el az indexelés operátorával. Tetszőleges pozíció esetén a beszúrás (```insert()```) és a törlés (```erase()```) művelete konstans (_O(1)_) idő alatt végezhető el. A lista mindkét végéhez adhatunk elemeket (```push_front()```, ```push_back()```), illetve törölhetünk (```pop_front()```, ```pop_back()```) onnan.

![stdListMemoryMap](img/stdListMemoryMap.png)

```cpp
#include <list>

int main()
{
  std::list<int> mylist1;
  std::list<int> mylist2;

  for (int i = 0; i < 10; ++i)
  {
    mylist1.push_back(i);
    mylist2.push_front(i*2);
  }
}
```

A szekvenciális tárolókra épülő, konténerillesztő osztálysablonok a tároló adapterek. Az alábbi konténer adapterek elemein nem lehet iterátorok segítségével végig lépkedni, ezért semmilyen algortimus hívásakor nem használhatjuk azokat.
___

[```stack```](https://en.cppreference.com/w/cpp/container/stack) - a __last in first out__ (_LIFO_) működésű __verem__ adatszerkezet típusa. A verem csak a legfelső pozícióban lévő elem módosítását (felülírás, kivétel, behelyezés) teszi lehetővé. Alapértelmezés szerint a __deque__ konténerre épül, azonban a __vector__ és a __list__ is használható a megvalósításához.

![stdStackMemoryMap](img/stdStackMemoryMap.png)

```cpp
#include <iostream>
#include <stack>

int main()
{
  std::stack<int> mystack;
  mystack.push(0);
  mystack.push(1);
  mystack.push(2);

  while (!mystack.empty())
  {
    std::cout << mystack.top() << ' ';
    mystack.pop();
  }
}
```

> kimenet: 2 1 0

___

[```queue```](https://en.cppreference.com/w/cpp/container/deque) - __sor__ adatszerkezetet megvalósító típus, amely csak az utolsó pozícióra való beszúrást és az első pozícióról való eltávolítást teszi lehetővé (__first in first out__ _FIFO_). Ezeken túlmenően az első és az utolsó elem lekérdezése és módosítása is megengedett. Az alapértelmezetten a __deque__ mellett  a __list__ szekvenciális tárolóra épülve is elkészíthető.

![stdQueueMemoryMap](img/stdQueueMemoryMap.png)

```cpp
#include <iostream>
#include <queue>

void showq(std::queue<int> myq)
{
  std::queue<int>tmpq = myq;
  while (!tmpq.empty())
  {
    std::cout << tmpq.front() << ' ';
    tmpq.pop();
  }
  std::cout << std::endl;
}

int main()
{
  std::queue<int> myq;
  myq.push(10);
  myq.push(20);
  myq.push(30);

  showq(myq);

  std::cout << "myq.size(): " << myq.size() << std::endl;
  std::cout << "myq.front(): " << myq.front() << std::endl;
  std::cout << "myq.back(): " << myq.back() << std::endl;
  myq.pop();
  showq(myq);
}
```

> kimenet:
>
> 10 20 30
>
> myq.size(): 3
>
> myq.front(): 10
>
> myq.back(): 30
>
> 20 30

___


[```priority_queue```](https://en.cppreference.com/w/cpp/container/priority_queue) - a __prioritásos sorban__ az elemek alapértelmezett módon a ```<``` (kisebb) operátorral hasonlítva, redezetten tárolódnak. A prioritásos sort csak az egyik, legnagyobb elemet tartalmazó végén érjük el. Ez az elem szükség esetén módosítható, vagy kivehető a sorból. Alapértelmezés szerint a __vector__ konténer fölött jön létre, azonban a __deque__ is alkalmazható.

![stdPriorityQueueMemoryMap](img/stdPriorityQueueMemoryMap.png)

```cpp
#include <iostream>
#include <queue>

void showpq(std::priority_queue<int> prQ)
{
  std::priority_queue<int> tmpPrQ = prQ;
  while (!tmpPrQ.empty())
  {
    std::cout << tmpPrQ.top() << ' ';
    tmpPrQ.pop();
  }
  std::cout << std::endl;
}

int main ()
{
  std::priority_queue<int> myPrQ;
  myPrQ.push(10);
  myPrQ.push(30);
  myPrQ.push(20);
  myPrQ.push(5);
  myPrQ.push(1);

  showpq(myPrQ);

  std::cout << "myPrQ.size(): " << myPrQ.size() << std::endl;
  std::cout << "myPrQ.top(): " << myPrQ.top() << std::endl;
  myPrQ.pop();

  showpq(myPrQ);
}
```

> kimenet:
>
> 30 20 10 5 1
>
> myPrQ.size(): 5
>
> myPrQ.top(): 30
>
> 20 10 5 1

__Megjegyzés__: a C++ alapértelmezetten __maximum kupacot__ (tehát egy olyan kupacot, amelyben bármely elem kulcsa nagyobb vagy egyeblő, mint a gyerekeinek kulcsa) hoz létre a prioritásos sornak.


### Asszociatív tárolók


Az asszociatív konténerekben az elemekhez való hozzáférés nem az elem pozíciója, hanem egy kulcs értéke alapján megy végbe. A __rendezett asszociatív tárolók__ esetén biztosítani kell a rendezéshez használható kisebb (```<```) műveletet. Az elemek fizikailag egy önkiegyensúlyozó bináris keresőfa ([piros-fekete fa](https://hu.wikipedia.org/wiki/Piros-fekete_fa)) adastruktúrában helyezkednek el.

![redBlackBinaryTree](img/redBlackBinaryTree.png)

A rendezett konténerek esetén általában logaritmikus a végrehajtási idő (_O(log(n))_), a rendezettségnek köszönhetően azonban hatékony algoritmuskkal dolgozhatunk. Ebbe a csoportba tartozik az egyedi kulcsokkal működő halmaz (__set__) és a szótár (asszociatív tömb: __map__), valamint ezek kulcsismétlődést megengedő változatai a __multiset__ és a __multimap__.

__Megjegyzés__: kulcsismétlődés esetén a keresés végehatási ideje lineáris (_O(n)_).

Más a helyzet a __rendezetlen__ (_unordered_) asszociatív konténerek esetében. Ebben az esetben az elemek gyors elérése érdekében minden elemhez egy hasító érték tárolódik egy _hash_ -táblában. Az elemek elérésekor ismét kiszámítódik a hasító érték, és ez alapján majdnem konstans idő alatt lehet elérni az elemeket.

![unorderedHashMemoryMap](img/unorderedHashMemoryMap.png)

A hasító (_kulcstranszformációs_) függvény a kulcsobjektumot egy indexszé (_hasító kód_) alakítja, amely a hasító táblában kijelöl egy elemet (indexeli azt). A hash-tábla minden eleme az objektumok egy csoportjára (bucket – vödör, kosár) hivatkozik, amennyiben az adott hash-kódhoz tartoznak objektumok. Kereséskor a megfelelő kosár objektumait egymás után a kulcshoz hasonlítva találjuk meg a kívánt objektumot, amennyiban az létezik. Látható tehát, hogy a hasító tábla működésének hatékonysága nagyban függ a hasító függvénytől. Egy jó hash-függvény véletlenszerűen és egyenletesen osztja szét az objektumokat a „vödrökbe”, minimalizálva ezzel a lineáris keresés lépéseit.

A C++ nyelv alaptípusaihoz az STL biztosítja a megfelelő ```hash()``` függvényeket (```<functional>``` fejléc). A fentebb látható négy asszociatív konténer nem rendezett változatai az __unordered_set__, __unordered_multiset__, __unordered_map__, __unordered_multimap__.

Míg a __set__ konténerekben a tárolt adat jelenti a kulcsot, addig a __map__ tárolókban (kulcs/érték) adatpárokat helyezhetünk el. Az adatpárok típusa a ```pair``` struktúrasablon, amely lehetővé teszi, hogy egyetlen objektumban két (akár különböző típusú) objektumot tároljunk. A tárolt objektumok közül az elsőre a ```first```, míg a másodikra a ```second``` névvel hivatkozhatunk. (A ```first``` jelenti a kulcsot a ```second``` a hozzá tartozó értéket.)

[```set```](https://en.cppreference.com/w/cpp/container/set), [```multiset```](https://en.cppreference.com/w/cpp/container/multiset) - mindkét rendezett halmaz konténer a tárolt adatokat kulcsként használja. A __set__ -ben a kulcsok (tárolt adatok) egyediek kell legyenek, míg a __multiset__ -ben ismétlődhetnek. A két osztálysablon műveletei a ```count()``` és az ```insert()``` tagfüggvényektől eltekintve megegyeznek. A __set__ esetében a beszúrás logarimtmikus idejű (_O(log(n))_), abban az esetben, ha az ```insert()``` -et használjuk, iterátorral a beszúrás konstans idejű. A keresés szintén logaritmikus idejű (a műveletek kihasználják a rendezettséget).

![setMulltiset](img/setMultiset.png)

```cpp
#include <iostream>
#include <iterator>
#include <set>

int main()
{
  std::set<int> mySet;
  std::multiset<int> myMultiSet;

  // elemek hozzáadása a set-hez, véletlen sorrendben
  mySet.insert(40);
  mySet.insert(30);
  mySet.insert(60);
  mySet.insert(20);
  mySet.insert(50);
  mySet.insert(50); // csak az első 50-es érték lesz hozzáadva
  mySet.insert(10);

  // elemek hozzáadása a multiset-hez véletlen sorrendben
  myMultiSet.insert(40);
  myMultiSet.insert(30);
  myMultiSet.insert(60);
  myMultiSet.insert(20);
  myMultiSet.insert(50);
  myMultiSet.insert(50);
  myMultiSet.insert(10);

  // set elemeinek kiírása
  std::set<int>::iterator itr = mySet.begin();
  for (; itr != mySet.end(); ++itr)
  {
    std::cout << *itr << ' ';
  }

  std::cout << std::endl;

  // multiset elemeinek kiírása
  std::multiset<int>::iterator mItr = myMultiSet.begin();
  for (; mItr != myMultiSet.end(); ++mItr)
  {
    std::cout << *mItr << ' ';
  }
}
```

> kimenet:
>
> 10 20 30 40 50 60
>
> 10 20 30 40 50 50 60

___

[```map```](https://en.cppreference.com/w/cpp/container/map), [```multimap```](https://en.cppreference.com/w/cpp/container/multimap) - mindkét asszociatív tömb elemei ```pair``` típusúak, és kulcs/érték párokat tartalmaznak. A tárolók elemei a kulcs alapján rendezettek. A kulcsok a __map__ esetén egyediek, míg __multimap__ esetén ismétlődhetnek. A halmazhoz hasonlóan a két osztálysablonnak csak a ```count()``` és az ```insert()``` tagfüggvényei különböznek egymsától. Az elemek indexelve vannak nem feltétlen nullától és nem is  feltétlenül egymás utáni indexek. A kulcsok értékét nem tudjuk módosítani. Keresés logaritmikus idejű (_O(log(n))_).

![mapMultimap](img/mapMultimap.png)

```cpp
#include <iostream>
#include <iterator>
#include <map>

int main()
{

  std::map<int, int> myMap;
  std::multimap<int, int> myMultiMap;

  // elemek hozzáadása a map-hez  véletlen sorrendben
  myMap.insert(std::pair<int, int>(7, 10));
  myMap.insert(std::pair<int, int>(2, 30));
  myMap.insert(std::pair<int, int>(1, 40));
  myMap.insert(std::pair<int, int>(5, 50));
  myMap.insert(std::pair<int, int>(2, 30)); // csak az első 2-es kulcsú kulcs/érték pár lesz beírva
  myMap.insert(std::pair<int, int>(3, 60));
  myMap.insert(std::pair<int, int>(6, 50));
  myMap.insert(std::pair<int, int>(4, 20));

  // elemek hozzáadása a multimap-hez  véletlen sorrendben
  myMultiMap.insert(std::pair<int, int> (5, 50));
  myMultiMap.insert(std::pair<int, int> (1, 40));
  myMultiMap.insert(std::pair<int, int> (6, 50));
  myMultiMap.insert(std::pair<int, int> (3, 60));
  myMultiMap.insert(std::pair<int, int> (4, 20));
  myMultiMap.insert(std::pair<int, int> (6, 10));
  myMultiMap.insert(std::pair<int, int> (2, 30));

  // elemek kiírása kulcs/ érték alapján
  std::map<int, int>::iterator itr = myMap.begin();
  for (; itr != myMap.end(); ++itr) {
      std::cout << itr->first << ' ' << itr->second << std::endl;
  }

  std::cout << std::endl;

  std::multimap<int, int>::iterator mItr = myMultiMap.begin();
  for (; mItr != myMultiMap.end(); ++mItr)
  {
    std::cout << mItr->first << ' ' << mItr->second << std::endl;
  }
}
```

> kimenet:
>
> 1 40
>
> 2 30
>
> 3 60
>
> 4 20
>
> 5 50
>
> 6 50
>
> 7 10
>
>
> 1 40
>
> 2 30
>
> 3 60
>
> 4 20
>
> 5 50
>
> 6 50
>
> 6 10

___


[```unordered_set```](https://en.cppreference.com/w/cpp/container/unordered_set), [```unordered_multiset```](https://en.cppreference.com/w/cpp/container/unordered_multiset), [```unordered_map```](https://en.cppreference.com/w/cpp/container/unordered_map), [```unordered_multimap```](https://en.cppreference.com/w/cpp/container/unordered_multimap) - jó hash-függvény esetén egy rendezetlen konténerben a keresés konstans idejű (_O(1)_). A beszúrás szintúgy. __unordered_set__ és __unordered_multiset__ esetén az adatok étéke nem változhat. __unordered_map__ és __unordered_multimap__ esetén a kulcsok értéke nem változhat, és nem tudjuk őket indexelni az indexelő operátor (```[]```) segítségével. A használatukhoz az ```<unordered_set>``` és az ```<unordered_map>``` fejlécfájl használata szükséges.


Az alábbi összehasonlítás megállja a helyét mind a négy, rendezett, illetve nem rendezett asszociatív konténer esetén:
* egy rendezett konténer kevesebb memóriát foglal ugyanannyi tárolt elem esetén,
* kevés elem esetén a keresés gyorsabb lehet a rendezett tárolókban,
* a műveletek többsége gyorsabb a rendezetlen asszociatív konténerekkel,
* a rendezetlen konténerek nem definiálják a lexikografikus összehasonlítás műveleteit: ```<```, ```<=```, ```>``` és ```>=.```

![containerChooseHelp](img/containerChooseHelp.png)


### Bejárók - Iterátorok


Az iterátorok elkülönítik egymástól a konténerelemekhez való hozzáférés módját a konténer fajtájától. Ezzel a megoldással lehetővé vált olyan általánosított algoritmusok készítése, amelyek függetlenek a konténerek eltérő elemhozzáférési megoldásaitól (```push_back()```, ```insert()```). Az iterátor egy pozíciót határoz meg a tárolóban. Használatához az ```<iterator>``` fejállomány szükséges. Az iterátorokra tekinthetünk úgy, mint mutatókra, amik egy konténer adott elemére mutatnak.

__Megjegyzés__: az iterátorosztályokat ellátták a hagyományos mutatók operátoraival, az iterátorokat paraméterként fogadó algoritmus függvénysablonok többsége C tömbökkel is működik.

Mivel a konténerek működése lényeges eltéréseket mutat, egyetlen általános iterátor helyett a szabvány négy egymásra épülő és egy ötödik, különálló iterátort vezetett be. A különböző algoritmusok is más-más kategóriájú iterátor(oka)t várnak paraméterként.

Legyenek ```p``` és ```q``` iterátorok és ```n``` pedig egy nemnegatív egész szám.

* a ```*p``` kifejezés megadja a konténer ```p``` által jelölt pozícióján álló elemet. Amennyiben az elem egy objektum, akkor annak tagjaira a ```(*p).memberName``` vagy a ```p->memberName``` formában hivatkozhatunk.
* a ```p[n]``` kifejezés megadja a konténer ```p + n``` kifejezés által kijelölt pozícióján álló elemet - megegyezik a ```(*p+n)``` kifejezéssel, ami a [pointer aritmetikából](#t%c3%b6mb-elemeinek-el%c3%a9r%c3%a9se) ismerős lehet.
* a ```p++```, illetve ```p--```  kifejezések hatására a ```p``` iterátor az aktuális pozíciót követő, illetve megelőző elemre lép. (Prefixes alakban is használható ```++p```, ```--p```.)
* a ```p == q``` és a ```p != q``` kifejezések segítségével ellenőrizhetjük, hogy ```p``` és ```q``` iterátorok a tárolón belül ugyanarra az elemre hivatkoznak-e vagy sem.
* a ```p < q```, ```p <= q```, ```p > q``` és a ```p >= q``` kifejezések segítségével ellenőrizhetjük, hogy a tárolón belül ```p``` által mutatott elem megelőzi-e a ```q``` által mutatott elemet, illetve fordítva.
* a ```p + n```, ```p - n```, ```p += n``` és a ```p -= n``` kifejezésekkel a ```p``` által mutatott elemhez képest ```n``` pozícióval távolabb álló elemre hivatkozhatunk, előre (```+```, ```+=```), illetve visszafelé (```-```, ```-=```).
* a ```q - p``` kifejezés megadja a ```q``` és ```p``` iterátorok által mutatott elemek pozíciókban mért távolságát.


#### Iterátorok kategorizálása

Mint azt korábban olvashattuk a szabvány az iterátorokat 4 + 1 kategóriába sorolja, mégpedig:

1. __Input Iterátor__
2. __Forward Iterátor__
3. __Bidirectional Iterátor__
4. __RandomAccess Iterátor__
5. __Output Iterátor__

![iteratorCategories](img/iteratorCategories.png)

__Megjegyzés__: a __forward iterátor__-tól kezdve, minden kategória helyettesítheti a megelőző kategóriákat.

![iteratorCategoriesDescription](img/iteratorCategoriesDescription.png)


##### Input Iterátor


A legegyszerűbb iterátor, amely csak a konténerek olvasására szolgál. A bemeneti iterátorral csak az ```istream_iterator``` osztálysablon tér vissza. A bemeneti iterátor tetszőleges más iterátorral helyettesíthető, kivéve az __output__ iterátort. Az alábbi példában három, szóközzel tagolt számot olvasunk be:

```cpp
#include <iostream>
#include <iterator>

int main()
{
  double data[3] = {0};
  std::cout << "Adj meg három számot: ";

  std::istream_iterator<double> pReader(std::cin);
  for (int i = 0; i < 3; ++i)
  {
    data[i] = *pReader;
    if (i < 2) pReader++;
  }

  for (int elem : data)
  {
    std::cout << elem << ' ';
  }
}
```

> kimenet: Adj meg három számot: 1 2 3
>
> 1 2 3


##### Output Iterátor


A kimeneti iterátorral mindenütt találkozhatunk, ahol valamilyen adatfeldolgozás folyik az STL eszközeivel, pl. másolás vagy összefűzés. Output iterátort a kimeneti adatfolyam iterátor adapterek (```ostream_iterator```) és a beszúró iterátor adapterek (```insterter```, ```front_inserter```, ```back_inserter```) szolgálnak. A kimeneti adatfolyam iterátorra való másolás az adatok kiírását jelenti:

```cpp
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> data = {1, 2, 3, 4, 5, 6, 7};
  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\t"));
}
```

> kimenet: 1 2 3 4 5 6 7

##### Forward Iterátor


Amennyiben egyesítjük a bemeneti és a kimeneti iterátorokat, megkapjuk az előrehaladó iterátort, amellyel a konténerben tárolt adatokon csak előre irányban lépkedhetünk. Az előrehaladó iterátor műveleteivel minden további nélkül készíthetünk elemeket új értékkel helyettesítő függvénysablont:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename FwdIter, typename Type>
void swap(FwdIter first, FwdIter last, const Type& old_t, const Type& new_t)
{
  while (first != last)
  {
    if (*first == old_t)
    {
      *first = new_t;
    }
    ++first;
  }
}

int main()
{
  std::vector<int> data = {1, 2, 3, 12, 23, 34};
  swap(data.begin(), data.end(), 2, 22);
  swap(data.begin(), data.end(), 1, 111);
  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\t"));
}
```
> kimenet: 111 22 12 23 34


##### Bidirectioanl Iterátor


A bidirectional iterátorral a konténerben tárolt adatokon előre és visszafelé is lépkedhetünk. Több algoritmus is kétirányú iterátorokat vár paraméterként, mint például az adatok sorrendjét megfordító ```reverse()``` algoritmus.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
  std::vector<int> data = {1, 2, 3, 12, 23, 34};
  std::reverse(data.begin(), data.end());
  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\t"));
}
```

> kimenet: 34 23 12 3 2 1


##### Random-Access Iterátor


A random-access iterátorok lehetőségei teljes egészében megegyeznek a normál mutatókéval. A ```vector``` és ```deque``` tárolókon túlmenően a C-s tömbök esetén is ilyen iterátorokat használhatunk. Az alábbi példa programban egy függvénysablont készítünk a random-access iterátorokkal kijelölt tartomány elemeinek véletlenszerű átrendezésére. (Az elempárok cseréjét az ```iter_swap()``` algoritmussal végezzük.)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>

template<typename RandIter>
void swap(RandIter first, RandIter last)
{
  while (first < last)
  {
    std::iter_swap(first, first + std::rand() % (last-first));
    ++first;
  }
}

int main()
{
  std::vector<int> data = {1, 2, 3, 12, 23, 34};
  std::srand(unsigned(time(nullptr)));
  swap(data.begin(), data.end());
  std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\t"));
}
```

> kimenet: 34 23 1 3 12 2

__Megjegyzés__: a fentebb látott kódrészletekben használt ```data.begin()``` és ```data.end()``` helyett használható a ```std::begin(data)``` és ```std::end(data)``` alak is.


#### Iterátorok konténerekben tárolt elemekhez


Normál és konstans iterátorokkal térnek vissza a konténerek ```begin()``` és ```cbegin()``` tagfüggvényei, míg az utolsó elem utáni pozícióra hivatkoznak az ```end()``` és ```cend()``` tagfüggvények. A bejáráshoz előre kell léptetnünk (__++__) a ```begin()``` és ```cbegin()``` tagok hívásával megkapott iterátorokat. A függvények által visszaadott iterátor és konstans iterátor típusú bejárók kategóriáját a konténer fajtája határozza meg.

![beginEndIterators](img/beginEndIterators.png)

Az ```array```, ```vector```, ```deque```, ```list```, ```set```, ```multiset```, ```map```, ```multimap``` konténerek esetén fordított irányú bejárást is lehetővé tesznek az ```rbegin()```, ```crbegin()```, illetve az ```rend()```, ```crend()``` tagfüggvények által visszaadott iterátorok. Ezek a függvények ```reverse_iterator```, illetve ```const_reverse_iterator``` típusú értékkel térnek vissza. A bejáráshoz ebben az esetben előre kell léptetnünk (__++__) az ```rbegin()```, ```crbegin()``` tagok hívásával megkapott iterátorokat.

![rBeginREndIterators](img/rBeginREndIterators.png)


### STL Algoritmusok


Az STL algoritmusok az ```<algorithm>``` könyvtárban találhatóak, és számos jól ismert fontos függvényt foglalnak magukba, mint pl. adott tulajdonságú elem keresése, törlése stb. Numerikus algorismusok esetén a ```<numeric>``` deklarációs fájlra van szükség.

Az egyik legnagyobb erősségük, hogy nagyon jól olvasható kódot eredményez a használatuk. Nagyon hasznosak és megbízhatóvá tehetik a C++ programok fejlesztését. Az algoritmusok egy részét arra tervezték, hogy módosítsák egy kijelölt adatsor elemeit, azonban soha nem változtatják meg magukat az adatokat tároló konténereket.

Az algoritmusok nem tagfüggvényei a konténereknek, globális függvénysablonok, amelyek iterátorok segítségével férnek hozzá a konténerben lévő adatokhoz. Az algoritmusok teljesen függetlenek a konténerektől, a paraméterként megkapott iterátorok feladata a konténerek ismerete.

Az algoritmusok közötti eligazodásban segít, ha a különböző műveleteket a viselkedésük és működésük alapján csoportokba soroljuk. Egy lehetséges kategorizálás - ahol egy algortimus akár több csoportban is megjelenhet:


#### Nem módosító algoritmusok:


Ezek az algoritmusok nem változtatják meg sem az adatelemeket, sem pedig azok tárolási sorrendjét.

* [```adjacent_find()```](https://en.cppreference.com/w/cpp/algorithm/adjacent_find)
* [```find_first_of()```](https://en.cppreference.com/w/cpp/algorithm/find_first_of)
* [```max_element()```](https://en.cppreference.com/w/cpp/algorithm/max_element)
* [```min_element()```](https://en.cppreference.com/w/cpp/algorithm/min_element)
* [```for_each()```](https://en.cppreference.com/w/cpp/algorithm/for_each)
* [```all_of()``` ```any_of``` ```none_of```](https://en.cppreference.com/w/cpp/algorithm/all_any_none_of)
* [```count()``` ```count_if()```](https://en.cppreference.com/w/cpp/algorithm/count)
* [```lexicographical_compare()```](https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare)
* [```minmax_element()```](https://en.cppreference.com/w/cpp/algorithm/minmax_element)
* [```equal()```](https://en.cppreference.com/w/cpp/algorithm/equal)
* [```max()```](https://en.cppreference.com/w/cpp/algorithm/max)
* [```min()```](https://en.cppreference.com/w/cpp/algorithm/min)
* [```mismatch()```](https://en.cppreference.com/w/cpp/algorithm/mismatch)
* [```search()```](https://en.cppreference.com/w/cpp/algorithm/search)
* [```find()``` ```find_if()``` ```find_if_not()```](https://en.cppreference.com/w/cpp/algorithm/find)
* [```find_end()```](https://en.cppreference.com/w/cpp/algorithm/find_end)
* [```minmax()```](https://en.cppreference.com/w/cpp/algorithm/minmax)
* [```search_n()```](https://en.cppreference.com/w/cpp/algorithm/search_n)


#### Módosító algoritmusok


Az adatmódosító algoritmusokat arra tervezték, hogy megváltoztassák a konténerekben tárolt adatelemek értékét. Ez megtörténhet közvetlenül, magában a konténerben, vagy pedig az elemek más konténerbe való másolásával. Néhány algoritmus csupán az elemek sorrendjét modosítja, és ezért került ide.

* [```copy()``` ```copy_if()```](https://en.cppreference.com/w/cpp/algorithm/copy)
* [```copy_backward()```](https://en.cppreference.com/w/cpp/algorithm/copy_backward)
* [```copy_n()```](https://en.cppreference.com/w/cpp/algorithm/copy_n)
* [```fill()```](https://en.cppreference.com/w/cpp/algorithm/fill)
* [```fill_n()```](https://en.cppreference.com/w/cpp/algorithm/fill_n)
* [```for_each()```](https://en.cppreference.com/w/cpp/algorithm/for_each)
* [```generate()```](https://en.cppreference.com/w/cpp/algorithm/generate)
* [```generate_n()```](https://en.cppreference.com/w/cpp/algorithm/generate_n)
* [```iter_swap()```](https://en.cppreference.com/w/cpp/algorithm/iter_swap)
* [```merge()```](https://en.cppreference.com/w/cpp/algorithm/merge)
* [```move()```](https://en.cppreference.com/w/cpp/algorithm/move)
* [```move_backward()```](https://en.cppreference.com/w/cpp/algorithm/move_backward)
* [```replace()``` ```replace_if()```](https://en.cppreference.com/w/cpp/algorithm/replace)
* [```replace_copy()``` ```replace_copy_if()```](https://en.cppreference.com/w/cpp/algorithm/replace_copy)
* [```swap()```](https://en.cppreference.com/w/cpp/algorithm/swap)
* [```swap_ranges()```](https://en.cppreference.com/w/cpp/algorithm/swap_ranges)
* [```transform()```](https://en.cppreference.com/w/cpp/algorithm/transform)


#### Eltávolító algoritmusok


Ezek valójában módosító algoritmusok, azonban céljuk az elemek eltávolítása egy konténerből, vagy másolása egy másik tárolóba.

* [```remove()``` ```remove_if```](https://en.cppreference.com/w/cpp/algorithm/remove)
* [```remove_copy()``` ```remove_copy_if()```](https://en.cppreference.com/w/cpp/algorithm/remove_copy)
* [```unique()```](https://en.cppreference.com/w/cpp/algorithm/unique)
* [```unique_copy()```](https://en.cppreference.com/w/cpp/algorithm/unique_copy)


#### Átalakító algoritmusok


Ezek is módosító algoritmusok, azonban kimondottan az elemsorrend megváltoztatásával jár a működésük.

* [```is_partitioned()```](https://en.cppreference.com/w/cpp/algorithm/is_partitioned)
* [```is_permutation()```](https://en.cppreference.com/w/cpp/algorithm/is_permutation)
* [```next_permutation()```](https://en.cppreference.com/w/cpp/algorithm/next_permutation)
* [```partition()```](https://en.cppreference.com/w/cpp/algorithm/partition)
* [```partition_copy()```](https://en.cppreference.com/w/cpp/algorithm/partition_copy)
* [```partition_point()```](https://en.cppreference.com/w/cpp/algorithm/partition_point)
* [```prev_permutation()```](https://en.cppreference.com/w/cpp/algorithm/prev_permutation)
* [```random_shuffle()``` ```shuffle()```](https://en.cppreference.com/w/cpp/algorithm/random_shuffle)
* [```reverse()```](https://en.cppreference.com/w/cpp/algorithm/reverse)
* [```reverse_copy()```](https://en.cppreference.com/w/cpp/algorithm/reverse_copy)
* [```rotate()```](https://en.cppreference.com/w/cpp/algorithm/rotate)
* [```rotate_copy()```](https://en.cppreference.com/w/cpp/algorithm/rotate_copy)
* [```stable_partition()```](https://en.cppreference.com/w/cpp/algorithm/stable_partition)


#### Rendező algoritmusok


Az itt található módosító algoritmusok feladata a teljes konténerben, vagy tároló egy tartományában található elemek rendezése.

* [```is_heap()```](https://en.cppreference.com/w/cpp/algorithm/is_heap)
* [```is_heap_until()```](https://en.cppreference.com/w/cpp/algorithm/is_heap_until)
* [```is_partitioned()```](https://en.cppreference.com/w/cpp/algorithm/is_partitioned)
* [```is_sorted()```](https://en.cppreference.com/w/cpp/algorithm/is_sorted)
* [```is_sorted_until()```](https://en.cppreference.com/w/cpp/algorithm/is_sorted_until)
* [```make_heap()```](https://en.cppreference.com/w/cpp/algorithm/make_heap)
* [```nth_element()```](https://en.cppreference.com/w/cpp/algorithm/nth_element)
* [```partial_sort()```](https://en.cppreference.com/w/cpp/algorithm/partial_sort)
* [```partial_sort_copy()```](https://en.cppreference.com/w/cpp/algorithm/partial_sort_copy)
* [```partition()```](https://en.cppreference.com/w/cpp/algorithm/partition)
* [```partition_copy()```](https://en.cppreference.com/w/cpp/algorithm/partition_copy)
* [```pop_heap()```](https://en.cppreference.com/w/cpp/algorithm/pop_heap)
* [```push_heap()```](https://en.cppreference.com/w/cpp/algorithm/push_heap)
* [```sort()```](https://en.cppreference.com/w/cpp/algorithm/sort)
* [```sort_heap()```](https://en.cppreference.com/w/cpp/algorithm/sort_heap)
* [```stable_partition()```](https://en.cppreference.com/w/cpp/algorithm/stable_partition)
* [```stable_sort()```](https://en.cppreference.com/w/cpp/algorithm/stable_sort)


#### Rendezett tartomány algoritmusok


Ezek az algoritmusok az elemek rendezettségét kihasználva igen hatékonyan működnek.

* [```binary_search()```](https://en.cppreference.com/w/cpp/algorithm/binary_search)
* [```equal_range()```](https://en.cppreference.com/w/cpp/algorithm/equal_range)
* [```includes()```](https://en.cppreference.com/w/cpp/algorithm/includes)
* [```inplace_merge()```](https://en.cppreference.com/w/cpp/algorithm/inplace_merge)
* [```lower_bound()```](https://en.cppreference.com/w/cpp/algorithm/lower_bound)
* [```merge()```](https://en.cppreference.com/w/cpp/algorithm/merge)
* [```set_differences()```](https://en.cppreference.com/w/cpp/algorithm/set_difference)
* [```set_intersection()```](https://en.cppreference.com/w/cpp/algorithm/set_intersection)
* [```set_symmetric_difference()```](https://en.cppreference.com/w/cpp/algorithm/set_symmetric_difference)
* [```set_union()```](https://en.cppreference.com/w/cpp/algorithm/set_union)
* [```upper_bound()```](https://en.cppreference.com/w/cpp/algorithm/upper_bound)


#### Numerikus algoritmusok


Számokat tároló konténerek elemein műveleteket végző algoritmusok csoportja.

* [```accumulate()```](https://en.cppreference.com/w/cpp/algorithm/accumulate)
* [```adjancent_difference()```](https://en.cppreference.com/w/cpp/algorithm/adjacent_difference)
* [```inner_product()```](https://en.cppreference.com/w/cpp/algorithm/inner_product)
* [```iota()```](https://en.cppreference.com/w/cpp/algorithm/iota)
* [```partial_sum()```](https://en.cppreference.com/w/cpp/algorithm/partial_sum)


Néhány tároló rendelkezik az algoritmusok némelyikével megegyező nevű tagfüggvénnyel. Ezek létezésnek oka, hogy kihasználva a konténerek speciális adottságait, hatékonyabb és biztonságosabb tagfüggvény készíthető, mint az általános algoritmus. Egyetemes szabályként megfogalmazható, hogy részesítsük előnyben a taggfüggvényeket a program készítése során.


#### Az algoritmusok végrehajtási ideje


A konténerműveletek időigénye mellett a felhasznált algoritmusok időigénye együtt határozza meg az adott programrész futásidejét. Az algoritmusok végrehajtásához szükséges időigényt a feldolgozandó adatsor elemeinek számával (_n_) jellemezhetjük:

* __O(1)__ - ```swap()```, ```iter_swap()```
* __O(log(n))__ - ```lower_bound()```, ```upper_bund()```, ```equal_range()```, ```binary_search()```, ```push_heap()```, ```pop_heap()```
* __O(n log(n))__ - ```inplace_merge()``` (legrosszabb esetben), ```stable_partition()``` (legrosszabb esetben),
* __O(n<sup>2</sup>)__ - ```find_end()```, ```find_first_of()```, ```search()```, ```search_n()```
* __O(n)__ - minden más algoritmus


### Lambda kifejezések


A lambda függvények lehetővé teszik, hogy egy vagy több soros névtelen függvényeket definiáljunk a forráskódban, ott ahol éppen szükség van rájuk. A lambda kifejezések szerkezete nem kötött, a fordító feltételezésekkel él a hiányzó részekkel kapcsolatban. Nézzünk erre egy példát:

```cpp
int a = []{ return 12 * 23; } ();
```

A bevezető szögletes zárójel jelzi, hogy lambda következik. Ez után áll a függvény törzse, ahol a ```return``` utasításból a fordító meghatározza a függvény értékét és típusát. Az utasítást záró kerek zárójelpár a függvényhívást jelenti.

Amennyiben paraméterezni kívánjuk a lambdát, a szögletes és a kapcsos zárójelek közé egy hagyományos paraméterlista is beékelődik:

```cpp
int a = [](int x, int y){ return x * y; } (12, 23);
```

Szükség esetén a függvény visszatérési típusát is megadhatjuk a C++11-ben bevezetett formában:

```cpp
int a = [](int x, int y) -> int { return x * y; } (12, 23);
```

A lambda függvények legfontosabb alkalmazási területe az STL algoritmusok hívása. 

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> data = {1, 2, 3, 5, 8, 13, 21};
  int quantity = std::count_if(data.begin(), data.end(), [] (int x) { return x % 2; });

  std::cout << "Quantity: " << quantity << std::endl;

  std::for_each(data.begin(), data.end(), [](int& e){ e *= 2; });

  std::sort(data.begin(), data.end(), [](int e1, int e2){ return e1 > e2; });

  std::for_each(data.begin(), data.end(), [](int x){ std::cout << x << ' '; });
}
```

Első lépésként megszámoljuk a ```data``` vektor páratlan elemeit, majd minden elemet a duplájára növelünk, csökkenő sorrendben rendezzük a vektort, végül pedig megjelenítjük az elemeket. Ezekben a példákban a lambda függvények csak a paramétereken keresztül tartották a kapcsolatot a környezetükben elérhető változókkal. Ellentétben a hagyományos függvényekkel, a lambda kifejezésekben elérhetjük a lokális hatókör változóit.

A fájl szintű és lokális statikus élettartamú nevek elelérése minden további nélkül működik:

```cpp
const double PI = 3.1415;

int main()
{
  static int b = 11;
  double x = [](){ return PI * b; } ();
}
```

A lokális, nem statikus függvényváltozók, illetve az osztály adattagjai esetén intézkedhetünk az elérés módjáról. Amennyiben a fenti példában ```PI``` és ```b``` lokális változók, a velük azonos hatókörben megadott lambda a következőképpen módosul:

```cpp
const double PI = 3.1415;
int b = 11;
double x = [PI, b](){ return PI * b; } ();
```

A lambdát és az elért változókat együtt szokás __closure__-nek nevezni, míg a felhasznált változókat, mint elkapott vagy __captured__ változókra hivatkozhatunk. A változókat érték, illetve referencia szerint is elkaphatjuk.

* ```[]``` egyetlen helyi változót sem kívánunk elkapni
* ```[=]``` az összes helyi változót érték szerint kapjuk el
* ```[&]``` az összes helyi változót referencia szerint kapjuk el
* ```[a, b]``` csak az ```a``` és ```b``` változókat kapjuk el érték szerint
* ```[a, &b]``` az ```a``` változót érték, míg ```b```-t referencia szerint kapjuk el
* ```[=, &b]``` az összes helyi változót érték szerint kapjuk el, kivéve ```b```-t, őt referenciával
* ```[&, a]``` az összes helyi változót referenciával kapjuk el, kivéve ```a```-t, amelyet érték szerint
* ```[this]``` osztályon belül definiált lambda kifejezésekben használhatjuk a ```this``` mutatót, vagyis elérhetjük az osztály adattagjait


__Megjegyzés__: C++17 óta ```[*this]``` is lehetőségünk van elkapni.

A fordító nem engedi az érték szerint elkapott változó módosítását.

Amennyiben a lambda függvényt többször szeretnénk használni, hozzárendelhetjük egy függvény mutatóhoz.

```cpp
void (*myLambda) (int) = [](int i){ i *= i; };

auto myLambda = [](int i){ i *= i; }; // C++11 auto kulcsszó

std::for_each(data.begin(), data.end(), myLambda);
```

Nézzünk egy példát, ahol egy vektor elemeit négyzetre emeljük először egy funktor segítségével, majd egy lambda segítségével:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct Square
{
  void operator()(int& i) const { i *= i; }
};

int main()
{
  Square sq;
  std::vector<int> data{1, 2, 3, 4, 5, 6}; // C++11-es vagy annál újabb fordító szükséges

  std::for_each(data.begin(), data.end(), sq); // funktorral

  std::for_each(data.begin(), data.end(), [](int& i){ i *= i; }); // lambdával
}
```


## Sablon - template


A C++ sablonok alatt olyan __osztálysablonokat__ (_class template_) és __függvénysablonokat__ (_function template_) értünk, melyek esetében az adott osztály, illetve függvény definiálásakor bizonyos elemeket nem adunk meg, hanem __paraméterként__ kezelünk. Ezen paraméterek megadása explicit vagy implicit módon az adott osztálysablon, illetve függvénysablon __felhasználásakor__ történik. Egy osztályt osztálysablonná alakítva az elemek típusát paraméterként kezelhetjük, és a kívánt elemtípust az osztálysablon felhasználása során adhatjuk meg.

Gondolhatunk a sablonokra úgy, mint olyan osztályokra, illetve függvényekre, melyek nem teljesek, és a felhasználásukkor a paraméterek megadásával válnak teljes értékű osztályokká vagy függvényekké.

A C++ sablonok tulajdonképpen a generikus típusok a C++ nyelvbeli megfelelői. Jellemző alkalmazási területük olyan tárolóosztályok létrehozása, amelyek tetszőleges típusú elem tárolására szolgálnak, mégpedig típusbiztos (_type safe_) módon. A fordító egészen addig ignorálja a sablonokat - nem fordítja bele az assembly kódba - , amíg azok a kód valamely részén felhasználásra nem kerülnek. Részletesebben a [Sablonok fordítása](#sablonok-ford%c3%adt%c3%a1sa) fejezet foglalkozik ezzel.


### Függvénysablon - function template


Legyen a felada két függvény megírása: az első két egész szám (```int```), a második két lebegőpontos szám (```double```) közül a nagyobbat adja vissza.

```cpp
inline int max(int lhs_, int rhs_)
{
  return lhs_ > rhs_ ? lhs_ : rhs_;
}

inline double max(double lhs_, double rhs_)
{
  return lhs_ > rhs_ ? lhs_ : rhs_;
}
```

Jól látható, hogy a két függvény törzse pontosan megegyezik. Ha újabb típusokra szeretnénk használni a ```max()``` függvényünket, akkor azokra is külön meg kellene írni. Ezen kódduplikálás elkerülésére eddigi ismereteink szerint egyetlen megoldás kínálkozik, a makrók használata. (kerülendő!) A makrókkal kapcsolatos gondokat a korábbi fejezetekben már láthattuk. A C++ nyelvben a probléma hatékony és biztonságos megoldására a __függvénysablonokat__ használhatjuk. A ```max()``` függvényre vonatkozóan ez azt jelenti, hogy olyan függvénysablonná alakítjuk át, amelyben a típus, amelyen dolgozik, nincs rögzítve, paraméterként kezeljük, és ezt a paramétert a függvénysablon felhasználsakor adjuk meg. A ```max()``` függvénysablon implementációja a következő:

```cpp
template <typename T>
inline T max(T lhs_, T rhs_)
{
  return lhs_ > rhs_ ? lhs_ : rhs_;
}
```

A függvény átalakítását a következő lépésekben végezzük:

* a függvénysablon fejlécét a ```template``` kulcsszóval kell kezdeni. Ezt követően ```< >``` között kell felsorolni a sablonparamétereket, vesszővel elválasztva. A példában egy sablonpraméter szerepel, ```T```. A sablonparamétereknek tetszőleges nevet adhatunk. Példánkban ```T``` egy típust jelöl, ezt a ```typename``` kulcsszóval jelezzük a fordító felé. A ```typename``` helyett a ```class``` kulcsszó is használható. Sablonok esetében a kettő teljesen ekvivalens. A ```class``` kulcsszó némiképp megtévesztő lehet, az adott paraméter nem csak osztály, hanem tetszőleges típus lehet. Sablon paraméter konstans is lehet.
* mindenhol, ahol eddig az ```int``` vagy ```double``` beégetett típust használtuk, a ```T``` paramétert szerepeltetjük. Ez esetünkben a függvény visszatérési értékének és bemeneti paramétereinek típusát jelenti. Használhatnánk lokálisan definiált vagy dinamikusan lefoglalt változók létrehozására is.

__Megjegyzés__: a ```typename``` kulcsszó később került be a nyelvbe, mint a ```class```, ezért eleinte azt használták sablonparaméterek megadásánál.

A példában a függvény, illetve a függvénysablon a függvénytörzs rövidsége miatt célszerűen ```inline```, de természetesen nem ```inline``` függvénysablonok írására is van lehetőség.

Eddig csak arról esett szó, hogyan lehet függvénysablont __létrehozni__. A következőkben arra lesz példa, hogyan lehet a függvénysablonokat __felhasználni__. A legegyszerűbb mód a __függvénysablon implicit példányosítása__ (_implicit function template instantiation_):

```cpp
int i = max(3, 5);
double d = max(2.3, 4.2);
```

A kódrészlet első sora ```int```, a második sora ```double``` típussal __példányosítja__ a függvénysablont. Ennek semmi köze az objektumok példányosításához. Ez azt jelenti, hogy __fordítás során__ az első esetben a ```T``` paraméter helyébe ```int```, a második esetben ```double``` típus helyettesítődik. A behelyettesítést követően a függvénysablonból közönséges függvény készül, melyet a fordító gépi kódra fordít. Jelen esetben azért beszélünk implicit példányosításról, mert a fordító a paraméterek típusából kikövetkezteti, milyen típust kell behelyettesíteni a sablonparaméterek helyére, vagyis a paramétereket nem adtuk meg explicit módon. Ezt a fajta kikövetkeztetést nevezzük __template argumentum dedukciónak__ (_template argument deduction_).

Implicit példányosítás esetén egy adott sablonparaméter csak egy típust jelölhet. A példára vonatkozóan ez azt jelenti, hogy a fordító kikényszeríti, hogy a ```max()``` függvény mindkét paraméterének típusa pontosan megegyezzen. Ennek megfelelően például a

```cpp
double d = max(1, 3.5);
```

kód nem fordul le, mert az első függvényparaméter esetében a ```T``` ```int```, a második esetében ```double``` típust jelentene. A fordító a függvénysablon implicit példányosítása esetén nem engedélyezi az automatikus konverziót. Természetesen ugyanígy fordítási hibát eredményezne, ha a függvényparaméterek nem konstansok, hanem változók lennének. Sőt, az ```unsigned``` és a ```signed``` típusok közötti konverzió sem megengedett. A probléma megoldása a következő lehet:

```cpp
double d = max(1.0, 3.5);
```

Itt mindkét paraméter típusa ```double```. Változókkal szemléltetve:

```cpp
int i;
double d;
...
double d = max((double)i, d);
```

A másik megoldást a konverziós problémára az jelenti, ha a ```max()``` függvénysablont __explicit módon példányosítjuk__ (_explicit function template instantiation_):

```cpp
double d = max<double>(1, 3.5);
```

Ebben az esetben a függvénysablon használatkor a függvénysablon neve utána ```< >``` között, vesszővel elválasztva felsoroljuk a paraméterekbehelyettesítési értékét. A példában ez a ```T``` helyére ```double``` megadását jelenti. Az expliciten példányosított függvények esetében a paraméterekre működik az automatikus konverzió, vagyis a ```max<double>(1, 3.5)``` nem okoz fordítási hibát: az első ```int``` paraméter automatikusan ```double```-ra konvertálódik. Ez logikus következménye annak, hogy az explicit módon példányosított függvénysablonok ugyanúgy viselkednek, mint a közönséges függvények, ennek megfelelően pontosan ugyanazok a konverziós szabályok érvényesek rájuk is.

Felmerülhet a kérdés, hogy a ```max()``` függvénysablonunk ténylegesen bármilyen típussal használható-e? Vessünk egy pillantást a függvénysablonunk implementációjára, ami magában rejti a választ.

```cpp
template <typename T>
inline T max(T lhs_, T rhs_)
{
  return lhs_ > rhs_ ? lhs_ : rhs_;
}
```

Ebben az implementációban két megkötés él a ```T``` sablonparaméterre vonatkozóan:

1. a függvény törzsében használhatjuk rá a ```>``` operátort, így a ```T``` típusra értelmezettnek kell lennie, és az általunk elvárt módon kell megvalósítania az összehasonlítást. Így ha ```T``` egy saját osztály vagy stuktúra, akkor gondoskodnunk kell a ```>``` operátor megfelelő megírásáról.
2. A függvény az ```lhs_``` és ```rhs_``` paramétereket érték szerint veszi át, valamint nem referencia típusssal tér vissza, így a függvény hívásakor meghívódik a ```T``` másolókonstruktora. Ha ```T``` saját típus, gondoskodjunk megfelelő másolókonstruktor megírásáról, amennyiben a beépített másolókonstruktor nem biztosít megfelelő működést.

Nagyobb objektumok esetében a ```max()``` függvénysablon hatékonyabb működést eredményez, ha referencia szerint történik a paraméterátadás:

```cpp
template <typename T>
inline const T& max(const T& lhs_, const T& rhs_)
{
  return lhs_ > rhs_ ? lhs_ : rhs_;
}
```


### Függvénysablon-specializáció


Mint azt az előzőekben láthattuk a ```max()``` függvénysablon teljesen jól működött egész és lebegőpontos számok esetében, de mi a helyzet más típusokkal? Tekintsük az alábbi kódrészletet:

```cpp
const char* text = max("abc", "bcd");
```

Ez a program hibás, ugyanis a ```max()``` függvény két string összehasonlítására nem alkalmas. Ennek oka, hogy két ```char*``` mutató közül a nagyobbikat adja vissza, vagyis a stringeket nem a tartalmazott karakterek, hanem a memóriabeli elhelyezkedésük alapján hasonlítja össze. Szerencsére van megoldás: __függvénysablon-specializációt__ (_function template specialization_) kell alkalmazni. Ennek a lényege, hogy az általános függvénysablon definíción kívül bizonyos paraméterek behelyettesítésére az általánostól eltérő implementációt adunk meg. A példánkra vonatkozóan ez azt jelenti, hogy megírjuk ugyan a fenti általános ```max()``` függvénysablont, de emelett meg kell írni egy ```const char*```-ra specializált implementációt is. Ez szintaktikailag két módon is megtehető. Az első a "klasszikus" megoldás:

```cpp
const char* max(const char* lhs_, const char* rhs_)
{
  return (std::strcmp(lhs_, rhs_) > 0) ? lhs_ : rhs_;
}
```

[```strcmp()```](https://en.cppreference.com/w/cpp/string/byte/strcmp) - beépített függvény a ```<string.h>``` fejállományban, amely paraméterül vár két ```string``` (vagy ```char*```) típusú argumentumot, majd lexikografikusan összehasonlítja őket.

A második a C++ gondolkodásmódjának jobban megfelelő megoldás:

```cpp
template<>
const char* max<const char*>(const char* lhs_, const char* rhs_)
{
  return (std::strcmp(lhs_, rhs_) > 0) lhs_ : rhs_;
}
```

Ez esetben a következő szabályok érvényesek:

* a függvénysablon elé a ```template<>``` kifejezést kell írni, üres paraméterlistával.
* a függvénysablon neve után ```< >``` között fel kell sorolni valamennyi sablonparaméterre vonatkozóan a specializált behelyettesítési értéket, vesszővel elválasztva. A példánkra vonatkozóan ez a ```const char*```.
* egy függvénysablonhoz több specializáció is készíthető, természetesen különböző paraméterbehelyettesítésekkel.
* a fordító a függvénysablon felhasználásakor egy adott specializációt alkalmaz, amennyiben a sablonparaméterek __pontosan__ megegyeznek a specializációban megadottakkal. A specializációk "illesztése" során a fordító semmiféle konverziót nem alkalmaz, így például nem konstansról konstans konverziót sem.
* függvénysablonokra vonatkozóan csak teljes, valamennyi paraméterre vonatkozó specializáció írható.

Felmerülhet kérdésként, hogy miért a ```const char*```-ra való specializációt írtuk meg és miért nem a ```char*```-ra? A specializációk illesztésekor a fordító a sablonparaméterekre vonatkozóan szigorú típusegyezősséget alkalmaz. Az ```"abc"``` és ```"bcd"``` literálok típusa ```const char*```. Így, ha a ```char*```-ra specializált változatot írtuk volna meg, akkor ezen paraméterekre vonatkozóan az általános ```max()``` implementáció hívódott volna meg.  A gondolatmenetet tovább folytatva kérdéses, hogy ha csak a ```const char*```-ra specializált verziót írjuk meg, akkor a ```char*``` paraméterek esetében alkalmazza-e a fordító a specializált változatot. A válasz ez esetben is nem. A tanulság pedig az, hogy a specializációt ```char*``` és ```const char*``` paraméterekre is meg kell írni, másként az adott helyzetnek megfelelően meglepő eredményeket kaphatunk a ```max()``` függvénysablon alkalmazásakor.

__Fontos__: a sablonspecializáció esetén, ha az érintett paraméter mutató típusú, a konstans és nem konstans paraméterekre is írjunk specializációt.

Sablonparaméter nem csak típus lehet, hanem típusos konstans is. Nézzük meg az alábbi példát:

```cpp
#include<iostream>

template<int N>
int square()
{
  return N * N;
}

int main()
{
  const int x = 10;
  std::cout << "square of " << x << " is " << square();
}
```

> kimenet: square of 10 is 100

A ```square()``` függvénysablon sablonparaméterként egy ```int``` konstanst vár, amelynek négyzetével tér vissza. A ```square()``` csak konstans paraméterrel használható, hiszen a sablon kifejtése fordítási időben történik. Ez nagyban korlátozza a használhatóságát, ugyanakkor előnye, hogy négyzetre emelés már fordítási időben megtörténik, ami jelentős futás közbeni sebességnövekedést eredményezhet.

Korábban említésre került, hogy nem csak egy sablon paramétert adhatunk meg. Írjunk egy függvénysablont, ami két sablonparaméterrel rendelkezik, és összehasonlítja a sablonparaméter-típusok memóriabeli méretét: 1-el tér vissza, ha az első paraméterben megadott típus nagyobb, -1-el, ha kisebb, és 0-val, ha egyenlők.

```cpp
#include<iostream>

template <typename T1, typename T2>
int compareTypes()
{
  if (sizeof(T1) > sizeof(T2))
  {
    return 1;
  }
  else if (sizeof(T1) <  sizeof(T2))
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  std::cout << "compare double to int " << compareTypes<double, int>() << std::endl;
  std::cout << "compare int to long " << compareTypes<int, long>() << std::endl;
  std::cout << "compare int to int " << compareTypes<int, int>() << std::endl;
}
```

> kimenet:
>
> compare double to int 1
>
> compare int to long -1
>
> compare int to int 0


### Hívott függvény kiválasztása


Amennyiben egy adott függvénynek több implementációja is van, felmerül a kérdés, hogy a függvényhívás során melyik függvény fog meghívódni. A következő szabályok érvényesek a sorszámnak megfelelő prioritási sorrendben:

1. ha létezik olyan közönséges függvény, melynek paraméterei típus szerint pontosan megegyezzenek, akkor az adott függvény hívódik meg.
2. ha létezik olyan függvénysablon, melynek paraméterei típus szerint pontosan megegyeznek, akkor az adott függvény hívódik meg.
3. ha létezik közönséges függvény vagy függvénysablon, mely esetében típuskonverzióval megegyeznek a paraméterek, akkor az adott függvény hívódik meg. Az automatikus típus konverzió nem érinthet sablonparamétert. Például a ```template <typename T> void myFunc(double a, T b, T c);``` esetében a ```b``` és ```c``` függvényparaméterekre vonatkozóan a korábbi szabályoknak megfelelően csak akkor lehetséges az automatikus konverzió, ha a ```myFunc()``` függvénysablont explicit példányosítjuk, vagyis  míg a ```myFunc(10, 10.1, 11);``` fordítási hibát okoz, mert a harmadik paraméternél automatikus ```int``` -> ```double``` konverzióra volna szükség. Az explicit példányosított ```myFunc<double>(10, 10.1, 11);``` hívás lefordul.


### Osztálysablon - class template


A fordítónak jeleznünk kell, hogy nem közönséges osztályról, hanem osztálysablonról van szó. Ezt a korábban bemutatott függvénysablonokhoz hasonlóan a ```template``` kulcsszó segítségével tehetjük meg.

```cpp
template <typename T>
class MyClass
{
public:
  MyClass(T a_);
  T getA() const { return _a; }
  void setA(T a_);
private:
  T _a
};
```

A ```template``` kulcsszót követően ```< >``` között fel kell sorolni a sablonparamétereket, vesszővel elválasztva. A paraméterekre vonatkozó szabályok megegyeznek a függvénysablonok esetében megadottakkal.

Amennyiben a tagfüggvények implementációját nem az osztálydefiníciós részben, implicit inline módon kívánjuk megadni, a következőképpen tehetjük meg:

```cpp
// a setA() tagfüggvény definíciója
template <typename T>
void MyClass<T>::setA(T a_)
{
  _a = a_;
}
```

A definíciót a többi tagfüggvény és konstruktor esetében is hasonló módon lehet megadni. Valamennyi tagfüggvény-definíció előtt a ```template``` kulcsszót kell megadni, és ```< >``` között fel kell sorolni a template paramétereket. Ezen túlmenően az osztály neve után ```< >``` között vesszővel elválasztva fel kell sorolni a sablonparaméterek __nevét__. Itt a ```class``` vagy ```typename``` kulcsszókat nem írjuk ki a paraméterek elé. __A konstruktor és destruktor nevének megadására ez az átalakítás nem érvényes.__

```cpp
// helyes
template <typename T>
MyClass<T>::MyClass(T a_): _a(a_) { }

// helytelen
MyClass<T>::MyClass<T>(T a_): _a(a_) { }
```

Míg a közönséges osztályok esetében az osztálydefiníciós rész a ```.h``` fejlécfájlba, a tagfüggvények definícióját a ```.cpp``` forrásfájlba szokás tenni, osztálysablonok esetében a tagfüggvények definícióját is a fejlécfájlba kell tenni. Ennek okait a [Sablonok fordítása](#sablonok-ford%c3%adt%c3%a1sa) című fejezet fejti ki részletesen.


Azokon a helyeken ahol az osztálysablont metódusparaméterként, tagváltozóként vagy lokális változóként használjuk, régebbi fordítók esetében fel kell sorolni a sablonparaméterek __neveit__ vesszővel elválasztva, a __class__, illetve __typename__ kulcsszó nélkül. A másolókonstruktort vehetjük példánk alapjául:

```cpp
template <typename T>
class MyClass
{
public:
  MyClass(const MyClass<T>& rhs_)
  {
    ...
  }
};
```

Ezen szabály alkalmazása modern fordítók esetében már nem kötelező. Célszerű emlékezni rá, hogy ha régebbi forráskódban látjuk.

A következőkben arra láthatunk példát, hogy hogyan tudjuk __felhasználni__ az osztálysablont.

```cpp
int main()
{
  MyClass<int> mc1;
  mc1.setA(1);

  MyClass<char> mc2;
  mc2.setA('a');
}
```
A felhasználás során az osztálysablon neve után ```< >``` között kell megadni a sablonparaméterek behelyettesítési értékét. Az osztálysablon felhasználására vonatkozó legfontosabb szabály a következő:
__az osztálysablon paraméterek megadása után ugyanúgy használható, mint egy közönséges osztály. Másképpen fogalmazva: ahol a kódban osztálynév szerepelhet, ott szerepelhet felparaméterezett osztálysablon is.__

Az osztálysablonok felhasználásával kapcsolatban érdemes megjegyezni, hogy amennyiben egy adott módon felparaméterezett osztálysablont többször kívánunk használni, kényelmes lehet új típusként való bevezetése a ```typedef```-fel:

```cpp
typedef MyClass<int> MC;
...
MC mc;
mc.petA(1);
```

Osztályok esetében is előfordulhat, hogy a sablonparaméter típusos konstans vagy osztálysablon. Abban az estben, ha __felparaméterezett sablon__-t használunk pl. ```MyClass<AnotherClass<int>>``` régebbi fordítók esetén (C++11 előtt) a utolsó ```>>``` közé szóközt kell rakni, mert a fordító __bitshift right__ operátorként ismeri fel. Modernebb fordítók esetén ez már nem jelent problémát.


#### Típusos konstans sablonparaméter


Mint azt korábban említettük, sablonparaméter lehet típusos konstans is. Nézzünk erre egy példát.

```cpp
template <typename T, int Size>
class MyClass
{
public:
  MyClass(T a_, int b_): _a(a_), _b(b_) { }
private:
  T _a;
  int _b;
};

int main()
{
  MyClass<int, 100> mc;
}
```

Alternatív megoldásként használhattunk ```const``` kulcsszóval ellátott konstanst.

```cpp
int main()
{
  const int size = 100;
  MyClass<int, size> mc;
}
```

Annak, hogy csak konstans adható meg elvi oka van. A sablonok a felhasználásuk során __fordítási időben fejtődnek ki__, így a sablonparaméterek behelyettesítési értékeinek már fordítási időben eldönthetőnek kell lenniük.


#### Alapértelmezett sablonparaméter


Akárcsak a függvénysablonok esetében, osztálysablonoknál is lehetőségünk van __alapértelmezett értéket__ megadni sablonparaméternek.

```cpp
template <typename T = int>
class MyClass { ... }

int main()
{
  MyClass<> mc;
  MyClass<char> mc2;
}
```

A ```T``` paraméternek az ```int``` alapértelmezett értéket adtuk. Így, ha az osztálysablon felhasználásakor nem adunk neki értéket, akkor az ```int``` értéket veszi fel. Az alapértelmezett osztálysablonok megadására ugyanazok a szabályok érvényesek, mint az alapértelmezett függvénysablonokra: jobbról balra sorban haladva kihagyás nélkül tetszőleges számú paraméternek adható alapértelmezett érték. Az alapértelmezett sablonparaméterek lehetővé teszik olyan sablonok készítését, melyek széles körben testre szabhatóak, ugyanakkor legtöbb helyzetben könnyen felhasználhatók.


#### Mutatók és referenciák, mint sablonparaméterek


Amennyiben az elemtípus, vagyis a ```T``` összetett, nagyobb méretű objektumokat erdeményező típus, akkor ezeket az objektumokat referenciaként érdemes paraméterben átadni a függvénynek annak érdekében, hogy elkerüljük a paraméterátadáskori másolat készítését, s így a másolókonstruktor hívását. Ezt úgy tudjuk elérni, hogy a ```T``` sablonparaméternek ```T&```-t adunk meg. Hasonló az helyzet mutatók esetében is, ```T*```.


#### Tagfüggvénysablonok


Függvénysablonok nemcsak globális függvények lehetnek, hanem tagfüggvények is. Ezek közönséges osztályok vagy osztálysablonok tagfüggvényei egyaránt lehetnek.

```cpp
class MyClass
{
public:
  template <typename T>
  void print(T val)
  {
    std::cout << val;
  }
};
```

A ```print()``` függvényből a fordítás során annyi különböző verzió keletkezik, ahány különböző típussal használjuk. Tagfüggvénysablon lehet konstruktor is, azonban erre van pár megkötés: a sablonkonstruktor sohasem fog másolókonstruktorként viselkedni, ezt mindig meg kell írni közönséges konstruktor formájában.


#### Az osztálysablonok és az öröklés


Tekinstsük az alábbi programot:

```cpp
class ClassA { ... };

template <typename T1, typename T2>
class TemplA
{
  T1 a;
  T2 b;
};
```

A ```ClassA``` közönséges osztály, a ```TemplA``` két sablonparaméterrel rendelkező osztálysablon. __Ősosztályként minden esetben csak közönséges osztály vagy felparaméterezett osztálysablon használható.__ Először nézzünk példát  a ```TemplA```-ból, mint ős osztálysablonból egy közönséges osztályt származtatunk:

```cpp
class ClassB: public TemplA<int, ClassA>
{ ... };
```

Az ős osztálysablonnál a ```T1``` paraméter helyébe az ```int``` kerül, a ```T2``` helyébe a ```ClassA``` osztályt helyettesítjük.  A következő esetben a ```ClassA```-ból mint közönséges osztályból osztálysablont származtatunk le:

```cpp
template <typename T1>
class TemplB: public ClassA
{
  T1 t; // T1 típusú tagváltozó
}
```

A legösszetettebb esetnek az osztálysablonból új osztálysablon leszármaztatása tekinthető. Például:

```cpp
template <typename T3, typename T4>
class TemplC: public TemplA<int, T3>
{
  T3 t; // T3 típusú tagváltozó
}
```

A leszármaztatott ```TemplC``` osztálysablonnak két paramétere van: ```T3``` és ```T4```. A szabálynak megfelelően az ős sablonosztályt itt is felparaméterezve használtuk fel. A ```T1``` paraméternek a fix ```int``` értéket adtuk meg, ```T2```-nek azonban a leszármaztatott osztály ```T3``` paraméterét adtuk "tovább".


#### Osztálysablon-specializáció


Akárcsak a függvénysablonok esetében, az osztálysablonoknál is előfordulhatnak olyan esetek, amikor az általános implementáció nem megfelelő egy adott típusra.

Az osztálysablon-specializáció megírására a következő szabályok érvényesek:

* az osztálysablon neve előtt a ```template``` kulcsszó után ```< >``` között csak azokat a maradó sablonparamétereket kell felsorolni, amelyeket a továbbiakban is paraméterként kívánunk kezelni, vagyis amelyeket nem kívánunk specializálni.
* az osztálysablon neve után ```< >``` között fel kell sorolni valamennyi sablonparamétert: a nem specializáltakat a sablonparaméter nevének megadásával, a specializáltakat a paraméter értékével.
* egy osztálysablonhoz több specializáció is készíthető, természetesen különböző, a paraméterekre vonatkozó megkötésekkel.
* a fordító a sablon felhasználásakor mindig a lehető legspeciálisabban illeszkedő sablonverziót alkalmazza.
* a fordító az illesztés során semmiféle konverziót nem alkalmaz, így például ```const```<-> nem ```const``` verziót sem.


__Részleges sablonspecializáció__-nak (_partial template specialization_) nevezzük azt, amikor csak részben kötjük meg a sablonparamétereket.

__Teljes specializáció__-nak (_(full) template specialization_) nevezzük, amikor minden sablonparaméterre adunk megkötést.


### Sablonok fordítása


A sablonok használatával kapcsolatban alapvető fontosságú annak ismerete, hogy a __sablonok fordítási időben fejtődnek ki__. Amikor a fordító a fordítás során először "találkozik" az osztály- vagy függvénysablon egy adott példányosításával, megfelelően behelyettesíti a sablonparamétereket, és legenerálja a behelyettesítésnek megfelelő kódot. __Osztálysablonok esetében a kódgenerálás tagfüggvényenként történik__, vagyis egy tagfüggvény kódja csak akkor generálódik le, ha legalább egy helyen használjuk.  Vizsgáljuk meg a korábban bevezetett ```MyClass``` osztálysablont.

```cpp
template <typename T>
class MyClass
{ ... };

int main()
{
  MyClass<int> mc1;
  mc1.setA(2);
  mc1.getA();

  MyClass<double> mc2;
  mc2.setA(3.14);
}
```

Amikor a fordító a ```MyClass<int> mc1;``` sorhoz ér, veszi a ```MyClass``` osztálysablont, a ```T``` paraméter helyébe ```int```-et helyettesít, legenerálja az alapértelmezett konstruktorának a kódját, és ennek hívására vonatkozóan generál kódot. A ```mc1.setA(2);``` sorhoz érve a fordító veszi a ```MyClass``` osztálysablont, a ```T``` helyére ```int```-et helyettesít, legenerálja a ```setA()``` metódus kódját, és most ennek a hívására vonatkozóan generál kódot. A ```getA()```  metódus kódja a ```setA()```-hoz hasonló módon generálódik. Hasonló a helyzet lép fel a ```MyClass<double> mc2;``` esetében is, csak ```int``` helyett ```double``` típust fog behelyettesíteni a fordító.

A sablonok ezen fordítási mechanizmusának számos kellemes és kellemetlen következménye van:

1. __Optimalizáció__: ha egy adott osztálysablon tagfüggvényét sehol sem használjuk, akkor nem fog legenerálódni a kód. Ennek következtében a generált kód mérete lényegesen kisebb lehet, mint a közönséges osztályokkal vagy függvényekkel dolgoznánk. Így alkalmazásuk a háttértáron és a memóriában is a lehető legkisebb helyet foglalja el.
2. __Kódburjánzás__: ha egy sablon - akár osztály akár függvény - több paraméterkombinációval használunk, valamennyire vonatkozóan legenerálódik a sablon tagfüggvényeinek kódja, ami a generált kód méretének növekedéséhez vezet. Ezt szokás __kódburjánzás__-nak vagy __kódfelfúvódás__-nak nevezni (_code bloat_).
3. __Fordítási hibák__: a fordítási modell talán legmeghökkentőbb következménye, hogy a __fordítási hibák rejtve maradnak__. Könnyen megeshet, hogy egy osztály- vagy függvénysablon megírását követően a fordítás során semmilyen hibát sem kapunk, és a kód mégis tele van szintaktikai és egyéb hibákkal. Valójában nem is várhatunk mást, mert a sablonok tagfüggvényei csak akkor fordulnak le, ha használjuk őket. Mindaddig nem esnek át teljes szintaktikai ellenőrzésen. Ilyen esetekben az osztálysablonok __explicit példányosítása__ (_explicit template instantiation_) lehet a válasz. Az explicit példányosítás a megadott paraméterekkel valamennyi tagfüggvényre vonatkozóan kikényszeríti a kód generálást. Például ```template class MyClass<int>;``` Ez a sor a ```MyClass``` osztálysablont a ```T = int``` paraméter-behelyettesítéssel példányosítja.

Függvénysablonok esetén is van lehetőségünk explicit példányosításra. Ehhez az adott függvénysablont a ```template``` kulcsszót követően az adott paraméter-behelyettesítésekkel deklarálni kell:

```cpp
template<typename T>
inline T max(T lhs_, T rhs,)
{
  return lhs_ > rhs_ ? lhs_ : rhs_;
}
// példányosítás T=int behelyettesítéssel
template inline int max<int>(int lhs_, int rhs_);
```

A fenti példában a ```max()``` függvény ```inline```, így az explicit példányosítás legenerálja ugyan a kódját, a hívás helyére azonban, amennyiben lehetséges, a törzse fog behelyettesítődni.

Az explicit példányosítás jól használható arra, hogy "előcsaljuk" a fordítási hibákat, de a kód részletes tesztelését önmagában nyilvánvalóan nem oldja meg.

Az explicit példányosítást sablon osztálykönyvtárak készítésekor is felhasználhatjuk.

Ha egy sablon a paraméterek adott kombinációjával jól lefordul és működik, még nem jelenti azt, hogy más paraméterek esetén is jól fog működni.


#### Fejléc- és forrásfájlok


A közönséges függvények és osztályok esetében a következő elvet használjuk:

* a függvények deklarációit a fejléc- (```.h```), a definícióit a forrásfájlokba (```.cpp```) tesszük.
* az osztályok deklarációit a fejléc- (```.h```), a tagfüggvények definícióit a forrásfájlokba (```.cpp```) tesszük.

Ez az elv sablonok esetében nem használható. Tekintsük a következő kódot:

```cpp
// MyClass.h
template <typename T>
class MyClass
{
public:
  void setA(T a_);
private:
  T _a;
};

// MyClass.cpp
#include "MyClass.h"

// a setA() tagfüggvény definíciója
template <typename T>
void MyClass<T>::setA(T a_)
{
  _a = a_;
}

// main.cpp
#include "MyClass.h"

int main()
{
  MyClass<int> mc;
  mc.setA(10);
}
```

A kód fordítási hibát okoz. Mit lát a fordító a __main.cpp__ feldolgozása során? A preprocesszor kifejti az ```#include "MyClass.h"```-t, és mivel ez gyakorlatilag egy egyszerű szövegszerű behelyettesítést jelent, a fordító a következő fájlon "dolgozik":

```cpp
// main.cpp
// MyClass.h
template <typename T>
class MyClass
{
public:
  void setA(T a_);
private:
  T _a;
};

int main()
{
  MyClass<int> mc;
  mc.setA(10);
}
```

A sablonokról tudjuk, hogy __fordítási__ (és __nem linkelési__) időben fejtődnek ki. A fordító a forrásfájlokat egyesével dolgozza fel, így a __main.cpp__ feldolgozásakor kizárólag a fenti forráskódot látja. A sablon kifejtéséhez a teljes forráskódjának a fordító rendelkezésére kell állnia. Így az ```mc.setA(10);``` hívásakor ez a feltétel nem teljesül, hiszen az egy másik forrásfájlban van kifejtve. Ennek következtében a linker "_Unresolved external symbol..._" vagy valami hasonló hibaüzenetet ad. A tanulság az, hogy __az osztálysablonok esetében a felhasználás során a tagfüggvények definícióját is elérhetővé kell tenni a fordtó számára__. Ezt kétféle képpen tehetjük meg. Az első megoldás szerint a tagfüggvényeket az osztálysablon-definíciójában "inline módon" adjuk meg.

```cpp
// MyClass.h
template <typename T>
class MyClass
{
public:
  void setA(T a_)
  {
    _a = a_;
  }
private:
  T _a;
};
```

A másik megoldás szerint a tagfüggvényeket az osztálydefiníciós fejlécfájlban de nem "inline módon" adjuk meg.

```cpp
// MyClass.h
template <typename T>
class MyClass
{
public:
  void setA(T a_);
private:
  T _a;
};

template <typename T>
void MyClass<T>::setA(T a_)
{
  _a = a_;
}
```

__Megjegyzés__: közönséges osztályok tagfüggvényei esetében ez utóbbi megoldás linkelési hibához vezetne a fejlécfájl többszöri ```include```-olása miatt. Osztálysablonok esetében ez nem igaz, mert a linker "okosan" mindig az első definíciót teszi a lefordított kódba, és a hivatkozásokat is erre vonatkozóan oldja fel. Ugyanez igaz a globális függvénysablonokra is, a közönséges függvényekkel szemben ezek definícióját is a fejlécfájlokba tesszük.


## Típuskonverziók


Az eddigiek során többször is észrevehettük, hogy a C++ típuskonverziói nagyban hasonlítanak a C nyelvre, mégis vannak különbségek. Ennek egyik oka, hogy a C++ fejlesztői már a kezdetektől fogva törekedtek rá, hogy a C-nél biztonságosabb nyelvet alkossanak. Másfelől a C++-ban megjelennek teljesen új, objektumorientált nyelvi elemek, amelyekhez új típuskonverziók tartoznak. A típustámogatás C++ alapelvét követve lehetőségünk van arra, hogy beépített automatikus típuskonverziókat írjunk. A C++ finomítja a C konverziós operátort: annak funkciója szerint négy konverziós operátort különböztet meg.


### Beépített típusok közötti típuskonverzió


A C nyelvben az ```enum``` és az ```int``` típus között létezik automatikus oda-vissza létezik implicit konverzió. Ezzel szemben C++-ban, ha ```enum``` típusra konvertálunk, ki kell írnunk a típuskonverziót.

```cpp
enum days {Mon, Tue, Wed, Thu, Fri};

int main()
{
  enum days day = Mon; //*
  int d;

  // C/C++ OK
  d = Mon;

  // C OK, C++ hiba
  day = d;

  // C/C++ OK
  day = (enum days)d; //*
}
```

A C++-ban az ```enum``` felhasználásakor (a ```*```-al jelölt sorokban) természetesen elhagyhatjuk az ```enum``` kulcsszót, mert az ```enum```  neve önmagában is típusértékű, de itt a C-vel való kompatibilitás miatt kiírtuk.

A C automatikus konverziót biztosít a ```void*``` típusú mutató és tetszőleges típusú mutató között oda-vissza, a C++-ban ezt a konverziót is ki kell írnunk.

A referenciája a következő szabályok érvényesek. Nem konstans referenciára nincs automatikus konverzió inkompatibilis típusok referenciáiról. Tekintsük az alábbi programot:

```cpp
void f(double& d)
{
  d = 1;
}

int main()
{
  int m = 2;
  f(m); // 1. hiba
  f((double)m) // 2. hiba
  f((double&)m) // 3. lefordul, de hibás
}
```

```int``` és ```double``` között van automatikus típuskonverzió. Referencia esetén azonban ugyanaz a helyzet, mint a mutatóknál: mindkettő memóriacímet jelent. A mutatóhoz hasonlóan két típus kötődik hozzá: a referencia típusa, amelyet megadunk deklarációként, illetve az adott memóriaterületen található változó típusa. Ez nem meglepő hiszen referenciára is működik a polimorfizmus.

Amikor egy ```int``` típusú változóval inicializálunk egy referenciát, a fordító hibát jelez, hiszen az ```int``` memóriareprezentációja eltér a ```double``` memóriareprezentációjától, és az a kísérlet, hogy ```int```-re jellemző memóriaterületet ```double```-ként kezelünk, nagy valószínűséggel programozói hiba. Nem is szólva arról, hogy a ```sizeof(int)``` kisebb lehet, mint a ```sizeof(double)```. vagyis az ```f()``` függvény a memóriában az ```m``` után következő változók értékét is elronthatja.

A második esetben az ```m``` változót konvertáljuk ```double``` típusúra. Ennek eredménye egy ideiglenes ```double``` érték, amely konstans, így nem adható át paraméterként olyan függvénynek, amely nem konstans referenciát vár. Ideiglenes értéket amúgy sem túl ésszerű változtatni, hiszen változtatás után nem férünk hozzá.

A harmadik esetben bemutatott "erőszakos" típuskonverzóval fordítási időben mindig sikerrel járunk.


### A felhasználói típusok konverziói


#### Konverzió független típusok között


Tegyül fel, hogy szeretnénk egy olyan __String__ osztályt írni, amely a C-beli lehetőségeknél könnyebbé teszi a szöveges műveleteket. A eddigiek alapján egyszerűen megírhatunk egy dinamikus karaktersorozatot tartalmazó osztályt, és az összeadás operátor megfelelő túlterhelésével lehetőséget biztosíthatunk sztringek kényelmes összefűzésére. Ugyanakkor szeretnénk, ha ez az osztály kompatibilis lenne az eddig C függvényekkel, ugyanis számos programozási felület C-ben íródott. A kompatibilitást kétféle módon szeretnénk megoldani:

1. ha egy függvény nullterminált karaktertömböt ad vissza vissza, akkor az automatikusan konvertálható legyen a __String__ osztályra. Pl. ha van egy függvényünk, amely __String__ argumentumot vár, akkor ott átadhassunk egy ```char*``` típusú, nullterminált, C stílusú sztringet.
2. ha van egy __String__ objektumunk, szeretnénk, hogy átadható legyen bárhol, ahol konstans C stílusú sztringet kell átadni.

Erre a két problémára a C++ két nyelvi elemet kínál. Ha egy __másik__ - esetleg beépített - __típusról__ szeretnénk konvertálni a mi __osztályunk típusára__, a __konverziós konstruktor__ jelent megoldást. Ha az __osztályunkról__ szeretnénk egy __másik típusra__ konvertálni, akkor a __konverziós operátor__ a megfelelő eszköz.

A konverziós konstruktor olyan egyparaméteres konstruktor, amelynek a paramétere olyan típusú, amilyen típusról konvertálni szeretnénk.

A konverziók leggyakoribb problémája, hogy bizonyos kifejezések esetén több megoldás is létezik, és a fordító nem tud választani. Ha a típuskonerziós útvonal nem egyértelmű, fordítási hibát jelent.

__Útmutató__:

* csak akkor írjunk konverziót, ha természetes. Sose erőltessük a konverziót.
* nagyon vigyázzunk a védett (_private_, _protected_) tagváltozók kiadására konverziós operátorok esetén, mert lehetőséget adhatunk objektumaink inkonzisztensé tételére. Ha kiadjuk ezeket a paramétereket konstansként tegyük, és írjuk elő az osztály felhasználóinak, hogy ne tárolják el a kapott értéket.
* konverziós operátor helyett használjuk a konverziós konstruktort. Az egységbe zárás alapelve miatt érdemesebb egy másik adatszerkezet alapján felépíteni az osztályt, mint kiadni az elrejtett tagváltozóit.
* mindig csak a legszükségesebb konverziót írjuk meg, mert minél több a konverzió, annal valószínűbb a kétértelműség.


#### Konverzió az öröklési hierarchia mentén


Tekintsük a leszármazottról szülőre történő típuskonverziót. Elékezzünk vissza a ```Person```-```Employee``` példájára.

```cpp
  Employee employee("John", 28, 3);
  Person p = (Person)employee;
```

Vagy az imént említett konstruktorszintaktikával:

```cpp
Person p = Person(employee);
```

A példa második fele jól illusztrálja, hogy itt konsruktor fog meghívódni. Felmerül a kérdés, hogy melyik konstruktor. A válasz a másolókonstruktor, hiszen a behelyettesíthetőség elve miatt a ```Person&``` típusú paraméter esetén megadhatunk ```Employee``` típusú objektumot. A másolókonstruktor viszont csak  az ősosztály részével "foglalkozik", így az __employee__ változó "alja" nem másolódik át, elveszik a konverzió során.

![objectOnTheFly](img/objectOnTheFly.png)

A C++ élénk fantáziájú úttörői ezt a konverzió közben történő jelenséget "szeletelés kapásból" (__slicing-on-the-fly__) névvel illették. Az eredeti, konvertált obejktum megmarad, mindössze a konverzió során nem másolódik át egy rész, bár az új objektu kétségkívül úgy néz ki, mintha a réginek levágták volna az alját. Mindezt a fenti ábra szemlélteti.

__Fontos__: __polimorf viselkedést csak mutatón és referencián keresztül adhatunk.__


## A C++ típuskonverziós operátorai


Az explicit típuskonverziót C nyelven a kifejezés elé ```()``` zárójelek közé írt új típus megadásával definiálhatjuk.

```cpp
double d = (int)3.14;
```

Ezt a típuskonverziót használjuk például mutatók között, egészek között, a konstans változókat ezzel konvertáljuk nem konstanssá. A nagyobb biztonság és átláthatóság érdekében a C++ saját konverziós operátorokat definiál, amelyek jobban kifejezik a típuskonverzió jelentését. A C megoldás ugyanis egy kalap alá vesz bizonyos konverziós szándékokat. Jobb lenne, ha pontosabban meg tudnánk adni a konverzió célját. Ezeket a C++ nyelvben az alábbi operátorok segítik:

* ```static_cast``` (statikus típuskonverzió)
* ```const_cast``` (konstans típuskonverzió)
* ```dynamic_cast``` (dinamikus típuskonverzió)
* ```reinterpret_cast``` (újraértelmező típuskonverzió)

Ezek az operátorok a 2. precedenciaszinten helyezkednek el. szintaxisuk az alábbi:

```static_cast <típusnév> (kifejezés)```

```const_cast <típusnév> (kifejezés)```

```dynamic_cast <típusnév> (kifejezés)```

```reinterpret_cast <típusnév> (kifejezés)```

A C stílusú típsukonverzió helyett leggyakrabban a __statikus típuskonverziót__ használjuk. Vagyis a lefelekerekítés végett eddig azt írtuk, hogy

```cpp
double d1 = (int) d2;
```

a C++-ban ez az alábbi formát ölti:

```cpp
double d1 = static_cast<int>(d2);
```

Ősosztály típusú mutatóról leszármazott típusú mutatóra is ezt a konverziós operátort használjuk, ha biztosak vagyunk a konverzióban. Ha nem ez a helyzet, akkor a ```dynamic_cast``` operátor futási időben megállapítja, hogy helyes-e a konverzió, és csak akkor hajtja végre.

A statikus típuskonverziónak megmaradtak azok a megkötései, amely a C stílusú elődjének, valamint nem konvertálhat konstans típust sem nem konstanssá, ekkor fordítási idejű hibát kapunk. Erre ugyanis egy kifejezetten erre a célra létrehozott típuskonverziós operátor áll a rendelkezésre.

A __konstans típuskonverzó__ képes egyedül konstans típust nem konstanssá tenni, illetve ```volatile``` típust nem azzá. Ez ugyanis olyan veszélyes művelet, amelyet külön át kell gondolni, és feltűnően megjelölni a kódban. Egyéb konverziókra nem alkalmazható. Más C++ konverziós operátor nem képes végrehajtani ezt a konverziót. Példaként tekintsük meg az alábbi függvényt, amely egy vásárolt osztálykönyvtár része és nincs jogunkban módosítani a forráskódját.

```cpp
void AddToStream(char* buff, unsigned len) { ... }
```

Ez a függvény egy ismeretlen formátumú állományhoz adja a változót. Mivel mentésről van szó, a ```buff``` változót konstansként kellett volna definiálni. Így, ha ki szeretnénk írni egy konstans tagváltozót, mert az állomány formátuma előírja, akkor típuskonverzióhoz kell folyamodnunk, amely nem konstanssá teszi az elmentendő változót. C++ nyelven erre az alábbi kódrészlet a legmegfelelőbb megoldás:

```cpp
class Data
{
public:
  const char _c;
  Data(char c_): _c(c_) { }
  void Save()
  {
    AddToStream(const_cast<char*>(&_c), sizeof(_c));
  }
};
```

A __dinamikus típsukonverzió__ szintén speciális típuskonverziót valósít meg: az öröklési hierarchián lefelé történő konverzióhoz szükséges. Az osztályoknak polimorfoknak kell lenniük, azaz a konvertálandó típusnak legalább egy virtuális függvényt kell tartalmazni. Mivel futási időben ellenőrzni, hogy tényleg végrehajtható-e a típuskonverzió, használatához a futásidejű típusinformációk kezelését be kell kapcsolnunk a fordításkor. Ezen típusinformáció segítségével a keresztbe konverziót is megoldja többszörös öröklés esetén, vagyis biztonságos. Ha a kívánt konverzió nem sikerül, akkor az operátor ```bad_cast``` kivételt dob. Privát öröklésnél nem használható az osztályhierarchián lefele való konverzióra, mert futási idejű hibát kapunk.

Az __újraértelmező típuskonverzió__ az implementációfüggő konverziók esetén használható. Általában mutatókra alkalmazzuk, amikor lényegében csak a mutató típusát változtatjuk, vagyis azt, hogy milyen műveletek értelmezhetők egy memóriaterületen. Ezért hatása sokszor fordítófüggő. Mivel az egész típusok és a mutatók mérete fordítófüggő, ezért az egész típusok és a mutatók közötti konverziók esetén is ezt az operátort használjuk. Ugyanakkor konstans típust nem konstanssá ez az oeprátor sem képes átkonvertálni.

Összegezve a C++-ban explicit típuskonverzió végett használható a konstruktorszintaxisú típuskonverzió, a régi C szintaktikájú típuskonverzió,illetve az útóbbit érdemes felváltanunk a ```static_cast```, ```const_cast```, ```reinterpret_cast``` valamelyikével. A ```dynamic_cast``` egyedülálló: a többi típuskonverziós operátor nem képes ellátni, viszont ennek az ára, hogy futásidejű típusinformációval és annak lekérdezésével lassítjuk programunkat.

__Útmutató__:

* ha a konverziónak tobb argumentuma van, mindig a konstruktorszintaxist alkalmazzuk
* C stílusú konverzió helyett használjuk a leginkább odaillő C++ konverziós operátort
* a dinamikus típuskonverziót lehetőleg kerüljük el.


## Imlicit konverzió


Implicit konverzióról akkor beszélünk, ha egy adott típusú objektumnak egy másik típusú objektumot adunk értékül, és az egyik objektum a másik típusára konvertálódik anélkül, hogy mi ezt a konverziót külön (explicit módon, pl. cast-ok segítségével) „kértük” volna.

A nyelv egyik érdekessége, hogy lévén a ```char``` típusok tudnak számokat tárolni, így egy ```char``` objektum könnyedén át tud konvertálni ```int``` típusúra. Példaképp, az ```’a’ + ’b’``` összeadásnál a karakterek összeadása nem definiált, azonban ```int```-ek között igen, így a fordító implicit módon átkonvertálja azokat ```int```-é.


Amennyiben a fordító megpróbál egy műveletet elvégezni, de típushiba miatt ez meghiúsul, megpróbálja az objektumokat átkonvertálni, lehetőleg veszteségmentesen. A fordító először implicit konverzióval próbálkozik, aztán egy felhasználó által definiált konverzióval, majd ismét egy implicit konverzióval. Amennyiben ezek után sem megvalósítható a művelet típushiba miatt, fordítási hibát kapunk.


### Aritmetikai konverziók


1. ha az egyik operandus ```long double```, akkor a másikat is ```long double```-ra konvertáljuk.
2. különben, ha az egyik operandus ```double```, akkor a másik is ```dobule``` lesz.
3. különben, ha az egyik ```float```, akkor a másik is ```float``` lesz.
4. amennyiben egyik operandus sem lebegőpontos, akkor haz az egyik operandus ```unsigned long```, akkor a másik is az lesz.
5. ha az egyik operandus ```long```, a másik pedig ```unsigned int```, akkor előfordulhat az, hogy a két típus ugyanakkora tárterületen van tárolva. Ha az ```int``` és a ```long``` mérete megegyezik, akkor ```unsigned long``` lesz mindkét operandus. Különben ha a ```long``` nagyobb, akkor ```long```-gá konvertálódik a másik.
6. különben, ha az egyik ```long``` a másik pedig nem ```unsignem int```, akkor ```long```-gá konvertálódik a másik operandus.
7. különben, ha az egyik operandus ```unsigned int```, a másik is kovertálódik ```unsigned int```-té.
8. különben minden ```int```-té konvertálódik, ha egyik korábbi sem teljesül.


### Logikai konverzió


Amikor ```for``` ciklusban vagy ```if``` ágban meg kell adnunk egy logikai értéket, akkor ott gyakran történhet implicit konverzió. Példaképp minden lebegőpontos vagy egész szám ami nullától különböző ```true``` értékre konvertálódik, míg a nulla érték ```false```-ra. Mutatóknál minden nem ```nullpointer``` ```true```.
