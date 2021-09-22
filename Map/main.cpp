#include "Map.hpp"

using namespace ft;

int main() {
	map<char, int> mp;
	pair<const char, int> pr('a', 42);
	mp.insert(pr);
	pair<const char, int> pr2('b', 42);
	mp.insert(pr2);
	pair<const char, int> pr3('c', 42);
	mp.insert(pr3);
	pair<const char, int> pr4('d', 42);
	mp['a'] = 666;
	mp['z'] = 222;

	map<char, int>::iterator it = mp.begin();
	map<char, int>::const_iterator cit = mp.begin() + 1;
	mp.print();
}
