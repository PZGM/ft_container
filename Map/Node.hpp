#include <cmath>
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

template<class Key, class Value>
class Node;

template<class Key, class Value>
class Node
{
	public:
	
		Key		key;
		Value	data;
		
		Node<Key, Value> * left;
		Node<Key, Value> * right;
		Node<Key, Value> * parent;

	Node(Key sec, Value obj) //constructeur
	{
		key = sec;
		data = obj;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	
	void	checkBalance(Node<Key, Value> * node, Node<Key, Value> **root)
	{
		if (height(node->left) - height(node->right) > 1 || height(node->left) - height(node->right) < -1) { 
			rebalance(node, root);
		}
		if (node->parent == NULL) {
			return;
		}
		checkBalance(node->parent, root);
	}

	void rebalance(Node<Key, Value> * node, Node<Key, Value> **root) {
		bool is_right;
		Node<Key, Value> * tmparent = node->parent;
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

	Node<Key, Value> *left_rotate(Node<Key, Value> * node) {
		Node<Key, Value> * tmp = node->right;
		node->right = tmp->left;
		tmp->left = node;
		node->parent = tmp;
			if (node->right)
		node->right->parent = node;
		return tmp; 
	}

	Node<Key, Value> *right_rotate(Node<Key, Value> * node) {
		Node<Key, Value> * tmp = node->left;
		node->left = tmp->right;
		tmp->right = node;
		node->parent = tmp;
		if (node->left)
			node->left->parent = node;
		return tmp; 
	}

	Node<Key, Value> *right_left_rotate(Node<Key, Value> * node) {
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}

	Node<Key, Value> *left_right_rotate(Node<Key, Value> * node) {
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}

	int height(Node<Key, Value> * node) {
		if (node == NULL)
			return 0;
		int right = height(node->right);
		int left = height(node->left);
		if (left > right)
			return left + 1;
		return right + 1;
	}


};
