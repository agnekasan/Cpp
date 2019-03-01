
/*
 Feladat:
 Egy videójáték egy részletét kell elkészíteni, mégpedig egy FPS játéknak. A programozó feladata, hogy ezt osztályok
 segítségével valósítsa meg.
 
 Első sorban készíteni kell egy Weapon osztályt.
 Az osztálynak legyen egy darab paraméteres konstruktora, ami bemenetként egy string-et, double-t és két int-et vár
 (fegyver típusának neve, sebzés, maximális lőszer, pontosság). Ezekhez hozza létre a szükésges adattagokat az osztályon
 belül és a láthatóságukat állítsa privátra (private). Mindegyik adattaghoz írjon egy megfelelő getter függvént, aminek
 segítségével le tudja majd kérdezni az objektum egyes értékeiket. Az adattagok közül csak a sebzés, maxmimális lőszer és a pontosság
 az amiknek az értékét módosítani szeretnénk a jövőben. Ezekhez hozza létre a megfelelő függvényeket, amiknek a segítségével ez
 lehetésgessé válik. Figyeljen arra, hogy ne lehessen negatív értéket adni ezeknek az adattagoknak, azaz csak akkor legyen engedélyezett
 a módosítás, ha egy 0 vagy attól nagyobb számra szeretnénk kicserélni a jelenlegi értékeket. Előfordulhat, hogy a maximális lőszert
 és a pontosságot nem tudjuk előre, így ezeknek adjon egy default értéket a konstruktor paraméternél, ez legyen 0.
 
 Ezek után készítsen egy Player osztályt, aminek konstruktor paraméterként megadhatjuk a játékos nevét (vezeték- és keresztnév),
 súlyát (kg-ban, pl. 83.5), magasságát (cm-ben, pl.185), és egy 1-5-ig terjedő skálán, hogy hány fegyvert tud mágánál tartani.
 Ha rossz számot adunk meg (<1 vagy >5), akkor ez az érték automatikusan 3 legyen, ellenkező esetben maga a megadott érték.
 A szükséges adattagokat hozza létre és a láthatóságukat allítsa privátra. A Weapon-öket egy vektorban szeretnénk tárolni, aminek
 a neve legyen weaponSlot. Az osztályhoz tartozzon egy default konstruktor is, ahol a magasságot és a súlyt állítsa 0-ra, a nevet
 "Unknow Solider"-re (itt az Unknow az első a Solider a második név) a hordozható fegyverek számát pedig 3-ra. Írja meg a szükséges
 lekérdező műveleteket, a név lekérdezésénél az egész nevet szerenénk vissza kapni (vezetéknév + keresztnév). Külön-külön nem szükséges.
 Módosítani egyik adattagon sem szeretnénk. Írjon egy függvényt melynek segítségével lehetőségünk van a Playernek egy új Weapon-t adni,
 abban az esetben, ha a weaponSlot még nincs tele. Ha tele van akkor egy figyelmeztető üzenetet jelenítsen meg, ahol hivatkizok a szóban
 forgó Player nevére pl. Hiba! A következő játékos : "jatékos neve" nem tud több fegyvert magánál hordozni! Illetve egy olyan metódust
 aminek segítségével le tudjuk kérdezni, hogy egy adott Player-nél milyen Weapon-ök vannak. (Itt a Weapon nevét szeretnénk csak kiírni,
 egymás alá, ha több van nála).
 
 Egy osztályszintű változóban tartsuk számon külön-külön, hogy eddig mennyi Weapon-t és Player-t hoztunk létre. Ezeket két barát (friend) függvény segítségével
 -- pl. getWeaponObjectCount() és a getPlayerObjectCount() -- le is tudjuk kérdezni. Azért barát, hogy ne egy adott objektum példányon lehessen csak meghívni.
 
 Hozzunk létre legalább két fegyvert, melyek közül az egyiknek nem tudjuk a maximális lőszer számát és a pontosságot, így ezeket a paramétereket mellőzzük
 a létrehozásnál, a másik Weapon-nél minden paramétert adjunk meg. Írassuk ki a képernyőre a Weapon-ök adatait. Hozzunk egy játékost bemeneti paraméterek nélkül,
 majd egy újabbat paraméterekkel. Teszteljük, hogy ha 6 vagy -1 méretű weaponSlot-ot szeretnénk adni akkor mi történik illetve ha a Weapon-öknél negatív számot adunk meg.
 Nézzük meg mi történik, ha több fegyvert akarunk adni a Playerne, mint amennyi elfér nála. Majd ezek után írassuk ki, hogy milyen fegyverei vannak és a legvégén pedig, hogy
 melyik osztályból hány objektumpéldányt hoztunk létre.
 
 Használjunk minél több -- a gyakorlaton látott illetve elhangzott --  C++ nyelvi eszközt, amely segítségével optimálisabbá tehetjük a
 kódunkat, mint pl. ahol lehet referenciával vegyük át az értékeket, illetve referenciként adjuk vissza, továbbá ahol lehet használjunk konstansokat.
 (Függvény bemeneti paraméter, vissza térési érték stb...)
 
 
 Az elkészítéshez szükséges anyagok közül szinte minden szerepelt gyakorlaton, illetve a gyakorlathoz tartozó anyagban benne van.
 Egy kis segítség pluszba ha vektornak szeretnénk helyet foglalni akkor a .reserve(n)-el tudjuk megtenni. Ez egy n méretű vektort fog allokálni, ami kezdetben üres.
 */

#include "Weapon/Weapon.hpp"
#include "Player/Player.hpp"

int getWeaponObjectCount();
int getPlayerObjectCount();

int main(int argc, const char * argv[]) {
    
    Weapon weapon_1("ShotGun", 55.5);
    Weapon weapon_2("MachineGun", 77.5, 100, 80);
    Weapon weapon_3("RepeaterCarabine", 80, 50, 87);
    
    Player player_1("Ryan", "Cooper", 83.5, 185, 3);
    player_1.addWeaponToPlayer(weapon_1);
    player_1.addWeaponToPlayer(weapon_2);
    player_1.addWeaponToPlayer(weapon_3);

    player_1.showPlayerWeapons();
    
    std::cout << std::endl;
    
    Player player_2 = Player();
    std::cout << player_2.getPlayerName() << std::endl;
    
    std::cout << std::endl;
    std::cout << getWeaponObjectCount() << std::endl;
    std::cout << getPlayerObjectCount() << std::endl;

    
    return 0;
}

int getWeaponObjectCount() { return Weapon::_weaponObjectCounter; }
int getPlayerObjectCount() { return Player::_playerObjectCounter; }


