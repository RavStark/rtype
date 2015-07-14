/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#include "Entities/Entity.hpp"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::move(const sf::Vector2f &vec)
{
	_sprite.move(vec);
}

void Entity::draw(sf::RenderWindow &mainWindow) const
{
	mainWindow.draw(_sprite);
}

int Entity::getPosX(void) const
{
	return _sprite.getPosition().x;
}

int Entity::getPosY(void) const
{
	return _sprite.getPosition().y;
}

void Entity::setPos(int x, int y)
{
	_sprite.setPosition(x, y);
}

void Entity::setWidth(unsigned width)
{
	_sprite.scale(sf::Vector2f(width / _sprite.getLocalBounds().width,1));
}

void Entity::setHeight(unsigned height)
{
	_sprite.scale(sf::Vector2f(1, height / _sprite.getLocalBounds().height));
}