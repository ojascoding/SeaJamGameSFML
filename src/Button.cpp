//
// Created by Ojas Vaidya on 21/11/21.
//

#define print(x) std::cout << x << std::endl;

#include "Button.h"


Button::Button(float x , float y , float width, float height ,
               const std::string& text,  sf::Font font , sf::Color idleColor,
               sf::Color hoverColor, sf::Color pressedColor)
{
    m_rect.setPosition(x, y);
    m_rect.setSize(sf::Vector2f(width, height));
    m_font = std::make_shared<sf::Font>(font);
    m_text.setFont(*m_font);
    m_text.setString(text);
    m_text.setFillColor(sf::Color::White);
    m_text.setCharacterSize(18);

    m_text.setPosition
    (
            m_rect.getPosition().x + (m_rect.getGlobalBounds().width / 2) - m_text.getGlobalBounds().width / 2,
            m_rect.getPosition().y + (m_rect.getGlobalBounds().height / 2) - m_text.getGlobalBounds().height / 2 - 5
    );

    m_idleColor = idleColor;
    m_hoverColor = hoverColor;
    m_pressedColor = pressedColor;

    m_rect.setFillColor(idleColor);
}

Button::~Button()
{

}

void Button::initVariables()
{
    buttonState = ButtonState::Idle;
}

void Button::update(sf::Vector2<int> mousePos)
{
    buttonState = ButtonState::Idle;

    if(m_rect.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        buttonState = ButtonState::Hover;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            buttonState = ButtonState::Pressed;
        }
    }


    switch(buttonState)
    {
        case ButtonState::Idle:
            m_rect.setFillColor(m_idleColor);
            break;
        case ButtonState::Hover:
            m_rect.setFillColor(m_hoverColor);
            break;
        case ButtonState::Pressed:
            m_rect.setFillColor(m_pressedColor);
            break;

        default:
            m_rect.setFillColor(sf::Color::Red);
            break;
    }
}


void Button::render(sf::RenderTarget *target)
{
    target->draw(m_rect);
    target->draw(m_text);

}

bool Button::isPressed() const
{
    if(buttonState == ButtonState::Pressed)
        return true;

    return false;
}



