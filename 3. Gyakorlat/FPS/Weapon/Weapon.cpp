#include "Weapon.hpp"

Weapon::Weapon(const std::string& weaponName_, double weaponDamage_, int weaponAmmoCapacity_, int weaponAccuracy_)
{
    _weaponName = weaponName_;
    _weaponDamage = weaponDamage_;
    _weaponAmmoCapacity = weaponAmmoCapacity_;
    _weaponAccuracy = weaponAccuracy_;
    _weaponObjectCounter++;
}

void Weapon::setWeaponDamage(double weaponDamage_)
{
    if (weaponDamage_ < 0)
        std::cout << "Damage can not be a negative number!";
    else
        _weaponDamage = weaponDamage_;
}

void Weapon::setWeaponAmmoCapacity(int weaponAmmoCapacity_)
{
    if (weaponAmmoCapacity_ < 0)
        std::cout << "Ammo capacity can not be a negative number!";
    else
        _weaponAmmoCapacity = weaponAmmoCapacity_;
}

void Weapon::setWeaponAccuracy(int weaponAccuracy_)
{
    if (weaponAccuracy_ < 0)
        std::cout << "Accuracy can not be a negative number!";
    else
        _weaponAccuracy = weaponAccuracy_;
}

int Weapon::_weaponObjectCounter = 0;

Weapon::~Weapon() { }