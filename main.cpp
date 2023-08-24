#include <iostream>
#include "Game.h"

int main()
{
    //init game engine
    Game game;

    //game loop

    while (game.running())
    {
        //Init srand
        std::srand(static_cast<unsigned>(time(NULL)));
    
        //udate
        game.update();
        //render
        game.render();

    }

	return 0;
}