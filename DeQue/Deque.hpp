#ifndef DEQUE_HPP
# define DEQUE_HPP

#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include "DequeIterator.hpp"
#include <memory>
namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
		class deque
		{
			public:
				typedef T											value_type;
				typedef value_type&									reference;
				typedef const value_type&							const_reference;
				typedef value_type*									pointer;
				typedef DequeIterator<value_type>					iterator;
				typedef typename Alloc::size_type					size_type;
				typedef const DequeIterator<value_type>				const_iterator;
				typedef DequeReverseIterator<value_type>			reverse_iterator;
				typedef const DequeReverseIterator<value_type>		const_reverse_iterator;
				typedef std::ptrdiff_t								difference_type;
			
				explicit	deque();
				explicit	deque(size_type n, const value_type& val = value_type());
				deque(const deque& x);
				~deque();

				deque<value_type, Alloc>		&operator=(const deque<T, Alloc> &c);

				iterator					begin();
				const_iterator				begin() const;
				iterator					end();
				const_iterator				end() const;
				reverse_iterator			rbegin();
				const_reverse_iterator		rbegin() const;
				reverse_iterator			rend();
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
				void				swap (deque& x);

				iterator					erase(iterator position);
				iterator					erase(iterator first, iterator last);
				iterator					insert (iterator position, const_reference val);
				void						insert (iterator position, size_type n, const_reference val);
				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last);


			private:
				ft::vector<<ft::vector <T, Alloc>, Alloc>	_storage;
				size_type					_size_last = _storage[_storage.size]._size();
				size_type					_size_first = _storage[0]._size();


				template <class InputIterator>
					void _insert(ft::deque<T, Alloc>::iterator position, InputIterator first, InputIterator last);
				template <class InputIterator>
					void _insert1(ft::deque<T, Alloc>::iterator position, InputIterator first, InputIterator last);
				void _insert1(ft::deque<T, Alloc>::iterator position, int n, const_reference value);
		};

					template <typename T, class Alloc = std::allocator<T> >
				bool operator== (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs);
					template <typename T, class Alloc = std::allocator<T> >
				bool operator!= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs);
					template <typename T, class Alloc = std::allocator<T> >
				bool operator>  (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs);
					template <typename T, class Alloc = std::allocator<T> >
				bool operator<  (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs);
					template <typename T, class Alloc = std::allocator<T> >
				bool operator>= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs);
					template <typename T, class Alloc = std::allocator<T> >
				bool operator<= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs);
					template <typename T, class Alloc = std::allocator<T> >
				void swap(ft::deque<T, Alloc> & x, ft::deque<T, Alloc> & y);

}


#endif
