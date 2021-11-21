#include "Game.h"
#include <iostream>

int main()
{

    Game game;

    // Start the game loop
    while (game.isRunning())
    {
        //Update
        game.update();

        //Render
        game.render();

    }

        return EXIT_SUCCESS;

}
