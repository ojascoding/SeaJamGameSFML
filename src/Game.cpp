#include "Game.h"

#define print(x) std::cout << x << std::endl;

//Constructor
Game::Game()
{
    initVariables();
    initGameObjects();
}

//Destructor
Game::~Game()
{

}

//Initialization


void Game::initVariables()
{
    videoMode.width = 1280;
    videoMode.height = 720;

    window = std::make_unique<sf::RenderWindow>(videoMode, "SFML window", sf::Style::Close | sf::Style::Titlebar);

    window->setFramerateLimit(60);

    bgColor = sf::Color(241, 244, 214);
    ui = std::make_unique<UI>(videoMode);
}


void Game::initGameObjects()
{

}



//Events

void Game::pollEvents()
{
    //polls all the events by getting the pollevent function from the class,
    while (window->pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
        }

    }
}

//Updating and Rendering

void Game::update()
{
    pollEvents();
    ui->update(*window);
}

void Game::render()
{
    //clear old frame
    window->clear(bgColor);

    //render objects
    ui->render(window.get());

    //display frame in window
    window->display();
}

//a function which checks if the function is running
bool Game::isRunning()
{
    return window->isOpen();
}