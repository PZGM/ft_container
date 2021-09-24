#ifndef AVL_HPP
# define AVL_HPP


# include "Node.hpp"
# include "../pair.hpp"

template<class Key, class Value, class Compare, class Alloc>
class AVL
{
	public:
		typedef typename Alloc::template rebind<Node<ft::pair<Key, Value> > >::other Node_allocator_type;

		Node_allocator_type	_node_alloc;
		Node<ft::pair<Key, Value> > *root;
		Node<ft::pair<Key, Value> > *end;
		Node<ft::pair<Key, Value> > *rend;
		int size;

	AVL() //contructeur avl class AVLTREE
	{
		_node_alloc = Node_allocator_type();
		root = NULL;
		size = 0;
		ft::pair<Key, Value> pr = ft::make_pair('>', 0);
		rend = _node_alloc.allocate(1);
		_node_alloc.construct(rend, pr);
		// rend = new Node<ft::pair<Key, Value> >(pr);
		root = rend;
		ft::pair<Key, Value> pr2 = ft::make_pair('<', 0);
		end = _node_alloc.allocate(1);
		_node_alloc.construct(end, pr2);
		// end = new Node<ft::pair<Key, Value> >(pr2);
		rend->right = end;
		end->parent = rend;
	}

	~AVL() {
		if (root)
			destroy(root);
	}

	void destroy(Node<ft::pair<Key, Value> > * node) {
		if (node->right)
			destroy(node->right);
		if (node->left)
			destroy(node->left);
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node,1);
		// delete node;
	}

	Node<ft::pair<Key, Value> >	* add(Key sec, Value obj) //add normal
	{
		ft::pair<Key, Value> pr = ft::make_pair(sec, obj);
		Node<ft::pair<Key, Value> > * node = _node_alloc.allocate(1);
		_node_alloc.construct(node, pr);
		// Node<ft::pair<Key, Value> > * node = new Node<ft::pair<Key, Value> >(pr);
		add(root, node);
		return node;
	}

	Node<ft::pair<Key, Value> >	* add(Key sec, Value obj, Node<ft::pair<Key, Value> > * nd) //add with hint
	{
		ft::pair<Key, Value> pr = ft::make_pair(sec, obj);
		Node<ft::pair<Key, Value> > * node = _node_alloc.allocate(1);
		_node_alloc.construct(node, pr);
		// Node<ft::pair<Key, Value> > * node = new Node<ft::pair<Key, Value> >(pr);
		add(nd, node);
		return node;
	}

	void	add(Node<ft::pair<Key, Value> > * parent, Node<ft::pair<Key, Value> > * newNode) //add recurcif
	{
		if (parent == rend || (parent != end && Compare()(parent->data.first, newNode->data.first)))
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
		if (root == NULL)
			return NULL;
		if (root != end && root != end && root->data.first == val)
			return root;
		if (root == end || Compare()(val, root->data.first)) {
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
		Node<ft::pair<Key, Value> > * parent = node->parent;
		if (node->right == NULL && node->left == NULL) {
			if (parent->right == node)
				parent->right = NULL;
			else
				parent->left = NULL;
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node,1);
			parent->checkBalance(parent, &root);
			size--;
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
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node,1);
			parent->checkBalance(parent, &root);
			size--;
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
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node,1);
			parent->checkBalance(parent, &root);
			size--;
			return;
		}

		Node<ft::pair<Key, Value> > * succ = in_order_succ(node);
		int special = 0;
		if (succ == end)
			special = 1;
		if (succ == rend)
			special = 2;
		node->data = succ->data;
		remove(succ);
		if (special == 1)
			end = node;
		if (special == 2)
			rend = node;
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

	bool is_null(Node<ft::pair<Key, Value> > *node) {
		return (node == NULL || node == end || node == rend);
	}

	Node<ft::pair<Key, Value> > * get_begin() {
		if (size == 0)
			return end;
		if (rend->right)
			return rend->right;
		return rend->parent;
	}

	Node<ft::pair<Key, Value> > * get_rbegin() {
		if (size == 0)
			return rend;
		if (end->left)
			return end->left;
		return end->parent;
	}

	Node<ft::pair<Key, Value> > * get_end() {
		return end;
	}

	Node<ft::pair<Key, Value> > * get_rend() {
		return rend;
	}


};

#endif