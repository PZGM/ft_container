#include <vector>
#include <list>
#include <iostream>
#include "../LisT/List.cpp"
#include "../Vector/Vector.cpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	list<int> lst;
	list<int> lst2;

	lst.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst.push_back(4);
	lst2.push_back(5);
	lst2.push_back(6);
	lst.push_back(7);

//	lst.merge(lst2);
//	lst2.merge(lst);
//	for (auto it = lst.begin(); it != lst.end(); it++)
//		std::cout << *it << std::endl;
//	for (auto it = lst2.begin(); it != lst2.end(); it++)
//		std::cout << *it << std::endl;
}
