#include "Player.hpp"

Player::Player()
{
    _playerFullName = "Unknow Solider";
    _playerWeight = 0.0;
    _playerHeight = 0;
    weaponSlot.reserve(3); 
    _playerObjectCounter++;
}

Player::Player(const std::string& playerFirstName_, const std::string& playerLastName_,
               double playerWeight_, int playerHeight_, int weaponSlotCapacity)
{
    _playerFullName = playerFirstName_ + " " + playerLastName_;
    _playerWeight = playerWeight_;
    _playerHeight = playerHeight_;
    
    if(weaponSlotCapacity < 1 || weaponSlotCapacity > 5)
        _weaponSlotCapacity = 3;
    else
        _weaponSlotCapacity = weaponSlotCapacity;
    
    weaponSlot.reserve(_weaponSlotCapacity);
    _playerObjectCounter++;
}

void Player::addWeaponToPlayer(const Weapon& weapon_)
{
    if(weaponSlot.size() < _weaponSlotCapacity)
        weaponSlot.push_back(weapon_);
    else
        std::cout << "Player: " << this->getPlayerName() << " can't carry more weapon" << std::endl;
}

void Player::showPlayerWeapons()
{
    for(int i = 0; i < weaponSlot.size(); i++)
        std::cout << weaponSlot[i].getWeaponName() << std::endl;
}

Player::~Player() { }

int Player::_playerObjectCounter = 0;