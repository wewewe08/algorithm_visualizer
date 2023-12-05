#include <SFML/Graphics.hpp>

#include "header-files/WindowManager.h"
#include "header-files/SelectionSort.h"

#include "header-files/ImageButton.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close);

    int numBars = 80;
    bool canRandomizeArray = true;
    std::vector<sf::RectangleShape> bars;
    SelectionSort selectionAlgorithm(window, bars, numBars);

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
                    break;
                case sf::Event::MouseButtonPressed:
                    if (randomizeButton.MouseHovering()) {
                        if (canRandomizeArray) {
                            std::cout << "Randomizing..." << std::endl;
                            canRandomizeArray = false;
                            std::mt19937 rng(std::time(nullptr));
                            selectionAlgorithm.RandomizeArray(numBars, rng);
                        }
                    }
                    break;
            } 
        }

        window.clear();
        selectionAlgorithm.DrawBars();

        if (!canRandomizeArray) {
            selectionAlgorithm.RunSelectionSort();
            canRandomizeArray =  true;
        }

        randomizeButton.DrawButton();

        window.display();
    }

    return 0;
}