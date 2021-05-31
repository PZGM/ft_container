#ifndef LIST_ITERATOR_HPP
# define LIST_ITERATOR_HPP

#include <iterator>
#include "ElemStruct.hpp"

typedef size_t size_type;

template <typename T>
class ListIterator : public std::iterator<std::input_iterator_tag, T>
{
	public:

		ListIterator(ft::elem<T> * e) : p(e) {}
		ListIterator(const ListIterator & mit) : p(mit.p) {}
		ListIterator & operator++() {
			if (p)
				p = p->next;
			return *this;
		}
		template <class Y>
			ListIterator operator++(Y) {
				ListIterator ret(*this);
				operator++();
				return ret;
			}
		ListIterator operator+(size_type n)
		{
			ListIterator ret(*this);
			while (n > 0)
			{
				ret++;
				n--;
			}
			while (n < 0)
			{
				ret--;
				n++;
			}
			return (ret);
		}


		ListIterator & operator--() {
			if (p)
				p = p->prev;
			return *this;
		}
		template <class Y>
			ListIterator operator--(Y) {
				ListIterator ret(*this);
				operator--();
				return ret;
			}
		ListIterator operator-(size_type n)
		{
			ListIterator ret(*this);
			while (n > 0)
			{
				ret--;
				n--;
			}
			while (n < 0)
			{
				ret++;
				n++;
			}
			return (ret);
		}
		bool operator==(const ListIterator & rhs) const {
			return p==rhs.p;
		}
		bool operator!=(const ListIterator & rhs) const {
			return p!=rhs.p;
		}
		T & operator*() {
			return p->content;
		}

	private:

		ft::elem<T> * p;
};

template <typename T>
class ListReverseIterator : public std::iterator<std::input_iterator_tag, T>
{
	public:

		ListReverseIterator(ft::elem<T> * e) : p(e) {}
		ListReverseIterator(const ListReverseIterator & mit) : p(mit.p) {}
		ListReverseIterator & operator++() {
			if (p)
				p = p->prev;;
			return *this;
		}
		template <class Y>
			ListReverseIterator operator++(Y) {
				ListReverseIterator ret(*this);
				operator++();
				return ret;
			}

		ListReverseIterator operator+(size_type n)
		{
			ListReverseIterator ret(*this);	
			while (n > 0)
			{
				ret++;
				n--;
			}
			while (n < 0)
			{
				ret--;
				n++;
			}
			return (*this);
		}


		ListReverseIterator & operator--() {
			if (p)
				p = p->prev;
			return *this;
		}
		template <class Y>
			ListReverseIterator operator--(Y) {
				ListReverseIterator ret(*this);
				operator--();
				return ret;
			}

		ListReverseIterator operator-(size_type n)
		{
			ListReverseIterator ret(*this);	
			while (n > 0)
			{
				ret--;
				n--;
			}
			while (n < 0)
			{
				ret++;
				n++;
			}
			return (*this);
		}
		bool operator==(const ListReverseIterator & rhs) const {
			return p==rhs.p;
		}
		bool operator!=(const ListReverseIterator & rhs) const {
			return p!=rhs.p;
		}
		T & operator*() {
			return p->content;
		}

	private:

		ft::elem<T> * p;
};
#endif
