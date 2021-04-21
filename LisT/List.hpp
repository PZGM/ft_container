#ifndef LIST_HPP
# define LIST_HPP

#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include "../IsType.hpp"
//#include "ListIterator.hpp"
#include <memory>

namespace ft
{
	template<typename T>
	struct elem
	{
		elem(T val) : content(val) {};
		elem	*prev;
		elem	*next;
		T		content;
	};

	template <typename T, class Alloc = std::allocator<T> >
		class list
		{
			public:
				typedef T											value_type;
				typedef value_type&									reference;
				typedef const value_type&							const_reference;
				typedef value_type*									pointer;
				typedef const value_type*							const_pointer;
//				typedef VectorIterator<value_type>					iterator;
				typedef typename Alloc::size_type					size_type;
/*				typedef const VectorIterator<value_type>			const_iterator;
				typedef VectorReverseIterator<value_type>			reverse_iterator;
				typedef const VectorReverseIterator<value_type>		const_reverse_iterator;
*/				typedef std::ptrdiff_t								difference_type;

				explicit	list();
				explicit	list(size_type n, const value_type& val = value_type());
				template <class InputIterator>
         			list (InputIterator first, InputIterator last);
				list(const list& x);
				~list();

				list<value_type, Alloc>		&operator=(const list<T, Alloc> &c);

/*				iterator					begin();
				const_iterator				begin() const;
				iterator					end();
				const_iterator				end() const;
				reverse_iterator			rbegin();
				const_reverse_iterator		rbegin() const;
				reverse_iterator			rend();
				const_reverse_iterator		rend() const;
*/
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
				void				swap (list& x);

/*				iterator					erase(iterator position);
				iterator					erase(iterator first, iterator last);
				iterator					insert (iterator position, const_reference val);
				void						insert (iterator position, size_type n, const_reference val);
				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last);
*/

			private:
				elem<T>		*_first;
				elem<T>		*_last;
				size_type	_size;
/*				template <class InputIterator>
					void _insert(ft::list<T, Alloc>::iterator position, InputIterator first, InputIterator last);
				template <class InputIterator>
					void _insert1(ft::list<T, Alloc>::iterator position, InputIterator first, InputIterator last);
				void _insert1(ft::list<T, Alloc>::iterator position, int n, const_reference value);
				template <class InputIterator>
				void _constructor(InputIterator first, InputIterator last, struct ft::__false_type);
				void _constructor(int n, const T & v, struct ft::__true_type);
*/		};

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
