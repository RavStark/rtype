/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#ifndef __BULLET_HPP
# define __BULLET_HPP__

#include "Entities/Entity.hpp"

class Bullet : public Entity
{
public:
	Bullet(int x, int y);
	~Bullet();
	virtual bool loadTexture(const std::string &filename);
};

#endif