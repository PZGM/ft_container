#include "Deque.hpp"
#include <limits.h>
#include <cmath>
#include <iostream>

//constructors

template <typename T, class Alloc>
ft::deque<T, Alloc>::deque() : _size(0) {
	_empty();
}

template <typename T, class Alloc>
ft::deque<T, Alloc>::deque(size_type n, ft::deque<T, Alloc>::const_reference v) {
	struct __true_type x;
	_constructor(n, v, x);
}

template <typename T, class Alloc>
	template <class InputIterator>
ft::deque<T, Alloc>::deque(InputIterator first, InputIterator last) : _size(0), _storage(0) {
	typedef typename ft::__is_integer<InputIterator>::__type isInt;
	isInt vraiNom;
	_constructor(first, last, vraiNom);
}


template <typename T, class Alloc>
ft::deque<T, Alloc>::deque(const deque<T, Alloc> & src)  : _storage(0), _size(0) {
	*this = src;
}

//private constructor

template <typename T, class Alloc>
void ft::deque<T, Alloc>::_constructor(int n, const T & v, struct ft::__true_type) {
	{
		_storage = ft::vector<ft::vector<T, Alloc>, Alloc>(n / 10 + 1);
		for(size_type j = 0; j < n; j+= 10)
		{
			_storage[j / 10 ].reserve(10);
			typename ft::vector<value_type>::iterator it = _storage[j / 10].begin();
			_storage[j / 10].insert(it, (j + 10 > n) ?  n % 10 : 10, v);
		}
		_size = n;
	}
}

template <typename T, class Alloc>
	template <typename InputIterator>
void ft::deque<T, Alloc>::_constructor(InputIterator first, InputIterator last, struct ft::__false_type)
{
	size_type n = 0;
	InputIterator cp = first;
	while (first !=	last)
	{
		first++;
		n++;
	}
	_storage = ft::vector<ft::vector<T, Alloc>, Alloc>(n / 10 + 1);
	for(size_type j = 0; j < n; j+= 10)
	{
		_storage[j / 10 ].reserve(10);
		typename ft::vector<value_type>::iterator it = _storage[j / 10].begin();
		_storage[j / 10].insert(it, (j + 10 > n) ?  n % 10 : 10, T());
		for (int i = 0; i < ((j + 10 > n) ?  n % 10 : 10); i++)
		{
			_storage[j/10][i] = static_cast<T>(*cp);
			cp++;
		}
	}
	_size = n;
}

//destructor

template <typename T, class Alloc>
ft::deque<T, Alloc>::~deque() { }

//iterator begin

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::iterator ft::deque<T, Alloc>::begin()
{
	return (ft::deque<T, Alloc>::iterator(0, & _storage));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_iterator ft::deque<T, Alloc>::begin() const
{
	return (ft::deque<T, Alloc>::iterator(0, & _storage));
}

//iterator end

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::iterator ft::deque<T, Alloc>::end()
{
	return (ft::deque<T, Alloc>::iterator(_size, & _storage));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_iterator ft::deque<T, Alloc>::end() const
{
	return (ft::deque<T, Alloc>::iterator(_size , & _storage));
}

//iterator rbegin

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reverse_iterator ft::deque<T, Alloc>::rbegin()
{
	return (ft::deque<T, Alloc>::reverse_iterator(_size - 1, & _storage));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reverse_iterator ft::deque<T, Alloc>::rbegin() const
{
	return (ft::deque<T, Alloc>::reverse_iterator(_size - 1, & _storage));
}

//iterator rend

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reverse_iterator ft::deque<T, Alloc>::rend()
{
	return (ft::deque<T, Alloc>::reverse_iterator(- 1, & _storage));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reverse_iterator ft::deque<T, Alloc>::rend() const
{
	return (ft::deque<T, Alloc>::reverse_iterator(-1, & _storage));
}

//clear

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::clear() {
	_size = 0;
	_storage.clear();
	_empty();
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
	return (Alloc().max_size());
	int bit = 64;
	if (INTPTR_MAX == INT32_MAX)
		bit = 32;
	size_type ret = (pow(2, bit) / sizeof(value_type));
	ret--;
	return (ret * 10);
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

//operator []

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reference ft::deque<T, Alloc>::operator[] (size_type pos) const {

	size_type chunk = 0;

	for( ; chunk < _storage.size() && pos >= _storage[chunk].size() ; chunk++)
		pos -= _storage[chunk].size();

	return(_storage[chunk][pos]);
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reference ft::deque<T, Alloc>::operator[] (size_type pos) {
	size_type chunk = 0;

	for( ; chunk < _storage.size() && pos >= _storage[chunk].size(); chunk++)
		pos -= _storage[chunk].size();

	return(_storage[chunk][pos]);
}


//operator=

template <typename T, class Alloc>
ft::deque<T, Alloc>  & ft::deque<T, Alloc>::operator=(const deque<T, Alloc> & src) {
	_storage = src._storage;
	for (int i = 0; i < _storage.size(); i++)
		_storage[i] = src._storage[i];
	_size = src._size;
	return *this;
}

//at

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reference & ft::deque<T, Alloc>::at(size_type n) {
	return (operator[](n));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reference ft::deque<T, Alloc>::at(size_type n) const
{
	return (operator[](n));
}

//front

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reference ft::deque<T, Alloc>::front()
{
	return (operator[](0));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reference ft::deque<T, Alloc>::front() const
{
	return (operator[](0));
}

//back

	template <typename T, class Alloc>
typename ft::deque<T, Alloc>::reference ft::deque<T, Alloc>::back()
{
	return (operator[](_size - 1));
}

template <typename T, class Alloc>
typename ft::deque<T, Alloc>::const_reference ft::deque<T, Alloc>::back() const
{
	return (operator[](_size - 1));
}

//assign

template <typename T, class Alloc>
	template <class Unknow>
void ft::deque<T, Alloc>::assign(Unknow first, Unknow second)
{
	typedef typename ft::__is_integer<Unknow>::__type isInt;
	isInt inst;
	_assign(first, second, inst);
}

template <typename T, class Alloc>
	template <class InputIterator>
void ft::deque<T, Alloc>::_assign(InputIterator firste, InputIterator laste, struct ft::__false_type)
{
	ft::vector<T> vec(firste, laste);
	clear();
	typename ft::vector<T>::iterator first = vec.begin();
	typename ft::vector<T>::iterator last = vec.end();

	size_type n = 0;
	typename ft::vector<T>::iterator cp = first;
	while (first !=	last)
	{
		first++;
		n++;
	}
	_storage = ft::vector<ft::vector<T, Alloc>, Alloc>(n / 10 + 1);
	for(size_type j = 0; j < n; j+= 10)
	{
		_storage[j / 10 ].reserve(10);
		typename ft::vector<value_type>::iterator it = _storage[j / 10].begin();
		_storage[j / 10].insert(it, (j + 10 > n) ?  n % 10 : 10, T());
		for (int i = 0; i < ((j + 10 > n) ?  n % 10 : 10); i++)
		{
			_storage[j/10][i] = static_cast<T>(*cp);
			cp++;
		}
	}
	_size = n;
}

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::_assign(size_type n, ft::deque<T, Alloc>::const_reference val, struct ft::__true_type)
{
//	clear();
	erase(begin(), end());
	insert(begin(), n, val);
	_size = n;
}

//push_back

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::push_back (const value_type& val)
{
	if (_size != 0 && _storage[_storage.size() - 1].size() == _storage[_storage.size() - 1].capacity()) {
		ft::vector<T> vec;
		vec.reserve(10);
		_storage.insert(_storage.end(), vec);
	}
	_storage[_storage.size() - 1].push_back(val);
	_size++;
}

//push_front

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::push_front (const value_type& val)
{

	/*if (_size != 0 && _storage[0].size() == _storage[0].capacity())
	{
		ft::vector<value_type> vec;
		_storage.insert(_storage.begin(), 1, vec);
	} */
	_storage[0].insert(_storage[0].begin(), 1, val);
	_size++;
}

//pop_back

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::pop_back()
{
	if (_size == 0)
		return;
	if (_storage[_storage.size() - 1].size() == 0)
		_storage.pop_back();
	else

		_storage[_storage.size() - 1].pop_back();
	_size--;
}

//pop front

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::pop_front ()
{
	if (_size == 0)
		return;
	_storage[0].erase(_storage[0].begin());
	if (_storage[0].size() == 0 && _storage.size() != 1)
	{
		_storage.erase(_storage.begin());
	}
	_size--;
}

//swap

	template <typename T, class Alloc>
void ft::deque<T, Alloc>::swap (deque& x)
{
//	std::cout << "A" << _storage[0][1] << "|" << x._storage[0][1]  << std::endl;
	_storage.swap(x._storage);
//	vector<vector<T, Alloc>, Alloc> tmp = _storage;
	size_type t = _size;

//	_storage = x._storage;
	_size = x._size;

//	x._storage = tmp;
	x._size = t;
//	std::cout << "B" << _storage[0][1] << "|" << x._storage[0][1]  << std::endl;
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
	ft::deque<T, Alloc>::iterator  t = begin();
	int i = 0;
	while (t != first)
	{
		t++;
		i++;
	}
	int l = 0;
	while (first != last)
	{
		first++;
		l++;
	}
	while (l)
	{
		size_type chunk = 0;
		size_type pos = i;
		for( ; chunk < _storage.size() && pos >= _storage[chunk].size() ; chunk++)
			pos -= _storage[chunk].size();
		if (chunk)
			chunk--;
		typename ft::vector<T, Alloc>::iterator it = _storage[chunk].begin();
		while (pos)
			it++;
		_storage[chunk].erase(it);
		l--;
		_size--;
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
	size_type chunk = 0;
	size_type pos = i;
	for (; chunk < _storage.size() && pos > _storage[chunk].size() ; chunk++)
		pos -= _storage[chunk].size();
	if (chunk == _storage.size())
	{
		ft::vector<T>  vec(0);
		vec.reserve(10);
		_storage.push_back(vec);
	}
	typename ft::vector<T, Alloc>::iterator ite = _storage[chunk].begin();
	for (; pos; pos--)
		ite++;
	_storage[chunk].insert(ite, value);
	_size++;
	return (ft::deque<T, Alloc>::iterator(i, & _storage));
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
	ft::deque<T, Alloc>::size_type i = 0;
	ft::deque<T, Alloc>::iterator it = begin();
	for (; it != position && i < _size; it++)
		i++;
	size_type chunk = 0;
	size_type pos = i;
	for (; chunk < _storage.size() && pos >= _storage[chunk].size() ; chunk++)
		pos -= _storage[chunk].size();
	if (chunk)
		chunk--;
	if (chunk >= _storage.size()) //new alloc
	{
		ft::vector<T>  vec(0);
		vec.reserve(10);
		_storage.push_back(vec);
	}
	typename ft::vector<T, Alloc>::iterator ite = _storage[chunk].begin();
	for (; pos; pos--)
		ite++;
	_storage[chunk].insert(ite, first, last);
	while (first != last)
	{
		first++;
		_size++;
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

// verif empty before add

template< typename T, class Alloc>
void ft::deque<T, Alloc>::_empty() {
	if (_size == 0 && _storage.size() == 0)
	{
		ft::vector<T>  vec(0);
		vec.reserve(10);
		_storage.push_back(vec);
	}
}
//relationnal iterator

	template <class T, class Alloc>
bool ft::operator== (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
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
bool ft::operator!= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (true);
	for (size_type i = 0; i < lhs.size(); i++)
	{
		if (lhs.at(i) == rhs.at(i))
			return (false);
	}
	return (true);
}

	template <class T, class Alloc>
bool ft::operator> (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) > rhs.at(i))
			return (true);
		if (lhs.at(i) < rhs.at(i))
			return (false);
	}
	if (lhs.size() > rhs.size())
		return (true);
	return(false);
}

	template <class T, class Alloc>
bool ft::operator< (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) < rhs.at(i))
			return (true);
		if (lhs.at(i) > rhs.at(i))
			return (false);
	}
	if (lhs.size() < rhs.size())
		return (true);
	return(false);
}

	template <class T, class Alloc>
bool ft::operator>= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) > rhs.at(i))
			return (true);
		if (lhs.at(i) < rhs.at(i))
			return (false);
	}
	if (lhs.size() >= rhs.size())
		return (true);
	return(false);
}

	template <class T, class Alloc>
bool ft::operator<= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs)
{
	for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) < rhs.at(i))
			return (true);
		if (lhs.at(i) > rhs.at(i))
			return (false);
	}
	if (lhs.size() <= rhs.size())
		return (true);
	return(false);
}

//non member swap

	template <class T, class Alloc>
void ft::swap (ft::deque<T,Alloc>& x, ft::deque<T,Alloc>& y)
{
	x.swap(y);
}
