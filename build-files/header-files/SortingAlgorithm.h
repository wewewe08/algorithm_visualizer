// SortingAlgorithm.h

#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class SortingAlgorithm {
    public:
        SortingAlgorithm(sf::RenderWindow& window, std::vector<sf::RectangleShape>& b, int arrSize) : window(window)
        {
            bars = b;
            barWidth =10;
            spacing = 5;
            totalWidth =arrSize * barWidth + (arrSize - 1) * spacing;
            startX = (window.getSize().x - totalWidth) / 2.0f;
        }

        void RandomizeArray(int arrSize, std::mt19937& rng);
        void DrawBars();

    private:
        sf::RenderWindow& window;
        std::vector<sf::RectangleShape> bars;

        int barWidth{};
        int spacing{};
        float totalWidth{};
        float startX{};
};

#endif // SORTING_ALGORITHM_H