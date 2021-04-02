#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <limits.h>
#include <stdexcept>
#include <iterator>
#include "VectorIterator.hpp"

typedef std::size_t				size_type;
namespace ft
{
		template <typename T> //template <class T, class Alloc = std::allocator<T> >
				class vector
				{
						public:
								typedef T											value_type;
								typedef value_type&									reference;
								typedef const value_type&							const_reference;
								typedef value_type*									pointer;
								typedef const value_type *							const_pointer;
								typedef VectorIterator<value_type>					iterator;
								typedef VectorIterator<value_type>					const_iterator;
								typedef VectorReverseIterator<iterator>				reverse_iterator;
								typedef VectorReverseIterator<const_iterator>		const_reverse_iterator;
								typedef std::ptrdiff_t								difference_type;

								explicit	vector();
								explicit	vector(size_type n, const value_type& val = value_type());
								vector(const vector& x);
								~vector();

								vector<value_type>		&operator=(const vector<T> &c);

								iterator					begin(void);
								const_iterator				begin(void) const;
								iterator					end(void);
								const_iterator				end(void) const;
								reverse_iterator			rbegin();
								const_reverse_iterator		rbegin(void) const;
								reverse_iterator			rend(void);
								const_reverse_iterator		rend(void) const;

								size_type			size(void) const;
								size_type			max_size(void) const;
								void				resize(size_type n, value_type val = value_type());
								size_type			capacity(void) const;
								bool				empty(void) const;
								void				reserve(size_type n);
								reference			at(size_type n);
								const_reference		at(size_type n) const;
								reference			operator[] (size_type n);
								const_reference		operator[] (size_type n) const;
								reference			front(void);
								const_reference		front(void) const;
								reference			back(void);
								const_reference		back(void) const;
								void				assign(size_type n, const T & val);
								template <class InputIterator>
										void			assign(InputIterator first, InputIterator last);

						private:
								T *			_storage;
								size_type	_size;
								size_type	_capacity;
				};
}

#endif
