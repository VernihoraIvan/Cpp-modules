#include "utils.hpp"
#include <iostream>

int main(void)
{
    int a = 4;
    int b = 9;
    int c = 4;

    // float a = 4.2f;
    // float b = 9.2f;
    // float c = 4.2f;

    // std::string a = "hi4";
    // std::string b = "hi9";
    // std::string c = "hii4";

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    ::swap(a, b);
    std::cout << "after swap(a, b)" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "min(a, c) = " << ::min(a, c) << std::endl;
    std::cout << "max(a, c) = " << ::max(a, c) << std::endl;

    return 1;
}