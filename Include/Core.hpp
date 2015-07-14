/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#ifndef __CORE_HPP__
# define __CORE_HPP__

#include <set>
#include <memory>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>

class Player;
class Bullet;

enum Scrolling{
	HORIZONTAL,
	VERTICAL
};

class Core
{
public:
	Core();
	~Core();
	bool init(void);
	void close(void);
	bool loadMedia(void);
	void loop(void);
	void inputPlayer(float time);
private:
	sf::RenderWindow _mainWindow;
	sf::Clock _bulletTime;
	Player *_player;
	std::set<std::shared_ptr<Bullet>> _bullets;

	//type h or v
	Scrolling _type;

	void manageBullets(float time);
	bool isBulletsOutWindow(const std::shared_ptr<Bullet>&) const;
};

#endif