#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <iterator>

template <typename T>
class VectorIterator : public std::iterator<std::input_iterator_tag, T>
{
		public:

				VectorIterator(T* x) : p(x) {}
				VectorIterator(const VectorIterator & mit) : p(mit.p) {}
				VectorIterator & operator++() {
						++p;
						return *this;
				}
				VectorIterator operator++(T) {
						VectorIterator tmp(*this);
						operator++();
						return tmp;
				}
				bool operator==(const VectorIterator & rhs) const {
						return p==rhs.p;
				}
				bool operator!=(const VectorIterator & rhs) const {
						return p!=rhs.p;
				}
				T & operator*() {
						return *p;
				}

		private:

				T* p;
};

template <typename T>
class VectorReverseIterator : public std::iterator<std::input_iterator_tag, T>
{
		public:

				VectorReverseIterator(T* x) : p(x) {}
				VectorReverseIterator(const VectorReverseIterator & mit) : p(mit.p) {}
				VectorReverseIterator & operator++() {
						--p;
						return *this;
				}
				VectorReverseIterator operator++(T) {
						VectorReverseIterator tmp(*this);
						operator++();
						return tmp;
				}
				bool operator==(const VectorReverseIterator & rhs) const {
						return p==rhs.p;
				}
				bool operator!=(const VectorReverseIterator & rhs) const {
						return p!=rhs.p;
				}
				T & operator*() {
						return *p;
				}

		private:

				T* p;
};
#endif
