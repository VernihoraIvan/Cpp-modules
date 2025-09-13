#include "Span.hpp"

template <typename T>
Span<T>::Span(void) : _N(0)
{
}

template <typename T>
Span<T>::Span(unsigned int N) : _N(N)
{
    // _vec = new int[_N];
    _vec.reserve(_N);
}

template <typename T>
Span<T>::Span(const Span &copy)
{
    *this = copy;
}

template <typename T>
Span<T>::~Span(void)
{
    if (_vec.capacity())
        // delete[] _vec;
        _vec.clear();
}

template <typename T>
Span<T> &Span<T>::operator=(const Span &copy)
{
    if (this != copy)
    {
        _N = copy._N;
        // delete[] _vec;
        _vec.clear();
        _vec.reserve(_N);
        for (unsigned int i = 0; i < _N; i++)
            _vec[i] = copy._vec[i];
    }
    return *this;
}

template <typename T>
void Span<T>::addNumber(int nbr)
{
    std::cout << "capacity: " << _vec.capacity() << std::endl;
    std::cout << "_N: " << _N << std::endl;
    if (_vec.size() == _vec.capacity())
        throw std::out_of_range("Span is full");
    if (_N == 0)
        throw std::out_of_range("Span is empty");
    _vec.push_back(nbr);
}

template <typename T>
int Span<T>::longestSpan(void)
{
    std::vector<int> sorted_vec = _vec;
    std::sort(sorted_vec.begin(), sorted_vec.end());
    return sorted_vec.back() - sorted_vec.front();
}

template <typename T>
int Span<T>::shortestSpan(void)
{
    if (_vec.size() < 2)
        throw std::invalid_argument("Container size is less than 2");
    std::vector<int> sorted_vec = _vec;
    std::sort(sorted_vec.begin(), sorted_vec.end());
    int shortestSpan = INT_MAX;
    for (size_t i = 0; i < sorted_vec.size() - 1; i++)
    {
        int currentShortestSpan;
        if (i + 1 < sorted_vec.size())
        {
            currentShortestSpan = (sorted_vec[i] - sorted_vec[i + 1]) * -1;
            shortestSpan = shortestSpan > currentShortestSpan ? currentShortestSpan : shortestSpan;
        }
    }
    std::cout << "shortestSppan: " << shortestSpan << std::endl;
    return shortestSpan;
}