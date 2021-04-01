#include "vector.hpp"
#include <cmath>

//iperator begin

template <typename T>
typename ft::vector<T>::iterator ft::vector<T>::begin(void) //why ?
{
	return (ft::vector<T>::iterator(&_storage[0]));
}

template <typename T>
const typename ft::vector<T>::iterator ft::vector<T>::begin(void) const
{
	return (ft::vector<T>::iterator(&_storage[0]));
}

//iperator end

template <typename T>
typename ft::vector<T>::iterator ft::vector<T>::end(void)
{
	return (ft::vector<T>::iterator(&_storage[_size]));
}

template <typename T>
const typename ft::vector<T>::iterator ft::vector<T>::end(void) const
{
	return (ft::vector<T>::iterator(&_storage[_size]));
}

//iperator rbegin

template <typename T>
typename ft::vector<T>::reverse_iterator ft::vector<T>::rbegin(void)
{
	return (ft::vector<T>::reverse_iterator(&_storage[_size - 1]));
}

template <typename T>
const typename ft::vector<T>::reverse_iterator ft::vector<T>::rbegin(void) const
{
	return (ft::vector<T>::reverse_iterator(&_storage[_size - 1]));
}

//iterator rend

template <typename T>
typename ft::vector<T>::reverse_iterator ft::vector<T>::rend(void)
{
	return (ft::vector<T>::reverse_iterator(&_storage[-1]));
}

template <typename T>
const typename ft::vector<T>::reverse_iterator ft::vector<T>::rend(void) const
{
	return (ft::vector<T>::reverse_iterator(&_storage[-1]));
}

//size 
template <typename T>
ft::vector<T>::vector() : _size(0), _capacity(0) {
	_storage = new T[0];
}

//max_size

template <typename T>
size_type ft::vector<T>::max_size(void) const {
	if ((ULONG_MAX) == (UINT_MAX))
		return (pow(2, 32) / sizeof(T) - 1);
	return (pow(2, 64) / sizeof(T) - 1);
}

//resize

template <typename T>
void ft::vector<T>::resize(size_type n, T val)
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

template <typename T>
size_type ft::vector<T>::capacity(void) const
{
	return (_capacity);
}

//empty

template <typename T>
bool ft::vector<T>::empty(void) const {
	return (_size == 0);
}

//reserve

template <typename T>
void ft::vector<T>::reserve(size_type n)
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

template <typename T>
const T & ft::vector<T>::operator[] (size_type n) const {
	return (_storage[n]);
}

template <typename T>
T & ft::vector<T>::operator[] (size_type n) {
	return (_storage[n]);
}

//at

template <typename T>
T & ft::vector<T>::at(size_type n) {
	return (_storage[n]);
}

template <typename T>
T & ft::vector<T>::at(size_type n) const
{
	return (_storage[n]);
}

//front

template <typename T>
T & ft::vector<T>::front()
{
	return (_storage[0]);
}

template <typename T>
const T & ft::vector<T>::front() const
{
	return (_storage[0]);
}

//back

template <typename T>
T & ft::vector<T>::back()
{
	return (_storage[_size -1]);
}

template <typename T>
const T & ft::vector<T>::back() const
{
	return (_storage[_size -1]);
}

//assign

template <typename T>
template <class InputIterator>
void ft::vector<T>::assign(InputIterator first, InputIterator last)
{
	int i = 0;
	for (InputIterator f = first; f != last; f++)
		i++;
	reserve(i);
	_size = i;
	i = 0;
	for (; first != last; first++)
	{
		_storage[i] = *first;
		i++;
	}
}

template <typename T>
void ft::vector<T>::assign(size_type n, const T & val)
{
	reserve(n);
	for (size_type i = 0; i < n; i++)
		_storage[i] = val;
	_size = n;
}


template <typename T>
ft::vector<T>::~vector() {
	delete [] _storage;
}

template <typename T>
ft::vector<T>::vector(const vector<T> & src) {
	*this = src;
}

template <typename T>
ft::vector<T>  & ft::vector<T>::operator=(const vector<T> & src) {
	delete [] _storage;
	_capacity = src._capacity;
	_size = src._size;
	_storage = new T[_capacity];
	for (size_type i = 0; i < _size; i++)
		_storage[i] = src._storage[i];;
	return *this;
}

template <typename T>
ft::vector<T>::vector(size_type n, const T & v) : _size(n), _capacity(n) {
	if (n > ft::vector<T>::max_size())
		throw std::runtime_error("ft::vector error : desole mon petit, tu t'es trompe, prend pas toute ma ram stueplait, chrome en a besoin");
	_storage = new T[n];
	for (size_type i = 0; i < n; i++)
		_storage[i] = v;
}




