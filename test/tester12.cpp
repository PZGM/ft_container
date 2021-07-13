#include <vector>
#include <list>
#include <iostream>
#include "../LisT/List.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif


//custom binary predict
bool cbp (int first, int second)
{ return ( second == first + 1); }

int main()
{
	list<int> lst;

	std::cout << "===unique with non consecutive equals values===" << std::endl;
	
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(0);
	lst.push_back(1);

	lst.unique();

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << std::endl;

	lst.clear();

	std::cout << "===unique with consecutive equals values===" << std::endl;
	
	lst.push_back(0);
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);	
	lst.push_back(3);

	lst.unique();

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << std::endl;

	lst.clear();

	std::cout << "===unique with one value===" << std::endl;
	
	lst.push_back(42);

	lst.unique();

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << std::endl;

	lst.clear();

	std::cout << "===unique with no value===" << std::endl;
	
	lst.unique();

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << std::endl;

	lst.clear();

	std::cout << "===unique with non consecutive equals values and custom bp===" << std::endl;
	
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(0);
	lst.push_back(1);

	lst.unique(cbp);

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << std::endl;

	lst.clear();

	std::cout << "===unique with consecutive equals values and custom bp===" << std::endl;
	
	lst.push_back(0);
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);	
	lst.push_back(3);

	lst.push_back(0);
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);	
	lst.push_back(3);
	
	lst.unique(cbp);

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << std::endl;

	lst.clear();
	list<int> lst2;

	std::cout << "===swap two list of same size===" << std::endl;
	
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);	
	lst.push_back(3);

	lst2.push_back(100);
	lst2.push_back(200);
	lst2.push_back(300);
	lst2.push_back(400);
	
	lst.swap(lst2);

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();

	std::cout << "===swap two list of different size===" << std::endl;
	
	lst.push_back(0);

	lst2.push_back(100);
	lst2.push_back(200);
	lst2.push_back(300);
	lst2.push_back(400);
	
	lst2.swap(lst);

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;
	
	lst.clear();
	lst2.clear();
	
	std::cout << "===swap two list with one empty===" << std::endl;

	lst2.push_back(100);
	lst2.push_back(200);
	lst2.push_back(300);
	lst2.push_back(400);
	
	lst2.swap(lst);

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;
	
	lst.clear();
	lst2.clear();
	
	std::cout << "===swap with non member function===" << std::endl;

	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);	
	lst.push_back(3);
	
	lst2.push_back(100);
	lst2.push_back(200);
	lst2.push_back(300);
	lst2.push_back(400);
	
	swap(lst, lst2);

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;
	
	lst.clear();
	lst2.clear();
	
	std::cout << "===swap two empty lists with non member function===" << std::endl;

	swap(lst, lst2);

	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;
}
