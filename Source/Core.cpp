/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#include "Core.hpp"
#include "Entities/Player.hpp"
#include "Entities/Bullet.hpp"
#include <iostream>

Core::Core()
:_type(Scrolling::HORIZONTAL)
{
	_player = new Player;
}

Core::~Core()
{
}

bool Core::init()
{
	_mainWindow.create(sf::VideoMode(800, 600, 32), "R-TYPE");
	_player->loadTexture("./ship.png");
	//todo need set size with resolution
	_player->setHeight(157 / 2);
	_player->setWidth(127 / 2);
	if (!_mainWindow.isOpen())
		return false;
	
	return true;
}

void Core::close()
{

}

bool Core::loadMedia(void)
{
	//Loading success flag
	bool success = true;
	//Load PNG texture
	//_shipTexture = loadTexture( "ship.png" );
	//if (_shipTexture == nullptr)
	//{
	//	std::cerr << "Failed to load texture image!" << std::endl;
	//	success = false;
	//}
	return success;
}

void Core::loop(void)
{
	sf::Clock _clock;
	float time = 0;
	while (_mainWindow.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		sf::Time elapsed = _clock.restart();
		time = elapsed.asSeconds();
		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_mainWindow.close();
		}
		manageBullets(time);
		inputPlayer(time);
		_mainWindow.clear(sf::Color(sf::Color(0, 0, 0)));
		_player->draw(_mainWindow);
		for (auto bullet : _bullets)
			bullet->draw(_mainWindow);
		_mainWindow.display();
	}
}

void Core::manageBullets(float time)
{
	std::set<std::shared_ptr<Bullet>> _cleanBullets;
	for (auto bullet : _bullets)
	{
		if (isBulletsOutWindow(bullet))
			_cleanBullets.insert(bullet);
		else
			bullet->move(sf::Vector2f(900 * time, 0));
	}
	for (auto bullet : _cleanBullets)
		_bullets.erase(bullet);
}

bool Core::isBulletsOutWindow(const std::shared_ptr<Bullet> &bullet) const
{
	if (_type == Scrolling::VERTICAL && bullet->getPosY() < 0)
		return true;
	else if (_type == Scrolling::HORIZONTAL && bullet->getPosX() > _mainWindow.getSize().x)
		return true;
	return false;
}

void Core::inputPlayer(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// la touche "flèche gauche" est enfoncée : on bouge le personnage
		_player->move(sf::Vector2f(-450 * time, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// la touche "flèche gauche" est enfoncée : on bouge le personnage
		_player->move(sf::Vector2f(0, -450 * time));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// la touche "flèche gauche" est enfoncée : on bouge le personnage
		_player->move(sf::Vector2f(450 * time, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		// la touche "flèche gauche" est enfoncée : on bouge le personnage
		_player->move(sf::Vector2f(0, 450 * time));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (_bulletTime.getElapsedTime().asMilliseconds() > 100)
		{
			auto bullet = std::make_shared<Bullet>(_player->getPosX(), _player->getPosY());
			bullet->loadTexture("./Ressources/bullet.png");
			_bullets.insert(bullet);
			_bulletTime.restart();
		}
	}
}