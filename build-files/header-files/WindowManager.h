// WindowManager.h

#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>

class WindowManager {
    private:
        sf::RenderWindow& window;
        std::chrono::milliseconds delay = std::chrono::milliseconds(20);

    public:
        std::vector<sf::RectangleShape> bars;
        int barWidth{};
        int spacing{};
        int arrSize {};
        float totalWidth{};
        float startX{};

        WindowManager(sf::RenderWindow& window, std::vector<sf::RectangleShape>& b, int arrSize);

        // generate random heights for each bar
        void RandomizeArray(int arrSize, std::mt19937 &rng) {}

        void DrawBars() {}

        void ChangeColors(sf::RectangleShape &bar, sf::Color color) {}

        // draw each bar again with delay
        void ResetWindow() {}

        // clears out thread vector
        void ResetThreads(std::vector<std::thread> &colorChangeThreads) {}
};