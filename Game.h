#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>


class Game
{
private:
	//varaibles

	//window

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event event;

	//game objects

	sf::RectangleShape enemy;

	//private functions
	void initVariables();
	void initWindow();
	void initEnemies();

public:

	//constructor, destrucctor
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;


	//functions
	void poll_events();
	void update();
	void render();
};

