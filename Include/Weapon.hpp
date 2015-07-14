/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#pragma once

class Weapon
{
public:
	enum WeaponType{
		DEFAULT,
		MEGA,
		ULTRA
	};

	Weapon();
	Weapon(Weapon::WeaponType);
	~Weapon(){};
	

	void setType(const WeaponType &type){ _type = type; }
	WeaponType getType(void) const { return _type; }
	unsigned getFirePower(void) const;
	unsigned getRapidFire(void) const;
private:
	WeaponType _type;
};