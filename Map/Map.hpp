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
					_node_alloc = Node_allocator_type();
					_storage = _node_alloc.allocate(1);
					_node_alloc.construct(_storage);
				}

				//range constructor

				template <class InputIterator>
					map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
						_node_alloc = Node_allocator_type();
						_storage = _node_alloc.allocate(1);
						_node_alloc.construct(_storage);
						while(first != last) {
							_storage->add((*first).first, (*first).second);
							first++;
						}
					}

				// copy constructor
				map(const map& src) {
					_node_alloc = Node_allocator_type();
					map<char, int>::iterator it = src.begin();
					_storage = _node_alloc.allocate(1);
					_node_alloc.construct(_storage);
					while(it != src.end()) {
						_storage->add((*it).first, (*it).second);
						it++;
					}
				}


				//destructor 
				~map() {
					_node_alloc.destroy(_storage);
					_node_alloc.deallocate(_storage, 1);
				}

				//operator=
				map		&operator=(const map &x) {
					_node_alloc.destroy(_storage);
					_node_alloc.deallocate(_storage, 1);
					_storage = _node_alloc.allocate(1);
					_node_alloc.construct(_storage);
					map::iterator it = x.begin();
					while (it != x.end()) {
						_storage->add((*it).first, (*it).second);
						it++;
					}
					return (*this);
				}


				//begin
				iterator			begin() {
					return (iterator(_storage->get_begin()));
				}

				const_iterator		begin() const {
					return (iterator(_storage->get_begin()));
				}

				//end
				iterator			end() {
					return (iterator(_storage->get_end()));
				}

				const_iterator		end() const {
					return (iterator(_storage->get_end()));
				}
				//rbegin
				reverse_iterator		rbegin() {
					return (reverse_iterator(_storage->get_rbegin()));
				}

				const_reverse_iterator	rbegin() const {
					return (reverse_iterator(_storage->get_rbegin()));
				}
				//rend
				reverse_iterator		rend() {
					return (reverse_iterator(_storage->get_rend()));
				}

				const_reverse_iterator	rend() const {
					return (reverse_iterator(_storage->get_rend()));
				}

				//empty
				bool				empty() const {
					return (!_storage->size);
				}
				//size
				size_type			size() const {
					return (_storage->size);
				}
				//max_size
				size_type			max_size() const {
					return (allocator_type().max_size()/5);
				}

				//operator[]
				mapped_type & operator[] (const key_type& k) {
					if (count(k) == 0)
						_storage->add(k, T());
					Node<ft::pair<Key, T> > *node = _storage->find(k);
					return node->data.second;
				}

				//insert
				iterator insert(iterator position, const value_type& val){
					_storage->add(val.first, val.second, get_node(position));
					return insert(val).first;		
				}


				ft::pair<iterator,bool>			insert(const value_type& val) {
					Node<ft::pair<Key, T> > * nd = _storage->find(val.first);
					if (nd != NULL) {
						pair<iterator,bool> pr = ft::make_pair(iterator(nd), false);
						return pr;
					}
					nd = _storage->add(val.first, val.second);
					iterator it = iterator(nd);
					ft::pair<iterator,bool> pr = ft::make_pair(it, true);
					return pr;
				}

				template <class InputIterator>
					void insert (InputIterator first, InputIterator last) {
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
					Node<ft::pair<Key, T> > * node = _storage->find(k);
					if (!node)
						return 0;
					_storage->remove(node);
					return 1;
				}


				void					erase(iterator first, iterator last) {
					while (first != last) {
						Node<ft::pair<Key, T> > * node = get_node(first);
						first++;
						_storage->remove(node);
					}
				}

				//swap
				void				swap (map& x) {
					AVL<Key, T, Compare, Alloc> * tmp = _storage;

					_storage = x._storage;

					x._storage = tmp;
				}

				//clear
				void				clear() {
					map::iterator it = begin();
					while (it != end()) {
						Node<ft::pair<Key, T> > *node = get_node(it);
						it++;
						_storage->remove(node);
					}
				}

				//find
				iterator find (const key_type& k) {
					Node<ft::pair<Key, T> > *node = _storage->find(k);
					if (node == NULL)
						return end();
					return iterator(node);
				}

				const_iterator find (const key_type& k) const {
					Node<ft::pair<Key, T> > *node = _storage->find(k);
					if (node == NULL)
						return end();
					return const_iterator(node);
				}


				//count
				size_type count (const key_type& k) const {
					Node<ft::pair<Key, T> > *node = _storage->find(k);
					if (node == NULL)
						return 0;
					return 1;
				}


				// lower_bound
				iterator upper_bound(const key_type& k) {
					map::iterator upper = this->begin();
					map::iterator end = this->end();
					while (upper != end && key_compare()(k, (*upper).first))
						upper++;
					upper++;
					return (upper);
				}

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


				//upper_bound
				iterator lower_bound (const key_type& k) {
					iterator lower = this->begin();
					iterator end = this->end();
					while (lower != end && !key_compare()((*lower).first, k))
						lower++;
					lower--;
					return (lower);
				}


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
				typedef typename Alloc::template rebind<AVL<Key, T, Compare, Alloc> >::other Node_allocator_type;

				AVL<Key, T, Compare, Alloc> * _storage;
				Node_allocator_type	_node_alloc;

				Node<ft::pair<Key, T> > * get_node(iterator it) {
					return (_storage->find((*it).first));
				}

		};

	template <typename Key,typename T, class Alloc>
		void swap(ft::map<Key,T, Alloc> & x, ft::map<Key,T, Alloc> & y) {
			x.swap(y);
		}




};
#endif
