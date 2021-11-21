//
// Created by Ojas Vaidya on 21/11/21.
//

#include "UI.h"

#define print(x) std::cout << x << std::endl

UI::UI(sf::VideoMode videoMode)
{
    initVariables(videoMode);
}

UI::~UI()
{
    delete button;
}

void UI::initVariables(sf::VideoMode &videoMode)
{
    if(!font.loadFromFile("../Assets/Fonts/Abel-Regular.ttf"))
        std::cout << "Font Failed to Load" << std::endl;

    button = new Button(videoMode.width / 2 - 80, videoMode.height - 100, 160, 80, "New Game", font, sf::Color(70, 70, 70, 255), sf::Color(100, 100, 100, 200), sf::Color(20, 20, 20, 200));

    if(!shopMenuTexture.loadFromFile("../Assets/Sprites/ShopMenuBackboard.png"))
    {
        print("Failed to load sprite");
    }

    shopMenuSprite.setTexture(shopMenuTexture);
}

void UI::update(sf::RenderWindow* target)
{
    button->update(sf::Mouse::getPosition(*target));
}

void UI::render(sf::RenderTarget *target)
{
    button->render(target);
}
