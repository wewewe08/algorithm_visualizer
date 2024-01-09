// SelectionSort.h

#pragma once

#include "WindowManager.h"

class SelectionSort : public WindowManager {
    private:
        sf::RenderWindow& window;
        sf::Color comparingColor = sf::Color(197, 54, 69); // red
        sf::Color sortedColor = sf::Color(65,117,113); // green
        sf::Color minIndexColor = sf::Color(90, 148, 255); // blue

    public:
        SelectionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int as);

        void SwapBars(sf::RectangleShape &a, sf::RectangleShape &b, int &index, int &minIndex) {}

        void RunSelectionSort() {}
};