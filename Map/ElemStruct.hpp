namespace ft
{
	template <typename Key, typename T>
		struct elem
		{
            elem(pair<Key, T>  val) : key(val.first), val(val.second) {};
			elem() {};
			elem	*prev;
			elem	*next;

			Key	key
			T	val;
		};
}
