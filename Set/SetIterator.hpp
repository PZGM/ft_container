#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

#include <iterator>
#include "Node.hpp"

typedef size_t size_type;

template <typename T>
class SetIterator : public std::iterator<std::input_iterator_tag, T>
{
	public:

		SetIterator(ft::elem<T> * e) : p(e) {}
		SetIterator(const SetIterator & mit) : p(mit.p) {}
		SetIterator & operator++() {
			if (p) {
				if (p->right)
					p = p->right;
				else {
					while ( p->content > p->father->content)
						p = p->father;
					p = p->father;
					while (p->left)
						p->left;
				}
			}
			return *this;
		}
		template <class Y>
			SetIterator operator++(Y) {
				SetIterator ret(*this);
				operator++();
				return ret;
			}
		SetIterator operator+(size_type n)
		{
			SetIterator ret(*this);
			ret.p += n;
			return (ret);
		}


		SetIterator & operator--() {
			if (p) {
				if (p->left)
					p = p->left;
				else {
					while (p->content < p->father->content)
						p = p->father;
					p = p->father;
					while (p->right)
						p->right;
				}
			}
			return *this;
		}
		template <class Y>
			SetIterator operator--(Y) {
				SetIterator ret(*this);
				operator--();
				return ret;
			}
		SetIterator operator-(size_type n)
		{
			SetIterator ret(*this);
			ret.p -= n;
			return (ret);
		}
		bool operator==(const SetIterator & rhs) const {
			return p==rhs.p;
		}
		bool operator!=(const SetIterator & rhs) const {
			return p!=rhs.p;
		}
		T & operator*() {
			return p->content;
		}

	private:

		ft::elem<T> * p;
};
//	To Do
template <typename T>
class SetReverseIterator : public std::iterator<std::input_iterator_tag, T>
{
	public:

		SetReverseIterator(ft::elem<T> * e) : p(e) {}
		SetReverseIterator(const SetReverseIterator & mit) : p(mit.p) {}
		SetReverseIterator & operator++() {
			if (p)
				p = p->prev;;
			return *this;
		}
		template <class Y>
			SetReverseIterator operator++(Y) {
				SetReverseIterator ret(*this);
				operator++();
				return ret;
			}

		SetReverseIterator operator+(size_type n)
		{
			SetReverseIterator ret(*this);
			p -= n;
			return (*this);
		}


		SetReverseIterator & operator--() {
			if (p)
				p = p->prev;
			return *this;
		}
		template <class Y>
			SetReverseIterator operator--(Y) {
				SetReverseIterator ret(*this);
				operator--();
				return ret;
			}

		SetReverseIterator operator-(size_type n)
		{
			SetReverseIterator ret(*this);
			p += n;
			return (*this);
		}
		bool operator==(const SetReverseIterator & rhs) const {
			return p==rhs.p;
		}
		bool operator!=(const SetReverseIterator & rhs) const {
			return p!=rhs.p;
		}
		T & operator*() {
			return p->content;
		}

	private:

		ft::elem<T> * p;
};
#endif
