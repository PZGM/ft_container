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
				COLOR	color;
				Node	*left;
				Node	*right;
				Node	*parent;
				bool	isEnd;
				int		pos; //-1 lower bound 0 normal 1 upper bound

				Node () {
					val = T();
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = false;
					color = RED;
					pos = 0;
				};

				Node (bool x) {
					val = T();
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = x;
					color = RED;
					pos = 0;
				}
				Node(T val) : val(val) {
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = false;
					color = RED;
					pos = 0;
				}
			};
}
