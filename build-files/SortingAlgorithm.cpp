#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int arrSize)
    : window(window), bars(bars), barWidth(10), spacing(5), totalWidth(arrSize * barWidth + (arrSize - 1) * spacing), startX((window.getSize().x - totalWidth) / 2.0f) {}

void SortingAlgorithm::RandomizeArray(int arrSize, std::mt19937 &rng) {
    std::uniform_int_distribution<std::mt19937::result_type> distribution(50, 300); // this produces random integers within the given range

    for (int i = 0; i < arrSize; ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth, distribution(rng)));
        float barYPos = (window.getSize().y / 2.0f) - bar.getSize().y;

        bar.setPosition(startX + i * (barWidth + spacing), barYPos);
        bars.push_back(bar);
    }
}

void SortingAlgorithm::DrawBars() {
    for (const sf::RectangleShape bar : bars) {
        window.draw(bar);
    }
}