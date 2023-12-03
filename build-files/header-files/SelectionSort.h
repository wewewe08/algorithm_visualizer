// SelectionSort.h

#pragma once

#include "SortingAlgorithm.h"
#include <iostream>
#include <thread>
#include <chrono>

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

        void SwapBars(sf::RectangleShape &a, sf::RectangleShape &b, int &index) {
            sf::Vector2f tempSizeA = a.getSize();
            sf::Vector2f tempSizeB = b.getSize();

            a.setSize(b.getSize());
            float barAYPos = (window.getSize().y / 2.0f) - a.getSize().y;
            a.setPosition(startX + index * (barWidth + spacing), barAYPos);

            a.setFillColor(sf::Color::Green);

            b.setSize(tempSizeA);
            //float barBYPos = (window.getSize().y / 2.0f) - b.getSize().y;
            //b.setPosition(startX + index * (barWidth + spacing), barBYPos);

            ResetWindow();
        }

        void RunSelectionSort() {
            for (int i = 0; i < arrSize - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < arrSize; ++j) {
                    SortingAlgorithm::bars[j].setFillColor(sf::Color::Red);
                    if (SortingAlgorithm::bars[j].getSize().y < SortingAlgorithm::bars[minIndex].getSize().y) {
                        minIndex = j;
                        SortingAlgorithm::bars[minIndex].setFillColor(sf::Color::Red);
                    }
                    ResetWindow();
                    SortingAlgorithm::bars[j].setFillColor(sf::Color::White);
                    //SortingAlgorithm::bars[minIndex].setFillColor(sf::Color::White);
                }
                // swapping elements
                SwapBars(SortingAlgorithm::bars[i], SortingAlgorithm::bars[minIndex], i);
            }
            std::cout << "Finished selection sort." << std::endl;
        }

    private:
        sf::RenderWindow& window;
};