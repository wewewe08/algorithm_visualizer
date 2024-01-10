// MergeSort.h

#pragma once

#include <SFML/Graphics.hpp>
#include "WindowManager.h"

class InsertionSort : public WindowManager {
    sf::RenderWindow& window;

    public:
        InsertionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int as);

        void RunInsertionSort();
};