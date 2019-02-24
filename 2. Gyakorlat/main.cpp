#include <iostream>
#include <vector> // vektor használatához szükséges header


class Player
{
private:
// ha nem írjuk, hogy private nem baj, mert alapértelmezetten annak veszi, 
// jobb olvashatóság kedvéért tanácsos kiírni
	// adattagok
	std::string name;
	int positionX;
	int positionY;

public:
	Player(); // alapértelmezett (default) konstruktor
	Player(const std::string&, int, int); // paraméteres konstruktor
	~Player(); // destruktor

	// setters
	void setPlayerPosition(int, int);

	// getters
	const std::string& getPlayerName() const; // a class-on kívül van kifejtve a működése
	inline int getXPosition() const { return positionX; } // explicit inline
	int getYPosition() const { return positionY; } // implicit inline

	friend void playerCollisionDetection(const Player&, const Player&);
	
};

void playerCollisionDetection(const Player& player_1, const Player& player_2)
{
	if(player_1.getXPosition() == player_2.getXPosition() && player_1.getYPosition() == player_2.getYPosition())
		std::cout << player_1.getPlayerName() << " & " << player_2.getPlayerName() << " ugyan azon a helyen állnak" << std::endl;
	else
		std::cout << player_1.getPlayerName() << " & " << player_2.getPlayerName() << " nem ugyan azon a helyen állnak" << std::endl;
}

Player::Player()
{
	name = "Unknow Solider";
	positionX = 0;
	positionY = 0;
}

Player::Player(const std::string& name_, int positionX_ = 0, int positionY_ = 0)
{
	name = name_;
	positionX = positionX_;
	positionY = positionY_;
}

// paramétres konstruktor, ha a bemeneti paraméter neve ugyan az, mint az adattagoké
/*
Player::Player(const std::string& name, int positionX = 0, int positionY = 0)
{
	this->name = name;
	this->positionX = positionX;
	this->positionY = positionY;
}
*/

// paraméteres konstruktor member initialization list-el
/*
Player::Player(const std::string& name_, int positionX_ = 0, int positionY_ = 0)
	: name(name_), positionX(positionX_), positionY(positionY_) { }
*/

Player::~Player() { }

void Player::setPlayerPosition(int positionX_, int positionY_)
{
	positionX = positionX_;
	positionY = positionY_;
}

const std::string& Player::getPlayerName() const { return name; }


int main(int argc, char const *argv[])
{
	// Player objektumpéldányok létrehozása
	Player p1; // default konstruktor hívása
	Player p2("Ryan"); // paraméteres konstruktor hívása az X és Y koordináták 0 értékkel
	Player p3("Jack", 11, 2); // paraméteres konstruktor hívása az X = 11 és Y = 2 értékekkel

	/*
	std::vector<Player> playersVector; // vektor létrehozása amiben Player objektumpéldányokat tudunk tárolni
	
	playersVector.push_back(p1);
	playersVector.push_back(p2);
	playersVector.push_back(p3);

	// ha így adjuk át akkor minden egyes Player-ből egy másolat fog készülni
    // ami bekerül a vektorba, így ha szeretnénk módosítani pl. a p1-nek X és Y
    // koordinátáit (p1.setPlayerPosition(9,6);) az a vektoron belüli p1 objektumpéldányra
    // nem fog vonatkozni, mivel az csak egy másolata lesz a p1-nek. annak módosításához a
    // vektoron belüli indexével kell hivatkoznunk rá. (playersVector[0].setPlayerPosition(9,6);)
    // egy jobb megoldás lenne, ha Player-re mutató pointereket tárolnánk és a Player-eknek a 
    // referenciáját adnánk át
    */

    std::vector<Player*> playersVector; // vektor létrehozása amiben Player-re mutató pointerek fogunk tárolni
	
	// az egyes instance-ok referenciájának átadása
	playersVector.push_back(&p1);
	playersVector.push_back(&p2);
	playersVector.push_back(&p3);

	// kiírásnál alőször dereferálnunk kell a mutatott objektumot majd ezek után a . operátorral segítségével tudunk
	// metódushívást végrehajtani, azért kell zarójelezni, mert a . operátor erősebben köt, mint a *
	for (int i = 0; i < playersVector.size(); ++i)
		std::cout << "Player neve: " << (*playersVector[i]).getPlayerName() << ", X és Y pozíciója: " 
			<< (*playersVector[i]).getXPosition() << ", " << (*playersVector[i]).getYPosition() << std::endl;
	
	p1.setPlayerPosition(9,6); // most, ha az eredeti példányon módosítunk akkor a vektorban lévő is módosul
							   // ugyanis nem egy másolata van a vektorunkban csak egy mutató az eredeti p1-re

	std::cout << std::endl;

	// a -> (nyíl) operátor segítségével kiválthatjuk a dereferálást és a pont operátort és közvetlen elérjük a metódusokat
	for (int i = 0; i < playersVector.size(); ++i)
		std::cout << "Player neve: " << playersVector[i]->getPlayerName() << ", X és Y pozíciója: " 
			<< playersVector[i]->getXPosition() << ", " << playersVector[i]->getYPosition() << std::endl;

	std::cout << std::endl;
	playerCollisionDetection(p1, p2);

	return 0;
}