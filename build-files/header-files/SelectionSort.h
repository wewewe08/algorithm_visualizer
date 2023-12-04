// SelectionSort.h

#pragma once

#include "WindowManager.h"

class SelectionSort : public WindowManager {
    public:
        SelectionSort (sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int arrSize) : WindowManager(window, bars, arrSize), window(window) {
            std::cout << "SelectionSort object created." << std::endl;
        }

        void SwapBars(sf::RectangleShape &a, sf::RectangleShape &b, int &index, int &minIndex) {
            sf::Vector2f tempSizeA = a.getSize();

            a.setSize(b.getSize());
            float barAYPos = (window.getSize().y / 2.0f) - a.getSize().y;
            a.setPosition(startX + index * (barWidth + spacing), barAYPos);
            a.setFillColor(sortedColor);

            b.setSize(tempSizeA);
            float barBYPos = (window.getSize().y / 2.0f) - b.getSize().y;
            b.setPosition(startX + minIndex * (barWidth + spacing), barBYPos);
            b.setFillColor(sf::Color::White);
        }

        void RunSelectionSort() {
            std::vector<std::thread> colorChangeThreads;
            for (int i = 0; i < arrSize - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < arrSize; ++j) {
                    WindowManager::ChangeColors(WindowManager::bars[j], comparingColor);
                    if (WindowManager::bars[j].getSize().y < WindowManager::bars[minIndex].getSize().y) {
                        WindowManager::ChangeColors(WindowManager::bars[minIndex], sf::Color::White); 
                        minIndex = j;
                        colorChangeThreads.emplace_back([&](){
                            WindowManager::ChangeColors(WindowManager::bars[minIndex], minIndexColor); // change color to new minIndex
                        });
                    }
                    WindowManager::ResetThreads(colorChangeThreads);
                    WindowManager::ResetWindow();

                    // dont reset minIndex color bar
                    if (WindowManager::bars[j].getFillColor() != minIndexColor) {
                        WindowManager::ChangeColors(WindowManager::bars[j], sf::Color::White);
                    }
                }
                // swapping elements
                SwapBars(WindowManager::bars[i], WindowManager::bars[minIndex], i, minIndex);
                WindowManager::ResetWindow();
            }
            // change last bar color
            WindowManager::ChangeColors(WindowManager::bars[arrSize - 1], sortedColor);
            std::cout << "Finished selection sort." << std::endl;
        }

    private:
        sf::RenderWindow& window;
        sf::Color comparingColor = sf::Color(197, 54, 69);
        sf::Color sortedColor = sf::Color(65,117,113);
        sf::Color minIndexColor = sf::Color(90, 148, 255);
};