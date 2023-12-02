#include <SFML/Graphics.hpp>
#include "header-files/SortingAlgorithm.h"
#include "header-files/Button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close);

    int numBars = 80;
    std::vector<sf::RectangleShape> bars;
    SortingAlgorithm sortingAlgorithm(window, bars, numBars);

    std::random_device rd; // this is a random device object used to generate random numbers
    std::mt19937 rng(rd()); // creates a Mersenne Twister pseudo-random number generator and seeds it with the value from "rd"
    sortingAlgorithm.RandomizeArray(numBars, rng);

    sf::Font satoshi_font;
    satoshi_font.loadFromFile("fonts/Satoshi-Medium.ttf");

    Button randomizeButton(window, "Generate new array", sf::Color::White, sf::Color::Black);
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