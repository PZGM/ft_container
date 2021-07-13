#ifndef DEQUE_HPP
# define DEQUE_HPP

#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include <memory>
#include "DequeIterator.hpp"
#include "../IsType.hpp"

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
			
				explicit	deque() : _size(0) {
					_empty();
				}

				explicit	deque(size_type n, const value_type& val = value_type()) {
					struct __true_type x;
					_constructor(n, val, x);
				}

				template <class InputIterator>
					deque (InputIterator first, InputIterator last) : _size(0), _storage(0) {
						typedef typename ft::__is_integer<InputIterator>::__type isInt;
						isInt vraiNom;
						_constructor(first, last, vraiNom);
					}

				deque(const deque& src) {
					*this = src;
				}

				~deque() {}

				deque<value_type, Alloc>		&operator=(const deque<T, Alloc> &src) {
					_storage = src._storage;
					for (int i = 0; i < _storage.size(); i++)
						_storage[i] = src._storage[i];
					_size = src._size;
					return *this;
				}

				iterator					begin() {
					return (ft::deque<T, Alloc>::iterator(0, & _storage));
				}

				const_iterator				begin() const {
					return (ft::deque<T, Alloc>::iterator(0, & _storage));
				}

				iterator					end() {
					return (ft::deque<T, Alloc>::iterator(_size, & _storage));
				}

				const_iterator				end() const {
					return (ft::deque<T, Alloc>::iterator(_size, & _storage));
				}

				reverse_iterator			rbegin() {
					return (ft::deque<T, Alloc>::reverse_iterator(_size - 1, & _storage));
				}

				const_reverse_iterator		rbegin() const {
					return (ft::deque<T, Alloc>::reverse_iterator(_size - 1, & _storage));
				}

				reverse_iterator			rend() {
					return (ft::deque<T, Alloc>::reverse_iterator(- 1, & _storage));
				}

				const_reverse_iterator		rend() const {
					return (ft::deque<T, Alloc>::reverse_iterator(- 1, & _storage));
				}

				void				clear() {
					_size = 0;
					_storage.clear();
					_empty();
				}

				size_type			size() const {
					return (_size);
				}

				size_type			max_size() const {
					return (Alloc().max_size());
				}

				void				resize(size_type n, value_type val = value_type()) {
					T *tmp = new T(n);
					int i = 0;
					for (; i < _size && i < n; i++)
						tmp[i] = _storage[i];
					for (; i < n; i++)
						tmp[i] = val;
					_size = n;
				}

				bool				empty() const {
					return (_size == 0);
				}

				reference			operator[] (size_type pos) {
					size_type chunk = 0;
					for( ; chunk < _storage.size() && pos >= _storage[chunk].size(); chunk++)
						pos -= _storage[chunk].size();
					return(_storage[chunk][pos]);
				}

				const_reference		operator[] (size_type pos) const {
					size_type chunk = 0;
					for( ; chunk < _storage.size() && pos >= _storage[chunk].size(); chunk++)
						pos -= _storage[chunk].size();
					return(_storage[chunk][pos]);
				}

				reference			at(size_type n) {
					return (operator[](n));
				}

				const_reference		at(size_type n) const {
					return (operator[](n));
				}

				reference			front() {
					return (operator[](0));
				}

				const_reference		front() const {
					return (operator[](0));
				}

				reference			back() {
					return (operator[](_size - 1));
				}

				const_reference		back() const {
					return (operator[](_size - 1));
				}

					template <class Unknow>
				void				assign(Unknow first, Unknow second) {
					typedef typename ft::__is_integer<Unknow>::__type isInt;
					isInt inst;
					_assign(first, second, inst);
				}

				template <class InputIterator>
					void	_assign(InputIterator firste, InputIterator laste, struct ft::__false_type) {
						ft::vector<T> vec(firste, laste);
						clear();
						typename ft::vector<T>::iterator first = vec.begin();
						typename ft::vector<T>::iterator last = vec.end();

						size_type n = 0;
						typename ft::vector<T>::iterator cp = first;
						while (first !=	last)
						{
							first++;
							n++;
						}
						_storage = ft::vector<ft::vector<T, Alloc>, Alloc>(n / 10 + 1);
						for(size_type j = 0; j < n; j+= 10)
						{
							_storage[j / 10 ].reserve(10);
							typename ft::vector<value_type>::iterator it = _storage[j / 10].begin();
							_storage[j / 10].insert(it, (j + 10 > n) ?  n % 10 : 10, T());
							for (int i = 0; i < ((j + 10 > n) ?  n % 10 : 10); i++)
							{
								_storage[j/10][i] = static_cast<T>(*cp);
								cp++;
							}
						}
						_size = n;	
					}

				void	_assign(size_type n, const_reference val, struct ft::__true_type) {
					erase(begin(), end());
					insert(begin(), n, val);
					_size = n;
				}

				void				push_back(const value_type& val) {
					if (_size != 0 && _storage[_storage.size() - 1].size() == _storage[_storage.size() - 1].capacity()) {
						ft::vector<T> vec;
						vec.reserve(10);
						_storage.insert(_storage.end(), vec);
					}
					_storage[_storage.size() - 1].push_back(val);
					_size++;
				}

				void				push_front(const value_type& val) {
					_storage[0].insert(_storage[0].begin(), 1, val);
					_size++;
				}

				void				pop_back() {
					if (_size == 0)
						return;
					if (_storage[_storage.size() - 1].size() == 0)
						_storage.pop_back();
					else
						_storage[_storage.size() - 1].pop_back();
					_size--;
				}

				void				pop_front() {
					if (_size == 0)
						return;
					_storage[0].erase(_storage[0].begin());
					if (_storage[0].size() == 0 && _storage.size() != 1)
					{
						_storage.erase(_storage.begin());
					}
					_size--;
				}

				void				swap (deque& x) {
					_storage.swap(x._storage);
					size_type t = _size;
					_size = x._size;
					x._size = t;
				}

				iterator					erase(iterator position) {
					return (erase(position, position + 1));
				}

				iterator					erase(iterator first, iterator last) {
						ft::deque<T, Alloc>::iterator  t = begin();
					int i = 0;
					while (t != first)
					{
						t++;
						i++;
					}
					int l = 0;
					while (first != last)
					{
						first++;
						l++;
					}
					while (l)
					{
						size_type chunk = 0;
						size_type pos = i;
						for( ; chunk < _storage.size() && pos >= _storage[chunk].size() ; chunk++)
							pos -= _storage[chunk].size();
						if (chunk)
							chunk--;
						typename ft::vector<T, Alloc>::iterator it = _storage[chunk].begin();
						while (pos)
							it++;
						_storage[chunk].erase(it);
						l--;
						_size--;
					}
					return (first);
				}

				iterator					insert (iterator position, const_reference value) {
					ft::deque<T, Alloc>::size_type i = 0;
					ft::deque<T, Alloc>::iterator it = begin();
					for (; it != position && i < _size; it++)
						i++;
					size_type chunk = 0;
					size_type pos = i;
					for (; chunk < _storage.size() && pos > _storage[chunk].size() ; chunk++)
						pos -= _storage[chunk].size();
					if (chunk == _storage.size())
					{
						ft::vector<T>  vec(0);
						vec.reserve(10);
						_storage.push_back(vec);
					}
					typename ft::vector<T, Alloc>::iterator ite = _storage[chunk].begin();
					for (; pos; pos--)
						ite++;
					_storage[chunk].insert(ite, value);
					_size++;
					return (ft::deque<T, Alloc>::iterator(i, & _storage));
				}

			void						insert (iterator position, size_type n, const_reference value) {
				while (n--)
					position = insert(position, value);
			}

			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last) {
					_insert1(position, first, last);
				}

			private:
				vector<vector<T, Alloc>, Alloc>	_storage;
				size_type					_size;

				void _empty() {
						if (_size == 0 && _storage.size() == 0)
					{
						ft::vector<T>  vec(0);
						vec.reserve(10);
						_storage.push_back(vec);
					}		
				}

				template <class InputIterator>
					void _insert(ft::deque<T, Alloc>::iterator position, InputIterator first, InputIterator last) {
						ft::deque<T, Alloc>::size_type i = 0;
						ft::deque<T, Alloc>::iterator it = begin();
						for (; it != position && i < _size; it++)
							i++;
						size_type chunk = 0;
						size_type pos = i;
						for (; chunk < _storage.size() && pos >= _storage[chunk].size() ; chunk++)
							pos -= _storage[chunk].size();
						if (chunk)
							chunk--;
						if (chunk >= _storage.size()) //new alloc
						{
							ft::vector<T>  vec(0);
							vec.reserve(10);
							_storage.push_back(vec);
						}
						typename ft::vector<T, Alloc>::iterator ite = _storage[chunk].begin();
						for (; pos; pos--)
							ite++;
						_storage[chunk].insert(ite, first, last);
						while (first != last)
						{
							first++;
							_size++;
						}
					}

				template <class InputIterator>
					void _insert1(ft::deque<T, Alloc>::iterator position, InputIterator first, InputIterator last) {
						_insert(position, first, last);
					}

				void _insert1(ft::deque<T, Alloc>::iterator position, int n, const_reference value) {
					while (n--)
						position = insert(position, value);
				}
			
					template <class InputIterator>
				void _constructor(InputIterator first, InputIterator last, struct ft::__false_type) {
					size_type n = 0;
					InputIterator cp = first;
					while (first !=	last)
					{
						first++;
						n++;
					}
					_storage = ft::vector<ft::vector<T, Alloc>, Alloc>(n / 10 + 1);
					for(size_type j = 0; j < n; j+= 10)
					{
						_storage[j / 10 ].reserve(10);
						typename ft::vector<value_type>::iterator it = _storage[j / 10].begin();
						_storage[j / 10].insert(it, (j + 10 > n) ?  n % 10 : 10, T());
						for (int i = 0; i < ((j + 10 > n) ?  n % 10 : 10); i++)
						{
							_storage[j/10][i] = static_cast<T>(*cp);
							cp++;
						}
					}
					_size = n;
				}

				void _constructor(int n, const T & v, struct ft::__true_type) {

										{
						_storage = ft::vector<ft::vector<T, Alloc>, Alloc>(n / 10 + 1);
						for(size_type j = 0; j < n; j+= 10)
						{
							_storage[j / 10 ].reserve(10);
							typename ft::vector<value_type>::iterator it = _storage[j / 10].begin();
							_storage[j / 10].insert(it, (j + 10 > n) ?  n % 10 : 10, v);
						}
						_size = n;
					}
				}		
};

					template <typename T, class Alloc>
				bool operator== (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs) {
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
				bool operator!= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs) {
					if (lhs.size() != rhs.size())
						return (true);
					for (size_type i = 0; i < lhs.size(); i++)
					{
						if (lhs.at(i) == rhs.at(i))
							return (false);
					}
					return (true);
				}

					template <typename T, class Alloc>
				bool operator>  (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs) {
					for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
					{
						if (lhs.at(i) > rhs.at(i))
							return (true);
						if (lhs.at(i) < rhs.at(i))
							return (false);
					}
					if (lhs.size() > rhs.size())
						return (true);
					return(false);
				}

					template <typename T, class Alloc>
				bool operator<  (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs) {
					for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
					{
						if (lhs.at(i) < rhs.at(i))
							return (true);
						if (lhs.at(i) > rhs.at(i))
							return (false);
					}
					if (lhs.size() < rhs.size())
						return (true);
					return(false);
				}

					template <typename T, class Alloc>
				bool operator>= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs) {
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
				bool operator<= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs) {
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
				void swap(ft::deque<T, Alloc> & x, ft::deque<T, Alloc> & y) {
					x.swap(y);
				}
				
}

#endif
