#include "Array.hpp"
#include <iostream>

template <typename T>
void printArray(Array<T> &array)
{
    for (unsigned int i = 0; i < array.size(); i++)
        std::cout << array[i] << std::endl;
}

int main(void)
{
    try
    {
        Array<int> array(5);
        array[0] = 1;
        array[1] = 2;
        array[2] = 3;
        array[3] = 4;
        array[4] = 5;
        // throws an exception
        // std::cout << array[5] << std::endl;
        printArray(array);

        Array<std::string> array_str(3);
        array_str[0] = "hello";
        array_str[1] = "world";
        array_str[2] = "test";
        printArray(array_str);

        Array<unsigned int> array_unsigned;
        printArray(array_unsigned);
    }
    catch (const std::exception &e)
    {
        std::cerr << "* Exception caught: " << e.what() << " *" << std::endl;
    }

    return 0;
}