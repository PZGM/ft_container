#include "vector.hpp"


template <typename T>
size_type ft::vector<T>::max_size(void) const
{
	return (LONG_MAX);
}

template <typename T>
T & ft::vector<T>::at(size_type n)
{
	return (_storage[n]);
}

template <typename T>
T & ft::vector<T>::at(size_type n) const
{
	return (_storage[n]);
}



template <typename T>
bool ft::vector<T>::empty(void) const
{
	return (_size == 0);
}
