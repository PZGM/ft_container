#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include "SetIterator.hpp"

namespace ft
{
	template<typename T>
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
						Destroy(_root);
				}
				bool		Search(const T &val, Node<T> **node);
				bool		insert(const T &val);
				size_t		DeleteAllValue(const T &val);
				void		DeleteValue(const T &val);
				void		Destroy(Node<T> *p);
				void		DestroyI() {Destroy(_root);}
				Node<T>*	getRoot() { return _root;}
				Node<T>*	getRoot() const { return _root;}
				size_t		getSize() { return _size;}
				size_t		getSize() const { return _size;}
				Node<T>		*max_node();
				Node<T>		*min_node();

			private:
				Node<T>	*_end;
				Node<T>	*_rend;
				Node<T>	*_root;
				size_t	_size;
				void	_DeleteBalance(Node<T> *node);
				void	_InsertBalance(Node<T> *node);
				Node<T>	*_left_rotation(Node<T> *node);
				Node<T>	*_right_rotation(Node<T> *node);
		};
}

#endif
