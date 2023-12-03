// SelectionSort.h

#pragma once

#include "SortingAlgorithm.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class SelectionSort : public SortingAlgorithm {
    public:
        SelectionSort (sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int arrSize) : SortingAlgorithm(window, bars, arrSize), window(window) {
            std::cout << "SelectionSort object created." << std::endl;
        }

        void ResetWindow() {
            std::this_thread::sleep_for(std::chrono::milliseconds(30));

            window.clear();
            DrawBars();
            window.display();
        }

        void ChangeColors(sf::RectangleShape &bar, sf::Color color) {
            bar.setFillColor(color);
        }

        void SwapBars(sf::RectangleShape &a, sf::RectangleShape &b, int &index, int &minIndex) {
            sf::Vector2f tempSizeA = a.getSize();

            a.setSize(b.getSize());
            float barAYPos = (window.getSize().y / 2.0f) - a.getSize().y;
            a.setPosition(startX + index * (barWidth + spacing), barAYPos);

            a.setFillColor(sf::Color::Green);

            b.setSize(tempSizeA);
            float barBYPos = (window.getSize().y / 2.0f) - b.getSize().y;
            b.setPosition(startX + minIndex * (barWidth + spacing), barBYPos);
            ResetWindow();
        }

        void RunSelectionSort() {
            for (int i = 0; i < arrSize - 1; ++i) {
                int minIndex = i;
                ChangeColors(SortingAlgorithm::bars[minIndex], sf::Color::Red);
                for (int j = i + 1; j < arrSize; ++j) {
                    ChangeColors(SortingAlgorithm::bars[j], sf::Color::Red);
                    std::lock_guard<std::mutex> lock(mutex);
                    if (SortingAlgorithm::bars[j].getSize().y < SortingAlgorithm::bars[minIndex].getSize().y) {
                        ChangeColors(SortingAlgorithm::bars[minIndex], sf::Color::White);
                        minIndex = j;
                        ChangeColors(SortingAlgorithm::bars[minIndex], sf::Color::Red);
                    }
                    ResetWindow();
                    ChangeColors(SortingAlgorithm::bars[j], sf::Color::White);
                }
                // swapping elements
                SwapBars(SortingAlgorithm::bars[i], SortingAlgorithm::bars[minIndex], i, minIndex);
                ResetWindow();
            }
            std::cout << "Finished selection sort." << std::endl;
        }

    private:
        sf::RenderWindow& window;
        std::mutex mutex; // synchronization
};