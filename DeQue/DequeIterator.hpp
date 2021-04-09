#ifndef DEQUE_ITERATOR_HPP
# define DEQUE_ITERATOR_HPP

#include <iterator>
#include "../Vector/Vector.cpp"

template <typename T>
class DequeIterator : public std::iterator<std::input_iterator_tag, T>
{
		public:

				DequeIterator(size_type p) : p(p) {}
				DequeIterator(const DequeIterator & mit) : p(mit.p){}
				
				DequeIterator & operator++() {
						p++;
					return(*this);
				}
				template< class Y>
				DequeIterator operator++(Y) {
						DequeIterator tmp(*this);
						operator++();
						return tmp;
				}
				DequeIterator operator+(size_type n)
				{
					DequeIterator ret(*this);
					ret.p += n;
					return (ret);
				}
				DequeIterator operator-(size_type n)
				{
					DequeIterator ret(*this);
					ret.p -= n;
					return (ret);
				}
				bool operator==(const DequeIterator & rhs) const {
						return p==rhs.p;
				}
				bool operator!=(const DequeIterator & rhs) const {
						return p!=rhs.p;
				}
				T & operator*() {
						return T();
				}

		private:

				size_type	p;
};

template <typename T>
class DequeReverseIterator : public std::iterator<std::input_iterator_tag, T>
{
		public:

				DequeReverseIterator(T* x) : p(x) {}
				DequeReverseIterator(const DequeReverseIterator & mit) : p(mit.p) {}
				DequeReverseIterator & operator++() {
						--p;
						return *this;
				}
				DequeReverseIterator operator++(T) {
						DequeReverseIterator tmp(*this);
						operator++();
						return tmp;
				}
				DequeReverseIterator operator+(size_type n)
				{
					p -= n;
					return (*this);
				}
				
				DequeReverseIterator operator-(size_type n)
				{
					p += n;
					return (*this);
				}
				bool operator==(const DequeReverseIterator & rhs) const {
						return p==rhs.p;
				}
				bool operator!=(const DequeReverseIterator & rhs) const {
						return p!=rhs.p;
				}
				T & operator*() {
						return *p;
				}

		private:

				T* p;
};
#endif
