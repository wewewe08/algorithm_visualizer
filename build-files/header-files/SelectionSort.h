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

        void SwapBars(sf::RectangleShape &a, sf::RectangleShape &b) {
            sf::Vector2f tempSizeA = a.getSize();
            a.setSize(b.getSize());
            b.setSize(tempSizeA);
        }

        void RunSelectionSort() {
            for (int i = 0; i < arrSize - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < arrSize; ++j) {
                    if (SortingAlgorithm::bars[j].getSize().y < SortingAlgorithm::bars[minIndex].getSize().y) {
                        minIndex = j;
                    }
                }
                // swapping elements
                SwapBars(SortingAlgorithm::bars[i], SortingAlgorithm::bars[minIndex]); 

                //std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
            std::cout << "Finished selection sort." << std::endl;
        }

    private:
        sf::RenderWindow& window;
};