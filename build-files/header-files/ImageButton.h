// Button.h

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class ImageButton {
    sf::RenderWindow& window;
    sf::Texture image;
    sf::Sprite button;

    public:
        ImageButton(sf::RenderWindow& w, std::string imgPath);

        void SetPosition(sf::Vector2f pos);

        void DrawButton();

        bool MouseHovering();
};