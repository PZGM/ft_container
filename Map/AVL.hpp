#ifndef AVL_HPP
# define AVL_HPP


# include "Node.hpp"
# include "../pair.hpp"

template<class Key, class Value>
class AVL
{
	public:
		Node<ft::pair<Key, Value> > *root;
		int size;

	AVL() //contructeur avl class AVLTREE
	{
		root = NULL;
		size = 0;
	}

	~AVL() {
		if (root)
			destroy(root);
		size = 0;
	}

	void destroy(Node<ft::pair<Key, Value> > * node) {
		if (node->right)
			destroy(node->right);
		if (node->left)
			destroy(node->left);
		delete node;
	}

	Node<ft::pair<Key, Value> >	* add(Key sec, Value obj) //add normal
	{
		size++;
		ft::pair<Key, Value> pr(sec, obj);
		Node<ft::pair<Key, Value> > * node = new Node<ft::pair<Key, Value> >(pr);
		if (root == NULL)
		{
			root = node;
			size++;
			return node;
		}
		add(root, node);
		return node;
	}

	Node<ft::pair<Key, Value> >	* add(Key sec, Value obj, Node<ft::pair<Key, Value> > * nd) //add with hint
	{
		size++;
		ft::pair<Key, Value> pr(sec, obj);
		Node<ft::pair<Key, Value> > * node = new Node<ft::pair<Key, Value> >(pr);
		if (nd == NULL)
		{
			nd = node;
			size++;
			return node;
		}
		add(nd, node);
		return node;
	}

	void	add(Node<ft::pair<Key, Value> > * parent, Node<ft::pair<Key, Value> > * newNode) //add recurcif
	{
		if (newNode->data.first > parent->data.first)
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

	Node<ft::pair<Key, Value> > * find(Key val) {
		return find_r(root, val);		
	}

	Node<ft::pair<Key, Value> > * find_r(Node<ft::pair<Key, Value> > * root, Key val) {
		if (!root)
			return NULL;
		if (root->data.first == val)
			return root;
		if (root->data.first > val) {
			if (root->left)
				return find_r(root->left, val);
			return NULL;
		}
		else{
			if (root->right)
				return find_r(root->right, val);
			return NULL;
		}
	}

	void remove(Node<ft::pair<Key, Value> > * node) {
		size--;
		Node<ft::pair<Key, Value> > * parent = node->parent;
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
		Node<ft::pair<Key, Value> > * succ = in_order_succ(node);
		std::cout << succ->data.first << std::endl;
		//delete proprement la data de node
		node->data = succ->data;
		remove(succ);
	}

	Node<ft::pair<Key, Value> > * in_order_succ(Node<ft::pair<Key, Value> > * node) {
		node = node->left;
		while (node->right)
			node = node->right;
		return node;
	}


	void print_set(int floor, int index, int height, Node<ft::pair<Key, Value> > * node) {
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
			std::cout << node->data.first;
		else
			std::cout << "_";
		for(int x = 0; x < pow(2, height - floor - 1) - 1; x++)
			std::cout << " ";
	}

	void print_r(Node<ft::pair<Key, Value> > *node, int floor, int height) {
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

#endif