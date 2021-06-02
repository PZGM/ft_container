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
				
				Node () {
					parent = NULL;
					left = NULL;
					right = NULL;
					color = RED;
				};

				Node(T val) : val(val) {
					parent = NULL;
					left = NULL;
					right = NULL;
					color = RED;
				}
			};
}
