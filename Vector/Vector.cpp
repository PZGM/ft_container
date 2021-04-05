#include "Vector.hpp"
#include <limits.h>
#include <cmath>
#include <iostream>

//constructor

template <typename T, class Alloc>
ft::vector<T, Alloc>::~vector() {
	delete [] _storage;
}

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(const vector<T, Alloc> & src) {
	*this = src;
}

template <typename T, class Alloc>
ft::vector<T, Alloc>  & ft::vector<T, Alloc>::operator=(const vector<T, Alloc> & src) {
	delete [] _storage;
	_capacity = src._capacity;
	_size = src._size;
	_storage = new T[_capacity];
	for (size_type i = 0; i < _size; i++)
		_storage[i] = src._storage[i];;
	return *this;
}

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const T & v) : _size(n), _capacity(n) {
	if (n > ft::vector<T, Alloc>::max_size())
		throw std::runtime_error("ft::vector error : desole, tu t'es trompe, prend pas toute ma ram stp, chrome en a besoin");
	_storage = new T[n];
	for (size_type i = 0; i < n; i++)
		_storage[i] = v;
}

//iperator begin
//
	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::begin()
{
	return (ft::vector<T, Alloc>::iterator(&_storage[0]));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::begin() const
{
	return (ft::vector<T, Alloc>::iterator(&_storage[0]));
}

//iperator end

	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end()
{
	return (ft::vector<T, Alloc>::iterator(&_storage[_size]));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::end() const
{
	return (ft::vector<T, Alloc>::iterator(&_storage[_size]));
}

//iperator rbegin

	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rbegin()
{
	return (ft::vector<T, Alloc>::reverse_iterator(&_storage[_size - 1]));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rbegin() const
{
	return (ft::vector<T, Alloc>::reverse_iterator(&_storage[_size - 1]));
}

//iterator rend

	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend()
{
	return (ft::vector<T, Alloc>::reverse_iterator(&_storage[-1]));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const
{
	return (ft::vector<T, Alloc>::reverse_iterator(&_storage[-1]));
}
//iterator erase

	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(ft::vector<T, Alloc>::iterator position)
{
	return (erase(position, position + 1));
}

	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(ft::vector<T, Alloc>::iterator first, ft::vector<T, Alloc>::iterator last)
{
	ft::vector<T, Alloc>::iterator  t = first;
	while (first != last)
	{
		(*first).value_type::~value_type();
		(*first) = static_cast<value_type>(NULL);
		++first;
		_size--;
	}
	while (t != end() && last != end())
	{
		*t = *last;
		(*last).value_type::~value_type();
		*last = static_cast<value_type>(NULL);
		++t;
		++last;
	}
	return (first);
}

//size 
template <typename T, class Alloc>
ft::vector<T, Alloc>::vector() : _size(0), _capacity(0) {
	_storage = new T[0];
}

//max_size

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::max_size() const {
	if ((ULONG_MAX) == (UINT_MAX))
		return (pow(2, 32) / sizeof(T) - 1);
	return (pow(2, 64) / sizeof(T) - 1);
}

//resize

	template <typename T, class Alloc>
void ft::vector<T, Alloc>::resize(size_type n, T val)
{
	T *tmp = new T(n);
	int i = 0;
	for (; i < _size && i < n; i++)
		tmp[i] = _storage[i];
	for (; i < n; i++)
		tmp[i] = val;
	delete [] _storage;
	_storage = tmp;
	_capacity = n;
	_size = n;
}

//capacity

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::capacity() const
{
	return (_capacity);
}

//empty

template <typename T, class Alloc>
bool ft::vector<T, Alloc>::empty() const {
	return (_size == 0);
}

//reserve

	template <typename T, class Alloc>
void ft::vector<T, Alloc>::reserve(size_type n)
{
	if (n > _capacity)
	{
		T *tmp = new T(n);
		for (size_type i = 0; i < _size; i++)
			tmp[i] = _storage[i];
		delete [] _storage;
		_storage = tmp;
	}
}

//operator []

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::operator[] (size_type n) const {
	return (_storage[n]);
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::operator[] (size_type n) {
	return (_storage[n]);
}

//at

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reference & ft::vector<T, Alloc>::at(size_type n) {
	return (_storage[n]);
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::at(size_type n) const
{
	return (_storage[n]);
}

//front

	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::front()
{
	return (_storage[0]);
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::front() const
{
	return (_storage[0]);
}

//back

	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::back()
{
	return (_storage[_size -1]);
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::back() const
{
	return (_storage[_size -1]);
}

//clear

	template <typename T, class Alloc>
void ft::vector<T, Alloc>::clear()
{
	erase(begin(), end());
}

//insert
	template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, const_reference value)
{
	ft::vector<T, Alloc>::size_type i = 0;
	ft::vector<T, Alloc>::iterator it = begin();
	while ((it + i) != position && i < _capacity)
		i++;
	if (_size == _capacity)
		reserve(_capacity + 1);
	size_type j = _size;
	while (j > i)
	{
		_storage[j] = _storage[j - 1];
		j--;
	}
	_storage[i] = value;
	_size++;
	return (ft::vector<T, Alloc>::iterator(&_storage[i]));
};

	template <typename T, class Alloc>
void ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, ft::vector<T, Alloc>::size_type n, const_reference value)
{
	while (n--)
		position = insert(position, value);
};


template <typename T, class Alloc>
	template <class InputIterator>
void ft::vector<T, Alloc>::insert1(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last)
{
	_insert(position, first, last);
}

template <typename T, class Alloc>
void ft::vector<T, Alloc>::insert1(ft::vector<T, Alloc>::iterator position, unsigned int n, const_reference value)
{
	while (n--)
		position = insert(position, value);
}

template <typename T, class Alloc>
	template <class InputIterator>
void ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last)
{
	insert1(position, first, last);
}
//assign

template <typename T, class Alloc>
	template <class InputIterator>
void ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	clear();
	insert(begin(), first, last);
}

	template <typename T, class Alloc>
void ft::vector<T, Alloc>::assign(size_type n, ft::vector<T, Alloc>::const_reference val)
{
	clear();
	insert(begin(), n, val);
}


template <typename T, class Alloc>
	template <class InputIterator>
void ft::vector<T, Alloc>::_insert(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last)
{
	int i = 0;
	while (first != last)
	{	
		i++;
		const_reference  value = *first;
		position = insert(position, value)++;
		++first;
	}
};

