#include "header-files/WindowManager.h"
#include "header-files/MergeSort.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

MergeSort::MergeSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& b, int as) : WindowManager(window, b, as) , window(window)
{
    std::cout << "MergeSort object created." << std::endl;
}

void MergeSort::RunMergeSort() {
    // implementation here 

    std::cout << "Finished merge sort." << std::endl;
}