#include <SFML/Graphics.hpp>
#include "header-files/SortingAlgorithm.h"
#include "header-files/Button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close);

    int numBars = 80;
    std::vector<sf::RectangleShape> bars;
    std::random_device rd;
    SortingAlgorithm sortingAlgorithm(window, bars, numBars);

    sf::Font satoshi_font;
    if (!satoshi_font.loadFromFile("fonts/satoshi.ttf")) {
        std::cerr << "Failed to load font." << std::endl;  //error handling
    }

    Button randomizeButton(window, "New array", sf::Color::White, sf::Color::Black);
    randomizeButton.SetPosition({100,450});
    randomizeButton.SetTextFont(satoshi_font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                case sf::Event::MouseButtonPressed:
                    if (randomizeButton.MouseHovering()) {
                        std::mt19937 rng(rd());
                        sortingAlgorithm.RandomizeArray(numBars, rng);
                    }
            } 
        }

        window.clear();

        sortingAlgorithm.DrawBars();
        randomizeButton.DrawButton();

        window.display();
    }

    return 0;
}