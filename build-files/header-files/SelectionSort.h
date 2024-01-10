// SelectionSort.h

#pragma once

#include <SFML/Graphics.hpp>
#include "WindowManager.h"

class SelectionSort : public WindowManager {
    sf::RenderWindow& window;

    public:
        SelectionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int as);

        void RunSelectionSort();
};