/*
R-TYPE
Remi Depond <depond.remi@gmail.com> 2015
*/

#include "Core.hpp"
#include "Entities/Player.hpp"
#include <iostream>

Core::Core()
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
	_player->setHeight(157 / 2);
	_player->setWidth(127 / 2);
	if (!_mainWindow.isOpen())
		return false;
	
	return true;
}

void Core::close()
{

}

/*SDL_Surface *SDLCore::loadImage(const std::string &filename)
{
	SDL_Surface *loadedSurface = nullptr;
	SDL_Surface *optimizedSurface = nullptr;

	loadedSurface = IMG_Load(filename.c_str());
	if (loadedSurface != nullptr)
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, _screenSurface->format, NULL);
		if (optimizedSurface == NULL)
			return nullptr;
		//{ printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError()); }
		//optimizedImage = SDL_ConvertSurfaceFormat(loadedImage, SDL_PIXELTYPE_UNKNOWN, 0);
		SDL_FreeSurface(loadedSurface);
		return optimizedSurface;
	}
	return nullptr;
}

SDL_Texture* SDLCore::loadTexture(const std::string &path)
{
	//The final texture
	SDL_Texture* newTexture = nullptr;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == nullptr )
		std::cerr << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(_windowRenderer, loadedSurface);
		if (newTexture == nullptr)
		{
			std::cerr << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError() << std::endl;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}*/

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
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		sf::Time elapsed = _clock.restart();
		time = elapsed.asSeconds();
		while (_mainWindow.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == sf::Event::Closed)
				_mainWindow.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// la touche "fl�che gauche" est enfonc�e : on bouge le personnage
			_player->move(sf::Vector2f(-450 * time, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// la touche "fl�che gauche" est enfonc�e : on bouge le personnage
			_player->move(sf::Vector2f(0, -450 * time));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// la touche "fl�che gauche" est enfonc�e : on bouge le personnage
			_player->move(sf::Vector2f(450 * time, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// la touche "fl�che gauche" est enfonc�e : on bouge le personnage
			_player->move(sf::Vector2f(0, 450 * time));
		}
		_mainWindow.clear(sf::Color(sf::Color(0, 0, 0)));
		_player->draw(_mainWindow);
		_mainWindow.display();
	}
}