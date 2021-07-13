#include <vector>
#include <list>
#include <iostream>
#include "../LisT/List.hpp"
#include "../Vector/Vector.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

//custom comparison
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int main()
{
	list<int> lst;
	list<int> lst2;

	std::cout << "===merge===" << std::endl;
	lst.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst.push_back(4);
	lst2.push_back(5);
	lst2.push_back(6);
	lst.push_back(7);
	
	lst.merge(lst2);
	
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();

	std::cout << "===merge reverse order===" << std::endl;
	lst.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst.push_back(4);
	lst2.push_back(5);
	lst2.push_back(6);
	lst.push_back(7);
	
	lst2.merge(lst);
	
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();

	std::cout << "===merge itself===" << std::endl;
	lst.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst.push_back(4);
	lst2.push_back(5);
	lst2.push_back(6);
	lst.push_back(7);
	
	lst2.merge(lst);
	
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();

	std::cout << "===merge with empty dst===" << std::endl;
	lst.push_back(1);
	lst.push_back(4);
	lst.push_back(7);
	
	lst2.merge(lst);
	
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;
	
	lst.clear();
	lst2.clear();

	std::cout << "===merge with empty src===" << std::endl;
	lst.push_back(1);
	lst.push_back(4);
	lst.push_back(7);
	
	lst.merge(lst2);
	
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;


	lst.clear();
	lst2.clear();

	std::cout << "===merge identical lists===" << std::endl;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(7);
	
	lst2.assign(lst.begin(), lst.end());

	lst2.merge(lst);
	
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();


	std::cout << "===merge with custom commparison===" << std::endl;
	lst.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst.push_back(4);
	lst2.push_back(5);
	lst2.push_back(6);
	lst.push_back(7);
	
	lst.merge(lst2, mycomparison);
	
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

}
