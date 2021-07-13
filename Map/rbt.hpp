#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include "MapIterator.hpp"

namespace ft
{
	template<typename T, class Compare>
		class rbt
		{
			public:

				rbt() : _root(new Node<Key, T>()), _size(0) {
				_end = new Node<Key, T>(true);
				_rend = new Node<Key, T>(true);
				_root->left = _rend;
				_root->right = _end;
				_end->parent = _root;
				_rend->parent = _root;
				}

				~rbt() {
					if(_root)
						Destroy(_root, 0);
				}


				rbt<Key, T, Compare>		&operator=(const rbt<Key, T, Compare> &src);

				bool		Search(const T &val, Node<Key, T> **node) const;
				bool		insert(const T &val);
				size_t		DeleteAllValue(const T &val);
				void		DeleteValue(const T &val);
				void		Destroy(Node<Key, T> *p, int i);
				void		DestroyI() {Destroy(_root, 0);}
				Node<Key, T>*	getRoot() { return _root;}
				Node<Key, T>*	getRoot() const { return _root;}
				size_t		getSize() { return _size;}
				size_t		getSize() const { return _size;}
				Node<Key, T>		*max_node();
				Node<Key, T>		*min_node();
				Node<Key, T>		*max_node() const;
				Node<Key, T>		*min_node() const;


			private:

				Compare	_comp;
				Node<Key, T>	*_end;
				Node<Key, T>	*_rend;
				Node<Key, T>	*_root;
				size_t	_size;
				void	_DeleteBalance(Node<Key, T> *node);
				void	_InsertBalance(Node<Key, T> *node);
				Node<Key, T>	*_left_rotation(Node<Key, T> *node);
				Node<Key, T>	*_right_rotation(Node<Key, T> *node);
		};
}
#endif
