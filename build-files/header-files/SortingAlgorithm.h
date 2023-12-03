// SortingAlgorithm.h

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class SortingAlgorithm {
    public:
        SortingAlgorithm(sf::RenderWindow& window, std::vector<sf::RectangleShape>& b, int arrSize) : window(window)
        {
            bars = b;
            barWidth = 8;
            spacing = 1;
            totalWidth =arrSize * barWidth + (arrSize - 1) * spacing;
            startX = (window.getSize().x - totalWidth) / 2.0f;
        }

        void RandomizeArray(int arrSize, std::mt19937 &rng) {
            std::uniform_int_distribution<std::mt19937::result_type> distribution(50, 200); // this produces random integers within the given range

            if (!bars.empty()) {
                bars.clear();
            }

            for (int i = 0; i < arrSize; ++i) {
                sf::RectangleShape bar(sf::Vector2f(barWidth, distribution(rng)));
                float barYPos = (window.getSize().y / 2.0f) - bar.getSize().y;

                bar.setPosition(startX + i * (barWidth + spacing), barYPos);
                bars.push_back(bar);
            }
        }

        void DrawBars() {
            for (const sf::RectangleShape bar : bars) {
                window.draw(bar);
            }
        }

    private:
        sf::RenderWindow& window;
        std::vector<sf::RectangleShape> bars;

        int barWidth{};
        int spacing{};
        float totalWidth{};
        float startX{};
};