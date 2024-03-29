#include "header-files/WindowManager.h"
#include "header-files/SelectionSort.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

SelectionSort::SelectionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int arrSize) : WindowManager(window, bars, arrSize) , window(window)
{
    std::cout << "SelectionSort object created." << std::endl;
}

void SelectionSort::RunSelectionSort() {
    std::vector<std::thread> colorChangeThreads;

    for (int i = 0; i < arrSize - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < arrSize; ++j) {
            WindowManager::ChangeColors(WindowManager::bars[j], WindowManager::comparingColor);
            if (WindowManager::bars[j].getSize().y < WindowManager::bars[minIndex].getSize().y) {
                WindowManager::ChangeColors(WindowManager::bars[minIndex], sf::Color::White); 
                minIndex = j;
                // thread  to change the new minIndex bar to blue while the comparing bar is still updating
                colorChangeThreads.emplace_back([&](){
                    WindowManager::ChangeColors(WindowManager::bars[minIndex], minIndexColor);
                });
            }
            WindowManager::ResetThreads(colorChangeThreads);
            WindowManager::ResetWindow();

            // resetting comparing bars
            if (WindowManager::bars[j].getFillColor() != minIndexColor) {
                WindowManager::ChangeColors(WindowManager::bars[j], sf::Color::White);
            }
        }
        // swapping elements
        WindowManager::ChangeColors(WindowManager::bars[minIndex], sf::Color::White); 
        WindowManager::SwapBars(WindowManager::bars[i], WindowManager::bars[minIndex], i, minIndex);
        WindowManager::ResetWindow();
    }
    // change last bar color to green
    WindowManager::ChangeColors(WindowManager::bars[arrSize - 1], sortedColor);
    std::cout << "Finished selection sort." << std::endl;
}