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
            sf::Vector2f buttonCenter = { pos.x + button.getSize().x / 2, pos.y + button.getSize().y / 2 };

            sf::FloatRect textBounds = text.getLocalBounds();

            text.setOrigin(textBounds.width / 2, textBounds.height / 2); // set origin of text to its center
            text.setPosition(pos);

            // text scaling
            if (textBounds.width > button.getSize().x) {
                float scale = button.getSize().x / textBounds.width;
                text.setScale(scale, 1.0f);
                std::cout << "out of bounds" << std::endl;
            } else {
                text.setScale(1.0f, 1.0f);
                std::cout << "not out of bounds" << std::endl;
            }
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