#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include <functional>
#include <memory>
#include "../IsType.hpp"
#include "rbt.hpp"

namespace ft
{
	template <class T>
		struct less : std::binary_function <T,T,bool> {
			bool operator() (const T& x, const T& y) const {
				return x<y;
			}
		};	
	template <typename T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
		class map
		{
			public:
				typedef T						value_type;
				typedef T						key_type;
				typedef Compare					key_compare;
				typedef Compare					value_compare;
				typedef Alloc					allocator_type;
				typedef value_type&					reference;
				typedef const value_type&				const_reference;
				typedef value_type*					pointer;
				typedef const value_type*				const_pointer;
				typedef SetIterator<value_type>			iterator;
				typedef typename Alloc::size_type			size_type;
				typedef const SetIterator<value_type>			const_iterator;
				typedef SetReverseIterator<value_type>			reverse_iterator;
				typedef const SetReverseIterator<value_type>		const_reverse_iterator;
				typedef std::ptrdiff_t					difference_type;

				explicit	map(const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type());
				template <class InputIterator>
					map(InputIterator first, InputIterator last,  const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
				map(const map& x);
				~map();

				map<T, Compare, Alloc>		&operator=(const map<T,Compare, Alloc> &rhs);
				iterator					find(const value_type& val) const;	
				void						swap(map& x);
				size_type					size() const;
				size_type					max_size() const;
				size_type					count(const value_type & val) const;
				bool						empty() const;
				void						clear();

				iterator			begin();
				const_iterator			begin() const;
				iterator			end();
				const_iterator			end() const;
				reverse_iterator		rbegin();
				const_reverse_iterator		rbegin() const;
				reverse_iterator		rend();
				const_reverse_iterator		rend() const;
				
				// insert
				std::pair<iterator,bool> insert(const value_type& val);
				iterator insert(iterator position, const value_type& val);
				template <class InputIterator>
				void insert(InputIterator first, InputIterator last);

				// erase 
				 void erase(iterator position);	
				size_type erase(const value_type & val);
				void erase(iterator first, iterator last);

				key_compare						key_comp() const;
				value_compare					value_comp() const;
				std::pair<iterator,iterator>	equal_range(const value_type& val) const;

				iterator lower_bound(const value_type& val) const;
				iterator upper_bound(const value_type& val) const;

			private:
				Compare					_comp;
				rbt<T, Compare>			*_tree;

				void		_destroy_map(Node<T> *leaf);
				
				iterator		_to_end(Node<T> *);
				const_iterator	_const_to_end(Node<T> *) const;

				iterator		_to_begin(Node<T> *);
				const_iterator	_const_to_begin(Node<T> *) const;
			
				reverse_iterator		_to_rend(Node<T> *);
				const_reverse_iterator	_const_to_rend(Node<T> *) const;
				
				reverse_iterator		_to_rbegin(Node<T> *);
				const_reverse_iterator	_const_to_rbegin(Node<T> *) const;
	
		};

	template <typename T, class Compare, class Alloc>
		bool operator== (const map<T,Compare,Alloc>& lhs, const map<T,Compare,Alloc>& rhs);
	template <typename T, class Compare, class Alloc>
		bool operator!= (const map<T,Compare,Alloc>& lhs, const map<T,Compare,Alloc>& rhs);
	template <typename T, class Compare, class Alloc>
		bool operator>  (const map<T,Compare,Alloc>& lhs, const map<T,Compare,Alloc>& rhs);
	template <typename T, class Compare, class Alloc>
		bool operator<  (const map<T,Compare,Alloc>& lhs, const map<T,Compare,Alloc>& rhs);
	template <typename T, class Compare, class Alloc>
		bool operator>= (const map<T,Compare,Alloc>& lhs, const map<T,Compare,Alloc>& rhs);
	template <typename T, class Compare, class Alloc>
		bool operator<= (const map<T,Compare,Alloc>& lhs, const map<T,Compare,Alloc>& rhs);
}


#endif
