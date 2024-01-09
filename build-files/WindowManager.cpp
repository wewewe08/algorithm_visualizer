#include "header-files/WindowManager.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>

WindowManager::WindowManager(sf::RenderWindow& window, std::vector<sf::RectangleShape>& b, int as) : window(window)
{
    bars = b;
    barWidth = 8;
    spacing = 1;
    arrSize = as;
    totalWidth = arrSize * barWidth + (arrSize - 1) * spacing;
    startX = (window.getSize().x - totalWidth) / 2.0f;
}

// generate random heights for each bar
void WindowManager::RandomizeArray(int arrSize, std::mt19937 &rng) {
    std::uniform_int_distribution<std::mt19937::result_type> distribution(50, 250); // this produces random integers within the given range

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

void WindowManager::DrawBars() {
    for (const auto &bar : bars) {
        window.draw(bar);
    }
}

void WindowManager::ChangeColors(sf::RectangleShape &bar, sf::Color color) {
    bar.setFillColor(color);
}

// draw each bar again with delay
void WindowManager::ResetWindow() {
    std::this_thread::sleep_for(delay);

    window.clear();
    DrawBars();
    window.display();
}

// clears out thread vector
void WindowManager::ResetThreads(std::vector<std::thread> &colorChangeThreads) {
    for (auto& thread : colorChangeThreads) {
        thread.join();
    }

    colorChangeThreads.clear();
}