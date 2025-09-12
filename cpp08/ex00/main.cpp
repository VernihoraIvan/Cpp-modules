#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    std::vector<int> container_vector;
    std::list<int> container_list;
    std::deque<int> container_deque;

    container_vector.push_back(1);
    container_vector.push_back(2);
    container_vector.push_back(3);

    container_list.push_back(1);
    container_list.push_back(2);
    container_list.push_back(3);

    container_deque.push_back(1);
    container_deque.push_back(2);
    container_deque.push_back(3);

    std::cout << "Vector test: " << std::endl;
    easyfind(container_vector, 2);
    std::cout << std::endl;

    std::cout << "List test: " << std::endl;
    easyfind(container_list, 3);
    std::cout << std::endl;

    std::cout << "Deque test: " << std::endl;
    easyfind(container_deque, 4);
    std::cout << std::endl;

    return 0;
}