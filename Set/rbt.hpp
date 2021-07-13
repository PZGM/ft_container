#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include "SetIterator.hpp"

namespace ft
{
	template<typename T, class Compare>
		class rbt
		{
			public:

				rbt() : _root(new Node<T>()), _size(0) {
					_end = new Node<T>(true);
					_rend = new Node<T>(true);
					_root->left = _rend;
					_root->right = _end;
					_end->parent = _root;
					_rend->parent = _root;
				}

				~rbt() {
					if(_root)
						Destroy(_root, 0);
				}

				rbt<T, Compare>		&operator=(const rbt<T, Compare> &src) {
					if (_size > 0)
						Destroy(_root, 0);
					if (src._size == 0) {
						return *this;
					}

					Node<T> *leaf = src.min_node();
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

				bool		Search(const T &val, Node<T> **node) const {
					Node<T> *leaf = _root;
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

				bool		insert(const T &val) {
					Node<T> *parent = NULL;
					Node<T> *newNode = new Node<T>(val);
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

				size_t		DeleteAllValue(const T &val) {
					size_t i = 0;
					Node<T> *leaf = NULL;
					while(Search(val, &leaf)) {
						DeleteValue(val);
						i++;
					}
					return i;
				}

				Node<T>* min_branch(Node<T> *leaf)
				{
					Node<T> *tmp = leaf;
					while(leaf)
					{
						tmp = leaf;
						leaf = leaf->left;
					}
					return tmp;
				}

				void rb_transplant(Node<T> *&u, Node<T> *&v)
				{
					if( u->parent == NULL )
						_root = v;
					else if( u == u->parent->left )
						u->parent->left = v;
					else
						u->parent->right = v;
					v->parent = u->parent;
				}

				void		DeleteValue(const T &val) {
					Node<T>		*leaf = NULL;
					Node<T>		*nextNode = NULL;
					if(Search(val,&leaf)) {
						/*	if(leaf->left && leaf->right && !leaf->left->isEnd && !leaf->right->isEnd)
							{
							Node<T> *tmpNode = leaf->right;
							while(tmpNode) {
							nextNode = tmpNode;
							tmpNode = tmpNode->left;
							}
							leaf->val = nextNode->val;
							leaf = nextNode;
							}
							if(leaf->left && !leaf->left->isEnd)
							{
							Node<T> *tmp = leaf->left;
							leaf->val = tmp->val;
							leaf->left = NULL;
							delete tmp;
							}
							else if(leaf->right && !leaf->right->isEnd)
							{
							Node<T> *tmp = leaf->right;
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
							if(leaf == _root) {
						//		std::cout << "truc" << std::endl;
						_root = NULL;
						}
						else if(leaf == leaf->parent->left)
						leaf->parent->left = NULL;
						else if(leaf == leaf->parent->right)
						leaf->parent->right = NULL;
						delete leaf;
						}	*/	

						Node<T> *y = leaf;
						COLOR col  = y->color;
						Node<T> *x = leaf;
						if(leaf->left == NULL)
						{
							x = leaf->right;
							rb_transplant(leaf, leaf->right);
						}
						else if(leaf->right == NULL)
						{
							x = leaf->left;
							rb_transplant(leaf, leaf->left);
						}
						else
						{
							y = min_branch(leaf->right);
							col = y->color;
							x = y->right;
							if(y->parent == leaf)
							{
								x->parent = y;
							}
							else
							{
								rb_transplant(y, y->right);
								y->right = leaf->right;
								y->right->parent = y;
							}
							rb_transplant(leaf, y);
							y->left = leaf->left;
							y->left->parent = y;
							y->color = leaf->color;
						}
						if(col == BLACK)
							_DeleteBalance(x);
					}
					_size--;
				}

				void		Destroy(Node<T> *leaf, int i) {
					if(leaf->left)
						Destroy(leaf->left, i + 1);
					if(leaf->right)
						Destroy(leaf->right, i + 1);
					delete leaf;
				}

				void		DestroyI() {
					Destroy(_root, 0);
				}

				Node<T>*	getRoot() {
					return _root;
				}

				Node<T>*	getRoot() const {
					return _root;
				}

				size_t		getSize() {
					return _size;
				}

				size_t		getSize() const {
					return _size;
				}

				Node<T>		*max_node() {
					Node<T> *leaf = _root;
					while(leaf->right && leaf->right->isEnd == false)
						leaf = leaf->right;
					return leaf;
				}
				Node<T>		*min_node() {
					Node<T> *leaf = _root;
					while(leaf->left && leaf->left->isEnd == false)
						leaf = leaf->left;
					return leaf;
				}

				Node<T>		*max_node() const {
					Node<T> *leaf = _root;
					while(leaf->right && leaf->right->isEnd == false)
						leaf = leaf->right;
					return leaf;
				}

				Node<T>		*min_node() const {
					Node<T> *leaf = _root;
					while(leaf->left && leaf->left->isEnd == false)
						leaf = leaf->left;
					return leaf;
				}


			private:

				Compare	_comp;
				Node<T>	*_end;
				Node<T>	*_rend;
				Node<T>	*_root;
				size_t	_size;

				void	_DeleteBalance(Node<T> *node) {
					/*	Node<T> *parent = NULL;
						Node<T> *other = NULL;
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
						}*/
					while(node != _root && node->color == BLACK)
					{
						if( node == node->parent->left )                                           
						{
							Node<T> *w = node->parent->right;
							if( w->color == RED )                                       //A: CASE 1
							{
								w->color = BLACK;
								node->parent->color = RED;
								_left_rotation(node->parent);
								w = node->parent->right;
							}
							if(w->left->color == BLACK and w->right->color == BLACK)    //A: CASE 2
							{
								w->color = RED;
								node = node->parent;
							}
							else
							{
								if(w->right->color == BLACK )                           //A: CASE 3
								{
									w->left->color = BLACK;
									w->color = RED;
									_right_rotation(w);
									w = node->parent->right;
								}
								w->color = node->parent->color;                                 //A: CASE 4
								node->parent->color = BLACK;
								w->right->color = BLACK;
								_left_rotation(node->parent);
								node = _root;
							}
						}
						else
						{
							Node<T> *w = node->parent->left;
							if(w->color == RED)                                         //B: CASE 1
							{
								w->color = BLACK;
								node->parent->color = RED;
								_right_rotation(node->parent);
								w = node->parent->left;
							}
							if(w->right->color==BLACK && w->left->color==RED)           //B: CASE 2
							{
								w->color = RED;
								node = node->parent;
							}
							else
							{
								if(w->left->color == BLACK)                             //B: CASE 3
								{
									w->right->color = BLACK;
									w->color = RED;
									_left_rotation(w);
									w = node->parent->left;
								}
								w->color = node->parent->color;                                 //B: CASE 4
								node->parent->color = BLACK;
								w->left->color = BLACK;
								_right_rotation(node->parent);
								node = _root;
							}
						}
					}
				node->color = BLACK;
				_root->parent = NULL;
		}

	void	_InsertBalance(Node<T> *node) {
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

	Node<T>	*_left_rotation(Node<T> *leaf) {
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

	Node<T>	*_right_rotation(Node<T> *leaf) {
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
};
}
#endif
