#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public sf::Drawable {
    public:
        Button(sf::RenderWindow& window, std::string t, sf::Vector2f size, sf::Color bgColor, sf::Color textColor);

        void DrawButton();

    private:
        sf::RenderWindow& window;
        sf::RectangleShape button;
        sf::Text text;
};