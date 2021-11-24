//
// Created by Ojas Vaidya on 23/11/21.
//

#include "ShopMenu.h"

#define print(x) std::cout << x << std::endl;

ShopMenu::ShopMenu(bool *setActive, sf::Vector2f pos, sf::Font font)
{
    initVariables(setActive, pos, font);
}

ShopMenu::~ShopMenu()
{

}

void ShopMenu::initVariables(bool *setActive, sf::Vector2f pos, sf::Font font)
{
    if(!shopMenuTexture.loadFromFile("../Assets/Sprites/ShopMenuBackboard.png"))
    {
        print("Failed to load sprite");
    }

    shopMenuSprite.setTexture(shopMenuTexture);
    shopMenuSprite.setPosition(pos);

    *setActive = false;

    shopMenuColor = sf::Color(44, 59, 152);
    shopMenuHoverColor = sf::Color(shopMenuColor.r - 25, shopMenuColor.g - 25, shopMenuColor.b - 25);
    shopMenuPressedColor = sf::Color(shopMenuColor.r - 35, shopMenuColor.g - 35, shopMenuColor.b - 35);

    fish = new Button(560, 400, 150, 50, std::to_string(fishCost), font, sf::Color::, shopMenuHoverColor, shopMenuPressedColor, 40);
    pollution = new Button(150, 750, 50, 20, std::to_string(pollutionCost), font, shopMenuColor, sf::Color(shopMenuColor.r - 25,
                                                                                                           shopMenuColor.g - 25, shopMenuColor.b - 25), sf::Color(shopMenuColor.r - 35, shopMenuColor.g - 35, shopMenuColor.b - 35), 40);
}

void ShopMenu::update(sf::RenderWindow &window)
{
    fish->update(sf::Mouse::getPosition(window));
    pollution->update(sf::Mouse::getPosition(window));
}

void ShopMenu::render(sf::RenderTarget *target)
{
    target->draw(shopMenuSprite);
    fish->render(target);
    pollution->render(target);
}
