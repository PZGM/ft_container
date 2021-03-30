#ifndef VECTOR_HPP
# define VECTOR_HPP

template <typename T>
class Vector
{
	private:
		T *_array;
		unsigned int _size;

	public:
		Vector();
		~Vector();
		Vector(unsigned int n);
		Vector(const Vector<T> &c);
		Vector<T> &operator=(const Vector<T> &c);
		size
		max size
		empty
		operator []
		at 
		front
		bac/k
		push back
		pop backinsert
		clear

		class OutOfBoundException: public std::exception
	{
		public:
			virtual char const *what() const throw();
	};

		T &operator[](unsigned int i);
		T const &operator[](unsigned int i) const;
		unsigned int size() const;
};

#endif
