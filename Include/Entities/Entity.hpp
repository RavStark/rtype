/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#ifndef __ENTITY_HPP__
# define __ENTITY_HPP__

#include "SFML/Graphics.hpp"
#include <string>

namespace sf{
	class RenderWindow;
}

class Entity
{
public:
	Entity();
	~Entity();

	void setPos(int x, int y);
	void setWidth(unsigned width);
	void setHeight(unsigned height);
	void move(const sf::Vector2f &vec);
	virtual bool loadTexture(const std::string &filename) = 0;
	void draw(sf::RenderWindow &mainWindow) const;

protected:
	int _posX = 0;
	int _posY = 0;
	sf::Sprite _sprite;
	sf::Texture _texture;
	//Weapon _weapon;
};

#endif