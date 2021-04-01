#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <climits>
#include <cstring>
#include <stdexcept>
#include <iterator>
#include <iostream>

typedef size_t size_type;

namespace ft
{
	template <typename T> //template <class T, class Alloc = std::allocator<T> >
		class vector
		{
			public:

				class iterator : public std::iterator<std::input_iterator_tag, T>
				{
					private:
						T* p;
					public:
						iterator(T* x) : p(x) {}
						iterator(const iterator& mit) : p(mit.p) {}
						iterator& operator++() {
							++p;
							return *this;
						}
						iterator operator++(int) {
							iterator tmp(*this);
							operator++(); return tmp;
						}
						bool operator==(const iterator& rhs) const {
							return p==rhs.p;
						}
						bool operator!=(const iterator& rhs) const {
							return p!=rhs.p;
						}
						T & operator*() {
							return *p;
						}
				};

				class reverse_iterator : public std::iterator<std::input_iterator_tag, T>
				{
					private:
						T* p;
					public:
						reverse_iterator(T* x) : p(x) {}
						reverse_iterator(const reverse_iterator& mit) : p(mit.p) {}
						reverse_iterator& operator++() {
							--p;return *this;
						}
						reverse_iterator operator++(int) {
							reverse_iterator tmp(*this);
							operator++();
							return tmp;
						}
						bool operator==(const reverse_iterator& rhs) const {
							return p==rhs.p;
						}
						bool operator!=(const reverse_iterator& rhs) const {
							return p!=rhs.p;
						}
						T & operator*() {
							return *p;
						}
				};

				vector();
				vector(size_type n, const T & v = T());
				vector(const vector<T> &c);
				~vector();
				vector<T> &operator=(const vector<T> &c);

				vector<T>::iterator begin(void);
				const vector<T>::iterator begin(void) const;
				vector<T>::iterator end(void);
				const vector<T>::iterator end(void) const;

				vector<T>::reverse_iterator rbegin(void);
				const vector<T>::reverse_iterator rbegin(void) const;
				vector<T>::reverse_iterator rend(void);
				const vector<T>::reverse_iterator rend(void) const;



				size_type size(void) const;
				size_type max_size(void) const;
				void resize(size_type n, T val = T());
				size_type capacity(void) const;
				bool empty(void) const;
				void reserve(size_type n);

				T & at(size_type n);
				T & at(size_type n) const;
				T & operator[] (size_type n);
				const T & operator[] (size_type n) const;
				T & front(void);
				const T & front(void) const;
				T & back(void);
				const T & back(void) const;
				void assign (size_type n, const T & val);
				template <class InputIterator>
				void assign (InputIterator first, InputIterator last);

			private:

				T *_storage;
				size_type _size;
				size_type _capacity;
		};
}

#endif
