#ifndef SET_HPP
# define SET_HPP

#include <iostream>
#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include <memory>
#include "SetIterator.hpp"
#include "../IsType.hpp"
#include "../rbt/rbt.cpp"

namespace ft
{
	template <class T>
		struct less : std::binary_function <T,T,bool> {
			bool operator() (const T& x, const T& y) const {
				return x<y;
			}
		};	
	template <typename T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
		class set
		{
			public:
				typedef T						value_type;
				typedef T						key_type;
				typedef Compare					key_compare;
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

				explicit	set(const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type());
				template <class InputIterator>
					set(InputIterator first, InputIterator last,  const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
				set(const set& x);
				~set();

				set<value_type, Alloc>		&operator=(const set<T, Alloc> &c);
				iterator find (const value_type& val) const;	
				void				swap (set& x);

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
					

			private: //compare a implementer
				size_type	_size;
				rbt			_tree;

				void		_destroy_set(Node<T> *leaf);
				iterator		_to_begin(Node<T> *);
				const_iterator	_to_begin(Node<T> *) const;

				iterator		_to_end(Node<T> *);
				const_iterator	_to_end(Node<T> *) const;
				iterator		_insert(const value_type& val, Node<T> *);
		};

	template <typename T, class Alloc>
		bool operator== (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator!= (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator>  (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator<  (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator>= (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator<= (const set<T,Alloc>& lhs, const set<T,Alloc>& rhs);
	template <typename T, class Alloc>
		void swap(ft::set<T, Alloc> & x, ft::set<T, Alloc> & y);
}


#endif
