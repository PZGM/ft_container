#include "List.hpp"
#include <iostream>


//constructors

	template <typename T, class Alloc>
ft::list<T, Alloc>::list() : _size(0) {
	_xnode = new elem<T>;
	_xnode->is_xnode = true;
	_xnode->next = _xnode;
	_xnode->prev = _xnode;
}

	template <typename T, class Alloc>
ft::list<T, Alloc>::list(size_type n, const value_type & val) : _size(n)
{
	struct __true_type x;
	_constructor(n, val, x);
}

	template <typename T, class Alloc>
		template <typename InputIterator>
ft::list<T, Alloc>::list(InputIterator first, InputIterator last)
{
	typedef typename ft::__is_integer<InputIterator>::__type isInt;
	isInt x;
	_constructor(first, last, x);	
}

	template <typename T, class Alloc>
ft::list<T, Alloc>::list(const list<T, Alloc> & src) : _size(0)
{
	//jpense que ce truc est full pete
	*this = src;
}

//faut faire l'operateur =

//private constructor

	template <typename T, class Alloc>
void ft::list<T, Alloc>::_constructor(size_type n, const value_type & val, struct ft::__true_type)
{	
	elem<T> *cur;
	_xnode = new elem<T>;	
	elem<T> *tmp = _xnode;
	
	for (int i = 0; i < n; i++)
	{
		cur = new elem<T>(val);
		if (!tmp)
			_xnode->next = cur;
		else
			tmp->next = cur;
		cur->prev = tmp;
		tmp = cur;
	}
	cur->next = _xnode;
	_xnode->prev  = cur;
	_size = n;
}

	template <typename T, class Alloc>
		template <typename InputIterator>
void ft::list<T, Alloc>::_constructor(InputIterator first, InputIterator last, struct ft::__false_type)
{
	
	elem<T> *cur;
	_xnode = new elem<T>();	
	elem<T> *tmp = _xnode;
	int i = 0;
	
	while (first != last)
	{
		cur = new elem<T>(first->content);
		if (!tmp)
			_xnode->next = cur;
		else
			tmp->next = cur;
		cur->prev = tmp;
		tmp = cur;
		first = first->next;
		i++;
	}
	cur->next = _xnode;
	_xnode->prev = cur;
	_size = i;
}

//destrctor

	template <typename T, class Alloc>
ft::list<T, Alloc>::~list()
{
	elem<T> *cur = _xnode->next;
	elem<T> *tmp;
	while (cur != _xnode)
	{
		tmp = cur;
		cur = cur->next;
		delete (tmp);
	}
	delete (_xnode);	
}

//begin

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::begin()
{
	return (ft::list<T, Alloc>::iterator(_xnode->next));
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::const_iterator ft::list<T, Alloc>::begin() const
{
	return (ft::list<T, Alloc>::const_iterator(_xnode->next));
}

//end

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::end()
{
	return (ft::list<T, Alloc>::iterator(_xnode));
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::const_iterator ft::list<T, Alloc>::end() const
{
	return (ft::list<T, Alloc>::const_iterator(_xnode));
}

//rbegin

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::reverse_iterator ft::list<T, Alloc>::rbegin()
{
	return (ft::list<T, Alloc>::reverse_iterator(_xnode->prev));
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::const_reverse_iterator ft::list<T, Alloc>::rbegin() const
{
	return (ft::list<T, Alloc>::const_reverse_iterator(_xnode->prev));
}

//rend

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::reverse_iterator ft::list<T, Alloc>::rend()
{
	return (ft::list<T, Alloc>::reverse_iterator(_xnode));
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::const_reverse_iterator ft::list<T, Alloc>::rend() const
{
	return (ft::list<T, Alloc>::const_reverse_iterator(_xnode));
}

//empty

	template <typename T, class Alloc>
bool	ft::list<T, Alloc>::empty() const
{
	return (!_size);
}

//size

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::size_type ft::list<T, Alloc>::size() const
{
	return (_size);
}

//max_size

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::size_type ft::list<T, Alloc>::max_size() const
{
	size_type max = 0;
	max--;
	return (max);
}

//front

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::reference ft::list<T, Alloc>::front()
{
	return (_xnode->next);
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::const_reference ft::list<T, Alloc>::front() const
{
	return (_xnode->next);
}

//back

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::reference ft::list<T, Alloc>::back()
{
	return (_xnode->prev);
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::const_reference ft::list<T, Alloc>::back() const
{
	return (_xnode->prev);
}

//clear

	template <typename T, class Alloc>
void ft::list<T, Alloc>::clear()
{
	elem<T> *cur = _xnode->next;
	elem<T> *tmp;
	while (cur != _xnode)
	{
		tmp = cur;
		cur = cur->next;
		delete (tmp);
	}
}

//resize

	template <typename T, class Alloc>
void ft::list<T, Alloc>::resize(size_type n, value_type val)
{
	//SoonTM
}

//insert


	template <typename T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::insert(iterator pos, const value_type & val)
{
	ft::list<T, Alloc>::iterator it = begin();
	elem<T> * cur = _xnode;
	while (it != pos)
	{
		it++;
		cur = cur->next;
	}
	elem<T> * newel = new elem<T>(val);
	newel->next = cur->next;
	newel->prev = cur;
	cur->next->prev = newel;
	cur->next = newel;
	_size++;
	return(iterator(newel));
}















