#ifndef LIST_HPP
# define LIST_HPP

#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include "../IsType.hpp"
#include "ListIterator.hpp"
#include <memory>

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
		class list
		{
			public:
				typedef T						value_type;
				typedef value_type&					reference;
				typedef const value_type&				const_reference;
				typedef value_type*					pointer;
				typedef const value_type*				const_pointer;
				typedef ListIterator<value_type>			iterator;
				typedef typename Alloc::size_type			size_type;
				typedef const ListIterator<value_type>			const_iterator;
				typedef ListReverseIterator<value_type>			reverse_iterator;
				typedef const ListReverseIterator<value_type>		const_reverse_iterator;
				typedef std::ptrdiff_t					difference_type;

				explicit	list() : _size(0) {
					_xnode = new elem<T>;
					_xnode->next = _xnode;
					_xnode->prev = _xnode;
				}

				explicit	list(size_type n, const value_type& val = value_type()) {
					struct __true_type x;
					_constructor(n, val, x);
				}

				template <class InputIterator>
					list (InputIterator first, InputIterator last) {
						typedef typename ft::__is_integer<InputIterator>::__type isInt;
						isInt x;
						_constructor(first, last, x);	
					}

				list(const list& src) {
					_size = 0;
					_xnode = new elem<T>;
					_xnode->next = _xnode;
					_xnode->prev = _xnode;
					insert(begin(), src.begin(), src.end());
				}

				~list() {
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

				list<value_type, Alloc>		&operator=(const list<T, Alloc> &x) {
					clear();
					delete (_xnode);
					_xnode = new elem<T>;
					_xnode->next = _xnode;
					_xnode->prev = _xnode;
					insert(begin(), x.begin(), x.end());
					return (*this);
				}

				iterator			begin() {
					return (ft::list<T, Alloc>::iterator(_xnode->next));
				}

				const_iterator		begin() const {
					return (ft::list<T, Alloc>::iterator(_xnode->next));
				}

				iterator			end() {
					return (ft::list<T, Alloc>::iterator(_xnode));
				}

				const_iterator		end() const {
					return (ft::list<T, Alloc>::iterator(_xnode));
				}

				reverse_iterator		rbegin() {
					return (ft::list<T, Alloc>::reverse_iterator(_xnode->prev));
				}

				const_reverse_iterator	rbegin() const {
					return (ft::list<T, Alloc>::reverse_iterator(_xnode->prev));
				}

				reverse_iterator		rend() {
					return (ft::list<T, Alloc>::reverse_iterator(_xnode));
				}

				const_reverse_iterator	rend() const {
					return (ft::list<T, Alloc>::reverse_iterator(_xnode));
				}

				bool				empty() const {
					return (!_size);
				}

				size_type			size() const {
					return (_size);
				}

				size_type			max_size() const {
					size_type max = 0;
					max--;
					max /= 48;
					return (max);
				}

				void				resize(size_type n, value_type val = value_type()) {
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

				void				clear() {
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

				reference			front() {
					return (_xnode->next->content);
				}

				const_reference		front() const {
					return (_xnode->next->content);
				}

				reference			back() {
					return (_xnode->prev->content);
				}

				const_reference		back() const {
					return (_xnode->prev->content);
				}

					template <class InputIterator>
				void				assign(InputIterator first, InputIterator last) {
					list<T> lst(first, last); 
					clear();
					insert(begin(), lst.begin(), lst.end());
				}

				void				assign(size_type n, const_reference val) {
					clear();
					insert(begin(), n, val);
				}

				void				push_front (const value_type& val) {
					insert(begin(), val);
				}

				void				push_back(const value_type& val) {
					insert(end(), val);	
				}

				void				pop_front() {
					erase(begin());	
				}

				void				pop_back() {
					erase(end() - 1);
				}

				void				swap (list& x) {
					size_type t = _size;
					elem<T> *tmp = _xnode;

					_size = x._size;
					_xnode = x._xnode;

					x._size = t;
					x._xnode = tmp;
				}

				iterator					erase(iterator pos) {
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

				iterator					erase(iterator first, iterator last) {
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

				iterator					insert (iterator pos, const_reference val) {
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

				void						insert (iterator pos, size_type n, const_reference val) {
					struct ft::__true_type x;
					_insert(pos, n, val, x);
				}

					template <class InputIterator>
				void insert (iterator pos, InputIterator first, InputIterator last) {
					typedef typename ft::__is_integer<InputIterator>::__type isInt;
					isInt x;
					_insert(pos, first, last, x);	
				}

				void splice (iterator pos, list& x) {
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

				void splice (iterator pos, list& x, iterator i) {
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

				void splice (iterator pos, list& x, iterator first, iterator last) {
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

				void unique() {
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
					template <class BinaryPredicate>
				void unique (BinaryPredicate binary_pred) {
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

				void merge (list& x) {
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

					template <class Compare>
				void merge (list& x, Compare comp) {
					elem<T> * dst = _xnode->next;
					elem<T> * src = x._xnode->next;
					elem<T> * tmp;
					if (src == x._xnode)
						return;
					while (dst != _xnode)
					{
						while (src != x._xnode && comp(src->content, dst->content))
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

				void remove(const value_type & val) {
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

					template <class Predicate>
				void remove_if (Predicate pred) {
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

				void sort() {
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

					template <class Compare>
				void sort(Compare compare) {
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

				void reverse() {
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

			private:
				elem<T>		*_xnode;
				size_type	_size;

				template <class InputIterator>
					void _insert(ft::list<T, Alloc>::iterator pos, InputIterator first, InputIterator last, struct ft::__false_type) {
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

				void _insert(ft::list<T, Alloc>::iterator pos, size_type n, const_reference val, struct ft::__true_type) {
						while (n)
						{
							insert(pos, val);
							n--;
						}
				}

				template <class InputIterator>
					void _constructor(InputIterator first, InputIterator last, struct ft::__false_type) {
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

				void _constructor(size_type n, const T & val, struct ft::__true_type) {
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

				void _update_size() {
					size_type i = 0;
					elem<T> * c = _xnode;
					while (c->next != _xnode)
					{
						i++;
						c = c->next;
					}
					_size = i;					
				}
		};

	template <typename T, class Alloc>
		bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
		bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
		bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
		bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
		bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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
		bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
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

	template <typename T, class Alloc>
		void swap(ft::list<T, Alloc> & x, ft::list<T, Alloc> & y) {
			x.swap(y);
		}
};


#endif
