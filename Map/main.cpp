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

	std::cout << "mop" << std::endl;

	map<char, int> mop(mp.begin() + 1, mp.end() - 1);
	mop.print();

	std::cout << "mip" << std::endl;

	map<char, int> mip(mp);
	mip.print();

	std::cout << "= de la discorde" << std::endl;

	mip = mop;

	std::cout << "mip" << std::endl;

	mip.print();

	std::cout << "mop" << std::endl;

	mop.print();

	mop.clear();
	mop.clear();
	mop.clear();
	mop.clear();

	mop.print();

	mop.insert(pr);
	mop.insert(pr2);

	mop.print();
}
