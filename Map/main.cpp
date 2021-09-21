#include "Map.hpp"

using namespace ft;

int main() {
	map<char, int> map;
	pair<const char, int> pr('a', 42);
	map.insert(pr);
	pair<const char, int> pr2('b', 42);
	map.insert(pr2);
	pair<const char, int> pr3('c', 42);
	map.insert(pr3);
	pair<const char, int> pr4('d', 42);
	//map.print();
	map['a'] = 666;
	map['z'] = 222;
	std::cout << map['a'] << std::endl;
	std::cout << map['z'] << std::endl;
	std::cout << map.size() << std::endl;
	map.print();
}
