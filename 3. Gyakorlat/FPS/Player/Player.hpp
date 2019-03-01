#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../Weapon/Weapon.hpp"

#include <vector>

class Player
{
private:
    std::string _playerFullName;

    double _playerWeight;
    int _playerHeight;
    int _weaponSlotCapacity;

    std::vector<Weapon> weaponSlot;

    static int _playerObjectCounter;
public:
    Player();
    Player(const std::string&, const std::string&, double, int, int);
    ~Player();
    
    // getters
    inline const std::string& getPlayerName() const { return _playerFullName; }
    inline const double getPlayerWeight() const { return _playerWeight; }
    inline const int getPlayerHeight() const { return _playerHeight; }
    
    // methods
    void addWeaponToPlayer(const Weapon&);
    void showPlayerWeapons();
    
    // friend declaration
    friend int getPlayerObjectCount();
};

#endif
