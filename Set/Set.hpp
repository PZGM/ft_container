#ifndef SET_HPP
# define SET_HPP

#include <iostream>
#include <cstddef>
#include <limits.h>
#include <stdexcept>
#include <functional>
#include <memory>
#include "../IsType.hpp"
#include "rbt.hpp"
#include "../pair.hpp"

namespace ft
{
	template <class T>
		struct less : std::binary_function <T,T,bool> {
			bool operator() (const T& x, const T& y) const {
				return x<y;
			}
		};	
	template <typename T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
		class set
		{
			public:
				typedef T						value_type;
				typedef T						key_type;
				typedef Compare					key_compare;
				typedef Compare					value_compare;
				typedef Alloc					allocator_type;
				typedef value_type&					reference;
				typedef const value_type&				const_reference;
				typedef value_type*					pointer;
				typedef const value_type*				const_pointer;
				typedef SetIterator<value_type>			iterator;
				typedef typename Alloc::size_type			size_type;
				typedef const SetIterator<value_type>			const_iterator;
				typedef SetReverseIterator<value_type>			reverse_iterator;
				typedef const SetReverseIterator<value_type>		const_reverse_iterator;
				typedef std::ptrdiff_t					difference_type;

				explicit	set(const key_compare& comp = key_compare(),  const allocator_type& alloc = allocator_type()) {
					_tree = new rbt<T, Compare>;
				}

				template <class InputIterator>
					set(InputIterator first, InputIterator last,  const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
						_tree = new rbt<T, Compare>;
						insert(first, last);
					}
				
				set(const set& x) {
					_tree = new rbt<T,Compare>;
					iterator it = x.begin();
					if (x.size() > 0) {
						while (it.isEnd() == false) {			
							if (insert(*it).second == false)
								it++;
						}
					}
				}

				~set() {
					delete _tree;
				}

				set<T, Compare, Alloc>		&operator=(const set<T,Compare, Alloc> &rhs) {
					iterator end;
					end = this->end();
					if (size() > 0) {
						end--;
						erase(begin(), end);
					}
					/*		end = rhs.end();
							end--;
							insert(rhs.begin(), end);
							*/		
					*(this->_tree) = *(rhs._tree);
					return *this;
				}

				iterator					find(const value_type& val) const {
					Node<T> *leaf = _tree->getRoot();
					if (_tree->Search(val, &leaf))
						return leaf;
					return end();
				}

				void						swap(set& x) {
					rbt<T, Compare>  *tmp;
					tmp  = x._tree;
					x._tree = _tree;
					_tree = tmp;
				}

				size_type					size() const {
					return _tree->getSize();
				}

				size_type					max_size() const {
					return ((Alloc().max_size() -1) / 10);
				}

				size_type					count(const value_type & val) const {
					size_t i = 0;
					iterator it  = begin();
					while (it != end()) {
						if(*it == val)
							i++;
						it++;
					}
					return i;
				}

				bool						empty() const {
					if (_tree->getSize() == 0)
						return true;
					return false;
				}

				void						clear() {
					_tree->DestroyI();
				}

				iterator				begin() {
					return _to_begin(_tree->getRoot());
				}

				const_iterator			begin() const {
					return _const_to_begin(_tree->getRoot());
				}

				iterator				end() {
					if (size() == 0)
						return begin();
					return _to_end(_tree->getRoot());
				}

				const_iterator			end() const {
					if (size() == 0)
						return begin();
					return _const_to_end(_tree->getRoot());
				}

				reverse_iterator		rbegin() {
					return _to_rbegin(_tree->getRoot());
				}

				const_reverse_iterator	rbegin() const {
					return _const_to_rbegin(_tree->getRoot());
				}

				reverse_iterator		rend() {
					if (size() == 0)
						return rbegin();
					return _to_rend(_tree->getRoot());
				}

				const_reverse_iterator	rend() const {
					if (size() == 0)
						return rbegin();
					return (_const_to_rend(_tree->getRoot));
				}
				
				// insert
				pair<iterator,bool> insert(const value_type& val) {
					pair<iterator, bool> pa;
					Node<T>	*node;
					if (_tree->Search(val, &node)) {	
						pa.first = node;
						pa.second = false;
					}
					else {
						_tree->insert(val);
						_tree->Search(val, &node);
						pa.first = node;
						pa.second = true;
					}
					return pa;
				}

				iterator insert(iterator position, const value_type& val) {
					Node<T>	*node = NULL;
					_tree->Search(val, node);
					if (node)
						return &node;
					return _tree->insert(val);
				}

				template <class InputIterator>
				void insert(InputIterator first, InputIterator last) {
					for ( ; first != last; first++) {
						if (ft::set<T, Compare, Alloc>::find(*first) == this->end())
							_tree->insert(*first);
					}
				}

				void erase(iterator position) {
					rbt<T,Compare> t = *_tree;
				//	*_tree = t;
					_tree->DeleteValue(*position);
				}

				size_type erase(const value_type & val) {
					return _tree->DeleteAllValue(val);
				}

				void erase(iterator first, iterator last) {
					ft::Node<T> *leaf;
					T val;
					T end = *last;
					
					iterator tmp = first;
					first++;
					if (tmp.GetBound() <= 0)
						_tree->DeleteValue(*tmp);
					while(*first != end) {
						tmp = first;
						first++;
						val = *first;
						_tree->DeleteValue(*tmp);
						_tree->Search(val, &leaf);
						first.newp(leaf);
					}
					if (last.GetBound() < 1)
						_tree->DeleteValue(*last);
				}

				key_compare						key_comp() const {
					return ft::set<T, Compare, Alloc>::key_compare();
				}

				value_compare					value_comp() const {
					return ft::set<T, Compare, Alloc>::value_compare();
				}

				pair<iterator,iterator>	equal_range(const value_type& val) const {
					pair<iterator, iterator> bound;

					bound.first = lower_bound(val);
					bound.second = upper_bound(val);

					return bound;
				}

				iterator lower_bound(const value_type& val) const {
					iterator it = begin();
					it++;
					while (it != end()) {
						if (!_comp(*it, val)) {		//(*it >=  val) {
							if (count(val) < 1)
								it.SetBound(-1);
							return it;
						}
						it++;
					}	
					return NULL;
				}

				iterator upper_bound(const value_type& val) const {
					iterator it = begin();
					size_type i = 0;
					it++;
					while (it != end()) {
						if(!_comp(*it, val)) {
							if (++i == count(val)) {
								it++;
								it.SetBound(1);
								return it;
							}
						}
						it++;
					}
					return NULL;
				}

			private:
				Compare					_comp;
				rbt<T, Compare>			*_tree;
				
				iterator		_to_end(Node<T> *leaf) {
					if(!leaf->right)
						return leaf;
					return(_to_end(leaf->right));
				}

				const_iterator	_const_to_end(Node<T> *leaf) const {
					if(!leaf->right)
						return leaf;
					return(_const_to_end(leaf->right));
				}

				iterator		_to_begin(Node<T> *leaf) {
					if(!leaf->left || leaf->left->isEnd == true)
						return leaf;
					return(_to_begin(leaf->left));
				}

				const_iterator	_const_to_begin(Node<T> *leaf) const {
					if(leaf->left == NULL || leaf->left->isEnd == true)
						return leaf;
					return(_const_to_begin(leaf->left));
				}
			
				reverse_iterator		_to_rend(Node<T> *leaf) {
					if(!leaf->left)
						return leaf;
					return(_to_rend(leaf->left));
				}

				const_reverse_iterator	_const_to_rend(Node<T> *leaf) const {
					if(!leaf->left)
						return leaf;
					return(_const_to_rend(leaf->left));
				}
				
				reverse_iterator		_to_rbegin(Node<T> *leaf) {
					if(!leaf->right || leaf->right->isEnd == true)
						return leaf;
					return(_to_rbegin(leaf->right));
				}

				const_reverse_iterator	_const_to_rbegin(Node<T> *leaf) const {
					if(!leaf->right || leaf->right->isEnd == true)
						return leaf;
					return(_const_to_rbegin(leaf->right));
				}
	
		};

	template <typename T, class Compare, class Alloc>
		bool operator== (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
						typename ft::set<T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::set<T, Compare, Alloc>::iterator b = rhs.begin();
			if (lhs.size() != rhs.size())
				return (false);
			while (a != lhs.end() && b != rhs.end() && !a.isEnd() && !b.isEnd())
			{
				if (*a != *b)
					return (false);
				a++;
				b++;
			}
			return (true);
		}

	template <typename T, class Compare, class Alloc>
		bool operator!= (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
			typename ft::set<T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::set<T, Compare, Alloc>::iterator b = rhs.begin();
			if (lhs.size() != rhs.size())
				return (true);
			while (a != lhs.end() && b != rhs.end() && !a.isEnd() && !b.isEnd())
			{
				if (*a != *b)
					return (true);
				a++;
				b++;
			}
			return (false);
		}

	template <typename T, class Compare, class Alloc>
		bool operator>  (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
			typename ft::set<T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::set<T, Compare, Alloc>::iterator b = rhs.begin();
			while (a != lhs.end() && b != rhs.end() && !a.isEnd() && !b.isEnd())
			{
				if (*a > *b)
					return (true);
				if (*a < *b)
					return (false);
				a++;
				b++;
			}
			if (lhs.size() > rhs.size())
				return (true);
			return (false);
		}

	template <typename T, class Compare, class Alloc>
		bool operator<  (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
			typename ft::set<T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::set<T, Compare, Alloc>::iterator b = rhs.begin();
			while (a != lhs.end() && b != rhs.end() && !a.isEnd() && !b.isEnd())
			{
				if (*a < *b)
					return (true);
				if (*a > *b)
					return (false);
				a++;
				b++;
			}
			if (lhs.size() < rhs.size())
				return (true);
			return (false);
		}

	template <typename T, class Compare, class Alloc>
		bool operator>= (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
						typename ft::set<T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::set<T, Compare, Alloc>::iterator b = rhs.begin();
			while (a != lhs.end() && b != rhs.end() && !a.isEnd() && !b.isEnd())
			{
				if (*a > *b)
					return (true);
				if (*a < *b)
					return (false);
				a++;
				b++;
			}
			if (lhs.size() >= rhs.size())
				return (true);
			return (false);
		}

	template <typename T, class Compare, class Alloc>
		bool operator<= (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
						typename ft::set<T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::set<T, Compare, Alloc>::iterator b = rhs.begin();
			while (a != lhs.end() && b != rhs.end() && !a.isEnd() && !b.isEnd())
			{
				if (*a < *b)
					return (true);
				if (*a > *b)
					return (false);
				a++;
				b++;
			}
			if (lhs.size() <= rhs.size())
				return (true);
			return (false);
		}
}


#endif
