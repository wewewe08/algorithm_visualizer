// Button.h

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
    public:
        Button(sf::RenderWindow& w, std::string t, sf::Color bgColor, sf::Color textColor) : window(w)
        {
            text.setString(t);
            text.setColor(textColor);
            text.setCharacterSize(20);

            button.setSize({200, 50});
            button.setFillColor(bgColor);
        }

        void SetPosition(sf::Vector2f pos) {
            button.setPosition(pos);

            float textXPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
            float textYPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);
            text.setPosition({textXPos, textYPos});
        }

        void DrawButton() {
            window.draw(button);
            window.draw(text);
        }

    private:
        sf::RenderWindow& window;
        sf::RectangleShape button;
        sf::Text text;
};