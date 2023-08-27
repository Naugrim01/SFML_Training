#include "Game.h"

//private functions

void Game::initVariables()
{
	this->window = nullptr;

    //Game logic

    this->points = 0;
    this->enemySpawnTimer = 0.f;
    this->enemySpawnTimerMax = 10.f;
    this->maxEnemies = 10;

}

void Game::initWindow()
{
	this->video_mode.height = 720;
	this->video_mode.width = 1280;
	this->window = new sf::RenderWindow(this->video_mode, "SFML works!", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
    this->enemy.setPosition(30.f, 30.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    //this->enemy.setOutlineColor(sf::Color::Red);
    //this->enemy.setOutlineThickness(2.f);
}

//constructors, destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}
//Accessors

const bool Game::running() const
{
	return this->window->isOpen();
}



//functions

void Game::spawnEnemy()
{
    /*
        @return void 

        Spawna enemies and sets their colors and positions.
        -Sets a random position.
        -Sets a random color.
        -Adds enemy to the vector.
    */

    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
    );

    this->enemy.setFillColor(sf::Color::Green);

    //Spawn the enemy
    this->enemies.push_back(this->enemy);

    //Remove enemies at end of screen
}

void Game::poll_events()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Q)
                this->window->close();
            break;
        }
    }
}

void Game::updateMousePsitions()
{
    // Updates mouse position
        /// Mouse position relative to window - vector 2i
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosview = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{
    /*
        @return void
        Updates the enemy spawn timer and spawns enemies when the total amount of enemies is smaller than the maximum.
        Moves the enemies downwards.
        Removes the enemies at the edge of the screen.//TODO
    */

    //Upgating the timer for enemy spawning
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }
    //Moving and updateing the enemies
    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;

        this->enemies[i].move(0.f, 1.f);
        //Check if clicked upon

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (this->enemies[i].getGlobalBounds().contains(this->mousePosview))
            {
                deleted = true;

                //Gain points
                this->points += 10.f;
            }
        }

        //If the enemy is past the bottom of the screen
        if (this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            deleted = true;
        }

        if (deleted)
        {
            this->enemies.erase(this->enemies.begin() + i);
        }
    }

}

void Game::update()
{ 
    this->poll_events();

    this->updateMousePsitions();

    this->updateEnemies();

}

void Game::renderEnemies()
{
    //Rendering all enemies
    for (auto& e : this->enemies)
    {
        this->window->draw(e);
    }
}

void Game::render()
{
    //clear old frame

    this->window->clear();

    //draw game objects

    this->renderEnemies();

    // display frame in window
    
    this->window->display();
}