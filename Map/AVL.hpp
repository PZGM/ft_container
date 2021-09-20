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
		std::cout << "-> add " << obj << std::endl;
		Node<T> * node = new Node<T>(obj);
		if (root == NULL)
		{
			root = node;
			size++;
			return;
		}
		add(root, node);
	}

	Node<T> * find(T val) {
		return find_r(root, val);		
	}

	Node<T> * find_r(Node<T> * root, T val) {
		if (root->data == val)
			return root;
		if (root->data > val) {
			if (root->left)
				return find_r(root->left, val);
			return NULL;
		}
		else {
			if (root->right)
				return find_r(root->right, val);
			return NULL;
		}
	}

	void remove(Node<T> * node) {
		Node<T> * parent = node->parent;
		if (node->right == NULL && node->left == NULL) {
			if (parent->right == node)
				parent->right = NULL;
			else
				parent->left = NULL;
			delete node;
			parent->checkBalance(parent, &root);
			return;
		}
		else if (node->right == NULL) {
			if (parent->right == node) {
				parent->right = node->left;
				node->left->parent = parent;
			}
			else
			{
				parent->left = node->left;
				node->left->parent = parent;
			}
			delete node;
			parent->checkBalance(parent, &root);
			return;
		}
		else if (node->left == NULL) {
			if (parent->right == node) {
				parent->right = node->right;
				node->right->parent = parent;
			}
			else
			{
				parent->left = node->right;
				node->right->parent = parent;
			}
			delete node;
			parent->checkBalance(parent, &root);
			return;
		}
		Node<T> * succ = in_order_succ(node);
		std::cout << succ->data << std::endl;
		//delete proprement la data de node
		node->data = succ->data;
		remove(succ);
	}

	Node<T> * in_order_succ(Node<T> * node) {
		node = node->left;
		while (node->right)
			node = node->right;
		return node;
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
		root->checkBalance(parent, &root);
	}

	void print_set(int floor, int index, int height, Node<T> * node) {
		for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
			std::cout << " ";
		int v = 2;
		for (int x = pow(2, floor - 1) ; x > 0; x/=2) {
			if (node != NULL && index / x == 0) {
					node = node->left;
			}
			else if (node != NULL){
				index -= x;
				node = node->right;
			}
		}
		if (node != NULL)
			std::cout << node->data;
		else
			std::cout << "X";
		for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
			std::cout << " ";
	}

	void print_r(Node<T> *node, int floor, int height) {
		for (int x = 0; x < pow(2, floor); x++) {
			print_set(floor, x, height, node);
			if (x != pow(2, floor) - 1)
			std::cout << ".";
		}
		if (floor == height - 1)
			return;
		std::cout << std::endl;

		print_r(node, floor + 1, height);
	}

	void print() {
		std::cout << std::endl;
		print_r(root, 0, root->height(root));
		std::cout << std::endl;
	}


};
