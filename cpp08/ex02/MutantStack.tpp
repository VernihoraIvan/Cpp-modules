#include "MutantStack.hpp"

template <typename T, class container>
MutantStack<T, container>::MutantStack() : std::stack<T>()
{
}

template <typename T, class container>
MutantStack<T, container>::~MutantStack()
{
}

template <typename T, class container>
MutantStack<T, container>::MutantStack(const MutantStack &stack) : std::stack<T>()
{
	*this = stack;
}

template <typename T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin()
{
	return this->c.begin();
}

template <typename T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end()
{
	return this->c.end();
}