#ifndef DEQUE_ITERATOR_HPP
# define DEQUE_ITERATOR_HPP

#include <iterator>
#include "../Vector/Vector.cpp"

template <typename T>
class DequeIterator : public std::iterator<std::input_iterator_tag, T>
{
		typedef ft::vector<ft::vector<T> > dvec;
		public:

				DequeIterator(size_type p, dvec s) : p(p), s(s) {}
				DequeIterator(const DequeIterator & mit) : p(mit.p), s(mit.s) {}
				
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
					size_type chunk;
					size_type pos;

				    chunk = (s.size() > 1) ? ((p < s[0].size()) ? 0 : (p - s[0].size() + 1) / 10 + 1) : 0 ;
					pos = (s.size() > 1) ? (p - s[0].size() + 1) % 10 : p % 10;
					return(s[chunk][pos]);	
				}

		private:

				size_type	p;
				dvec		s;
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
