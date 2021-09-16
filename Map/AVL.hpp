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
		if (height(node->left) - height(node->right) > 1 || height(node->left) - height(node->right) < -1)
			rebalance(node, root);
		if (node->parent == NULL)
			return;
		// checkBalance(node->parent, root);
	}

	void rebalance(Node<T> * node, Node<T> **root) {
		// std::cout << "r = " << node->data << std::endl;
		// std::cout << "r = " << height(node->right->left) << std::endl;
		// std::cout << "l = " << height(node->right->right) << std::endl;
		if (height(node->right) - height(node->left) > 1) {
			if (height(node->right->left) < height(node->right->right))
				node = left_rotate(node);
				// std::cout << "left" << std::endl;
			else
				node = right_left_rotate(node);
				// std::cout << "right left" << std::endl;
		}
		else {
			if (height(node->left->left) > height(node->left->right))
				node = right_rotate(node);
				// std::cout << "right" << std::endl;
			else
				node = left_right_rotate(node);
				// std::cout << "left right" << std::endl;
		}
		// 		std::cout << "tmp" << std::endl;
		// std::cout << node->parent << std::endl;
		// std::cout << node->data << std::endl;
		// std::cout << node->left->data << std::endl;
		// std::cout << node->right->data << std::endl;

		if (node->parent == NULL)
			*root = node;
	}

	Node<T> *left_rotate(Node<T> * node) {
		Node<T> * tmp = node->right;
		node->right = tmp->left;
		tmp->left = node;
		tmp->parent = NULL;
		// std::cout << "tmp" << std::endl;
		// std::cout << tmp->data << std::endl;
		// std::cout << tmp->left->data << std::endl;
		// std::cout << tmp->right->data << std::endl;
		return tmp; 
	}

	Node<T> *right_rotate(Node<T> * node) {
		Node<T> * tmp = node->left;
		node->left = tmp->right;
		tmp->right = node;
		tmp->parent = NULL;
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