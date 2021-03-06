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
				return (x < y);
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
				typedef const iterator							const_iterator;
				typedef MapReverseIterator<Key, T>				reverse_iterator;
				typedef const reverse_iterator					const_reverse_iterator;
				typedef std::ptrdiff_t							difference_type;
				typedef Alloc									allocator_type;

				//default constructor

				explicit	map(const key_compare & comp = key_compare()) {
					_tree_alloc = Tree_allocator_type();
					_storage = _tree_alloc.allocate(1);
					_tree_alloc.construct(_storage);
				}

				//range constructor

				template <class InputIterator>
					map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
						_tree_alloc = Tree_allocator_type();
						_storage = _tree_alloc.allocate(1);
						_tree_alloc.construct(_storage);
						while(first != last) {
							_storage->add((*first).first, (*first).second);
							first++;
						}
					}

				// copy constructor
				map(const map& src) {
					_tree_alloc = Tree_allocator_type();
					iterator it = src.begin();
					_storage = _tree_alloc.allocate(1);
					_tree_alloc.construct(_storage);
					while(it != src.end()) {
						_storage->add((*it).first, (*it).second);
						it++;
					}
				}

				//destructor 
				~map() {
					_tree_alloc.destroy(_storage);
					_tree_alloc.deallocate(_storage, 1);
				}

				//operator=
				map		&operator=(const map &x) {
					_tree_alloc.destroy(_storage);
					_tree_alloc.deallocate(_storage, 1);
					_storage = _tree_alloc.allocate(1);
					_tree_alloc.construct(_storage);
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
					return (const_iterator(_storage->get_begin()));
				}

				//end
				iterator			end() {
					return (iterator(_storage->get_end()));
				}

				const_iterator		end() const {
					return (const_iterator(_storage->get_end()));
				}
				//rbegin
				reverse_iterator		rbegin() {
					return (reverse_iterator(_storage->get_rbegin()));
				}

				const_reverse_iterator	rbegin() const {
					return (const_reverse_iterator(_storage->get_rbegin()));
				}
				//rend
				reverse_iterator		rend() {
					return (reverse_iterator(_storage->get_rend()));
				}

				const_reverse_iterator	rend() const {
					return (const_reverse_iterator(_storage->get_rend()));
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

				key_compare key_comp() const{
					return Compare();
				}

				class value_compare
				{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
					friend class map;
					protected:
						Compare comp;
						value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
					public:
						typedef bool result_type;
						typedef value_type first_argument_type;
						typedef value_type second_argument_type;
						bool operator() (const value_type& x, const value_type& y) const
						{
							return comp(x.first, y.first);
						}
				};

				value_compare value_comp() const{
					return (value_compare(Compare()));
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
				iterator lower_bound (const key_type& k) {
					if (count(k))
						return find(k);
					map::iterator it = begin();
					while (it != end() && !key_compare()(k, (*it).first))
						it++;
					return (it);
				}
								//upper_bound
				iterator upper_bound(const key_type& k) {
					map::iterator it = begin();
					while (it != end() && !key_compare()(k, (*it).first))
						it++;
					return (it);
				}

				// lower_bound
				const_iterator lower_bound (const key_type& k) const {
					if (count(k))
						return find(k);
					map::const_iterator it = begin();
					while (it != end() && !key_compare()(k, (*it).first))
						it++;
					return (it);
				}
				//upper_bound
				const_iterator upper_bound(const key_type& k) const {
					map::const_iterator it = begin();
					while (it != end() && !key_compare()(k, (*it).first))
						it++;
					return (it);
				}


				//equal range
				
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
					pair<const_iterator, const_iterator> pair(lower_bound(k), upper_bound(k));
					return pair;
				}

				pair<iterator,iterator>             equal_range (const key_type& k) {
					pair<iterator, iterator> pair(lower_bound(k), upper_bound(k));
					return pair;
				}

			private:
				typedef typename Alloc::template rebind<AVL<Key, T, Compare, Alloc> >::other Tree_allocator_type;

				AVL<Key, T, Compare, Alloc> * _storage;
				Tree_allocator_type	_tree_alloc;

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
