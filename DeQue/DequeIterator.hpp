#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <iterator>

typedef size_t size_type;

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
				template< class Y>
				VectorIterator operator++(Y) {
						VectorIterator tmp(*this);
						operator++();
						return tmp;
				}
				VectorIterator operator+(size_type n)
				{
					VectorIterator ret(*this);
					ret.p += n;
					return (ret);
				}
				VectorIterator operator-(size_type n)
				{
					VectorIterator ret(*this);
					ret.p -= n;
					return (ret);
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
				VectorReverseIterator operator+(size_type n)
				{
					p -= n;
					return (*this);
				}
				
				VectorReverseIterator operator-(size_type n)
				{
					p += n;
					return (*this);
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
