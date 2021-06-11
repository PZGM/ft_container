#include "Set.hpp"

//constructor

template <typename T,class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc) {
}


template <typename T,class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const ft::set<T,Compare,Alloc>& x) {
	insert(x.first(), x.last());
}

template <typename T,class Compare, class Alloc>
template <class InputIterator>
ft::set<T, Compare, Alloc>::set(InputIterator first, InputIterator last, const key_compare& comp,const  allocator_type& alloc) {
	insert(first, last);
}

//destructor

template <typename T,class Compare, class Alloc>
ft::set<T,Compare, Alloc>::~set() {
}

//insert

template <typename T,class Compare, class Alloc>
std::pair<typename ft::set<T, Compare, Alloc>::iterator, bool> ft::set<T, Compare, Alloc>::insert(const value_type& val) {
	std::pair<iterator, bool> pa;
	Node<T>	*node;
	if (_tree.Search(val, &node)) {	
		pa.first = node;
		pa.second = false;
	}
	else {
		_tree.insert(val);
		_tree.Search(val, &node);
		pa.first = node;
		pa.second = true;
	}
	return pa;
}

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::insert(iterator pos, const value_type & val) {
	Node<T>	*node = NULL;
	_tree.Search(val, node);
	if (node)
		return &node;
	return _tree.insert(val);
}

template <typename T,class Compare, class Alloc>
template <class InputIterator>
void ft::set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last) {
	for ( ; first != last; first++) {
		if (ft::set<T, Compare, Alloc>::find(*first) == this->end())
			_tree.insert(*first);
	}
}

// find

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::find(const value_type& val) const{
	return (_tree.Search(val, _tree.getRoot));
}

// size

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type  ft::set<T, Compare, Alloc>::size() const{
	return _tree.getSize();
}


//end

	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::end() {
	return _to_end(_tree.getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_end(ft::Node<T> *leaf) {
	if(!leaf->right)
		return leaf;
	return(_to_end(leaf->right));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::end() const {
	return (_to_end(_tree.getRoot));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_to_end(ft::Node<T> *leaf) const {
	if(!leaf->right)
		return leaf;
	return(_const_to_end(leaf->right));
}

//rend

	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator ft::set<T, Compare, Alloc>::rend() {
	return _to_rend(_tree.getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator ft::set<T, Compare, Alloc>::_to_rend(ft::Node<T> *leaf) {
	if(!leaf->left)
		return leaf;
	return(_to_end(leaf->left));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator ft::set<T, Compare, Alloc>::rend() const {
	return (_to_rend(_tree.getRoot));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator ft::set<T, Compare, Alloc>::_to_rend(ft::Node<T> *leaf) const {
	if(!leaf->left)
		return leaf;
	return(_const_to_rend(leaf->left));
}

//rbegin

	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator ft::set<T, Compare, Alloc>::rbegin() {
	return _to_rbegin(_tree.getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator ft::set<T, Compare, Alloc>::_to_rbegin(ft::Node<T> *leaf) {
	if(!leaf->right || leaf->right->isEnd == true)
		return leaf;
	return(_to_rbegin(leaf->right));
}
	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator ft::set<T, Compare, Alloc>::rbegin() const {
	return _to_rbegin(_tree.getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator ft::set<T, Compare, Alloc>::_to_rbegin(ft::Node<T> *leaf) const {
	if(!leaf->right || leaf->right->isEnd == true)
		return leaf;
	return(_to_rbegin(leaf->right));
}


//begin

	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::begin() {
	return _to_begin(_tree.getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_begin(ft::Node<T> *leaf) {
	if(!leaf->left || leaf->left->isEnd == true)
		return leaf;
	return(_to_begin(leaf->left));
}
	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::begin() const{
	return _to_begin(_tree.getRoot());
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_to_begin(ft::Node<T> *leaf) const {
	if(!leaf->left || leaf->left->isEnd == true)
		return leaf;
	return(_to_begin(leaf->left));
}

