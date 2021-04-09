#include "Deque.hpp"
#include <limits.h>
#include <cmath>
#include <iostream>

//constructors

template <typename T, class Alloc>
ft::deque<T, Alloc>::deque() : _size(0) {}

template <typename T, class Alloc>
ft::deque<T, Alloc>::deque(size_type n, ft::deque<T, Alloc>::const_reference v) {
	if (n > ft::deque<T, Alloc>::max_size())
		throw std::runtime_error("ft::deque error : desole, tu t'es trompe, prend pas toute ma ram stp, chrome en a besoin");
	if (n > 0)
	{
		_storage = ft::vector<ft::vector<T, Alloc>, Alloc>(n / 10 + 1);
		for(size_type j = 0; j /10  <= n / 10; j+= 10)
		{
			_storage[j / 10 ].reserve(10);
			//_storage.insert(_storage[j / 10 ].begin(), n % 10 , v);
		}
		_size = n;
	}
}

template <typename T, class Alloc>
ft::deque<T, Alloc>::deque(const deque<T, Alloc> & src)  : _storage(NULL), _size(0) {
	*this = src;
}

//destructor

template <typename T, class Alloc>
ft::deque<T, Alloc>::~deque() {
	if (_size > 0)
		_storage.~vector();
}

//iterator begin

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::iterator ft::deque<T, Alloc>::begin()
{
	return (ft::deque<T, Alloc>::iterator(&_storage[0][0]));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_iterator ft::deque<T, Alloc>::begin() const
{
	return (ft::deque<T, Alloc>::iterator(&_storage[0][0]));
}

//iterator end

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::iterator ft::deque<T, Alloc>::end()
{
	return (ft::deque<T, Alloc>::iterator());
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_iterator ft::deque<T, Alloc>::end() const
{
	return (ft::deque<T, Alloc>::iterator(&_storage[_storage._size() - 1][_storage[_storage._size() - 1]._size()]));
}

//iterator rbegin

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reverse_iterator ft::deque<T, Alloc>::rbegin()
{
	return (ft::deque<T, Alloc>::reverse_iterator(&_storage[_size - 1]));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reverse_iterator ft::deque<T, Alloc>::rbegin() const
{
	return (ft::deque<T, Alloc>::reverse_iterator(&_storage[_size - 1]));
}

//iterator rend

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reverse_iterator ft::deque<T, Alloc>::rend()
{
	return (ft::deque<T, Alloc>::reverse_iterator(&_storage[-1]));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reverse_iterator ft::deque<T, Alloc>::rend() const
{
	return (ft::deque<T, Alloc>::reverse_iterator(&_storage[-1]));
}

//clear

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::clear()
{
	erase(begin(), end());
}

//size 

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::size_type ft::deque<T, Alloc>::size() const
{
	return (_size);
}

//max_size

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::size_type ft::deque<T, Alloc>::max_size() const {
	int bit = 64;
	if (INTPTR_MAX == INT32_MAX)
		bit = 32;
	size_type ret = (pow(2, bit) / sizeof(value_type));
	ret--;
	return (ret);
}

//resize

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::resize(size_type n, T val)
{
	T *tmp = new T(n);
	int i = 0;
	for (; i < _size && i < n; i++)
		tmp[i] = _storage[i];
	for (; i < n; i++)
		tmp[i] = val;
	_size = n;
}

//capacity

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::size_type ft::deque<T, Alloc>::capacity() const
{
	return (33);
}

//empty

template <typename T, class Alloc>
bool ft::deque<T, Alloc>::empty() const {
	return (_size == 0);
}

//reserve

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::reserve(size_type n)
{
}

//operator []

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reference ft::deque<T, Alloc>::operator[] (size_type p) const {

	size_type chunk;
	size_type pos;

	chunk = (_storage.size() > 1) ? ((p < _storage[0].size()) ? 0 : (p - _storage[0].size() + 1) / 10 + 1) : 0 ;
	pos = (_storage.size() > 1) ? (p - _storage[0].size() + 1) % 10 : p % 10;
	return(_storage[chunk][pos]);
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reference ft::deque<T, Alloc>::operator[] (size_type p) {
	size_type chunk;
	size_type pos;

	chunk = (_storage.size() > 1) ? ((p < _storage[0].size()) ? 0 : (p - _storage[0].size() + 1) / 10 + 1) : 0 ;
	pos = (_storage.size() > 1) ? (p - _storage[0].size() + 1) % 10 : p % 10;
	return(_storage[chunk][pos]);
}


//operator=

template <typename T, class Alloc>
ft::deque<T, Alloc>  & ft::deque<T, Alloc>::operator=(const deque<T, Alloc> & src) {
	return *this;
}

//at

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reference & ft::deque<T, Alloc>::at(size_type n) {
	return (_storage[n]);
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reference ft::deque<T, Alloc>::at(size_type n) const
{
	return (_storage[n]);
}

//front

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reference ft::deque<T, Alloc>::front()
{
	return (_storage[0]);
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reference ft::deque<T, Alloc>::front() const
{
	return (_storage[0]);
}

//back

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reference ft::deque<T, Alloc>::back()
{
	return (_storage[_size -1]);
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reference ft::deque<T, Alloc>::back() const
{
	return (_storage[_size -1]);
}

//assign

template <typename T, class Alloc>
	template <class InputIterator>
void ft::deque<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	int i;
	for (i = 0; first + i != last && begin() + i != end(); i++)
		;
	erase(begin(), begin() + i);
	insert(begin(), first, last);
	_size = i;
}

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::assign(size_type n, ft::deque<T, Alloc>::const_reference val)
{
	erase(begin(), begin() + n);
	insert(begin(), n, val);
	_size = n;
}

//push_back

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::push_back (const value_type& val)
{
	if (_storage[_storage.size() - 1].size() == 10) {
		ft::vector<T> vec;
		vec.reserve(10);
		_storage.insert(_storage.end(), vec);
	}
	_storage[_storage.size() - 1].insert(_storage[_storage.size() - 1].end(),val);
	_size++;
}

//pop_back

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::pop_back()
{
	_storage[_size - 1].value_type::~value_type();
	_size--;
}

//swap

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::swap (deque& x)
{
}

//erase

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::iterator ft::deque<T, Alloc>::erase(ft::deque<T, Alloc>::iterator position)
{
	return (erase(position, position + 1));
}

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::iterator ft::deque<T, Alloc>::erase(ft::deque<T, Alloc>::iterator first, ft::deque<T, Alloc>::iterator last)
{
	ft::deque<T, Alloc>::iterator  t = first;
	while (first != last)
	{
		(*first).value_type::~value_type();
		++first;
		_size--;
	}
	while (t != end())
	{

		(*t).value_type::~value_type();
		*t = *last;
		++t;
		++last;
	}
	return (first);
}

//insert

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::iterator ft::deque<T, Alloc>::insert(ft::deque<T, Alloc>::iterator position, const_reference value)
{
	ft::deque<T, Alloc>::size_type i = 0;
	ft::deque<T, Alloc>::iterator it = begin();
	for (; it != position && i < _size; it++)
		i++;
	size_type j = _size;
	while (j > i)
	{
		operator[](j) = operator[](j - 1);
		j--;
	}
	push_back();
	_size++;
	return (ft::deque<T, Alloc>::iterator(&_storage[i]));
};

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::insert(ft::deque<T, Alloc>::iterator position, ft::deque<T, Alloc>::size_type n, const_reference value)
{
	while (n--)
		position = insert(position, value);
};

template <typename T, class Alloc>
	template <class InputIterator>
void ft::deque<T, Alloc>::insert(ft::deque<T, Alloc>::iterator position, InputIterator first, InputIterator last)
{
	_insert1(position, first, last);
}


//private insert

template <typename T, class Alloc>
	template <class InputIterator>
void ft::deque<T, Alloc>::_insert(ft::deque<T, Alloc>::iterator position, InputIterator first, InputIterator last)
{
	int i;
	InputIterator prems = first;

	for (i = 0; prems != last; prems++) {
		i++;
	}
	int y = 0;
	for (; begin() + y != position; y++)
		;
	value_type val[i];
	prems = first;
	for (int j = 0; prems != last; prems++) {
		val[j] = *prems;
		j++;
	}
	reserve(_size + i);
	i = 0;
	while (first != last)
	{	
		position = insert(begin() + y, val[i]) + 1;
		y++;
		i++;
		first++;
	}
};

template <typename T, class Alloc>
	template <class InputIterator>
void ft::deque<T, Alloc>::_insert1(ft::deque<T, Alloc>::iterator position, InputIterator first, InputIterator last)
{
	_insert(position, first, last);
}

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::_insert1(ft::deque<T, Alloc>::iterator position, int n, const_reference value)
{
	while (n--)
		position = insert(position, value);
}

//relationnal iterator

	template <class T, class Alloc>
bool operator== (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_type i = 0; i < lhs.size(); i++)
	{
		if (lhs.at(i) != rhs.at(i))
			return (false);
	}
	return (true);
}

	template <class T, class Alloc>
bool operator!= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	if (lhs.size() == rhs.size())
		return (false);
	for (size_type i = 0; i < lhs.size(); i++)
	{
		if (lhs.at(i) == rhs.at(i))
			return (false);
	}
	return (true);
}

	template <class T, class Alloc>
bool operator> (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) > rhs.at(i))
			return (true);
		if (rhs.at(i) < rhs.at(i))
			return (false);
	}
	if (lhs.size() > rhs.size())
		return (true);
	return(false);
}

	template <class T, class Alloc>
bool operator< (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) < rhs.at(i))
			return (true);
		if (rhs.at(i) > rhs.at(i))
			return (false);
	}
	if (lhs.size() < rhs.size())
		return (true);
	return(false);
}

	template <class T, class Alloc>
bool operator>= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) > rhs.at(i))
			return (true);
		if (rhs.at(i) < rhs.at(i))
			return (false);
	}
	if (lhs.size() >= rhs.size())
		return (true);
	return(false);
}

	template <class T, class Alloc>
bool operator<= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) < rhs.at(i))
			return (true);
		if (rhs.at(i) > rhs.at(i))
			return (false);
	}
	if (lhs.size() <= rhs.size())
		return (true);
	return(false);
}

//non member swap

	template <class T, class Alloc>
void swap (ft::deque<T,Alloc>& x, ft::deque<T,Alloc>& y)
{
	x.swap(y);
}

