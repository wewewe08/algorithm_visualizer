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
            a.setFillColor(sortedColor);

            b.setSize(tempSizeA);
            float barBYPos = (window.getSize().y / 2.0f) - b.getSize().y;
            b.setPosition(startX + minIndex * (barWidth + spacing), barBYPos);
            SortingAlgorithm::ResetWindow();
        }

        void RunSelectionSort() {
            std::vector<std::thread> colorChangeThreads;
            for (int i = 0; i < arrSize - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < arrSize; ++j) {
                    SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[j], comparingColor);
                    if (SortingAlgorithm::bars[j].getSize().y < SortingAlgorithm::bars[minIndex].getSize().y) {
                        SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[minIndex], sf::Color::White);
                        minIndex = j;
                        colorChangeThreads.emplace_back([&](){
                            SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[minIndex], minIndexColor);
                        });
                    }
                    SortingAlgorithm::ResetThreads(colorChangeThreads);
                    SortingAlgorithm::ResetWindow();

                    // dont reset minIndex color bar
                    if (SortingAlgorithm::bars[j].getFillColor() != minIndexColor) {
                        SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[j], sf::Color::White);
                    }
                }
                // swapping elements
                SwapBars(SortingAlgorithm::bars[i], SortingAlgorithm::bars[minIndex], i, minIndex);
                SortingAlgorithm::ResetWindow();
            }
            // change last bar color
            SortingAlgorithm::ChangeColors(SortingAlgorithm::bars[arrSize - 1], sortedColor);
            std::cout << "Finished selection sort." << std::endl;
        }

    private:
        sf::RenderWindow& window;
        sf::Color comparingColor = sf::Color(197, 54, 69);
        sf::Color sortedColor = sf::Color(65,117,113);
        sf::Color minIndexColor = sf::Color(90, 148, 255);
};