#include <map>
#include "Map.hpp"
#include <iostream>
#define MAG "\033[1;35m"

template<class T, class U>
bool equal(std::map<T, U>& real, ft::map<T, U>& mine)
{
	typename ft::map<T, U>::iterator m_it = mine.begin();

	if (real.size() != mine.size())
	{
		std::cout << "\nSize not equal" << std::endl;
		return false;
	}
	for (typename std::map<T, U>::iterator r_it = real.begin(); r_it != real.end(); r_it++, m_it++)
		if (m_it->first != r_it->first || m_it->second != r_it->second)
			return false;
	return true;
}


int main() {
		std::cout << MAG << "Constructors :" << std::endl;
	int test = 1;

	ft::map<int, double> m_def;
	std::map<int, double> r_def;
	check_ok(test, equal(r_def, m_def));

	std::vector<std::pair<int, double> > v;
	std::vector<ft::pair<int, double> > v2;
	for (int i = 0; i < 100; i++)
	{
		int r = rand() % 800;
		v.push_back(std::pair<int, double>(i, r));
		v2.push_back(ft::pair<int, double>(i, r));
	}

	ft::map<int, double> m_range(v2.begin(), v2.end());
	std::map<int, double> r_range(v.begin(), v.end());
	check_ok(test, equal(r_range, m_range));

	ft::map<int, double> m_cpy(m_range);
	std::map<int, double> r_cpy(r_range);
	check_ok(test, equal(r_cpy, m_cpy));

	std::cout << "\n" << std::endl;

}