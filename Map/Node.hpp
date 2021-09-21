#ifndef NODE_HPP
# define NODE_HPP



# include <cmath>
# include <string>
# include <iostream>
# include <istream>
# include <iomanip>
# include <ctype.h>
# include <ios>
# include <fstream>
# include <stdlib.h>
# include <sstream>
# include <memory>
# include <stdexcept>

template<class T>
class Node;

template<class T>
class Node
{
	public:
	
		T		data;
		
		Node<T> * left;
		Node<T> * right;
		Node<T> * parent;

	Node(T obj) //constructeur
	{
		data = obj;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

		Node() //default constructeur
	{
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	
	void	checkBalance(Node<T> * node, Node<T> **root)
	{
		if (height(node->left) - height(node->right) > 1 || height(node->left) - height(node->right) < -1) { 
			rebalance(node, root);
		}
		if (node->parent == NULL) {
			return;
		}
		checkBalance(node->parent, root);
	}

	void rebalance(Node<T> * node, Node<T> **root) {
		bool is_right;
		Node<T> * tmparent = node->parent;
		if (node->parent != NULL) {
			is_right = node->parent->right == node;
		}
		if (height(node->right) - height(node->left) > 1) {
			if (height(node->right->left) < height(node->right->right)) {
				node = left_rotate(node);
			}
			else {
				node = right_left_rotate(node);
			}
		}
		else{
			if (height(node->left->left) > height(node->left->right)) {
				node = right_rotate(node);
			}
			else {
				node = left_right_rotate(node);
			}
		}
		if (tmparent == NULL) {
			*root = node;
		}
		else {
		if (is_right == true)
			tmparent->right  = node;
		else
			tmparent->left = node;
		}
		node->parent = tmparent;
	}

	Node<T> *left_rotate(Node<T> * node) {
		Node<T> * tmp = node->right;
		node->right = tmp->left;
		tmp->left = node;
		node->parent = tmp;
			if (node->right)
		node->right->parent = node;
		return tmp; 
	}

	Node<T> *right_rotate(Node<T> * node) {
		Node<T> * tmp = node->left;
		node->left = tmp->right;
		tmp->right = node;
		node->parent = tmp;
		if (node->left)
			node->left->parent = node;
		return tmp; 
	}

	Node<T> *right_left_rotate(Node<T> * node) {
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}

	Node<T> *left_right_rotate(Node<T> * node) {
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}

	int height(Node<T> * node) {
		if (node == NULL)
			return 0;
		int right = height(node->right);
		int left = height(node->left);
		if (left > right)
			return left + 1;
		return right + 1;
	}


};

#endif