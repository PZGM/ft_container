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
ft::list<T, Alloc>::list(const list<T, Alloc> & src)
{
	_size = 0;
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

//push_front

	template <typename T, class Alloc>
void ft::list<T, Alloc>::push_front (const value_type& val)
{
	insert(begin(), val);	
}

//push_back

	template <typename T, class Alloc>
void ft::list<T, Alloc>::push_back(const value_type& val)
{
	insert(end(), val);	
}

//pop_front

	template <typename T, class Alloc>
void ft::list<T, Alloc>::pop_front ()
{
	erase(begin());	
}

//pop_back

	template <typename T, class Alloc>
void ft::list<T, Alloc>::pop_back()
{
	erase(end() - 1);	
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
	_update_size();
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
	size_type t = _size;
	elem<T> *tmp = _xnode;

	_size = x._size;
	_xnode = x._xnode;

	x._size = t;
	x._xnode = tmp;
}

//splice

	template <typename T, class Alloc>
void ft::list<T, Alloc>::splice(iterator pos, list & x)
{
	if (x.empty())
		return;
	elem<T> * c = _xnode->next;
	iterator it = begin();
	while (it != pos)
	{
		it++;
		c = c->next;
	}
	c->prev->next = x._xnode->next;
	c->prev = x._xnode->prev;
	x._xnode->next->prev = c;
	x._xnode->prev->next = c;
	x._xnode->prev = x._xnode;
	x._xnode->next = x._xnode;
	x._update_size();
	_update_size();
}

	template <typename T, class Alloc>
void ft::list<T, Alloc>::splice(iterator pos, list& x, iterator i)
{
	if (x.empty())
		return;
	elem<T> * c = _xnode->next;
	iterator it = begin();
	while (it != pos)
	{
		it++;
		c = c->next;
	}
	elem<T> * c2 = x._xnode->next;
	iterator it2 = x.begin();
	while (it2 != i)
	{
		it2++;
		c2 = c2->next;
	}
	c2->prev->next = c2->next;
	c2->next->prev = c2->prev;
	c2->prev = c->prev;
	c2->next = c;
	c->prev->next = c2;
	c->prev = c2;
	x._update_size();
	_update_size();
}


	template <typename T, class Alloc>
void ft::list<T, Alloc>::splice(iterator pos, list& x, iterator first, iterator last)
{
	elem<T> * epos = _xnode->next;
	iterator itpos= begin();
	while (itpos!= pos)
	{
		itpos++;
		epos = epos->next;
	}
	elem<T> * efirst = x._xnode->next;
	iterator itfirst = x.begin();
	while (itfirst != first)
	{
		itfirst++;
		efirst = efirst->next;
	}
	elem<T> * elast = x._xnode->next;
	iterator itlast = x.begin();
	while (itlast != last)
	{
		itlast++;
		elast = elast->next;
	}
	efirst->prev->next = elast;
	elast->next->prev = efirst->prev;
	efirst->prev = epos->prev;
	elast->prev->next = epos;
	epos->prev->next = efirst;
	epos->prev = elast;
	x._update_size();
	_update_size();
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
	elem<T> * c = _xnode->next;
	elem<T> * t = NULL;
	while (c != _xnode)
	{
		if (c->content == val)
		{
			c->prev->next = c->next;
			c->next->prev = c->prev;
			t = c;	
			c = c->next;
			_size--;
			delete (t);
		}
		else
			c = c->next;
	}
}

//remove_if

	template <typename T, class Alloc>
		template <class Predicate>
void ft::list<T, Alloc>::remove_if (Predicate pred)
{
	elem<T> * c = _xnode->next;
	elem<T> * t = NULL;
	while (c != _xnode)
	{
		if (pred(c->content))
		{
			c->prev->next = c->next;
			c->next->prev = c->prev;
			t = c;
			c = c->next;
			_size--;
			delete (t);
		}
		else
			c = c->next;
	}
}

//unique

	template <typename T, class Alloc>
void ft::list<T, Alloc>::unique()
{
	ft::list<T, Alloc>::iterator it = begin();
	while (it != end() && (it + 1) != end())
	{
		if (*it == *(it + 1))
		{
			erase(it);
			it = begin();
		}
		else
			it++;
	}
}

	template <typename T, class Alloc>
		template <class BinaryPredicate>
void ft::list<T, Alloc>::unique(BinaryPredicate binary_pred)
{

	ft::list<T, Alloc>::iterator it = begin();
	while (it != end() && (it + 1) != end())
	{
		if (binary_pred(*it, *(it + 1)))
		{
			erase(it + 1);
			it = begin();
		}
		else
			it++;
	}
}

//merge

	template <typename T, class Alloc>
void ft::list<T, Alloc>::merge (list & x)
{
	elem<T> * dst = _xnode->next;
	elem<T> * src = x._xnode->next;
	elem<T> * tmp;
	if (src == x._xnode)
		return;
	while (dst != _xnode)
	{
		while (src != x._xnode && src->content < dst->content)
		{
			tmp = src->next;
			src->prev = dst->prev;
			dst->prev->next = src;
			dst->prev = src;
			src->next = dst;
			src = tmp;
		}
		dst = dst->next;
	}
	while(src != x._xnode)
	{
		tmp = src->next;
		src->prev = dst->prev;
		dst->prev->next = src;
		dst->prev = src;
		src->next = dst;
		src = tmp;
	}
	x._xnode->next = x._xnode;
	x._xnode->prev = x._xnode;
}

//compare

	template <typename T, class Alloc>
		template <class Compare>
void ft::list<T, Alloc>::merge(list & x, Compare comp)
{
	elem<T> * dst = _xnode->next;
	elem<T> * src = x._xnode->next;
	elem<T> * tmp;
	if (src == x._xnode)
		return;
	while (dst != _xnode)
	{
		while (src != x._xnode && comp(src->content,dst->content))
		{
			tmp = src->next;
			src->prev = dst->prev;
			dst->prev->next = src;
			dst->prev = src;
			src->next = dst;
			src = tmp;
		}
		dst = dst->next;
	}
	while(src != x._xnode)
	{
		tmp = src->next;
		src->prev = dst->prev;
		dst->prev->next = src;
		dst->prev = src;
		src->next = dst;
		src = tmp;
	}
	x._xnode->next = x._xnode;
	x._xnode->prev = x._xnode;
}

//sort

	template <typename T, class Alloc>
void ft::list<T, Alloc>::sort()
{
	elem<T> * c = _xnode->next;
	elem<T> * d = _xnode->next->next;
	elem<T> * next;
	elem<T> * prev;
	elem<T> * tmp;
	while (d != _xnode)
	{
		c = _xnode->next;
		while (c != d)
		{
			if (d->content < c->content)
			{
				if (c->next == d)
				{
					prev = c->prev;
					next = d->next;

					prev->next = d;
					next->prev = c;

					d->next = c;
					c->prev = d;

					d->prev = prev;
					c->next = next;

					c = _xnode;
					d = _xnode->next;

				}
				else
				{
					prev = c->prev;
					next = d->next;

					prev->next = d;
					next->prev = c;

					c->next->prev = d;
					d->prev->next = c;

					d->next = c->next;
					c->prev = d->prev;

					d->prev = prev;
					c->next = next;

					c = _xnode;
					d = _xnode->next;
				}
			}
			c = c->next;
		}
		d = d->next;
	}
}

	template <typename T, class Alloc>
		template <class Compare>
void ft::list<T, Alloc>::sort(Compare compare)
{
	elem<T> * c = _xnode->next;
	elem<T> * d = _xnode->next->next;
	elem<T> * next;
	elem<T> * prev;
	elem<T> * tmp;
	while (d != _xnode)
	{
		c = _xnode->next;
		while (c != d)
		{
			if (compare(d->content, c->content))
			{
				if (c->next == d)
				{
					prev = c->prev;
					next = d->next;

					prev->next = d;
					next->prev = c;

					d->next = c;
					c->prev = d;

					d->prev = prev;
					c->next = next;

					c = _xnode;
					d = _xnode->next;

				}
				else
				{
					prev = c->prev;
					next = d->next;

					prev->next = d;
					next->prev = c;

					c->next->prev = d;
					d->prev->next = c;

					d->next = c->next;
					c->prev = d->prev;

					d->prev = prev;
					c->next = next;

					c = _xnode;
					d = _xnode->next;
				}
			}
			c = c->next;
		}
		d = d->next;
	}
}


	template <typename T, class Alloc>
void ft::list<T, Alloc>::reverse()
{
	elem<T> * cur = _xnode;
	elem<T> * nex = cur->next;
	elem<T> * tmp;
	do
	{
		nex = cur->next;
		tmp = cur->prev;
		cur->prev = cur->next;
		cur->next = tmp;
		cur = nex;
	}
	while (cur != _xnode);
}

//private tool

	template <typename T, class Alloc>
void ft::list<T, Alloc>::_update_size()
{
	size_type i = 0;
	elem<T> * c = _xnode;
	while (c->next != _xnode)
	{
		i++;
		c = c->next;
	}
	_size = i;
}

//relaional operators

	template <typename T, class Alloc>
bool ft::operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	typename ft::list<T, Alloc>::iterator a = lhs.begin();
	typename ft::list<T, Alloc>::iterator b = rhs.begin();
	if (lhs.size() != rhs.size())
		return (false);
	while (a != lhs.end() && b != rhs.end())
	{
		if (*a != *b)
			return (false);
		a++;
		b++;
	}
	return (true);
}


	template <typename T, class Alloc>
bool ft::operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	typename ft::list<T, Alloc>::iterator a = lhs.begin();
	typename ft::list<T, Alloc>::iterator b = rhs.begin();
	if (lhs.size() != rhs.size())
		return (true);
	while (a != lhs.end() && b != rhs.end())
	{
		if (*a != *b)
			return (true);
		a++;
		b++;
	}
	return (false);
}

	template <typename T, class Alloc>
bool ft::operator> (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	typename ft::list<T, Alloc>::iterator a = lhs.begin();
	typename ft::list<T, Alloc>::iterator b = rhs.begin();
	while (a != lhs.end() && b != rhs.end())
	{
		if (*a > *b)
			return (true);
		if (*a < *b)
			return (false);
		a++;
		b++;
	}
	if (lhs.size() > rhs.size())
		return (true);
	return (false);
}

	template <typename T, class Alloc>
bool ft::operator< (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	typename ft::list<T, Alloc>::iterator a = lhs.begin();
	typename ft::list<T, Alloc>::iterator b = rhs.begin();
	while (a != lhs.end() && b != rhs.end())
	{
		if (*a < *b)
			return (true);
		if (*a > *b)
			return (false);
		a++;
		b++;
	}
	if (lhs.size() < rhs.size())
		return (true);
	return (false);
}

	template <typename T, class Alloc>
bool ft::operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	typename ft::list<T, Alloc>::iterator a = lhs.begin();
	typename ft::list<T, Alloc>::iterator b = rhs.begin();
	while (a != lhs.end() && b != rhs.end())
	{
		if (*a > *b)
			return (true);
		if (*a < *b)
			return (false);
		a++;
		b++;
	}
	if (lhs.size() >= rhs.size())
		return (true);
	return (false);
}

	template <typename T, class Alloc>
bool ft::operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
	typename ft::list<T, Alloc>::iterator a = lhs.begin();
	typename ft::list<T, Alloc>::iterator b = rhs.begin();
	while (a != lhs.end() && b != rhs.end())
	{
		if (*a < *b)
			return (true);
		if (*a > *b)
			return (false);
		a++;
		b++;
	}
	if (lhs.size() <= rhs.size())
		return (true);
	return (false);
}

//non member swap

template <class T, class Alloc>
void ft::swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y) {
	x.swap(y);
}

