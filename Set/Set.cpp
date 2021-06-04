#include "Set.hpp"

//constructor

template <typename T,class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc) : _size(0) {
}


template <typename T,class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const ft::set<T,Compare,Alloc>& x) : _size(0) {
	insert(x.first(), x.last());
}

template <typename T,class Compare, class Alloc>
template <class InputIterator>
ft::set<T, Compare, Alloc>::set(InputIterator first, InputIterator last, const key_compare& comp,const  allocator_type& alloc) : _size(0){
	insert(first, last);
}

//destructor

template <typename T,class Compare, class Alloc>
ft::set<T,Compare, Alloc>::~set() {
}

//insert

template <typename T,class Compare, class Alloc>
std::pair<typename ft::set<T, Compare, Alloc>::iterator, bool> ft::set<T, Compare, Alloc>::insert(const value_type& val) {
	if (_tree.getRoot())
	std::cout << "ivgx|" << _tree.getRoot()->val << std::endl;
	std::pair<iterator, bool> pa;
	Node<T>	*node;
	if (_tree.Search(val, &node)) {	
		std::cout << "false " << std::endl;
		pa.first = node;
		pa.second = false;
	}
	else {
		std::cout << "true : ";
		_tree.insert(val);
		std::cout << "yoyoy " << std::endl;
		_tree.Search(val, &node);
		std::cout << "node = " << node->val << "|" << _tree.getRoot()->val << std::endl;
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
	std::cout << " POPOPOPO " << std::endl;
	return _tree.insert(val);
}

template <typename T,class Compare, class Alloc>
template <class InputIterator>
void ft::set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last) {
	for ( ; first != last; first++) {
		std::cout << "HAHAHAHAHAHA " << std::endl;
		if (ft::set<T, Compare, Alloc>::find(*first) == this->end())
			_tree.insert(*first);
	}
}

// find

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::find(const value_type& val) const{
	return (_tree.Search(val, _tree.getRoot));
}

//begin

	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::begin()
{
	return (_to_begin(_tree.getRoot()));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_begin(ft::Node<T> *leaf) {
	if(!leaf->left)
		return leaf;
	return(_to_begin(leaf->left));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::begin() const
{
	return (ft::set<T, Compare, Alloc>::_to_begin(_tree.getRoot));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_to_begin(ft::Node<T> *leaf) const {
	if(!leaf->left)
		return leaf;
	return(_const_to_begin(leaf->left));
}

//end + 1 (= size?)

	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::end()
{
	return (_to_end(_tree.getRoot()));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_end(ft::Node<T> *leaf) {
	if(!leaf->right)
		return leaf;
	return(_to_end(leaf->right));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::end() const
{
	return (_to_end(_tree.getRoot));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_to_end(ft::Node<T> *leaf) const {
	if(!leaf->right)
		return leaf;
	return(_const_to_end(leaf->right));
}

