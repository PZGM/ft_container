#ifndef DEQUE_ITERATOR_HPP
# define DEQUE_ITERATOR_HPP

#include <iterator>
#include "../Vector/Vector.cpp"

template <typename T, class Alloc = std::allocator<T> >
class DequeIterator : public std::iterator<std::input_iterator_tag, T>
{
		typedef ft::vector<ft::vector<T, Alloc>, Alloc > dvec;
		public:

				DequeIterator(size_type p, dvec * s) : p(p), s(s) {}
				DequeIterator(const DequeIterator & mit) : p(mit.p), s(mit.s) {}
				
				DequeIterator & operator++() {
						p++;
					return(*this);
				}

				DequeIterator<T, Alloc>				operator=(const DequeIterator<T, Alloc> &src) {
					p = src.p;
					return *this;
				}

				template <class Y>
				DequeIterator operator++(Y) {
						DequeIterator ret(*this);
						operator++();
						return ret;
				}

				DequeIterator operator+(size_type n) {
					DequeIterator ret(*this);
					ret.p += n;
					return (ret);
				}


				DequeIterator & operator--() {
						p--;
					return(*this);
				}

				template <class Y>
				DequeIterator operator--(Y) {
						DequeIterator ret(*this);
						operator--();
						return ret;
				}

				DequeIterator operator-(size_type n) {
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
					size_type chunk = 0;
					size_type pos = p;
					for( ; chunk <  s->size() && pos >= (*s)[chunk].size() ; chunk++)
						pos -= (*s)[chunk].size();
				//	if (chunk)
				//		chunk--;
					return((*s)[chunk][pos]);	
				}

		private:

				size_type	p;
				dvec		* s;
};

template <typename T, class Alloc = std::allocator<T> >
class DequeReverseIterator : public std::iterator<std::input_iterator_tag, T>
{
		typedef ft::vector<ft::vector<T, Alloc>, Alloc > dvec;
		public:

				DequeReverseIterator(size_type p, dvec * s) : p(p), s(s) {}
				DequeReverseIterator(const DequeReverseIterator & mit) : p(mit.p), s(mit.s) {}
			
				DequeReverseIterator & operator++() {
						--p;
						return *this;
				}
				
				template <class Y>
				DequeReverseIterator operator++(Y) {
						DequeReverseIterator ret(*this);
						operator++();
						return ret;
				}

				DequeReverseIterator operator+(size_type n) {
					DequeReverseIterator ret(*this);
					p -= n;
					return (*this);
				}


				
				DequeReverseIterator & operator--() {
						++p;
						return *this;
				}
				
				template <class Y>
				DequeReverseIterator operator--(Y) {
						DequeReverseIterator ret(*this);
						operator--();
						return ret;
				}

				DequeReverseIterator operator-(size_type n) {
					DequeReverseIterator ret(*this);
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
					size_type chunk = 0;
					size_type pos = p;
					for( ; chunk < s->size() && pos >= (*s)[chunk].size() ; chunk++)
						pos -= (*s)[chunk].size();
					if (chunk)
						chunk--;
					return((*s)[chunk][pos]);	
				}



		private:

				size_type	p;
				dvec		* s;
};
#endif
