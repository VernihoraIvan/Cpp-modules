#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _array(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _array = new T[n];
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    _size = copy._size;
    _array = new T[copy._size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array(void)
{
    if (_array)
        delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this != &copy)
    {
        if (_array)
            delete[] _array;
        _size = copy._size;
        _array = new T[copy._size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = copy._array[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index is out of range");
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return _size;
}
