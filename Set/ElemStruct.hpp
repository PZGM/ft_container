namespace ft
{
	template <typename T>
		struct elem
		{
            elem(T val) : content(val) {};
			elem() {};
			elem	*father;
			elem	*left;
			elem	*right;
			T	content;
		};
}
