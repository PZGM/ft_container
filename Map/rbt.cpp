/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzgm <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:22:27 by pzgm              #+#    #+#             */
/*   Updated: 2021/07/01 17:31:57 by pzgm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt.hpp"
#include "../Queue/Queue.hpp"

	template<typename Key, typename T, class Compare>
bool ft::rbt<Key, T,Compare>::Search(const Key & val, Node<Key, T> **node) const {
	Node<Key, T> *leaf = _root;
	*node = NULL;
	if ( _size == 0)
		return false;
	while (leaf && leaf->isEnd == false)
	{
		*node = leaf;
		if (leaf->val == val)
			return true;
		if (!_comp(leaf->val,val))
			leaf = leaf->left;
		else
			leaf = leaf->right;
	}
	return false;
}

	template<typename Key, typename T, class Compare>
bool ft::rbt<Key, T,Compare>::insert(const Key & val) {
	Node<Key, T> *parent = NULL;
	Node<Key, T> *newNode = new Node<Key, T>(val);
	Search(val, &parent);
	if(parent == NULL || _size == 0) {
		_root->color = BLACK;
		_root->val = val;
		delete newNode;
		_size++;
		return true;
	}
	if(parent->val == val) {  //enlever ce if pour multi
		delete newNode;
		return false;
	}
	if(_end->parent)
		_end->parent->right = NULL;
	if(_rend->parent)
		_rend->parent->left = NULL;
	if(_comp(val, parent->val))   //compare
		parent->left = newNode;
	else
		parent->right = newNode;
	newNode->parent = parent;
	_InsertBalance(newNode);
	_size++;
	_end->parent = max_node();
	_rend->parent = min_node();
	_end->val = _root->val;
	_rend->val = _root->val;
	_end->parent->right = _end;
	_rend->parent->left = _rend;
	return true;
}

	template<typename Key, typename T, class Compare>
void ft::rbt<Key, T,Compare>::_InsertBalance(Node<Key, T> *node) {
	Node<Key, T> *parent = node->parent;
	Node<Key, T> *grandParent = NULL;
	while(parent && parent->color == RED)
	{
		grandParent = parent->parent;
		if(parent == grandParent->left) {
			Node<Key, T> *uncle = grandParent->right;
			if(uncle && uncle->color == RED)
			{
				parent->color = BLACK;
				uncle->color  = BLACK;
				grandParent->color = RED;
				node = grandParent;
				parent = grandParent->parent;
			}
			else
			{
				if(node == parent->right) {
					node = _left_rotation(parent);
					parent = node->parent;
					grandParent = parent->parent;
				}
				parent->color = BLACK;
				grandParent->color = RED;
				_right_rotation(grandParent);
			}
		}
		else {
			Node<Key, T> *uncle = grandParent->left;
			if(uncle && uncle->color == RED)
			{
				uncle->color = BLACK;
				parent->color = BLACK;
				grandParent->color = RED;
				node = grandParent;
				parent = node->parent;
			}
			else
			{
				if(node == parent->left)
				{
					node = _right_rotation(parent);
					parent = node->parent;
					grandParent = parent->parent;
				}
				parent->color = BLACK;
				grandParent->color = RED;
				_left_rotation(grandParent);
			}
		}
	}
	_root->color = BLACK;
	_root->parent = NULL;
}

	template<typename Key, typename T, class Compare>
ft::Node<Key, T> *ft::rbt<Key, T,Compare>::_left_rotation(Node<Key, T> *leaf) {
	Node<Key, T> *y = leaf->right;
	if(y == NULL)
		return leaf;
	leaf->right = y->left;
	if(y->left)
		y->left->parent = leaf;
	if(_root == leaf)
		_root = y;
	else
	{
		if(leaf == leaf->parent->left)
			leaf->parent->left = y;
		else
			leaf->parent->right = y;
		y->parent = leaf->parent;
	}
	y->left = leaf;
	leaf->parent = y;
	return leaf;
}

	template<typename Key, typename T, class Compare>
ft::Node<Key, T>* ft::rbt<Key, T,Compare>::_right_rotation(Node<Key, T> *leaf) {
	Node<Key, T> *y = leaf->left;
	if(y == NULL)
		return leaf;
	leaf->left = y->right;
	if(y->right)
		y->right->parent = leaf;
	if(_root == leaf)
		_root = y;
	else
	{
		if(leaf == leaf->parent->left)
			leaf->parent->left = y;
		else
			leaf->parent->right = y;
		y->parent = leaf->parent;
	}
	y->right = leaf;
	leaf->parent = y;
	return leaf;
}

	template<typename Key, typename T, class Compare>
void ft::rbt<Key, T,Compare>::Destroy(Node<Key, T> *leaf, int i) {
	if(leaf->left)
		Destroy(leaf->left, i + 1);
	if(leaf->right)
		Destroy(leaf->right, i + 1);
	delete leaf;
}


	template<typename Key, typename T, class Compare>
size_t ft::rbt<Key, T,Compare>::DeleteAllValue(const Key &val) {
	size_t i = 0;
	Node<Key, T> *leaf = NULL;
	while(Search(val, &leaf)) {
		DeleteValue(val);
		i++;
	}
	return i;
}

	template<typename Key, typename T, class Compare>
void ft::rbt<Key, T,Compare>::DeleteValue(const Key &val)
{
	Node<Key, T>		*leaf = NULL;
	Node<Key, T>		*nextNode = NULL;
	if(Search(val,&leaf)) {
		if(leaf->left && leaf->right)
		{
			Node<Key, T> *tmpNode = leaf->right;
			while(tmpNode) {
				nextNode = tmpNode;
				tmpNode = tmpNode->left;
			}
			leaf->val = nextNode->val;
			leaf = nextNode;
		}
		if(leaf->left)
		{
			Node<Key, T> *tmp = leaf->left;
			leaf->val = tmp->val;
			leaf->left = NULL;
			delete tmp;
		}
		else if(leaf->right)
		{
			Node<Key, T> *tmp = leaf->right;
			leaf->val = tmp->val;
			leaf->right = NULL;
			delete tmp;
		}
		else
		{
			if(_end->parent)
				_end->parent->right = NULL;
			if(_rend->parent)
				_rend->parent->left = NULL;
			_DeleteBalance(leaf);
			_end->parent = max_node();
			_rend->parent = min_node();
			_end->val = _root->val;
			_rend->val = _root->val;
			_end->parent->right = _end;
			_rend->parent->left = _rend;
			if(leaf == _root)
				_root = NULL;
			else if(leaf==leaf->parent->left)
				leaf->parent->left = NULL;
			else if(leaf==leaf->parent->right)
				leaf->parent->right = NULL;
			delete leaf;
		}
		_size--;
	}
}

	template<typename Key, typename T, class Compare>
void ft::rbt<Key, T,Compare>::_DeleteBalance(Node<Key, T> *node)
{
	Node<Key, T> *parent = NULL;
	Node<Key, T> *other = NULL;
	while(node->color == BLACK && node->parent)
	{
		parent = node->parent;
		if(node == parent->left)
		{
			other = parent->right;
			if(other->color == RED) {
				parent->color = RED;
				other->color = BLACK;
				_left_rotation(parent);
				other = parent->right;
			}
			if( (other->left == NULL || other->left->color == BLACK)
					&& (other->right == NULL || other->left->color == BLACK)) {
				other->color = RED;
				node = parent;
				continue;
			}
			if( other->right == NULL || other->right->color == BLACK) {
				other->left->color = BLACK;
				other->color = RED;
				_right_rotation(other);
				other = parent->right;
			}
			other->right->color = BLACK;
			other->color = parent->color;
			parent->color = BLACK;
			_left_rotation(parent);
			break;
		}
		else
		{
			other = parent->left;
			if(other->color == RED) {
				parent->color = RED;
				other->color = BLACK;
				_right_rotation(parent);
				other = parent->left;
			}
			if( (other->left == NULL || other->left->color==BLACK)
					&& (other->right == NULL || other->left->color == BLACK)) {
				other->color = RED;
				node = parent;
				continue;
			}
			if( other->left == NULL || other->left->color == BLACK) {
				other->right->color = BLACK;
				other->color = RED;
				_left_rotation(other);
				other = parent->left;
			}
			other->left->color = BLACK;
			other->color = parent->color;
			parent->color = BLACK;
			_right_rotation(parent);
			break;
		}
	}
	node->color = BLACK;
	_root->parent = NULL;
}

template<typename Key, typename T, class Compare>
ft::Node<Key, T>* ft::rbt<Key, T,Compare>::max_node() {
	Node<Key, T> *leaf = _root;
	while(leaf->right && leaf->right->isEnd == false)
		leaf = leaf->right;
	return leaf;
}

template<typename Key, typename T, class Compare>
ft::Node<Key, T>* ft::rbt<Key, T,Compare>::min_node() {
	Node<Key, T> *leaf = _root;
	while(leaf->left && leaf->left->isEnd == false)
		leaf = leaf->left;
		return leaf;
}

template<typename Key, typename T, class Compare>
ft::Node<Key, T>* ft::rbt<Key, T,Compare>::max_node() const {
	Node<Key, T> *leaf = _root;
	while(leaf->right && leaf->right->isEnd == false)
		leaf = leaf->right;
	return leaf;
}

template<typename Key, typename T, class Compare>
ft::Node<Key, T>* ft::rbt<Key, T,Compare>::min_node() const {
	Node<Key, T> *leaf = _root;
	while(leaf->left && leaf->left->isEnd == false)
		leaf = leaf->left;
		return leaf;
}


// operator=

template <typename Key, typename T, class Compare>
ft::rbt<Key, T, Compare>  & ft::rbt<Key, T, Compare>::operator=(const rbt<Key, T, Compare> & src) {
	if (_size > 0)
		Destroy(_root, 0);
	if (src._size == 0) {
		return *this;
	}

	Node<Key, T> *leaf = src.min_node();
	while (leaf != src.max_node()) {
		insert(leaf->val);
			if (leaf->right) {
					leaf = leaf->right;
					while (leaf->left)
						leaf = leaf->left;
				}
				else { 
					while (leaf->parent && leaf == leaf->parent->right) //when root parent null
						leaf = leaf->parent;
					leaf = leaf->parent;
				}
	}
	insert(leaf->val);
	return *this;
}

