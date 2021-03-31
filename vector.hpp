#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <climits>
#include <cstring>

typedef size_t size_type;

namespace ft
{
	template <typename T>
		class vector
		{
			public:
				vector();
				~vector();
				vector(unsigned int n);
				//vector()
				vector(const vector<T> &c);
				vector<T> &operator=(const vector<T> &c);

				//size = _size;
				size_type max_size(void) const;
				T & at(size_type n);
				T & at(size_type n) const;
				bool empty(void) const;
				//empty
				//operator []
				//at 
				//front
				//bac/k
				//push back
				//pop backinsert
				//clear
				T &operator[](unsigned int i);
				T const &operator[](unsigned int i) const;
				unsigned int size() const;
			private:

				T *_storage;
				unsigned int _size;
		};	
}

#endif
