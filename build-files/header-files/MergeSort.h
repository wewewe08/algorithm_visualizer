// MergeSort.h

#pragma once

#include <SFML/Graphics.hpp>
#include "WindowManager.h"

class MergeSort : public WindowManager {
    sf::RenderWindow& window;
    sf::Color comparingColor = sf::Color(197, 54, 69); // red
    sf::Color sortedColor = sf::Color(65,117,113); // green
    sf::Color minIndexColor = sf::Color(90, 148, 255); // blue

    public:
        MergeSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int as);

        void RunMergeSort();
};