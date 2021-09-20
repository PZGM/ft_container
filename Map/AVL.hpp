#include "Node.hpp"

template<class T>
class AVL
{
	public:
		Node<T> *root;
		int size;

	AVL() //contructeur avl class AVLTREE
	{
		root = NULL;
		size = 0;
	}

	void 	add(T obj) //add normal
	{
		Node<T> * node = new Node<T>(obj);
		if (root == NULL)
		{
			root = node;
			size++;
			return;
		}
		add(root, node);
	}

	void	add(Node<T> * parent, Node<T> * newNode) //add recurcif
	{
		if (newNode->data > parent->data)
		{
			if (parent->right == NULL)
			{
				parent->right = newNode;
				newNode->parent = parent;
				size++;
			} else 
				add(parent->right, newNode);
		} else
		{
			if (parent->left == NULL)
			{
				parent->left = newNode;
				newNode->parent = parent;
				size++;
			} else 
				add(parent->left, newNode);
		}
		// std::cout <<"papa = "<< parent->data << std::endl;
		// std::cout << "rrrrr = " <<parent->right << std::endl;
		// if (parent->right)
		// 	std::cout << "right = " << parent->right->data << std::endl;
		// std::cout << "lllll = " <<parent->left << std::endl;
		// if (parent->left)
		// 	std::cout << "left = " << parent->left->data << std::endl;
		root->checkBalance(parent, &root);
	}

	void print_set(int floor, int index, int height, Node<T> * node) {
		//  std::cout << "floor = " << floor << " index = " << index << " height = " << height << std::endl;
		for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
			std::cout << " ";
		int v = 2;
		for (int x = pow(2, floor - 1) ; x > 0; x/=2) {
			// std::cout << "X = " << x << std::endl;
			if (node != NULL && index / x == 0) {
					node = node->left;
				// std::cout << "GO left" << std::endl;
			}
			else if (node != NULL){
				index -= x;
				node = node->right;
				// std::cout << "GO right" << std::endl;
			}
		}
		if (node != NULL)
			std::cout << node->data;
		else
			std::cout << "X";
		for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
			std::cout << " ";
	}

	void print(Node<T> *node, int floor, int height) {
		for (int x = 0; x < pow(2, floor); x++) {
			print_set(floor, x, height, node);
			if (x != pow(2, floor) - 1)
			std::cout << ".";
		}
		if (floor == height - 1)
			return;
		std::cout << std::endl;

		print(node, floor + 1, height);
	}


};
