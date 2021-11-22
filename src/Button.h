//
// Created by Ojas Vaidya on 21/11/21.
//

#ifndef SEAJAMGAME_BUTTON_H
#define SEAJAMGAME_BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

enum class ButtonState
{
    Idle = 0, Hover, Pressed
};

class Button
{
private:
    ButtonState buttonState;

    sf::RectangleShape m_rect;
    std::shared_ptr<sf::Font> m_font;
    sf::Text m_text;

    sf::Color m_idleColor;
    sf::Color m_hoverColor;
    sf::Color m_pressedColor;


    void initVariables();
public:
    Button(float x, float y , float width, float height,
           const std::string& text, sf::Font font , sf::Color idleColor,
           sf::Color hoverColor, sf::Color pressedColor);
    ~Button();

    //Accessors

    bool isPressed() const;
    sf::Vector2f getPos();

    //Functions
    void update(sf::Vector2<int> mousePos);
    void render(sf::RenderTarget* target);
};


#endif //CLIONSFML2_BUTTON_H
