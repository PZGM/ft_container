/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzgm <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:22:27 by pzgm              #+#    #+#             */
/*   Updated: 2021/06/10 15:41:17 by pzgm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt.hpp"
#include "../Queue/Queue.hpp"

	template<typename T>
void ft::rbt<T>::print()
{
	Node<T> *node;
	ft::queue<Node<T> *> q;
	q.push(_root);
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		if(node->left)
		{
			std::cout<< "left: " << node->left->val << " ->color: " << ((node->left->color == RED) ? "RED" : "BLACK" ) << " ";
			q.push(node->left);
		}
		if(node->right)
		{
			std::cout<< "right: " <<node->right->val<< " ->color: " <<  ((node->left->color == RED) ? "RED" : "BLACK") << " ";
			q.push(node->right);
		}
		std::cout<<std::endl<<std::endl;
	}
}

	template<typename T>
bool ft::rbt<T>::Search(const T & val, Node<T> **node)
{
	Node<T> *leaf = _root;
	*node = NULL;
	while (leaf)
	{
		*node = leaf;
		if (leaf->val == val)
			return true;
		if (leaf->val > val)
			leaf = leaf->left;
		else
			leaf = leaf->right;
	}
	return false;
}

	template<typename T>
bool ft::rbt<T>::insert(const T & val)
{
	Node<T> *parent = NULL;
	Node<T> *newNode = new Node<T>(val);
	Search(val, &parent);
	if(parent == NULL) {
		_root = newNode;
		_root->color = BLACK;
		_size++;
		return true;
	}
	if(parent->val == val) {  //enlever ce if pour multi
		delete newNode;
		return false;
	}
	if(_end->parent)
		_end->parent->right = NULL;
	if(val < parent->val)   //compare
		parent->left = newNode;
	else
		parent->right = newNode;
	newNode->parent = parent;
	_InsertBalance(newNode);
	_size++;
	_end->parent = max_node();
	_end->val = _root->val;
	_end->parent->right = _end;
	return true;
}

	template<typename T>
void ft::rbt<T>::_InsertBalance(Node<T> *node)
{
	Node<T> *parent = node->parent;
	Node<T> *grandParent = NULL;
	while(parent && parent->color == RED)
	{
		grandParent = parent->parent;
		if(parent == grandParent->left) {
			Node<T> *uncle = grandParent->right;
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
			Node<T> *uncle = grandParent->left;
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

	template<typename T>
ft::Node<T> *ft::rbt<T>::_left_rotation(Node<T> *leaf)
{
	Node<T> *y = leaf->right;
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

	template<typename T>
ft::Node<T>* ft::rbt<T>::_right_rotation(Node<T> *leaf)
{
	Node<T> *y = leaf->left;
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

	template<typename T>
void ft::rbt<T>::Destroy(Node<T> *leaf)
{
	if(leaf->left)
		Destroy(leaf->left);
	if(leaf->right)
		Destroy(leaf->right);
	delete leaf;
}

	template<typename T>
void ft::rbt<T>::DeleteValue(const T &val)
{
	Node<T>		*leaf = NULL;
	Node<T>		*nextNode = NULL;
	Search(val,leaf);
	if(leaf == NULL)
		return;
	if(leaf->left && leaf->right)
	{
		Node<T> *tmpNode = leaf->right;
		while(tmpNode) {
			nextNode = tmpNode;
			tmpNode = tmpNode->left;
		}
		leaf->val = nextNode->val;
		leaf = nextNode;
	}
	if(leaf->left)
	{
		Node<T> *tmp = leaf->left;
		leaf->val = tmp->val;
		leaf->left = NULL;
		delete tmp;
	}
	else if(leaf->right)
	{
		Node<T> *tmp = leaf->right;
		leaf->val = tmp->val;
		leaf->right = NULL;
		delete tmp;
	}
	else
	{
		_DeleteBalance(leaf);
		if(leaf==_root)
		{
			_root = NULL;
		}
		else if(leaf==leaf->parent->left)
			leaf->parent->left = NULL;
		else if(leaf==leaf->parent->right)
			leaf->parent->right = NULL;
		delete leaf;
	}
	_size--;
}

	template<typename T>
void ft::rbt<T>::_DeleteBalance(Node<T> *node)
{
	Node<T> *parent = NULL;
	Node<T> *other = NULL;
	while(node->color==BLACK && node->parent)
	{
		parent = node->parent;
		if(node == parent->left)
		{
			other = parent->right;
			if(other->color==RED) {
				parent->color = RED;
				other->color = BLACK;
				_left_rotation(parent);
				other = parent->right;
			}
			if( (other->left == NULL || other->left->color == BLACK)
					&& (other->right == NULL || other->left->color == BLACK)) {
				other->color=RED;
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

template<typename T>
ft::Node<T>* ft::rbt<T>::max_node() {
	Node<T> *leaf = _root;
	while(leaf->right && leaf->right->isEnd == false)
		leaf = leaf->right;
	return leaf;
}
