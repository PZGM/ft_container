namespace ft
{
	template <typename T>
		struct elem
		{
                	elem(T val) : content(val), is_xnode(false) {};
			elem() : is_xnode(true) {};
			elem	*prev;
			elem	*next;
			T	content;
			bool	is_xnode;
		};
}
