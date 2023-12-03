#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

#include "header-files/SortingAlgorithm.h"
#include "header-files/SelectionSort.h"

#include "header-files/ImageButton.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close);

    int numBars = 80;
    std::vector<sf::RectangleShape> bars;
    std::random_device rd;
    SelectionSort selectionAlgorithm(window, bars, numBars);

    std::string imgPath = "images/randomizeButton.png";
    ImageButton randomizeButton(window, imgPath);
    randomizeButton.SetPosition({100,450});

    std::mt19937 rng(rd());
    selectionAlgorithm.RandomizeArray(numBars, rng);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (randomizeButton.MouseHovering()) {
                        std::cout << "Button pressed" << std::endl;
                        //std::mt19937 rng(rd());
                        //selectionAlgorithm.RandomizeArray(numBars, rng);
                        selectionAlgorithm.RunSelectionSort();
                    }
                    break;
            } 
        }

        window.clear();

        selectionAlgorithm.DrawBars();
        randomizeButton.DrawButton();

        window.display();
    }

    return 0;
}