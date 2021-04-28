namespace ft
{
	template <typename T>
		struct elem
		{
            elem(T val) : content(val) {};
			elem() {};
			elem	*prev;
			elem	*next;
			T	content;
		};
}
