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
	mp.print();
	std::cout << "___" << std::endl;
	map<char, int>::iterator it = mp.begin();
	while (it != mp.end()) {
		std::cout << (*it).first << " | " << (*it).second << std::endl;
		it++;
	}

	std::cout << "___" << std::endl;

	map<char, int>::reverse_iterator ite = mp.rbegin();
	while (ite != mp.rend()) {
		std::cout << (*ite).first << " | " << (*ite).second << std::endl;
		ite++;
	}
}
