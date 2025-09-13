#include "Span.hpp"
#include <iostream>

int main()
{
    try
    {
        unsigned int size = 5;
        Span<int> sp(size);
        sp.addNumber(6);
        sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        // sp.addNumber(11);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "* Exception caught: " << e.what() << " *" << std::endl;
    }

    return 0;
}