/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include "Entities/Entity.hpp"
#include <iostream>

class Player : public Entity
{
public:
	Player();
	Player(int x, int y);
	~Player();
	virtual bool loadTexture(const std::string &filename);
private:
	unsigned _hp;
	unsigned _shield;

};

#endif