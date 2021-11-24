//
// Created by Ojas Vaidya on 23/11/21.
//

#ifndef SEAJAMGAMESFML_SHOPMENU_H
#define SEAJAMGAMESFML_SHOPMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class ShopMenu
{
private:
    sf::Texture shopMenuTexture;
    sf::Sprite shopMenuSprite;

    sf::Color shopMenuColor;
    sf::Color shopMenuHoverColor;
    sf::Color shopMenuPressedColor;

    Button* fish;
    Button* pollution;

    int fishCost;
    int pollutionCost;

    void initVariables(bool *setActive, sf::Vector2f pos, sf::Font font);
public:
    ShopMenu(bool *setActive, sf::Vector2f pos, sf::Font font);
    virtual ~ShopMenu();

    void update(sf::RenderWindow &window);
    void render(sf::RenderTarget *target);
};


#endif //SEAJAMGAMESFML_SHOPMENU_H
