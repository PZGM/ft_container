#ifndef SET_HPP
# define SET_HPP

#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include <memory>
#include "../IsType.hpp"

namespace ft
{
	template<typename T>
		bool less(T x, T y) { return ((x < y) ? true : false); }

	template <typename T, class Compare = less<T>, class Alloc = std::allocator<T> >
		class set
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

				explicit	set();
				explicit	set(size_type n, const value_type& val = value_type());
				template <class InputIterator>
					set (InputIterator first, InputIterator last);
				set(const set& x);
				~set();

				set<value_type, Alloc>		&operator=(const set<T, Alloc> &c);

				iterator			begin();
				const_iterator			begin() const;
				iterator			end();
				const_iterator			end() const;
				reverse_iterator		rbegin();
				const_reverse_iterator		rbegin() const;
				reverse_iterator		rend();
				const_reverse_iterator		rend() const;

				void				clear();
				size_type			size() const;
				size_type			max_size() const;
				void				resize(size_type n, value_type val = value_type());
				size_type			capacity() const;
				bool				empty() const;
				void				reserve(size_type n);

				reference			operator[] (size_type n);
				const_reference		operator[] (size_type n) const;
				reference			at(size_type n);
				const_reference		at(size_type n) const;
				reference			front();
				const_reference		front() const;
				reference			back();
				const_reference		back() const;

				template <class InputIterator>
					void				assign(InputIterator first, InputIterator last);
				void				assign(size_type n, const_reference val);
				void				push_back(const value_type& val);
				void				pop_back();
				void				swap (set& x);

				/*
				   iterator					erase(iterator position);
				   iterator					erase(iterator first, iterator last);
				   iterator					insert (iterator position, const_reference val);
				   void						insert (iterator position, size_type n, const_reference val);
				   template <class InputIterator>
				   void insert (iterator position, InputIterator first, InputIterator last);
				   */

			private:
				elem<T>		*_xnode;
				size_type	_size;
				/*
				   template <class InputIterator>
				   void _insert(ft::set<T, Alloc>::iterator position, InputIterator first, InputIterator last);
				   template <class InputIterator>
				   void _insert1(ft::set<T, Alloc>::iterator position, InputIterator first, InputIterator last);
				   void _insert1(ft::set<T, Alloc>::iterator position, int n, const_reference value);
				   */				template <class InputIterator>
				void _constructor(InputIterator first, InputIterator last, struct ft::__false_type);
				void _constructor(size_type n, const T & v, struct ft::__true_type);
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
