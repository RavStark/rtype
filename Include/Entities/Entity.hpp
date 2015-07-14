/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#ifndef __ENTITY_HPP__
# define __ENTITY_HPP__

#include "SFML/Graphics.hpp"
#include <string>
#include <memory>

namespace sf{
	class RenderWindow;
}

class Weapon;

class Entity
{
public:
	Entity();
	~Entity();

	int getPosX(void) const;
	int getPosY(void) const;
	void setPos(int x, int y);
	void setWidth(unsigned width);
	void setHeight(unsigned height);

	//weapon
	void setWeapon(const std::shared_ptr<Weapon> &weapon) { _weapon = weapon; }
	std::shared_ptr<Weapon> getWeapon(void) const { return _weapon; }
	void move(const sf::Vector2f &vec);
	virtual bool loadTexture(const std::string &filename) = 0;
	void draw(sf::RenderWindow &mainWindow) const;

protected:
	int _posX = 0;
	int _posY = 0;
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::shared_ptr<Weapon> _weapon;
};

#endif