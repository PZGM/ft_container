#include "Map.hpp"

//constructor

template <typename Key, typename T,class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc) {
	_tree = new rbt<Key, T, Compare>;
}

template <typename Key, typename T,class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const ft::map<Key, T,Compare,Alloc>& x) {
	_tree = new rbt<Key, T,Compare>;
	iterator it = x.begin();
	if (x.size() > 0) {
		while (it.isEnd() == false) {			
			if (insert(*it).second == false)
				it++;
		}
	}
}

template <typename Key, typename T,class Compare, class Alloc>
template <class InputIterator>
ft::map<Key, T, Compare, Alloc>::map(InputIterator first, InputIterator last, const key_compare& comp,const  allocator_type& alloc) {
	_tree = new rbt<Key, T, Compare>;
	insert(first, last);
}

//destructor

template <typename Key, typename T,class Compare, class Alloc>
ft::map<Key, T,Compare, Alloc>::~map() {
	delete _tree;
}

//insert

template <typename Key, typename T,class Compare, class Alloc>
std::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool> ft::map<Key, T, Compare, Alloc>::insert(const key_type& id) {
	std::pair<iterator, bool> pa;
	Node<Key, T>	*node;
	if (_tree->Search(id, &node)) {	
		pa.first = node;
		pa.second = false;
	}
	else {
		_tree->insert(id);
		_tree->Search(id, &node);
		pa.first = node;
		pa.second = true;
	}
	return pa;
}

template <typename Key, typename T,class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::insert(iterator pos, const key_type & id) {
	Node<Key, T>	*node = NULL;
	_tree->Search(id, node);
	if (node)
		return &node;
	return _tree->insert(id);
}

template <typename Key, typename T,class Compare, class Alloc>
template <class InputIterator>
void ft::map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last) {
	for ( ; first != last; first++) {
		if (ft::map<Key, T, Compare, Alloc>::find(*first) == this->end())
			_tree->insert(*first);
	}
}

// erase

template <typename Key, typename T,class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::erase(iterator position) {
	_tree->DeleteValue(*position);
}

template <typename Key, typename T,class Compare, class Alloc>
typename ft::map<Key, T,Compare,Alloc>::size_type ft::map<Key, T, Compare, Alloc>::erase(const key_type & id) {
	return _tree->DeleteAllValue(id);
}

template <typename Key, typename T,class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::erase(iterator first, iterator last) {
	ft::Node<Key, T> *leaf;
	Key id;
	Key end = *last;

	iterator tmp = first;
	first++;
	if (tmp.GetBound() <= 0)
		_tree->DeleteValue(*tmp);
	while(*first != end) {
		tmp = first;
		first++;
		id = *first;
		_tree->DeleteValue(*tmp);
		_tree->Search(id, &leaf);
		first.newp(leaf);
	}
	if (last.GetBound() < 1)
		_tree->DeleteValue(*last);
}

// find

template <typename Key, typename T,class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::find(const key_type& id) const{
	Node<Key, T> *leaf = _tree->getRoot();
	if (_tree->Search(id, &leaf))
		return leaf;
	return end();
}

// size

template <typename Key, typename T,class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type  ft::map<Key, T, Compare, Alloc>::size() const{
	return _tree->getSize();
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::max_size() const
{
	return ((Alloc().max_size() -1) / 10);
}

//end

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::end() {
	if (size() == 0)
		return begin();
	return _to_end(_tree->getRoot());
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::_to_end(ft::Node<Key, T> *leaf) {
	if(!leaf->right)
		return leaf;
	return(_to_end(leaf->right));
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::end() const {	
	if (size() == 0)
		return begin();
	return _const_to_end(_tree->getRoot());
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::_const_to_end(ft::Node<Key, T> *leaf) const {
	if(!leaf->right)
		return leaf;
	return(_const_to_end(leaf->right));
}

//rend

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rend() {
	if (size() == 0)
		return rbegin();

	return _to_rend(_tree->getRoot());
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::_to_rend(ft::Node<Key, T> *leaf) {
	if(!leaf->left)
		return leaf;
	return(_to_rend(leaf->left));
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rend() const {
	if (size() == 0)
		return rbegin();
	return (_const_to_rend(_tree->getRoot));
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::_const_to_rend(ft::Node<Key, T> *leaf) const {
	if(!leaf->left)
		return leaf;
	return(_const_to_rend(leaf->left));
}

//rbegin

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rbegin() {
	return _to_rbegin(_tree->getRoot());
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::_to_rbegin(ft::Node<Key, T> *leaf) {
	if(!leaf->right || leaf->right->isEnd == true)
		return leaf;
	return(_to_rbegin(leaf->right));
}
template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rbegin() const {
	return _const_to_rbegin(_tree->getRoot());
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::_const_to_rbegin(ft::Node<Key, T> *leaf) const {
	if(!leaf->right || leaf->right->isEnd == true)
		return leaf;
	return(_const_to_rbegin(leaf->right));
}


//begin

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::begin() {
	return _to_begin(_tree->getRoot());
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::_to_begin(ft::Node<Key, T> *leaf) {
	if(!leaf->left || leaf->left->isEnd == true)
		return leaf;
	return(_to_begin(leaf->left));
}
template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::begin() const{
	return _const_to_begin(_tree->getRoot());
}

template <typename Key, typename T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::_const_to_begin(ft::Node<Key, T> *leaf) const {
	if(leaf->left == NULL || leaf->left->isEnd == true)
		return leaf;
	return(_const_to_begin(leaf->left));
}

// empty

template <typename Key, typename T,class Compare, class Alloc>
bool  ft::map<Key, T, Compare, Alloc>::empty() const{
	if (_tree->getSize() == 0)
		return true;
	return false;
}

// clear

template <typename Key, typename T,class Compare, class Alloc>
void  ft::map<Key, T, Compare, Alloc>::clear() {
	_tree->DestroyI();
}

// count

template <typename Key, typename T,class Compare, class Alloc>
typename ft::map<Key, T,Compare,Alloc>::size_type ft::map<Key, T, Compare, Alloc>::count(const key_type & id) const {
	size_t i = 0;
	iterator it  = begin();
	while (it != end()) {
		if(*it == id)
			i++;
		it++;
	}
	return i;
}
// swap

template <typename Key, typename T,class Compare, class Alloc>
void  ft::map<Key, T, Compare, Alloc>::swap(map & x) {
	rbt<Key, T, Compare>  *tmp;
	tmp  = x._tree;
	x._tree = _tree;
	_tree = tmp;
}


// upper/lower bound compare

template <typename Key, typename T,class Compare, class Alloc>
typename ft::map<Key, T,Compare,Alloc>::iterator ft::map<Key, T,Compare,Alloc>::lower_bound (const key_type& id) const {
	iterator it = begin();
	it++;
	while (it != end()) {
		if (!_comp(*it, id)) {		//(*it >=  id) {
			if (count(id) < 1)
				it.SetBound(-1);
			return it;
		}
		it++;
		}	
		return NULL;
	}

	template <typename Key, typename T,class Compare, class Alloc>
		typename ft::map<Key, T,Compare,Alloc>::iterator ft::map<Key, T,Compare,Alloc>::upper_bound (const key_type& id) const {
			iterator it = begin();
			size_type i = 0;
			it++;
			while (it != end()) {
				if(!_comp(*it, id)) {
					if (++i == count(id)) {
						it++;
						it.SetBound(1);
						return it;
					}
				}
				it++;
			}
			return NULL;
		}

	// operator=

	template <typename Key, typename T, class Compare, class Alloc>
		ft::map<Key, T,Compare, Alloc>  & ft::map<Key, T,Compare, Alloc>::operator=(const ft::map<Key, T, Compare, Alloc>& rhs) {
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

	// relational operator

	template <typename Key, typename T, class Compare, class Alloc>
		bool ft::operator== (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			typename ft::map<Key, T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key, T, Compare, Alloc>::iterator b = rhs.begin();
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


	template <typename Key, typename T, class Compare, class Alloc>
		bool ft::operator!= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			typename ft::map<Key, T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key, T, Compare, Alloc>::iterator b = rhs.begin();
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

	template <typename Key, typename T, class Compare, class Alloc>
		bool ft::operator> (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			typename ft::map<Key, T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key, T, Compare, Alloc>::iterator b = rhs.begin();
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

	template <typename Key, typename T, class Compare, class Alloc>
		bool ft::operator< (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			typename ft::map<Key, T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key, T, Compare, Alloc>::iterator b = rhs.begin();
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

	template <typename Key, typename T, class Compare, class Alloc>
		bool ft::operator>= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			typename ft::map<Key, T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key, T, Compare, Alloc>::iterator b = rhs.begin();
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

	template <typename Key, typename T, class Compare, class Alloc>
		bool ft::operator<= (const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			typename ft::map<Key, T, Compare, Alloc>::iterator a = lhs.begin();
			typename ft::map<Key, T, Compare, Alloc>::iterator b = rhs.begin();
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

	template <typename Key, typename T, class Compare, class Alloc>
		typename ft::map<Key, T, Compare, Alloc>::key_compare ft::map<Key, T, Compare, Alloc>::key_comp() const {
			return ft::map<Key, T, Compare, Alloc>::key_compare();
		}


	template <typename Key, typename T, class Compare, class Alloc>
		typename ft::map<Key, T, Compare, Alloc>::key_compare ft::map<Key, T, Compare, Alloc>::key_comp() const {
			return ft::map<Key, T, Compare, Alloc>::key_compare();
		}


	template <typename Key, typename T, class Compare, class Alloc>
		std::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator> ft::map<Key, T, Compare, Alloc>::equal_range (const Key & id) const {
			std::pair<iterator, iterator> bound;

			bound.first = lower_bound(id);
			bound.second = upper_bound(id);

			return bound;
		}
