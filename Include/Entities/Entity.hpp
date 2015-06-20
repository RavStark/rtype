/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#ifndef __ENTITY_HPP__
# define __ENTITY_HPP__

#include <string>

namespace sf{
	class RenderWindow;
}

class Entity
{
public:
	Entity();
	~Entity();

	void setPos(int x, int y) { _posX = x; _posY = y; };
	void setWidth(unsigned width) { _width = width; }
	void setHeight(unsigned height) { _height = height; }
	virtual bool loadTexture(const std::string &filename) = 0;
	virtual void draw(sf::RenderWindow &mainWindow) const = 0;

protected:
	int _posX = 0;
	int _posY = 0;
	unsigned _width = 0;
	unsigned _height = 0;
};

#endif