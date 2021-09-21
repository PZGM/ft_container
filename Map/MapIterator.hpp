#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <iterator>
#include "Node.hpp"

typedef size_t size_type;

template <typename Key, typename Value>
class MapIterator : public std::iterator<std::input_iterator_tag, Key, Value>
{
	public:

		MapIterator(Node<ft::pair<Key, Value> > * e) : p(e) {}
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
		
		ft::pair<Key, Value> & operator*() {
			return p->data;
		}

	private:

		Node<ft::pair<Key, Value> > * p;
		ft::pair<Key, Value> x;
};

template <typename Key, typename Value>
class MapReverseIterator : public std::iterator<std::input_iterator_tag, Key, Value>
{
	public:

		MapReverseIterator(Node<ft::pair<Key, Value> > * e) : p(e) {}
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
		ft::pair<Key, Value> & operator*() {
			return p->data;
		}

	private:

		Node<ft::pair<Key, Value> > * p;
		ft::pair<Key, Value> x;
};
#endif
