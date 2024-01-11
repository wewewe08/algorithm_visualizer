#include "header-files/WindowManager.h"
#include "header-files/InsertionSort.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

InsertionSort::InsertionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& bars, int arrSize) : WindowManager(window, bars, arrSize) , window(window)
{
    std::cout << "InsertionSort object created." << std::endl;
}

void InsertionSort::RunInsertionSort() {
    // implementation here 
    
    int i, j, key;
    for (i = 1; i < arrSize; ++i){
        key = WindowManager::bars[i].getSize().y;
        j = i - 1;

        while (j >= 0 && WindowManager::bars[j].getSize().y < key) {
            //WindowManager::SwapBars(WindowManager::bars[j+1], WindowManager::bars[j], i, j);
            j = j - 1;
        }
        //WindowManager::SwapBars(WindowManager::bars[j+1], WindowManager::bars[key], i, j);
    }

    std::cout << "Finished insertion sort." << std::endl;
}