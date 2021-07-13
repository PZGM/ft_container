namespace ft
{
	enum COLOR {
		RED,
		BLACK
	};

	template <typename key, typename T>
		class Node
		{
			public:
				Key		id;
				T		val;
				COLOR	color;
				Node	*left;
				Node	*right;
				Node	*parent;
				bool	isEnd;
				int		pos; //-1 lower bound 0 normal 1 upper bound

				Node () {
					key	= key();
					val = T();
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = false;
					color = RED;
					pos = 0;
				};

				Node (bool x) {
					key	= key();
					val = T();
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = x;
					color = RED;
					pos = 0;
				}
				Node(T val) : val(val) {
					key	= key();
					parent = NULL;
					left = NULL;
					right = NULL;
					isEnd = false;
					color = RED;
					pos = 0;
				}
			};
}
