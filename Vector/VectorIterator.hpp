#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <iterator>

class iterator : public std::iterator<std::input_iterator_tag, T>
{
		public:

				iterator(T* x) : p(x) {}
				iterator(const iterator & mit) : p(mit.p) {}
				iterator & operator++() {
						++p;
						return *this;
				}
				iterator operator++(T) {
						iterator tmp(*this);
						operator++();
						return tmp;
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

		private:

				T* p;
};

#endif
