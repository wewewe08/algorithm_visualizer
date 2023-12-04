#include <SFML/Graphics.hpp>

#include "header-files/WindowManager.h"
#include "header-files/SelectionSort.h"

#include "header-files/ImageButton.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600), "Algorithm Visualizer", sf::Style::Titlebar | sf::Style::Close);

    int numBars = 80;
    bool canRandomizeArray = false;
    std::vector<sf::RectangleShape> bars;
    SelectionSort selectionAlgorithm(window, bars, numBars);

    std::string imgPath = "images/randomizeButton.png";
    ImageButton randomizeButton(window, imgPath);
    randomizeButton.SetPosition({100,450});

    std::mt19937 rng(std::time(nullptr));
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
                        std::mt19937 rng(std::time(nullptr));
                        if (canRandomizeArray) {
                            selectionAlgorithm.RandomizeArray(numBars, rng);
                        }
                        selectionAlgorithm.RunSelectionSort();
                        canRandomizeArray = false;
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