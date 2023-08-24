#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>


class Game
{
private:
	//Varaibles

	//Window

	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event event;

	//Mouse positions

	sf::Vector2i mousePosWindow;

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//Private functions
	void initVariables();
	void initWindow();
	void initEnemies();

public:

	//Constructor, destrucctor
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;


	//Functions
	void spawnEnemy();

	void poll_events();
	void updateMousePsitions();
	void updateEnamies();
	void update();

	void renderEnemies();
	void render();
};

