#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <iterator>
#include "ElemStruct.hpp"

typedef size_t size_type;

template <typename Key, typename T>
class MapIterator : public std::iterator<std::input_iterator_tag, Key, T>
{
	public:

		MapIterator(ft::elem<Key, T> * e) : p(e) {}
		MapIterator(const MapIterator & mit) : p(mit.p) {}
		MapIterator & operator++() {
			if (p)
				p = p->next;
			return *this;
		}
		template <class Y>
			MapIterator operator++(Y) {
				MapIterator ret(*this);
				operator++();
				return ret;
			}
		MapIterator operator+(size_type n)
		{
			MapIterator ret(*this);
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


		MapIterator & operator--() {
			if (p)
				p = p->prev;
			return *this;
		}
		template <class Y>
			MapIterator operator--(Y) {
				MapIterator ret(*this);
				operator--();
				return ret;
			}
		MapIterator operator-(size_type n)
		{
			MapIterator ret(*this);
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
		bool operator==(const MapIterator & rhs) const {
			return p==rhs.p;
		}
		bool operator!=(const MapIterator & rhs) const {
			return p!=rhs.p;
		}
			ft::pair<Key, T> & operator*() {
			ft::pair<Key, T> x;
			x.first = p->key;
			x.second = p.val;
			return x;
		}

	private:

		ft::elem<Key, T> * p;
};

template <typename Key, typename T>
class MapReverseIterator : public std::iterator<std::input_iterator_tag, Key, T>
{
	public:

		MapReverseIterator(ft::elem<Key,T> * e) : p(e) {}
		MapReverseIterator(const MapReverseIterator & mit) : p(mit.p) {}
		MapReverseIterator & operator++() {
			if (p)
				p = p->prev;;
			return *this;
		}
		template <class Y>
			MapReverseIterator operator++(Y) {
				MapReverseIterator ret(*this);
				operator++();
				return ret;
			}

		MapReverseIterator operator+(size_type n)
		{
			MapReverseIterator ret(*this);	
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


		MapReverseIterator & operator--() {
			if (p)
				p = p->prev;
			return *this;
		}
		template <class Y>
			MapReverseIterator operator--(Y) {
				MapReverseIterator ret(*this);
				operator--();
				return ret;
			}

		MapReverseIterator operator-(size_type n)
		{
			MapReverseIterator ret(*this);	
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
		bool operator==(const MapReverseIterator & rhs) const {
			return p==rhs.p;
		}
		bool operator!=(const MapReverseIterator & rhs) const {
			return p!=rhs.p;
		}
		ft::pair<Key, T> & operator*() {
			ft::pair<Key, T> x;
			x.first = p->key;
			x.second = p.val;
			return x;
		}

	private:

		ft::elem<Key, T> * p;
};
#endif
