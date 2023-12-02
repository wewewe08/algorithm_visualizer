// SortingAlgorithm.h

#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class SortingAlgorithm {
    public:
        SortingAlgorithm(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int arrSize);

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