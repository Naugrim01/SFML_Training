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
}

//constructors, destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
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
}

void Game::render()
{
    this->window->clear(sf::Color(0, 255, 0, 255));

    //draw game objects

    this->window->display();
}