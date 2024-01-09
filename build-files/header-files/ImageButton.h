// Button.h

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class ImageButton {
    private:
        sf::RenderWindow& window;
        sf::Texture image;
        sf::Sprite button;

    public:
        ImageButton(sf::RenderWindow& w, std::string imgPath) : window(w)
        {
            if (!image.loadFromFile(imgPath)) {
                std::cerr << "Failed to load image" << std::endl;
            }

            button.setTexture(image);
            button.setScale(1.0f, 1.0f);
        }

    void SetPosition(sf::Vector2f pos) {}

    void DrawButton() {}

    bool MouseHovering() {}
};