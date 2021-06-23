#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

#include <iterator>
#include "Node.hpp"

typedef size_t size_type;

template <typename T>
class SetIterator : public std::iterator<std::input_iterator_tag, T>
{
	public:
		SetIterator(){};
		~SetIterator(){};
		SetIterator(ft::Node<T> * e) : p(e) , _bound(0) {}
		SetIterator(const SetIterator & mit) : p(mit.p) , _bound(mit._bound) {}
		SetIterator & operator++() {
			if (p) {
				if (p->right) {
					p = p->right;
					while (p->left)
						p = p->left;
				}
				else { 
					while (p->parent && p == p->parent->right) //when root parent null
						p = p->parent;
					p = p->parent;
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
					while (p->val < p->parent->val)
						p = p->parent;
					p = p->parent;
					while (p->right)
						p->right;
				}
			}
			return *this;
		}

		void	SetBound(int pos) {
			_bound = pos;
		}

		int		GetBound() const {
			return _bound;
		}
		
		bool isEnd() const {
			return p->isEnd;
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
			return p->val;
		}
		
		void newp(ft::Node<T> *e) {
			p = e;
		}
	private:

		ft::Node<T> * p;
		int _bound;
};
//	To Do
template <typename T>
class SetReverseIterator : public std::iterator<std::input_iterator_tag, T>
{
	public:

		SetReverseIterator(ft::Node<T> * e) : p(e) {}
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
			return p->val;
		}

	private:

		ft::Node<T> * p;
};
#endif
