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

				explicit	list();
				explicit	list(size_type n, const value_type& val = value_type());
				template <class InputIterator>
					list (InputIterator first, InputIterator last);
				list(const list& x);
				~list();

				list<value_type, Alloc>		&operator=(const list<T, Alloc> &c);

				iterator			begin();
				const_iterator			begin() const;
				iterator			end();
				const_iterator			end() const;
				reverse_iterator		rbegin();
				const_reverse_iterator		rbegin() const;
				reverse_iterator		rend();
				const_reverse_iterator		rend() const;

				bool				empty() const;
				size_type			size() const;
				size_type			max_size() const;

				void				resize(size_type n, value_type val = value_type());
				size_type			capacity() const;
				void				clear();
				void				reserve(size_type n);

				reference			operator[] (size_type n);
				const_reference			operator[] (size_type n) const;
				reference			at(size_type n);
				const_reference			at(size_type n) const;
				reference			front();
				const_reference			front() const;
				reference			back();
				const_reference			back() const;

					template <class InputIterator>
				void				assign(InputIterator first, InputIterator last);
				void				assign(size_type n, const_reference val);
				void				push_front (const value_type& val);
				void				push_back(const value_type& val);
				void				pop_front();
				void				pop_back();
				void				swap (list& x);

				iterator					erase(iterator position);
				iterator					erase(iterator first, iterator last);
				iterator					insert (iterator position, const_reference val);
				void						insert (iterator position, size_type n, const_reference val);
					template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last);

				void splice (iterator position, list& x);
				void splice (iterator position, list& x, iterator i);
				void splice (iterator position, list& x, iterator first, iterator last);
				void unique();
					template <class BinaryPredicate>
				  void unique (BinaryPredicate binary_pred);
				void merge (list& x);
				void remove(const value_type & val);
					template <class Predicate>
				void remove_if (Predicate pred);

			private:
				elem<T>		*_xnode;
				size_type	_size;
				template <class InputIterator>
					void _insert(ft::list<T, Alloc>::iterator position, InputIterator first, InputIterator last, struct ft::__false_type);
				void _insert(ft::list<T, Alloc>::iterator position, size_type n, const_reference value, struct ft::__true_type);
				template <class InputIterator>
					void _constructor(InputIterator first, InputIterator last, struct ft::__false_type);
				void _constructor(size_type n, const T & v, struct ft::__true_type);
		};

	template <typename T, class Alloc>
		bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <typename T, class Alloc>
		bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
	template <typename T, class Alloc>
		void swap(ft::list<T, Alloc> & x, ft::list<T, Alloc> & y);
}


#endif
