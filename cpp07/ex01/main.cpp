#include "iter.hpp"
#include <iostream>
#include <string>

int main(void)
{
    int array[] = {1, 2, 3, 4, 5};
    std::cout << "int array: " << std::endl;
    iter(array, 5, print<int>);

    std::string array_str[] = {"hello", "world", "this", "is", "a", "test"};
    std::cout << "string array: " << std::endl;
    iter(array_str, 6, print<std::string>);

    float array_float[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::cout << "float array: " << std::endl;
    iter(array_float, 5, print<float>);

    return 0;
}