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

template<class T>
class Node;

template<class T>
class Node
{
	public:
	
		T data;

		Node<T> * left;
		Node<T> * right;
		Node<T> * parent;

	Node(T obj) //constructeur
	{
		data=obj;
		parent =NULL;
		left = NULL;
		right = NULL;
	}
	
	void	checkBalance(Node<T> * node, Node<T> **root)
	{
		// std::cout << height(node->left) << std::endl;
		// std::cout << height(node->right) << std::endl;
		if (height(node->left) - height(node->right) > 1 || height(node->left) - height(node->right) < -1) { 
			rebalance(node, root);
		}
		if (node->parent == NULL) {
			return;
		}
		checkBalance(node->parent, root);
	}

	void rebalance(Node<T> * node, Node<T> **root) {
		std::cout << "parent of " << node->data << " is " << node->parent << std::endl;
		Node<T> * tmparent = node->parent;
		if (node->parent != NULL)
			bool right = node->parent->right == parent;
		if (height(node->right) - height(node->left) > 1) {
			if (height(node->right->left) < height(node->right->right)) {
				std::cout << "left " << node->data << std::endl;
				node = left_rotate(node);
			}
			else {
				std::cout << "right left " << node->data<< std::endl;
				node = right_left_rotate(node);
			}
		}
		else{
			if (height(node->left->left) > height(node->left->right)) {
				std::cout << "right " << node->data<< std::endl;
				node = right_rotate(node);
			}
			else {
				std::cout << "left right " << node->data<< std::endl;
				node = left_right_rotate(node);
			}
		}


				if (tmparent == NULL) {
					*root = node;
				}
				else {
				if (right)
					tmparent->right  = node;
				else
					tmparent->left = node;
				}
				node->parent = tmparent;
	}

	Node<T> *left_rotate(Node<T> * node) {
		std::cout << "===LEFT ROTATE " << node->data << std::endl;
		Node<T> * tmp = node->right;
		//Node<T> * tmparent = node->parent;
		node->right = tmp->left;
		tmp->left = node;
		//tmp->parent = tmparent;
		node->parent = tmp;

		// std::cout << "tmp" << std::endl;
		// std::cout << tmp->data << std::endl;
		// std::cout << tmp->left->data << std::endl;
		// std::cout << tmp->right->data << std::endl;
		return tmp; 
	}

	Node<T> *right_rotate(Node<T> * node) {
		std::cout << "===RIGHT ROTATE " << node->data << std::endl;
		Node<T> * tmp = node->left;
		//Node<T> * tmparent = node->parent;
		node->left = tmp->right;
		tmp->right = node;
		//tmp->parent = tmparent;
		node->parent = tmp;

		return tmp; 
	}

	Node<T> *parent_right_rotate(Node<T> * node) {
		std::cout << "===RIGHT ROTATE " << node->data << std::endl;
		Node<T> * tmp = node->left;
		//Node<T> * tmparent = node->parent;
		node->left = tmp->right;
		tmp->right = node;
		//tmp->parent = tmparent;
		node->parent = tmp;

		return tmp; 
	}

	Node<T> *right_left_rotate(Node<T> * node) {
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}

	Node<T> *left_right_rotate(Node<T> * node) {
		std::cout << "left rotate " << node->left->data << std::endl;
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
