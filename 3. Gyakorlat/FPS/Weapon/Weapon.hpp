#ifndef _WEAPON_H_
#define _WEAPON_H_ 

#include <iostream>

class Weapon
{
private:
    std::string _weaponName; 

    double _weaponDamage;        
    int _weaponAmmoCapacity;     
    int _weaponAccuracy;   

    static int _weaponObjectCounter;
    
public:
    Weapon(const std::string&, double, int weaponAmmoCapacity_ = 0 , int weaponAccuracy_ = 0);     
    ~Weapon();                                         
    
    // getters
    inline const std::string& getWeaponName() const { return _weaponName; }
    inline double getWeaponDamage() const { return _weaponDamage; }
    inline int getWeaponAmmoCapacity() const { return _weaponAmmoCapacity; }
    inline int  getWeaponAccuracy() const { return _weaponAccuracy; }
    
    // setters
    void setWeaponDamage(double);
    void setWeaponAmmoCapacity(int);
    void setWeaponAccuracy(int);
    
    // friend declaration
    friend int getWeaponObjectCount();
    
};

#endif
