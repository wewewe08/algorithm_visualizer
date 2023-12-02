#include <SFML/Graphics.hpp>
#include "SortingAlgorithm.h"
#include "Button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Algorithm Visualizer", sf::Style::Default);

    int numBars = 100;
    std::vector<sf::RectangleShape> bars;
    SortingAlgorithm sortingAlgorithm(window, bars, numBars);

    std::random_device rd; // this is a random device object used to generate random numbers
    std::mt19937 rng(rd()); // creates a Mersenne Twister pseudo-random number generator and seeds it with the value from "rd"
    sortingAlgorithm.RandomizeArray(numBars, rng);

    Button randomizeButton(window, "Generate new array", sf::Color::White, sf::Color::Black);
    randomizeButton.SetPosition({100,300});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        sortingAlgorithm.DrawBars();
        randomizeButton.DrawButton();

        window.display();
    }

    return 0;
}