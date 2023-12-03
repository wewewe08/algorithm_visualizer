// SelectionSort.h

#pragma once

#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm {
    public:
        SelectionSort (sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int arrSize) : SortingAlgorithm(window, bars, arrSize), window(window) {
            std::cout << "SelectionSort object created." << std::endl;
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
            SortingAlgorithm::ResetWindow();
        }

        void RunSelectionSort() {
            std::vector<std::thread> colorChangeThreads;

            for (int i = 0; i < arrSize - 1; ++i) {
                int minIndex = i;
                SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[minIndex], sf::Color::Red);
                for (int j = i + 1; j < arrSize; ++j) {
                    SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[j], sf::Color::Red);
                    if (SortingAlgorithm::bars[j].getSize().y < SortingAlgorithm::bars[minIndex].getSize().y) {
                        colorChangeThreads.emplace_back([&](){
                            SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[minIndex], sf::Color::White);
                        });
                        
                        minIndex = j;

                        colorChangeThreads.emplace_back([&](){
                            SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[minIndex], sf::Color::Red);
                        });
                    }

                    SortingAlgorithm::ResetThreads(colorChangeThreads);
                    SortingAlgorithm::ResetWindow();
                    SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[j], sf::Color::White);
                }
                // swapping elements
                SwapBars(SortingAlgorithm::bars[i], SortingAlgorithm::bars[minIndex], i, minIndex);
                SortingAlgorithm::ResetWindow();
            }
            // change last bar color
            SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[arrSize - 1], sf::Color::Green);
            std::cout << "Finished selection sort." << std::endl;
        }

    private:
        sf::RenderWindow& window;
};