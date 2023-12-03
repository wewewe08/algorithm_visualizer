// Button.h

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class ImageButton {
    public:
        ImageButton(sf::RenderWindow& w, std::string imgPath) : window(w)
        {
            if (!image.loadFromFile(imgPath)) {
                std::cerr << "Failed to load image" << std::endl;
            }

            button.setTexture(image);
            button.setScale(1.0f, 1.0f);
        }

        void SetPosition(sf::Vector2f pos) {
            button.setPosition(pos);
        }

        void DrawButton() {
            window.draw(button);
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
        sf::Texture image;
        sf::Sprite button;
};