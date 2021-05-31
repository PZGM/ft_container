namespace ft
{

	enum COLOR {
		RED,
		BLACK
	};

	template <typename T>
		class Node
		{
			public:
				T val;
				COLOR color;
				Node *left;
				Node *right;
				Node *parent;

				Node(T val) : val(val) {
					parent = NULL;
					left = NULL;
					right = NULL;
					color = RED;
				}

				Node *uncle() {
					if (parent == NULL or parent->parent == NULL)
						return NULL;
					if (parent->isOnLeft())
						return parent->parent->right;
					else
						return parent->parent->left;
				}

				bool isOnLeft() {
					return this == parent->left;
				}

				Node *sibling() {
					if (parent == NULL)
						return NULL;
					if (isOnLeft())
						return parent->right;
					return parent->left;
				}

				void moveDown(Node *boParent) {
					if (parent != NULL) {
						if (isOnLeft()) {
							parent->left = boParent;
						}
						else {
							parent->right = boParent;
						}
					}
					boParent->parent = parent;
					parent = boParent;
				}

				bool hasRedChild() {
					return (left != NULL and left->color == RED) or
						(right != NULL and right->color == RED);
				}
		};
}
