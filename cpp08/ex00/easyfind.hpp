#include <algorithm>
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

template <typename T>
void easyfind(T &container, int value)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
        std::cout << GREEN << "Value " << value << " found" << RESET << std::endl;
    else
        std::cerr << RED << "Value " << value << " not found" << RESET << std::endl;
}