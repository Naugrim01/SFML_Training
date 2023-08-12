#include "Game.h"

//private functions

void Game::initVariables()
{
	this->window = nullptr;

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
    this->enemy.setOutlineColor(sf::Color::Red);
    this->enemy.setOutlineThickness(5.f);
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

void Game::update()
{
    this->poll_events();

    //update mouse position
        ///relative to the screen:
    //std::cout << "mouse position: " << sf::Mouse::getPosition().x << ' ' << sf::Mouse::getPosition().y << '\n';

        ///relative to the window:
    std::cout << "mouse position: " << sf::Mouse::getPosition(*this->window).x << ' ' << sf::Mouse::getPosition(*this->window).y << '\n';
}

void Game::render()
{
    //clear old frame

    this->window->clear();

    //draw game objects

    this->window->draw(this->enemy);

    // display frame in window
    
    this->window->display();
}