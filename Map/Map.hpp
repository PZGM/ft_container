#ifndef MAP_HPP
# define MAP_HPP

#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include "../IsType.hpp"
#include "MapIterator.hpp"
#include <memory>

namespace ft
{
	template <class T, class Key>
		struct less : std::binary_function <Key,T,bool> {
			bool operator() (const T& x, const T& y) const {
				return x<y;
			}
		};

	template <typename Key, typename T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<Key, T> > >
		class map
		{
			public:
				typedef	Key										key_type;
				typedef T										mapped_type;
				typedef	pair<const key_type, mapped_type>		value_type;
				typedef	Compare									key_compare;
				typedef value_type&								reference;
				typedef const value_type&						const_reference;
				typedef value_type*								pointer;
				typedef const value_type*						const_pointer;
				typedef MapIterator<Key, T>						iterator;
				typedef typename Alloc::size_type				size_type;
				typedef const MapIterator<Key, T>				const_iterator;
				typedef MapReverseIterator<Key, T>				reverse_iterator;
				typedef const MapReverseIterator<Key, T>		const_reverse_iterator;
				typedef std::ptrdiff_t							difference_type;
				typedef Alloc									allocator_type;

				//default constructor

				explicit	map(const key_compare & comp = key_compare()) : _size(0) {
					_xnode = new elem<Key ,T>;
					_xnode->next = _xnode;
					_xnode->prev = _xnode;
				}

				//range constructor

				template <class InputIterator>
					map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {	
						_xnode = new elem<Key, T>();	
						elem<Key, T> *cur = _xnode;
						elem<Key, T> *tmp = _xnode;
						int i = 0;

						while (first != last)
						{
							cur = new elem<Key, T>(*(first).first, *(first).second);
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

				map(const map& src) {
					_size = 0;
					_xnode = new elem<Key, T>;
					_xnode->next = _xnode;
					_xnode->prev = _xnode;
					insert(begin(), src.begin(), src.end());
				}

				~map() {
					elem<Key, T> *cur = _xnode->next;
					elem<Key, T> *tmp;
					while (cur != _xnode)
					{
						tmp = cur;
						cur = cur->next;
						delete (tmp);
					}
					delete (_xnode);
				}

				map<value_type, Alloc>		&operator=(const map<Key,T, Alloc> &x) {
					clear();
					delete (_xnode);
					_xnode = new elem<Key, T>;
					_xnode->next = _xnode;
					_xnode->prev = _xnode;
					insert(begin(), x.begin(), x.end());
					return (*this);
				}

				iterator			begin() {
					return (ft::map<Key,T, Alloc>::iterator(_xnode->next));
				}

				const_iterator		begin() const {
					return (ft::map<Key,T, Alloc>::iterator(_xnode->next));
				}

				iterator			end() {
					return (ft::map<Key,T, Alloc>::iterator(_xnode));
				}

				const_iterator		end() const {
					return (ft::map<Key,T, Alloc>::iterator(_xnode));
				}

				reverse_iterator		rbegin() {
					return (ft::map<Key,T, Alloc>::reverse_iterator(_xnode->prev));
				}

				const_reverse_iterator	rbegin() const {
					return (ft::map<Key,T, Alloc>::reverse_iterator(_xnode->prev));
				}

				reverse_iterator		rend() {
					return (ft::map<Key,T, Alloc>::reverse_iterator(_xnode));
				}

				const_reverse_iterator	rend() const {
					return (ft::map<Key,T, Alloc>::reverse_iterator(_xnode));
				}

				bool				empty() const {
					return (!_size);
				}

				size_type			size() const {
					return (_size);
				}

				size_type			max_size() const {
					return allocator().max_size;
				}

				void				clear() {
					elem<Key, T> *cur = _xnode->next;
					elem<Key, T> *tmp;
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

				template <class InputIterator>
					void				assign(InputIterator first, InputIterator last) {
						map<Key, T> lst(first, last); 
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

				void				swap (map& x) {
					size_type t = _size;
					elem<Key, T> *tmp = _xnode;

					_size = x._size;
					_xnode = x._xnode;

					x._size = t;
					x._xnode = tmp;
				}

				iterator					erase(iterator pos) {
					ft::map<Key,T, Alloc>::iterator it = begin();
					elem<Key, T> * cur = _xnode->next;
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
					ft::map<Key,T, Alloc>::iterator it = begin();
					elem<Key, T> * efirst = _xnode->next;
					while (it != first)
					{
						it++;
						efirst = efirst->next;
					}
					elem<Key, T> * elast = efirst;
					while (it != last)
					{
						it++;
						elast = elast->next;
					}
					efirst->prev->next = elast;
					elast->prev = efirst->prev;
					it = iterator(efirst);
					elem<Key, T> * tmp;
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
					elem<Key, T> *cur = _xnode->next;
					iterator it = begin();
					while (it != pos)
					{
						it++;
						cur = cur->next;
					}
					if (cur->next = _xnode)
						cur = cur->next;
					while (Compare(val.first , cur->key)) {
						if (val.first == cur->next->key)
							return iterator(cur->next);
						if (!Compare(val.first, cur->next->key)) {
							elem newNode = new elem(val);
							cur->next->prec = newNode;
							newNode->next = cur->next;
							newNode->prec = cur;
							cur->next = newNode;
							return iterator(newNode);
						}
						cur = cur->next;
					}
				}


				pair<iterator,bool>			insert(const value_type& val) {
					elem<Key, T> *cur = _xnode->next;
					while (Compare(val.first , cur->key)) {
						if (val.first == cur->next->key)
							return cur->next;
						if (!Compare(val.first, cur->next->key)) {
							elem newNode = new elem(val);
							cur->next->prec = newNode;
							newNode->next = cur->next;
							newNode->prec = cur;
							cur->next = newNode;
							return newNode;
						}
						cur = cur->next;
					}
				}

				template <class InputIterator>
					void insert (InputIterator first, InputIterator last) {
						while (first != last && first != end())
						{
							insert(*first);
							first++;
						}
					}

				void splice (iterator pos, map& x) {
					if (x.empty())
						return;
					elem<Key, T> * c = _xnode->next;
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

				void splice (iterator pos, map& x, iterator i) {
					if (x.empty())
						return;
					elem<Key, T> * c = _xnode->next;
					iterator it = begin();
					while (it != pos)
					{
						it++;
						c = c->next;
					}
					elem<Key, T> * c2 = x._xnode->next;
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

				void splice (iterator pos, map& x, iterator first, iterator last) {
					elem<Key, T> * epos = _xnode->next;
					iterator itpos= begin();
					while (itpos!= pos)
					{
						itpos++;
						epos = epos->next;
					}
					elem<Key, T> * efirst = x._xnode->next;
					iterator itfirst = x.begin();
					while (itfirst != first)
					{
						itfirst++;
						efirst = efirst->next;
					}
					elem<Key, T> * elast = x._xnode->next;
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
					ft::map<Key,T, Alloc>::iterator it = begin();
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
						ft::map<Key,T, Alloc>::iterator it = begin();
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

				void merge (map& x) {
					elem<Key, T> * dst = _xnode->next;
					elem<Key, T> * src = x._xnode->next;
					elem<Key, T> * tmp;
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
					void merge (map& x, Compare comp) {
						elem<Key, T> * dst = _xnode->next;
						elem<Key, T> * src = x._xnode->next;
						elem<Key, T> * tmp;
						if (src == x._xnode)
							return;
						while (dst != _xnode)
						{
							while (src != x._xnode && comp(src->content, dst->content))
							{
								tmp = src->next;
								src->prev = dst->prev;
								c = c->next;
							}
						}
					}

				template <class Predicate>
					void remove_if (Predicate pred) {
						elem<Key, T> * c = _xnode->next;
						elem<Key, T> * t = NULL;
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
					elem<Key, T> * c = _xnode->next;
					elem<Key, T> * d = _xnode->next->next;
					elem<Key, T> * next;
					elem<Key, T> * prev;
					elem<Key, T> * tmp;
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
						elem<Key, T> * c = _xnode->next;
						elem<Key, T> * d = _xnode->next->next;
						elem<Key, T> * next;
						elem<Key, T> * prev;
						elem<Key, T> * tmp;
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
					elem<Key, T> * cur = _xnode;
					elem<Key, T> * nex = cur->next;
					elem<Key, T> * tmp;
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
				elem<Key, T>	*_xnode;
				size_type		_size;

				template <class InputIterator>
					void _constructor(InputIterator first, InputIterator last, struct ft::__false_type) {
						_xnode = new elem<Key, T>();	
						elem<Key, T> *cur = _xnode;
						elem<Key, T> *tmp = _xnode;
						int i = 0;

						while (first != last)
						{
							cur = new elem<Key, T>(*first);
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
					elem<Key, T> *cur;
					_xnode = new elem<Key, T>;	
					elem<Key, T> *tmp = _xnode;
					cur = _xnode;

					for (int i = 0; i < n; i++)
					{
						cur = new elem<Key, T>(val);
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
					elem<Key, T> * c = _xnode;
					while (c->next != _xnode)
					{
						i++;
						c = c->next;
					}
					_size = i;					
				}
		};

	template <typename Key,typename T, class Alloc>
		bool operator== (const map<Key,T,Alloc>& lhs, const map<Key,T,Alloc>& rhs) {
			typename ft::map<Key,T, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key,T, Alloc>::iterator b = rhs.begin();
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

	template <typename Key,typename T, class Alloc>
		bool operator!= (const map<Key,T,Alloc>& lhs, const map<Key,T,Alloc>& rhs) {
			typename ft::map<Key,T, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key,T, Alloc>::iterator b = rhs.begin();
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

	template <typename Key,typename T, class Alloc>
		bool operator>  (const map<Key,T,Alloc>& lhs, const map<Key,T,Alloc>& rhs) {
			typename ft::map<Key,T, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key,T, Alloc>::iterator b = rhs.begin();
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

	template <typename Key,typename T, class Alloc>
		bool operator<  (const map<Key,T,Alloc>& lhs, const map<Key,T,Alloc>& rhs) {
			typename ft::map<Key,T, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key,T, Alloc>::iterator b = rhs.begin();
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

	template <typename Key,typename T, class Alloc>
		bool operator>= (const map<Key,T,Alloc>& lhs, const map<Key,T,Alloc>& rhs) {
			typename ft::map<Key,T, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key,T, Alloc>::iterator b = rhs.begin();
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

	template <typename Key,typename T, class Alloc>
		bool operator<= (const map<Key,T,Alloc>& lhs, const map<Key,T,Alloc>& rhs) {
			typename ft::map<Key,T, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key,T, Alloc>::iterator b = rhs.begin();
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

	template <typename Key,typename T, class Alloc>
		void swap(ft::map<Key,T, Alloc> & x, ft::map<Key,T, Alloc> & y) {
			x.swap(y);
		}

	mapped_type& operator[] (const key_type& k) {
		while (_xnode != end) { 
			if (_xnode->key == k)
				return iterator(_xnode);
			_xnode = _xnode->next;
		}
		pair<Key, T> x(k, T());
		return (insert(x).first;
				}


				};
#endif
