#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include "../IsType.hpp"
#include "VectorIterator.hpp"
#include <memory>

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
		class vector
		{
			//  les com c'est l'ancien container
			public:
				typedef T											value_type;
				typedef Alloc										allocator_type;
				typedef value_type&									reference;
				typedef const value_type&							const_reference;
				// typedef value_type*								pointer;
				typedef typename Alloc::pointer						pointer;
				typedef typename Alloc::const_pointer				const_pointer;
				typedef VectorIterator<value_type>				iterator;
				// typedef VectorIterator<pointer>						iterator;
				// typedef typename Alloc::size_type				size_type;
				typedef std::size_t									size_type;
				typedef const VectorIterator<value_type>			const_iterator;
				typedef VectorReverseIterator<value_type>			reverse_iterator;
				typedef const VectorReverseIterator<value_type>		const_reverse_iterator;
				// typedef VectorIterator<const_pointer>			const_iterator;
				// typedef VectorReverseIterator<pointer>			reverse_iterator;
				// typedef VectorReverseIterator<const_pointer>	const_reverse_iterator;
				typedef std::ptrdiff_t								difference_type;

				explicit	vector(const allocator_type& alloc = allocator_type()) : _storage(NULL), _size(0), _capacity(0), _alloc(alloc) {}
				
				explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
                	struct __true_type x;
					_constructor(n, val, x);
            	}

				template <class InputIterator>
         			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
						_size = 0;
						_capacity = 0;
						_storage = NULL;
						_alloc = alloc;
						typedef typename ft::__is_integer<InputIterator>::__type isInt;
						isInt vraiNom;
						_constructor(first, last, vraiNom);
					}

				vector(const vector& src, const allocator_type& alloc = allocator_type()) : _size(src._size), _capacity(src._capacity), _storage(NULL), _alloc(alloc){
					_storage = _alloc.allocate(src._capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_storage[i], src._storage[i]);
				}

				~vector() {
					if (_capacity > 0)
					{
						for (size_type i = 0; i < _size; i++)
							_alloc.destroy(&_storage[i]);
						_alloc.deallocate(_storage, _capacity);
					}
				}

				vector<value_type, Alloc>		&operator=(const vector<T, Alloc> &src) {
					if (_capacity > 0)
					{
						for (size_type i = 0; i < _size; i++)
							_alloc.destroy(&_storage[i]);
						_alloc.deallocate(_storage, _capacity);
					}
					_capacity = src._capacity;
					_size = src._size;
					if (_capacity > 0)
						_storage = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_storage[i], src._storage[i]);
					return *this;
				}

				iterator					begin() {
					return (ft::vector<T, Alloc>::iterator(&_storage[0]));
				}

				const_iterator				begin() const {
					return (ft::vector<T, Alloc>::iterator(&_storage[0]));
				}

				iterator					end() {
					return (ft::vector<T, Alloc>::iterator(&_storage[_size]));
				}

				const_iterator				end() const {
					return (ft::vector<T, Alloc>::iterator(&_storage[_size]));
				}

				reverse_iterator			rbegin() {
					return (ft::vector<T, Alloc>::reverse_iterator(&_storage[_size - 1]));
				}

				const_reverse_iterator		rbegin() const {
					return (ft::vector<T, Alloc>::reverse_iterator(&_storage[_size - 1]));
				}

				reverse_iterator			rend() {
					return (ft::vector<T, Alloc>::reverse_iterator(&_storage[-1]));
				}
				const_reverse_iterator		rend() const {
					return (ft::vector<T, Alloc>::reverse_iterator(&_storage[-1]));
				}

				void				clear() {
					erase(begin(), end());
				}

				size_type			size() const {
					return (_size);
				}

				size_type			max_size() const {
					return (_alloc.max_size());
				}

				void				resize(size_type n, value_type val = value_type()) {
					T *tmp = _alloc.allocate(n);
					int i = 0;
					for (; i < _size && i < n; i++)
						_alloc.construct(&tmp[i], _storage[i]);
					for (; i < n; i++)
						_alloc.construct(&tmp[i], val);
					if (_capacity > 0) {
						for (size_type i = 0; i < _size; i++)
							_alloc.destroy(&_storage[i]);
						_alloc.deallocate(_storage, _capacity);
					}
					_storage = tmp;
					_capacity = n;
					_size = n;
				}

				size_type			capacity() const {
					return (_capacity);
				}

				bool				empty() const {
					return (_size == 0);
				}

				void				reserve(size_type n) {
					if (n > _capacity) {
						value_type *tmp = _alloc.allocate(n);
						for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _storage[i]);
						if (_capacity > 0) {
							for (size_type i = 0; i < _size; i++)
								_alloc.destroy(&_storage[i]);
							_alloc.deallocate(_storage, _capacity);
						}
						_storage = tmp;
						_capacity = n;
					}
				}

				reference			operator[] (size_type n) {
					return (_storage[n]);
				}

				const_reference		operator[] (size_type n) const {
					return (_storage[n]);
				}

				reference			at(size_type n) {
					return (_storage[n]);
				}

				const_reference		at(size_type n) const {
					return (_storage[n]);
				}

				reference			front() {
					return (_storage[0]);
				}

				const_reference		front() const {
					return (_storage[0]);
				}

				reference			back() {
					return (_storage[_size -1]);
				}

				const_reference		back() const {
					return (_storage[_size -1]);
				}

				template <class InputIterator>
					void				assign(InputIterator first, InputIterator last) {
						clear();
						insert(begin(), first, last);
					}

				void				assign(size_type n, const_reference val) {
					clear();
					insert(begin(), n, val);
					_size = n;
				}

				void				push_back(const value_type& val) {
					reserve(_size + 1);
					_alloc.construct(&_storage[_size], val);
					_size++;
				}

				void				pop_back() {
					_alloc.destroy(&_storage[_size - 1]);//on tente on verra
					_size--;
				}

				void				swap (vector& x) {
					size_type tmp = x.size();
					x._size = _size;
					_size = tmp;

					tmp = x._capacity;
					x._capacity = _capacity;
					_capacity = tmp;

					value_type* tmps = x._storage;
					x._storage = _storage;
					_storage = tmps;

					Alloc tmpa = x._alloc;
					x._alloc = _alloc;
					_alloc = tmpa;
				}

				iterator					erase(iterator position) {
					return (erase(position, position + 1));
				}

				iterator					erase(iterator first, iterator last) {
					ft::vector<T, Alloc>::iterator  t = first;
					while (first != last)
					{
						++first;
						_size--;
						_alloc.destroy(&_storage[_size]);
					}
					while (t != end())
					{
						*t = *last;
						++t;
						++last;
					}
					return (first);
				}

				iterator					insert (iterator position, const_reference val) {
					ft::vector<T, Alloc>::size_type i = 0;
					ft::vector<T, Alloc>::iterator it = begin();
					for (; it != position && i < _size; it++)
						i++;
					if (_size == _capacity)
						reserve(_capacity + 1);
					size_type j = _size;
					while (j > i)
					{
						_alloc.construct(&_storage[j], _storage[j - 1]);
						j--;
					}
					_alloc.construct(&_storage[i], val);
					_size++;
					return (ft::vector<T, Alloc>::iterator(&_storage[i]));
				}

				void						insert (iterator position, size_type n, const_reference val) {
					while (n--)
						position = insert(position, val);
				}

				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last) {
						_insert1(position, first, last);
					}


			private:
				value_type*	_storage;
				size_type	_size;
				size_type	_capacity;
				Alloc		_alloc;

				template <class InputIterator>
					void _insert(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last) {
						int i;
						InputIterator prems = first;
						
						for (i = 0; prems != last; prems++) {
							i++;
						}
						int y = 0;
						for (; begin() + y != position; y++)
							;
						value_type val[i];
						prems = first;
						for (int j = 0; prems != last; prems++) {
							val[j] = *prems;
							j++;
						}
						reserve(_size + i);
						i = 0;
						while (first != last)
						{
							insert(begin() + y, val[i]) + 1;
							y++;
							i++;
							first++;
						}
					}

				template <class InputIterator>
					void _insert1(ft::vector<T, Alloc>::iterator position, InputIterator first, InputIterator last) {
						_insert(position, first, last);
					}

				void _insert1(ft::vector<T, Alloc>::iterator position, int n, const_reference value) {
					while (n--)
						position = insert(position, value);
				}
				
				template <class InputIterator>
			void _constructor(InputIterator first, InputIterator last, struct ft::__false_type) {
				assign(first, last);
			}

				void _constructor(int n, const T & v, struct ft::__true_type) {
					if (n > ft::vector<T, Alloc>::max_size())
						throw std::runtime_error("ft::vector error : desole, tu t'es trompe, prend pas toute ma ram stp, chrome en a besoin");
					if (n > 0)
						_storage = _alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_storage[i], v);
					_capacity = n;
					_size = n;
				}
		};

					template <typename T, class Alloc>
				bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
					if (lhs.size() != rhs.size())
						return (false);
					for (size_type i = 0; i < lhs.size(); i++)
					{
						if (lhs.at(i) != rhs.at(i))
							return (false);
					}
					return (true);
				}

					template <typename T, class Alloc>
				bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
					if (lhs.size() != rhs.size())
						return (true);
					for (size_type i = 0; i < lhs.size() && i < rhs.size(); i++)
					{
						if (lhs.at(i) != rhs.at(i))
							return (true);
					}
					return (false);
				}

					template <typename T, class Alloc>
				bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
					for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
					{
						if (lhs.at(i) > rhs.at(i))
							return (true);
						if (rhs.at(i) < rhs.at(i))
							return (false);
					}
					if (lhs.size() > rhs.size())
						return (true);
					return(false);
				}

					template <typename T, class Alloc>
				bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
					for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
					{
						if (lhs.at(i) < rhs.at(i))
							return (true);
						if (rhs.at(i) > rhs.at(i))
							return (false);
					}
					if (lhs.size() < rhs.size())
						return (true);
					return(false);
				}

					template <typename T, class Alloc>
				bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
					for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
					{
						if (lhs.at(i) > rhs.at(i))
							return (true);
						if (lhs.at(i) < rhs.at(i))
							return (false);
					}
					if (lhs.size() >= rhs.size())
						return (true);
					return(false);
				}

					template <typename T, class Alloc>
				bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
					for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
					{
						if (lhs.at(i) < rhs.at(i))
							return (true);
						if (lhs.at(i) > rhs.at(i))
							return (false);
					}
					if (lhs.size() <= rhs.size())
						return (true);
					return(false);
				}

					template <typename T, class Alloc>
				void swap(ft::vector<T, Alloc> & x, ft::vector<T, Alloc> & y) {
					x.swap(y);
				}
}


#endif
