/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#include "Entities/Bullet.hpp"
#include <iostream>

Bullet::Bullet(int x, int y)
{
	setPos(x, y);
}

Bullet::~Bullet()
{
}

bool Bullet::loadTexture(const std::string &filename)
{

	if (!_texture.loadFromFile(filename))
	{
		std::cerr << "[Player] Err: loading texture " << filename << std::endl;
		return false;
	}
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	return true;
}
