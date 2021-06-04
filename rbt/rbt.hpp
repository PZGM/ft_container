#ifndef RBT_HPP
# define RBT_HPP

#include <iostream>
#include "../Set/SetIterator.hpp"

namespace ft
{
	template<typename T>
		class rbt
		{
			public:
				rbt() : _root(NULL){ }
				~rbt() {
					if(_root)
						Destroy(_root);
				}

				void		print();
				bool		Search(const T &val, Node<T> **node);
				bool		insert(const T &val);
				void		DeleteValue(const T &val);
				void		Destroy(Node<T> *p);
				void		DestroyI() {Destroy(_root);}
				Node<T>*	getRoot() { return _root;}

			private:	
				Node<T>	*_root;
				void	_DeleteBalance(Node<T> *node);
				void	_InsertBalance(Node<T> *node);
				Node<T>	*_left_rotation(Node<T> *node);
				Node<T>	*_right_rotation(Node<T> *node);
		};
}

#endif
