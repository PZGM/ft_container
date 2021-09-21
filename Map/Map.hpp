#ifndef MAP_HPP
# define MAP_HPP

#include "AVL.hpp"
#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include "../IsType.hpp"
#include "MapIterator.hpp"
#include <memory>

namespace ft
{
	template <class Key>
		struct less : std::binary_function <Key,Key,bool> {
			bool operator() (const Key & x, const Key & y) const {
				if (x > y)
					return true;
				return false;
			}
		};

	template <typename Key, typename T, class Compare = less<Key>, class Alloc = std::allocator<std::pair<Key, T> > >
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

				explicit	map(const key_compare & comp = key_compare()) {
					_storage = new AVL<Key, T>();
				}

				//range constructor

				template <class InputIterator>
					map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){	
					}
				//  copy constructoor
				// map(const map& src) {
				// }


				//destructor 
				~map() {
					delete _storage;
				}

				// //operator=
				// map<value_type, Alloc>		&operator=(const map<Key,T, Alloc> &x) {
				// 	clear();
				// 	delete (_xnode);
				// 	_xnode = new struct_type;
				// 	_xnode->next = _xnode;
				// 	_xnode->prev = _xnode;
				// 	insert(begin(), x.begin(), x.end());
				// 	return (*this);
				// }


				// //begin
				iterator			begin() {
					return (iterator(_storage));
				}

				const_iterator		begin() const {
					return (iterator(_storage));
				}
				// //end
				// iterator			end() {
				// 	return (iterator(_xnode));
				// }

				// const_iterator		end() const {
				// 	return (iterator(_xnode));
				// }
				// //rbegin
				// reverse_iterator		rbegin() {
				// 	return (reverse_iterator(_xnode->prev));
				// }

				// const_reverse_iterator	rbegin() const {
				// 	return (reverse_iterator(_xnode->prev));
				// }
				// //rend
				// reverse_iterator		rend() {
				// 	return (reverse_iterator(_xnode));
				// }

				// const_reverse_iterator	rend() const {
				// 	return (reverse_iterator(_xnode));
				// }
				// //empty
				// bool				empty() const {
				// 	return (!_size);
				// }
				// //size
				// size_type			size() const {
				// 	return (_size);
				// }
				// //max_size
				// size_type			max_size() const {
				// 	return (allocator_type().max_size()/5);
				// }
				// //operator[]
				// mapped_type & operator[] (const key_type& k) {
				// 	if (count(k) == 0) {
				// 		const pair<const Key, T> x(k, T());
				// 		insert(x);
				// 	}
				// 	struct_type * cur;
				// 	cur = _xnode->next;
				// 	while (cur != _xnode) { 
				// 		if (cur->key == k)
				// 			return cur->val;
				// 		cur = cur->next;
				// 	}
				// 	return cur->val;
				// }

				//insert
				iterator insert(iterator position, const value_type& val){
					_storage->add(val.first, val.second, get_node(position));
					return insert(val).first;		
				}


				pair<iterator,bool>			insert(const value_type& val) {
					Node<ft::pair<Key, T> > * nd = _storage->find(val.first);
					if (nd != NULL) {
						pair<iterator,bool> pr(nd, false);
						return pr;
					}
					nd = _storage->add(val.first, val.second);
					iterator it = iterator(nd);
					pair<iterator,bool> pr(it, true);
					return pr;
				}

				template <class InputIterator>
					void insert (InputIterator first, InputIterator last) {
						pair<Key, T> tmp;
						while (first != last)
						{
							value_type val = value_type((*first).first, (*first).second);
							insert(val);
							first++;
						}
					}

				void					print() {
					if (_storage)
						_storage->print();
				}

				//erase
				void					erase(iterator position) {
					_storage->remove(get_node(position));
				}


				size_type erase(const key_type& k) {
					Node<ft::pair<Key, T> > node = _storage->find(k);
					if (!node)
						return 0;
					_storage->remove(node);
					return 1;
				}


				void					erase(iterator first, iterator last) {
					while (first != last) {
						erase (first);
						first++;
					}
				}

				//swap
				void				swap (map& x) {
					AVL<Key, T> * tmp = _storage;

					_storage = x._storage;

					x._storage = tmp;
				}

				//clear
				void				clear() {
					delete _storage;
					_storage = NULL;
				}

				//find
				// iterator find (const key_type& k) {
				// 	if (!_storage)
				// 	Node<ft::pair<Key, Value> > *node = _storage->find()
				// 	return it;
				// }

				// const_iterator find (const key_type& k) const {
				// 	iterator it = begin();
				// 	while (it != end() && (*it).first != k)
				// 		it++;
				// 	const_iterator ite = it;
				// 	return ite;
				// }


				// //count
				// size_type count (const key_type& k) const {
				// 	struct_type * cur = _xnode->next;
				// 	while (cur != _xnode)
				// 	{
				// 		if (cur->key == k)
				// 			return 1;
				// 		cur = cur->next;
				// 	}
				// 	return 0;
				// }


				// // lower_bound
				// iterator lower_bound (const key_type& k) {
				// 	return _storage->find(k);
				// }

				// const_iterator lower_bound (const key_type& k) const {
				// 	struct_type *cur = _xnode->next;
				// 	if (_size == 0)
				// 		return iterator(_xnode);
				// 	if (!Compare()(cur->key, k)) {
				// 	while (!Compare()(cur->next->key, k))
				// 		cur = cur->next;
				// 	}
				// 	const_iterator curr = iterator(cur);
				// 	return cur;
				// }


				// //upper_bound
				// iterator upper_bound(const key_type& k) {
				// 	struct_type *cur = _xnode->next;
				// 	if (_size == 0)
				// 		return iterator(_xnode);
				// 	while (!Compare()(cur->key, k))
				// 		cur = cur->next;
				// 	return iterator(cur);
				// }
				// const_iterator upper_bound (const key_type& k) const {
				// 	struct_type *cur = _xnode->next;
				// 	if (_size == 0)
				// 		return iterator(_xnode);
				// 	while (!Compare()(cur->key, k))
				// 		cur = cur->next;
				// 	const_iterator curr = iterator(cur);
				// 	return cur;
				// }


				// //equal range
				
				// pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				// 	pair<const_iterator, const_iterator> pair(lower_bound(k), upper_bound(k));
				// 	return pair;
				// }

				// pair<iterator,iterator>             equal_range (const key_type& k) {
				// 	pair<iterator, iterator> pair(lower_bound(k), upper_bound(k));
				// 	return pair;
				// }

			private:

				AVL<Key, T> * _storage;

				Node<ft::pair<Key, T> > * get_node(iterator it) {
					return (_storage->find((*it).first));
				}

	// 			template <class InputIterator>
	// 				void _constructor(InputIterator first, InputIterator last, struct ft::__false_type) {
	// 					_xnode = new struct_type();	
	// 					struct_type *cur = _xnode;
	// 					struct_type *tmp = _xnode;
	// 					int i = 0;

	// 					while (first != last)
	// 					{
	// 						cur = new struct_type(*first);
	// 						if (!tmp)
	// 							_xnode->next = cur;
	// 						else
	// 							tmp->next = cur;
	// 						cur->prev = tmp;
	// 						tmp = cur;
	// 						first++;;
	// 						i++;
	// 					}
	// 					cur->next = _xnode;
	// 					_xnode->prev = cur;
	// 					_size = i;
	// 				}

	// 			void _constructor(size_type n, const T & val, struct ft::__true_type) {
	// 				struct_type *cur;
	// 				_xnode = new struct_type;	
	// 				struct_type *tmp = _xnode;
	// 				cur = _xnode;

	// 				for (int i = 0; i < n; i++)
	// 				{
	// 					cur = new struct_type(val);
	// 					if (!tmp)
	// 						_xnode->next = cur;
	// 					else
	// 						tmp->next = cur;
	// 					cur->prev = tmp;
	// 					tmp = cur;
	// 				}
	// 				cur->next = _xnode;
	// 				_xnode->prev  = cur;
	// 				_size = n;
	// 			}

	// 			void _update_size() {
	// 				size_type i = 0;
	// 				struct_type * c = _xnode;
	// 				while (c->next != _xnode)
	// 				{
	// 					i++;
	// 					c = c->next;
	// 				}
	// 				_size = i;					
	// 			}


		};

	// template <typename Key,typename T, class Alloc>
	// 	void swap(ft::map<Key,T, Alloc> & x, ft::map<Key,T, Alloc> & y) {
	// 		x.swap(y);
	// 	}




};
#endif
