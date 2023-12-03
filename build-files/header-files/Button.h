// Button.h

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
    public:
        Button(sf::RenderWindow& w, std::string t, sf::Color bgColor, sf::Color textColor) : window(w)
        {
            text.setString(t);
            text.setFillColor(textColor);
            text.setCharacterSize(20);

            button.setSize({150, 50});
            button.setFillColor(bgColor);
        }

        void SetPosition(sf::Vector2f pos) {
            button.setPosition(pos);

            float textXPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
            float textYPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);
            text.setPosition({textXPos, textYPos});
        }

        void SetButtonColor(sf::Color color) {
            button.setFillColor(color);
        }

        void SetTextFont(sf::Font& font) {
            text.setFont(font);
        }

        void DrawButton() {
            window.draw(button);
            window.draw(text);
        }

        bool MouseHovering() {
            float mouseX = sf::Mouse::getPosition(window).x;
            float mouseY = sf::Mouse::getPosition(window).y;

            float buttonPosX = button.getPosition().x;
            float buttonPosY = button.getPosition().y;

            float buttonPosWidth = buttonPosX + button.getLocalBounds().width;
            float buttonPosHeight = buttonPosY + button.getLocalBounds().height;

            if (mouseX < buttonPosWidth && mouseX > buttonPosX && mouseY < buttonPosHeight && mouseY > buttonPosY) {
                return true;
            }

            return false;
        }

    private:
        sf::RenderWindow& window;
        sf::RectangleShape button;
        sf::Text text;
};