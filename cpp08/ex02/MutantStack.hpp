
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
  public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	
	typedef typename container::iterator iterator;

	iterator begin();
	iterator end();

};

#include "MutantStack.tpp"

#endif