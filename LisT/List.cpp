#include "List.hpp"
#include <iostream>


//constructors

	template <typename T, class Alloc>
ft::list<T, Alloc>::list() : _size(0), _first(NULL), _last(NULL) {}

	template <typename T, class Alloc>
ft::list<T, Alloc>::list(size_type n, const value_type & val) : _size(n)
{
	elem *cur;
	elem *tmp = NULL;
	
	for (int i = 0; i < n; i++)
	{
		cur = new elem(val);
		
		if (!tmp)
			_first = cur;
		else
			tmp->next = cur;
		cur->prev = tmp;
		tmp = cur;
	}
	_last = cur;
}
