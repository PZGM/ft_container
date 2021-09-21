#include "Map.hpp"

using namespace ft;

int main() {
	map<char, int> map;
	pair<const char, int> pr('a', 42);
	map.insert(pr);
	pair<const char, int> pr2('b', 42);
	map.insert(pr2);
	pair<const char, int> pr3('c', 42);
	auto ret = map.insert(pr3);
	pair<const char, int> pr4('d', 42);
	map.insert(ret.first, pr4);
	map.erase(ret.first);
	map.print();

	ft::map<char, int> mop;
	pair<const char, int> pf('A', 42);
	mop.insert(pf);
	pair<const char, int> pf2('B', 42);
	mop.insert(pf2);
	pair<const char, int> pf3('C', 42);
	auto rot = mop.insert(pf3);
	pair<const char, int> pf4('D', 42);
	mop.insert(rot.first, pf4);
	mop.erase(rot.first);
	mop.print();
	map.swap(mop);
	map.print();
	mop.print();

	std::cout << "clear" << std::endl;

	map.clear();
	map.print();
}

