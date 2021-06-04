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
	_destroy_set(_root);
}

// destroy tree

template <typename T,class Compare, class Alloc>
void ft::set<T, Compare, Alloc>::_destroy_set(ft::Node<T> *leaf) {
	if (leaf != NULL) {
		_destroy_set(leaf->left);
		_destroy_set(leaf->right);
		delete leaf;
	}
}

//insert

template <typename T,class Compare, class Alloc>
std::pair<typename ft::set<T, Compare, Alloc>::iterator, bool> ft::set<T, Compare, Alloc>::insert(const value_type& val) {
	std::pair<set<T, Compare, Alloc>::iterator, bool> pa; 
	if (ft::set<T, Compare, Alloc>::find(val) != this->end()) {
		pa.first = ft::set<T, Compare, Alloc>::find(val);
		pa.second = false;
	}
	else {
		pa.first = _tree.insert(val);
		pa.second = true;
	}
	return pa;
}

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::insert(iterator pos, const value_type& val) {
	if (ft::set<T, Compare, Alloc>::find(val) != this->end())
		return ft::set<T, Compare, Alloc>::_find(val, pos);
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


//private insert

template <typename T,class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_insert(const value_type& val, ft::Node<T> *leaf) {

	if( leaf == NULL) {
		leaf = new ft::Node<T>;
		leaf->val = val;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->color = RED;
		_size++;
		_insertBalance(leaf);
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
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_find(const value_type& val, ft::Node<T> *leaf) const {
	if (leaf) {
		if (val == leaf->val)
			return leaf;
		if (Compare(val, leaf->val))
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
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_begin(ft::Node<T> *leaf) {
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
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_to_begin(ft::Node<T> *leaf) const {
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
typename ft::set<T, Compare, Alloc>::iterator ft::set<T, Compare, Alloc>::_to_end(ft::Node<T> *leaf) {
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
typename ft::set<T, Compare, Alloc>::const_iterator ft::set<T, Compare, Alloc>::_to_end(ft::Node<T> *leaf) const {
	if(!leaf || !leaf->right)
		return leaf;
	return(_const_to_end(leaf->right));
}

//private rbt

// For balancing the tree after deletion
template <typename T,class Compare, class Alloc>
void ft::set<T,Compare, Alloc>::_deleteBalance(Node<T> x) {
	Node<T> tmp;
	while (x != _root && x->color == BLACK) {
		if (x == x->parent->left) {
			tmp = x->parent->right;
			if (tmp->color == RED) {
				tmp->color = BLACK;
				x->parent->color = RED;
				_leftRotate(x->parent);
				tmp = x->parent->right;
			}

			if (tmp->left->color == BLACK && tmp->right->color == BLACK) {
				tmp->color = RED;
				x = x->parent;
			}
			else {
				if (tmp->right->color == BLACK) {
					tmp->left->color = BLACK;
					tmp->color = RED;
					_rightRotate(tmp);
					tmp = x->parent->right;
				}

				tmp->color = x->parent->color;
				x->parent->color = BLACK;
				tmp->right->color = BLACK;
				_leftRotate(x->parent);
				x = _root;
			}
		}
		else {
			tmp = x->parent->left;
			if (tmp->color == RED) {
				tmp->color = BLACK;
				x->parent->color = RED;
				_rightRotate(x->parent);
				tmp = x->parent->left;
			}

			if (tmp->right->color == BLACK && tmp->right->color == BLACK) {
				tmp->color = RED;
				x = x->parent;
			}
			else {
				if (tmp->left->color == BLACK) {
					tmp->right->color = BLACK;
					tmp->color = RED;
					_leftRotate(tmp);
					tmp = x->parent->left;
				}

				tmp->color = x->parent->color;
				x->parent->color = BLACK;
				tmp->left->color = BLACK;
				_rightRotate(x->parent);
				x = _root;
			}
		}
	}
	x->color = BLACK;
}

template <typename T,class Compare, class Alloc>
void ft::set<T,Compare, Alloc>::_rbTransplant(Node<T> u, Node<T> v) {
	if (u->parent == NULL)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

template <typename T,class Compare, class Alloc>
void ft::set<T,Compare, Alloc>::_deleteNodeRec(Node<T> leaf, T val) {
	Node<T> z = NULL;
	Node<T> x;
	Node<T> y;
	while (leaf != NULL) {
		if (leaf->data == val) {
			z = leaf;
		}

		if (leaf->data <= val) {
			leaf = leaf->right;
		} else {
			leaf = leaf->left;
		}
	}

	if (z == NULL) {
		std::cout << "Value not found in the tree" << std::endl;
		return;
	}

	y = z;
	COLOR y_color = y->color;
	if (z->left == NULL) {
		x = z->right;
		_rbTransplant(z, z->right);
	}
	else if (z->right == NULL) {
		x = z->left;
		_rbTransplant(z, z->left);
	}
	else {
		y = _minimum(z->right);
		y_color = y->color;
		x = y->right;
		if (y->parent == z)
			x->parent = y;
		 else {
			_rbTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		_rbTransplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	delete z;
	if (y_color == BLACK) {
		_deleteBalance(x);
	}
}

// For balancing the tree after insertion
template <typename T,class Compare, class Alloc>
void ft::set<T,Compare, Alloc>::_insertBalance(Node<T> x) {
	Node<T> tmp;
	while (x->parent->color == RED) {
		if (x->parent == x->parent->parent->right) {
			tmp = x->parent->parent->left;
			if (tmp->color == RED) {
				tmp->color = BLACK;
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else {
				if (x == x->parent->left) {
					x = x->parent;
					_rightRotate(x);
				}
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				_leftRotate(x->parent->parent);
			}
		}
		else {
			tmp = x->parent->parent->right;

			if (tmp->color == RED) {
				tmp->color = BLACK;
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else {
				if (x == x->parent->right) {
					x = x->parent;
					_leftRotate(x);
				}
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				_rightRotate(x->parent->parent);
			}
		}
		if (x == _root) {
			break;
		}
	}
	_root->color = BLACK;
}

template <typename T,class Compare, class Alloc>
ft::Node<T> ft::set<T,Compare, Alloc>::_minimum(Node<T> leaf) {
	while (leaf->left != NULL)
		leaf = leaf->left;
	return leaf;
}

template <typename T,class Compare, class Alloc>
ft::Node<T> ft::set<T,Compare, Alloc>::_maximum(Node<T> leaf) {
	while (leaf->right != NULL)
		leaf = leaf->right;
	return leaf;
}

template <typename T,class Compare, class Alloc>
ft::Node<T> ft::set<T,Compare, Alloc>::_successor(Node<T> x) {
	Node<T> y;
	if (x->right != NULL)
		return _minimum(x->right);
	y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

template <typename T,class Compare, class Alloc>
ft::Node<T> ft::set<T,Compare, Alloc>::_predecessor(Node<T> x) {
	Node<T> y;
	if (x->left != NULL)
		return _maximum(x->left);
	y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = y->parent;
	}
	return y;
}

template <typename T,class Compare, class Alloc>
void ft::set<T,Compare, Alloc>::_leftRotate(Node<T> x) {
	Node<T> y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		_root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

template <typename T,class Compare, class Alloc>
void ft::set<T,Compare, Alloc>::_rightRotate(Node<T> x) {
	Node<T> y = x->left;
	x->left = y->right;
	if (y->right != NULL)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		_root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
}

// Inserting a leaf
/*
template <typename T,class Compare, class Alloc>
void ft::set<T,Compare, Alloc>::_insert(T val) {
	Node<T> leaf = new Node<T>;
	leaf->parent = NULL;
	leaf->val = val;
	leaf->left = NULL;
	leaf->right = NULL;
	leaf->color = RED;

	Node<T> y = NULL;
	Node<T> x = _root;
	while (x != NULL) {
		y = x;
		if (leaf->val < x->val) //COMPARE
			x = x->left;
		else
			x = x->right;
	}
	leaf->parent = y;
	if (y == NULL)
		_root = leaf;
	else if (leaf->data < y->data)
		y->left = leaf;
	else
		y->right = leaf;
	if (leaf->parent == NULL) {
		leaf->color = BLACK;
		return;
	}
	if (leaf->parent->parent == NULL)
		return;
	_insertBalance(leaf);
}
*/
template <typename T,class Compare, class Alloc>
void ft::set<T,Compare, Alloc>::_deleteNode(T val) {
	deleteNodeRec(_root, val);
}

