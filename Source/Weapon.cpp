/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#include "Weapon.hpp"

Weapon::Weapon()
	:_type(WeaponType::DEFAULT)
{

}

Weapon::Weapon(WeaponType type)
: _type(type)
{

}

unsigned Weapon::getRapidFire(void) const
{
	unsigned rapidFire = 0;
	switch (_type)
	{
	case Weapon::DEFAULT:
		rapidFire = 5;
		break;
	case Weapon::MEGA:
		rapidFire = 10;
		break;
	case Weapon::ULTRA:
		rapidFire = 20;
		break;
	default:
		break;
	}
	return rapidFire;
}

unsigned Weapon::getFirePower(void) const
{
	unsigned firePower = 0;
	switch (_type)
	{
	case Weapon::DEFAULT:
		firePower = 5;
		break;
	case Weapon::MEGA:
		firePower = 10;
		break;
	case Weapon::ULTRA:
		firePower = 20;
		break;
	default:
		break;
	}
	return firePower;
}