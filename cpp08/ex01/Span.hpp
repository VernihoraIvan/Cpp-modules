#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

template <typename T>
class Span
{
public:
    Span(void);
    Span(unsigned int N);
    Span(const Span &copy);
    ~Span(void);

    Span &operator=(const Span &copy);
    void addNumber(int nbr);
    int shortestSpan(void);
    int longestSpan(void);

private:
    unsigned int _N;
    std::vector<int> _vec;
};

#include "Span.tpp"

#endif