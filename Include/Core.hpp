/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#ifndef __CORE_HPP__
# define __CORE_HPP__

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>

class Player;

class Core
{
public:
	Core();
	~Core();
	bool init(void);
	void close(void);
	//SDL_Surface *loadImage(const std::string &filename);
	//SDL_Texture *loadTexture(const std::string &path);
	bool loadMedia(void);
	void loop(void);
private:
	sf::RenderWindow _mainWindow;
	Player *_player;
};

#endif