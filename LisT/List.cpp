#include "List.hpp"
#include <iostream>

//constructors

	template <typename T, class Alloc>
ft::list<T, Alloc>::list() : _size(0) {
	_xnode = new elem<T>;
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
	_xnode = new elem<T>;
	_xnode->next = _xnode;
	_xnode->prev = _xnode;
	insert(begin(), src.begin(), src.end());
}

//assign operator

	template <typename T, class Alloc>
ft::list<T, Alloc> & ft::list<T, Alloc>::operator= (const list& x)
{
	clear();
	delete (_xnode);
	_xnode = new elem<T>;
	_xnode->next = _xnode;
	_xnode->prev = _xnode;
	insert(begin(), x.begin(), x.end());
	return (*this);
}

//private constructor

	template <typename T, class Alloc>
void ft::list<T, Alloc>::_constructor(size_type n, const value_type & val, struct ft::__true_type)
{	
	elem<T> *cur;
	_xnode = new elem<T>;	
	elem<T> *tmp = _xnode;
	cur = _xnode;
	
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
	
	_xnode = new elem<T>();	
	elem<T> *cur = _xnode;
	elem<T> *tmp = _xnode;
	int i = 0;
	
	while (first != last)
	{
		cur = new elem<T>(*first);
		if (!tmp)
			_xnode->next = cur;
		else
			tmp->next = cur;
		cur->prev = tmp;
		tmp = cur;
		first++;;
		i++;
	}
	cur->next = _xnode;
	_xnode->prev = cur;
	_size = i;
}

//destructor

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
	max /= 48;
	return (max);
}

//front

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::reference ft::list<T, Alloc>::front()
{
	return (_xnode->next->content);
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::const_reference ft::list<T, Alloc>::front() const
{
	return (_xnode->next->content);
}

//back

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::reference ft::list<T, Alloc>::back()
{
	return (_xnode->prev->content);
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::const_reference ft::list<T, Alloc>::back() const
{
	return (_xnode->prev->content);
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
	_xnode->prev = _xnode;
	_xnode->next = _xnode;
	_size = 0;
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


	template <typename T, class Alloc>
void ft::list<T, Alloc>::insert(iterator pos, size_type n, const value_type & val)
{
	struct ft::__true_type x;
	_insert(pos, n, val, x);	
}

	template <typename T, class Alloc>
		template <class InputIterator>
void ft::list<T, Alloc>::insert(iterator pos, InputIterator first, InputIterator last)
{

	typedef typename ft::__is_integer<InputIterator>::__type isInt;
	isInt x;
	_insert(pos, first, last, x);	
}

///private insert


	template <typename T, class Alloc>
void ft::list<T, Alloc>::_insert(iterator pos, size_type n, const value_type & val, struct ft::__true_type)
{
	while (n)
	{
		insert(pos, val);
		n--;
	}
}

	template <typename T, class Alloc>
		template <class InputIterator>
void ft::list<T, Alloc>::_insert(iterator pos, InputIterator first, InputIterator last, struct ft::__false_type)
{
	if (first == last)
		return;
	elem<T> * beg = NULL;
	elem<T> * tmp = NULL;
	elem<T> * c;
	while (first != last)
	{
		c = new elem<T>;
		if (!beg)
			beg  = c;
		c->content = *first;
		c->prev = tmp;
		if (tmp)
			tmp->next = c;
		tmp = c;
		first++;
	}
	ft::list<T, Alloc>::iterator it = begin();
	elem<T> * cur = _xnode;
	while (it != pos)
	{
		it++;
		cur = cur->next;
	}
	c->next = cur->next;
	beg->prev = cur;
	cur->next->prev = c;
	cur->next = beg;

}

//erase

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::erase(ft::list<T, Alloc>::iterator pos)
{
	
	ft::list<T, Alloc>::iterator it = begin();
	elem<T> * cur = _xnode->next;
	while (it != pos)
	{
		it++;
		cur = cur->next;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	it = iterator(cur->next);
	delete cur;
	_size--;
	return (it);
}

	template <typename T, class Alloc>
typename ft::list<T, Alloc>::iterator ft::list<T, Alloc>::erase(ft::list<T, Alloc>::iterator first, ft::list<T, Alloc>::iterator last)
{	
	ft::list<T, Alloc>::iterator it = begin();
	elem<T> * efirst = _xnode->next;
	while (it != first)
	{
		it++;
		efirst = efirst->next;
	}
	elem<T> * elast = efirst;
	while (it != last)
	{
		it++;
		elast = elast->next;
	}
	efirst->prev->next = elast;
	elast->prev = efirst->prev;
	it = iterator(efirst);
	elem<T> * tmp;
	while (efirst != elast)
	{
		tmp = efirst;
		efirst = efirst->next;
		delete tmp;
		_size--;
	}
	return (it);
}

//resize
	template <typename T, class Alloc>
void ft::list<T, Alloc>::resize(size_type n, value_type val)
{
	elem<T> * c = _xnode;
	int i = 0;
	while (c->next != _xnode)
	{
		i++;
		c = c->next;
	}
	if (i > n)
	{
		iterator it = begin();
		for(; n; n--)
			it++;
		erase(it, end());
	}
	if (i < n)
		insert(end() - 1, n - i, val);
}

//swap

	template <typename T, class Alloc>
void ft::list<T, Alloc>::swap(list & x)
{
	size_type *t = _size;
	elem<T> *tmp = _xnode;

	_size = x._size;
	_xnode = x._xnode;

	x._size = t;
	x._xnode = tmp;
}

//slice

	template <typename T, class Alloc>
void ft::list<T, Alloc>::splice(iterator pos, list & x)
{
	
	elem<T> * c = _xnode->next;
	iterator it = begin();
	int i = 0;
	while (it != pos)
	{
		i++;
		it++;
		c = c->next;
	}
	c->prev->next = x._xnode->next;
	c->prev = x._xnode->prev;
}

//assign 

	template <typename T, class Alloc>
		template <class InputIterator>
void ft::list<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	list<T> lst(first, last); 
	clear();
	insert(begin(), lst.begin(), lst.end());
}

	template <typename T, class Alloc>
void ft::list<T, Alloc>::assign(size_type n, const value_type & val)
{
	clear();
	insert(begin(), n, val);
}

//remove

	template <typename T, class Alloc>
void ft::list<T, Alloc>::remove(const value_type & val)
{
	elem<T> * c = _xnode;
	elem<T> * t = NULL;
	while (c != _xnode)
	{
		if (c->content == val)
		{
			c->prev->next = c->next;
			c->next->prev = c->prev;
			t = c;
		}
		c = c->next;
		if (t && t->content == val)
			delete (t);
	}
}

//remove_if

	template <typename T, class Alloc>
		template <class Predicate>
void ft::list<T, Alloc>::remove_if (Predicate pred)
{
	elem<T> * c = _xnode;
	elem<T> * t = NULL;
	while (c != _xnode)
	{
		if (pred(c->content))
		{
			c->prev->next = c->next;
			c->next->prev = c->prev;
			t = c;
		}
		c = c->next;
		if (t && pred(t->content))
			delete (t);
	}
}






















