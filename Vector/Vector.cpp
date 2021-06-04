#include "Vector.hpp"
#include <limits.h>
#include <cmath>
#include <iostream>

//constructors

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector() : _storage(NULL), _size(0), _capacity(0) {
}

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, const T & v)	: _size(n), _capacity(n) {
	struct __true_type x;
	_constructor(n, v, x);
}

template <typename T, class Alloc>
ft::vector<T, Alloc>::vector(const vector<T, Alloc> & src) : _size(0), _capacity(0), _storage(NULL) {
	*this = src;
}

template <typename T, class Alloc>
	template <class InputIterator>
ft::vector<T, Alloc>::vector(InputIterator first, InputIterator last)
	{
	_size = 0;
	_capacity = 0;
	_storage = NULL;
	typedef typename ft::__is_integer<InputIterator>::__type isInt;
	isInt vraiNom;
	_constructor(first, last, vraiNom);
}

//private constructors


template <typename T, class Alloc>
void ft::vector<T, Alloc>::_constructor(int n, const T & v, struct ft::__true_type) {
	if (n > ft::vector<T, Alloc>::max_size())
		throw std::runtime_error("ft::vector error : desole, tu t'es trompe, prend pas toute ma ram stp, chrome en a besoin");
	if (n > 0)
		_storage = new T[n];
	for (size_type i = 0; i < n; i++)
		_storage[i] = v;
	_capacity = n;
	_size = n;
}


template <typename T, class Alloc>	
template <class InputIterator>
void ft::vector<T, Alloc>::_constructor(InputIterator first, InputIterator last, struct ft::__false_type) {
	assign(first, last);
}

//destructor

template <typename T, class Alloc>
ft::vector<T, Alloc>::~vector() {
	if (_capacity > 0)
		delete [] _storage;
}

//iterator begin

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::begin() {
	return (ft::vector<T, Alloc>::iterator(&_storage[0]));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::begin() const {
	return (ft::vector<T, Alloc>::iterator(&_storage[0]));
}

//iterator end

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end() {
	return (ft::vector<T, Alloc>::iterator(&_storage[_size]));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::end() const {
	return (ft::vector<T, Alloc>::iterator(&_storage[_size]));
}

//iterator rbegin

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rbegin() {
	return (ft::vector<T, Alloc>::reverse_iterator(&_storage[_size - 1]));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rbegin() const {
	return (ft::vector<T, Alloc>::reverse_iterator(&_storage[_size - 1]));
}

//iterator rend

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend() {
	return (ft::vector<T, Alloc>::reverse_iterator(&_storage[-1]));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const {
	return (ft::vector<T, Alloc>::reverse_iterator(&_storage[-1]));
}

//clear

template <typename T, class Alloc>
void ft::vector<T, Alloc>::clear() {
	erase(begin(), end());
}

//size 

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::size() const {
	return (_size);
}

//max_size

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::max_size() const {
	return (Alloc().max_size());
}

//resize

template <typename T, class Alloc>
void ft::vector<T, Alloc>::resize(size_type n, T val) {
	T *tmp = new T(n);
	int i = 0;
	for (; i < _size && i < n; i++)
		tmp[i] = _storage[i];
	for (; i < n; i++)
		tmp[i] = val;
	if (_capacity > 0)
		delete [] _storage;
	_storage = tmp;
	_capacity = n;
	_size = n;
}

//capacity

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::capacity() const {
	return (_capacity);
}

//empty

template <typename T, class Alloc>
bool ft::vector<T, Alloc>::empty() const {
	return (_size == 0);
}

//reserve

template <typename T, class Alloc>
void ft::vector<T, Alloc>::reserve(size_type n) {
	if (n > _capacity)
	{
		value_type *tmp = new T[n];
		for (size_type i = 0; i < _size; i++)
			tmp[i] = _storage[i];
		if (_capacity > 0)
			delete [] _storage;
		_storage = tmp;
		_capacity = n;
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


//operator=

template <typename T, class Alloc>
ft::vector<T, Alloc>  & ft::vector<T, Alloc>::operator=(const vector<T, Alloc> & src) {
	if (_capacity > 0)
		delete [] _storage;
	_capacity = src._capacity;
	_size = src._size;
	if (_capacity > 0)
		_storage = new T[_capacity];
	for (size_type i = 0; i < _size; i++)
		_storage[i] = src._storage[i];
	return *this;
}

//at

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reference & ft::vector<T, Alloc>::at(size_type n) {
	return (_storage[n]);
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::at(size_type n) const {
	return (_storage[n]);
}

//front

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::front() {
	return (_storage[0]);
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::front() const {
	return (_storage[0]);
}

//back

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::back() {
	return (_storage[_size -1]);
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::back() const {
	return (_storage[_size -1]);
}

//assign

template <typename T, class Alloc>
template <class InputIterator>
void ft::vector<T, Alloc>::assign(InputIterator first, InputIterator last) {
	clear();
	insert(begin(), first, last);
}

template <typename T, class Alloc>
void ft::vector<T, Alloc>::assign(size_type n, ft::vector<T, Alloc>::const_reference val) {
	clear();
	insert(begin(), n, val);
	_size = n;
}

//push_back

template <typename T, class Alloc>
void ft::vector<T, Alloc>::push_back (const value_type& val) {

	reserve(_size + 1);
	_storage[_size] = T(val);
	_size++;
}

//pop_back

template <typename T, class Alloc>
void ft::vector<T, Alloc>::pop_back() {
	//	_storage[_size - 1].value_type::~value_type();
	_size--;
}

//swap

template <typename T, class Alloc>
void ft::vector<T, Alloc>::swap (vector& x) {
	size_type tmp = x.size();
	x._size = _size;
	_size = tmp;

	tmp = x._capacity;
	x._capacity = _capacity;
	_capacity = tmp;

	value_type* tmps = x._storage;
	x._storage = _storage;
	_storage = tmps;
}

//erase

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(ft::vector<T, Alloc>::iterator position) {
	return (erase(position, position + 1));
}

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::erase(ft::vector<T, Alloc>::iterator first, ft::vector<T, Alloc>::iterator last) {
	ft::vector<T, Alloc>::iterator  t = first;
	while (first != last)
	{
		++first;
		_size--;
	}
	while (t != end())
	{
		*t = *last;
		++t;
		++last;
	}
	return (first);
}

//insert

template <typename T, class Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, const_reference value) {
	ft::vector<T, Alloc>::size_type i = 0;
	ft::vector<T, Alloc>::iterator it = begin();
	for (; it != position && i < _size; it++)
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
void ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, ft::vector<T, Alloc>::size_type n, const_reference value) {
	while (n--)
		position = insert(position, value);
};

template <typename T, class Alloc>
template <class InputIterator>
void ft::vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last) {
	_insert1(position, first, last);
}


//private insert

template <typename T, class Alloc>
template <class InputIterator>
void ft::vector<T, Alloc>::_insert(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last) {
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
		insert(begin() + y, val[i]) + 1;
		y++;
		i++;
		first++;
	}
};

template <typename T, class Alloc>
template <class InputIterator>
void ft::vector<T, Alloc>::_insert1(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last) {
	_insert(position, first, last);
}

	template <typename T, class Alloc>
void ft::vector<T, Alloc>::_insert1(ft::vector<T, Alloc>::iterator position, int n, const_reference value)
{
	while (n--)
		position = insert(position, value);
}

//relational operator

template <typename T, class Alloc>
bool ft::operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
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
bool ft::operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return (true);
	for (size_type i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs.at(i) != rhs.at(i))
			return (true);
	}
	return (false);
}

template <class T, class Alloc>
bool ft::operator> (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
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
bool ft::operator< (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
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
bool ft::operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
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
bool ft::operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
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
void ft::swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
	x.swap(y);
}

