#include <iostream>
#include "Game.h"

int main()
{
    //init game engine
    Game game;

    //game loop

    while (game.running())
    {

    
        //udate
        game.update();
        //render
        game.render();

    }

	return 0;
}