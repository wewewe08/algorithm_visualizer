#include "header-files/WindowManager.h"
#include "header-files/InsertionSort.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

InsertionSort::InsertionSort(sf::RenderWindow& window, std::vector<sf::RectangleShape>& b, int as) : WindowManager(window, b, as) , window(window)
{
    std::cout << "InsertionSort object created." << std::endl;
}

void InsertionSort::RunInsertionSort() {
    // implementation here 
    
    std::cout << "Finished insertion sort." << std::endl;
}