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

    button = new Button(videoMode.width / 2 - 80, videoMode.height - 100, 160, 80, "Shop", font, sf::Color(70, 70, 70, 255), sf::Color(100, 100, 100, 200), sf::Color(20, 20, 20, 200));

    if(!shopMenuTexture.loadFromFile("../Assets/Sprites/ShopMenuBackboard.png"))
    {
        print("Failed to load sprite");
    }

    shopMenuSprite.setTexture(shopMenuTexture);

    shopMenuSprite.setPosition(button->getPos().x - 40, button->getPos().y - 240);
    shouldShopMenu = false;

    if(!textFont.loadFromFile("../Assets/Fonts/Pixel_Square.ttf"))
        std::cout << "Font failed to load" << std::endl;

    pollutionText = sf::Text(std::to_string(pollutionAmount), textFont, 100);
    pollutionText.setPosition(50, videoMode.height - 125);
    pollutionText.setFillColor(sf::Color(102, 102, 0));

    fishText = sf::Text(std::to_string(fishAmount), textFont, 100);
    fishText.setPosition(videoMode.width - 165, videoMode.height - 125);
    fishText.setFillColor(sf::Color(212, 175, 55));
}

void UI::update(sf::RenderWindow* target)
{
    button->update(sf::Mouse::getPosition(*target));
    if(button->isPressed())
    {
        shouldShopMenu = !shouldShopMenu;
    }
}

void UI::render(sf::RenderTarget *target)
{
    button->render(target);

    target->draw(pollutionText);
    target->draw(fishText);

    if(shouldShopMenu)
    {
        target->draw(shopMenuSprite);
    }
}
