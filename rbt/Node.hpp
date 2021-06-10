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
				bool isEnd;
				
				Node () {
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = false;
					color = RED;
				};

				Node (bool x) {
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = x;
					color = RED;
				}
				Node(T val) : val(val) {
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = false;
					color = RED;
				}
			};
}
