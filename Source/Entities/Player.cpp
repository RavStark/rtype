/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#include "Entities/Player.hpp"
#include <iostream>

Player::Player(unsigned width, unsigned height)
:Entity()
{

}
Player::Player(int x, int y, unsigned width, unsigned height)
:Entity()
{
}

Player::~Player()
{

}

bool Player::loadTexture(const std::string &filename)
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

void Player::draw(sf::RenderWindow &mainWindow) const
{
	mainWindow.draw(_sprite);
}