#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main()
{
    try
    {
        std::cout << "Test 1" << std::endl;
        unsigned int size = 5;
        Span<int> sp(size);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(-1);
        // sp.addNumber(-1232132132);
        // sp.addNumber(17);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

        std::cout << std::endl;

        std::cout << "Test 2" << std::endl;
        int size2 = 100;
        int maxNbr = 40000;
        Span<int> sp2(size2);

        std::vector<int> nbrs;
        srand(time(NULL));
        for (int i = 0; i < size2; i++)
        {
            int nbr = rand() % maxNbr;
            nbrs.push_back(nbr);
        }
        sp2.addMultipleNumbers(nbrs);
        std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "* Exception caught: " << e.what() << " *" << std::endl;
    }

    return 0;
}