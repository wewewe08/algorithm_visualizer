#include <SFML/Graphics.hpp>
#include "header-files/SortingAlgorithm.h"
#include "header-files/ImageButton.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close);

    int numBars = 80;
    std::vector<sf::RectangleShape> bars;
    std::random_device rd;
    SortingAlgorithm sortingAlgorithm(window, bars, numBars);

    std::string imgPath = "images/randomizeButton.png";
    ImageButton randomizeButton(window, imgPath);
    randomizeButton.SetPosition({100,450});

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