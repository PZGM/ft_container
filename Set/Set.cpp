#include "Set.hpp"

//constructor

template <typename T,class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc) : _size(0) {
	_root = NULL;
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
	_destroy_set(_root);
}

// destroy tree

template <typename T,class Compare, class Alloc>
void ft::set<T, Compare, Alloc>::_destroy_set(ft::elem<T> *leaf) {
	if (leaf != NULL) {
		_destroy_set(leaf->left);
		_destroy_set(leaf->right);
		delete leaf;
	}
}

//insert

template <typename T,class Compare, class Alloc>
std::pair<typename ft::set<T, Compare, Alloc>::iterator, bool> ft::set<T, Compare, Alloc>::insert(const value_type& val) {
	std::pair<iterator, bool> pa; 
	if (ft::set<T, Compare, Alloc>::find(val) != this->end()) {
		pa.first = ft::set<T, Compare, Alloc>::find(val);
		pa.second = false;
	}
	else {
		pa.first = _insert(val, _root);
		pa.second = true;
	}
	return pa;
}

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::insert(iterator pos, const value_type& val) {
	if (ft::set<T, Compare, Alloc>::find(val) != this->end())
		return ft::set<T, Compare, Alloc>::_find(val, pos);
	return _insert(val, pos);
}


template <typename T,class Compare, class Alloc>
template <class InputIterator>
void ft::set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last) {
	for ( ; first != last; first++) {
		if (ft::set<T, Compare, Alloc>::find(*first) == this->end())
			_insert(*first, _root);
	}
}


//private insert

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_insert(const value_type& val, ft::elem<T> *leaf) {

	if( leaf == NULL) {
		leaf = new ft::elem<T>;
		leaf->content = val;
		leaf->left = NULL;
		leaf->right = NULL;
		_size++;
	}
	else {
		if (Compare(val, leaf))
			return(_insert(val, leaf->left));
		else
			return(_insert(val, leaf->right));
	}
	return leaf;
}

// find

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::find(const value_type& val) const{
	return (_find(val, _root));
}

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_find(const value_type& val, ft::elem<T> *leaf) const {
	if (leaf) {
		if (val == leaf->content)
			return leaf;
		if (Compare(val, leaf->content))
			return _find(val, leaf->left);
		else
			return _find(val, leaf->right);
	}
	return leaf;
}



//begin

	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::begin()
{
	return (ft::set<T, Alloc>::_to_begin(_root));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_begin(ft::elem<T> *leaf) {
	if(!leaf || leaf->left)
		return leaf;
	return(_to_begin(leaf->left));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::begin() const
{
	return (ft::set<T, Compare, Alloc>::_to_begin(_root));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_to_begin(ft::elem<T> *leaf) const {
	if(!leaf || !leaf->left)
		return leaf;
	return(_const_to_begin(leaf->left));
}

//end

	template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::end()
{
	return (ft::set<T, Alloc>::_to_end(_root));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_end(ft::elem<T> *leaf) {
	if(!leaf || !leaf->right)
		return leaf;
	return(_to_end(leaf->right));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::end() const
{
	return (ft::set<T, Compare, Alloc>::_to_end(_root));
}

template <typename T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_to_end(ft::elem<T> *leaf) const {
	if(!leaf || !leaf->right)
		return leaf;
	return(_const_to_end(leaf->right));
}


