/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include "Entities/Entity.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
class Player : public Entity
{
public:
	Player(unsigned width, unsigned height);
	Player(int x, int y, unsigned width, unsigned height);
	~Player();
	virtual bool loadTexture(const std::string &filename);
	virtual void draw(sf::RenderWindow &mainWindow) const;
	void move(sf::Vector2f &vec) { _sprite.move(vec); std::cout << _sprite.getPosition().y << std::endl; }
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
};

#endif