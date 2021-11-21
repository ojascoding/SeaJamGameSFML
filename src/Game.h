#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.h"
#include <iostream>

//this is a class that acts like the game engine

class Game
{
private:
    //Variables
    std::unique_ptr<sf::RenderWindow> window;
    sf::VideoMode videoMode;
    sf::Event event;

    //GameObjects
    sf::Color bgColor;
    Button* button;
    sf::Font font;

    void initVariables();
    void initGameObjects();

public:
    //Constructors and Destructors
    Game();
    virtual ~Game();

    //functions
    void pollEvents();
    void update();
    void render();
    bool isRunning();
};


#endif
