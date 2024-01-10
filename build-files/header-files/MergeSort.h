// MergeSort.h

#pragma once

#include <SFML/Graphics.hpp>
#include "WindowManager.h"

class MergeSort : public WindowManager {
    sf::RenderWindow& window;

    public:
        MergeSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int as);

        void Merge();

        void RunMergeSort();
};