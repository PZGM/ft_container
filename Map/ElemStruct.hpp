#include "../pair.hpp"

namespace ft
{
	template <typename Key, typename T>
		struct elem
		{
            elem(pair<Key, T>  val) : key(val.first), val(val.second) {};
			elem(): key(Key()), val(T()) {};
			elem	*prev;
			elem	*next;

			Key	key;
			T	val;
		};
}
