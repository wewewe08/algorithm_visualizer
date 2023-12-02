#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Algorithm Visualizer", sf::Style::Default);

    std::cout << "Testing output" << std::endl;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.display();
    }

    return 0;
}