#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include "VectorIterator.hpp"
#include <memory>
namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
		class vector
		{
			public:
				typedef T											value_type;
				typedef value_type&									reference;
				typedef const value_type&							const_reference;
				typedef value_type*									pointer;
				typedef const value_type *							const_pointer;
				typedef VectorIterator<value_type>					iterator;
				typedef typename Alloc::size_type					size_type;
				typedef VectorIterator<value_type>					const_iterator;
				typedef VectorReverseIterator<iterator>				reverse_iterator;
				typedef VectorReverseIterator<const_iterator>		const_reverse_iterator;
				typedef std::ptrdiff_t								difference_type;

				explicit	vector();
				explicit	vector(size_type n, const value_type& val = value_type());
				vector(const vector& x);
				~vector();

				vector<value_type, Alloc>		&operator=(const vector<T, Alloc> &c);

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
				void				swap (vector& x);

				iterator					erase(iterator position);
				iterator					erase(iterator first, iterator last);
				iterator					insert (iterator position, const_reference val);
				void						insert (iterator position, size_type n, const_reference val);
				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last);


			private:
				value_type*	_storage;
				size_type	_size;
				size_type	_capacity;


				template <class InputIterator>
					void _insert(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last);
				template <class InputIterator>
					void insert1(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last);
				void insert1(ft::vector<T, Alloc>::iterator position, int n, const_reference value);
		};

	//	template <class T, class Alloc>
	//bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

}

#endif
