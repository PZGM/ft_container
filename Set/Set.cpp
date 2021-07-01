#include "Set.hpp"

//constructor

template <typename T,class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc) {
	_tree = new rbt<T, Compare>;
}


template <typename T,class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const ft::set<T,Compare,Alloc>& x) {
	_tree = new rbt<T,Compare>;
	iterator it = x.begin();
	if (x.size() > 0) {
		while (it.isEnd() == false) {			
		if (insert(*it).second == false)
			it++;
		}
	}
}

template <typename T,class Compare, class Alloc>
template <class InputIterator>
ft::set<T, Compare, Alloc>::set(InputIterator first, InputIterator last, const key_compare& comp,const  allocator_type& alloc) {
	_tree = new rbt<T, Compare>;
	insert(first, last);
}

//destructor

template <typename T,class Compare, class Alloc>
ft::set<T,Compare, Alloc>::~set() {
	delete _tree;
}

//insert

template <typename T,class Compare, class Alloc>
std::pair<typename ft::set<T, Compare, Alloc>::iterator, bool> ft::set<T, Compare, Alloc>::insert(const value_type& val) {
	std::pair<iterator, bool> pa;
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

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::insert(iterator pos, const value_type & val) {
	Node<T>	*node = NULL;
	_tree->Search(val, node);
	if (node)
		return &node;
	return _tree->insert(val);
}

template <typename T,class Compare, class Alloc>
template <class InputIterator>
void ft::set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last) {
	for ( ; first != last; first++) {
		if (ft::set<T, Compare, Alloc>::find(*first) == this->end())
			_tree->insert(*first);
	}
}

// erase

template <typename T,class Compare, class Alloc>
void ft::set<T, Compare, Alloc>::erase(iterator position) {
	_tree->DeleteValue(*position);
}

template <typename T,class Compare, class Alloc>
typename ft::set<T,Compare,Alloc>::size_type ft::set<T, Compare, Alloc>::erase(const value_type & val) {
	return _tree->DeleteAllValue(val);
}

template <typename T,class Compare, class Alloc>
void ft::set<T, Compare, Alloc>::erase(iterator first, iterator last) {
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

// find

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::find(const value_type& val) const{
	Node<T> *leaf = _tree->getRoot();
	if (_tree->Search(val, &leaf))
		return leaf;
	return end();
}

// size

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type  ft::set<T, Compare, Alloc>::size() const{
	return _tree->getSize();
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type ft::set<T, Compare, Alloc>::max_size() const
{
	size_type max = 0;
	max--;
	return (max);
}

//end

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::end() {
	if (size() == 0)
		return begin();
	return _to_end(_tree->getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_end(ft::Node<T> *leaf) {
	if(!leaf->right)
		return leaf;
	return(_to_end(leaf->right));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::end() const {	
	if (size() == 0)
		return begin();
	return _const_to_end(_tree->getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_const_to_end(ft::Node<T> *leaf) const {
	if(!leaf->right)
		return leaf;
	return(_const_to_end(leaf->right));
}

//rend

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator ft::set<T, Compare, Alloc>::rend() {
	if (size() == 0)
		return rbegin();

	return _to_rend(_tree->getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator ft::set<T, Compare, Alloc>::_to_rend(ft::Node<T> *leaf) {
	if(!leaf->left)
		return leaf;
	return(_to_rend(leaf->left));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator ft::set<T, Compare, Alloc>::rend() const {
	if (size() == 0)
		return rbegin();
	return (_const_to_rend(_tree->getRoot));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator ft::set<T, Compare, Alloc>::_const_to_rend(ft::Node<T> *leaf) const {
	if(!leaf->left)
		return leaf;
	return(_const_to_rend(leaf->left));
}

//rbegin

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator ft::set<T, Compare, Alloc>::rbegin() {
	return _to_rbegin(_tree->getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator ft::set<T, Compare, Alloc>::_to_rbegin(ft::Node<T> *leaf) {
	if(!leaf->right || leaf->right->isEnd == true)
		return leaf;
	return(_to_rbegin(leaf->right));
}
template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator ft::set<T, Compare, Alloc>::rbegin() const {
	return _const_to_rbegin(_tree->getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator ft::set<T, Compare, Alloc>::_const_to_rbegin(ft::Node<T> *leaf) const {
	if(!leaf->right || leaf->right->isEnd == true)
		return leaf;
	return(_const_to_rbegin(leaf->right));
}


//begin

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::begin() {
	return _to_begin(_tree->getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_begin(ft::Node<T> *leaf) {
	if(!leaf->left || leaf->left->isEnd == true)
		return leaf;
	return(_to_begin(leaf->left));
}
template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::begin() const{
	return _const_to_begin(_tree->getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_const_to_begin(ft::Node<T> *leaf) const {
	if(leaf->left == NULL || leaf->left->isEnd == true)
		return leaf;
	return(_const_to_begin(leaf->left));
}

// empty

template <typename T,class Compare, class Alloc>
bool  ft::set<T, Compare, Alloc>::empty() const{
	if (_tree->getSize() == 0)
		return true;
	return false;
}

// clear

template <typename T,class Compare, class Alloc>
void  ft::set<T, Compare, Alloc>::clear() {
	_tree->DestroyI();
}

// count

template <typename T,class Compare, class Alloc>
typename ft::set<T,Compare,Alloc>::size_type ft::set<T, Compare, Alloc>::count(const value_type & val) const {
	size_t i = 0;
	iterator it  = begin();
	while (it != end()) {
		if(*it == val)
			i++;
		it++;
	}
	return i;
}
// swap

template <typename T,class Compare, class Alloc>
void  ft::set<T, Compare, Alloc>::swap(set & x) {
	rbt<T, Compare>  *tmp;
	tmp  = x._tree;
	x._tree = _tree;
	_tree = x._tree;
}


// upper/lower bound compare

template <typename T,class Compare, class Alloc>
typename ft::set<T,Compare,Alloc>::iterator ft::set<T,Compare,Alloc>::lower_bound (const value_type& val) const {
	iterator it = begin();
	it++;
	while (it != end()) {
		if (!_comp(*it, val)) {		//(*it >=  val) {
			it.SetBound(-1);
			return it;
		}
		it++;
		}	
		return NULL;
	}

	template <typename T,class Compare, class Alloc>
		typename ft::set<T,Compare,Alloc>::iterator ft::set<T,Compare,Alloc>::upper_bound (const value_type& val) const {
			iterator it = begin();
			it++;
			while (it != end()) {
				if(!_comp(*it, val)) {
					it++;
					it.SetBound(1);
					return it;
				}
				it++;
			}
			return NULL;
		}

	// operator

	template <typename T, class Compare, class Alloc>
		ft::set<T,Compare, Alloc>  & ft::set<T,Compare, Alloc>::operator=(const ft::set<T, Compare, Alloc>& rhs) {
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
			this->_tree = rhs._tree;
			return *this;
		}

	// relational operator

	template <typename T, class Compare, class Alloc>
		bool ft::operator== (const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
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
		bool ft::operator!= (const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
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
		bool ft::operator> (const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
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
		bool ft::operator< (const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
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
		bool ft::operator>= (const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
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
		bool ft::operator<= (const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
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

	// comparateur

	template <typename T, class Compare, class Alloc>
		typename ft::set<T, Compare, Alloc>::key_compare ft::set<T, Compare, Alloc>::key_comp() const {
			return ft::set<T, Compare, Alloc>::key_compare();
		}


	template <typename T, class Compare, class Alloc>
		typename ft::set<T, Compare, Alloc>::value_compare ft::set<T, Compare, Alloc>::value_comp() const {
			return ft::set<T, Compare, Alloc>::value_compare();
		}


	template <typename T, class Compare, class Alloc>
		std::pair<typename ft::set<T, Compare, Alloc>::iterator, typename ft::set<T, Compare, Alloc>::iterator> ft::set<T, Compare, Alloc>::equal_range (const T & val) const {
			std::pair<iterator, iterator> bound;

			bound.first = lower_bound(val);
			bound.second = upper_bound(val);

			return bound;
		}
