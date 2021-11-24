//
// Created by Ojas Vaidya on 21/11/21.
//

#ifndef SEAJAMGAMESFML_UI_H
#define SEAJAMGAMESFML_UI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.h"
#include "ShopMenu.h"
#include <iostream>

class UI
{
private:
    Button* button;
    sf::Font font;

    ShopMenu* shopMenu;

    sf::Text pollutionText;
    sf::Text fishText;
    sf::Font textFont;

    int pollutionAmount = 50;
    int fishAmount = 50;
    int moneyAmount = 500;

    bool shouldShopMenu;

    void initVariables(sf::VideoMode &videoMode);
public:
    UI(sf::VideoMode videoMode);
    ~UI();

    void update(sf::RenderWindow &target);
    void render(sf::RenderTarget *target);
};


#endif //SEAJAMGAMESFML_UI_H
