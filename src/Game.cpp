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
    delete button;
}

//Initialization


void Game::initVariables()
{
    videoMode.width = 1280;
    videoMode.height = 720;

    window = std::make_unique<sf::RenderWindow>(videoMode, "SFML window", sf::Style::Close | sf::Style::Titlebar);

    window->setFramerateLimit(60);

    bgColor = sf::Color(241, 244, 214);
    if(!font.loadFromFile("../Assets/Fonts/Abel-Regular.ttf"))
        std::cout << "Font Failed to Load" << std::endl;

    button = new Button(videoMode.width / 2 - 80, videoMode.height - 100, 160, 80, "New Game", font, sf::Color(70, 70, 70, 255), sf::Color(100, 100, 100, 200), sf::Color(20, 20, 20, 200));
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

            default:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window->close();
        }

    }
}

//Updating and Rendering

void Game::update()
{
    pollEvents();
    button->update(sf::Mouse::getPosition(*window));
}

void Game::render()
{
    //clear old frame
    window->clear(bgColor);

    //render objects
    button->render(this->window.get());
    //display frame in window
    window->display();
}

//a function which checks if the function is running
bool Game::isRunning()
{
    return window->isOpen();
}


