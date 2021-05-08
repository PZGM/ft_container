#include <vector>
#include <list>
#include <iostream>
#include "../LisT/List.cpp"

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
	/*list<char> lst;
	list<char> lst2;

	std::cout << "===splice a entire list===" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		lst.push_back('a' + i);
		lst2.push_back('0' + i);
	}
	auto it = lst.begin();
	it++;
	lst.splice(it, lst2);
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();

	std::cout << "===splice an empty list===" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		lst.push_back('a' + i);
	}
	it = lst.begin();
	it++;
	lst.splice(it, lst2);
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();

	std::cout << "===splice one elem===" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		lst.push_back('a' + i);
		lst2.push_back('0' + i);
	}
	it = lst.begin();
	it++;
	auto ite = lst2.begin();
	ite++;
	ite++;
	lst.splice(it, lst2, ite);
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();

	std::cout << "===splice partial list===" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		lst.push_back('a' + i);
		lst2.push_back('0' + i);
	}
	it = lst.begin();
	it++;
	ite = lst2.begin();
	ite++;
	auto itee = ite;
	itee++;
	itee++;
	lst.splice(it, lst2, ite, itee);
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	lst.clear();
	lst2.clear();

	std::cout << "===remove===" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		lst.push_back('a' + i);
		lst2.push_back('0' + i);
	}
	lst.push_back('b');
	lst.push_back('b');
	lst.push_back('c');
	lst.remove('b');
	lst2.remove('4');
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "===sort===" << std::endl;
*/
	list<int> lst3;

	lst3.push_back(8);
	lst3.push_back(1);
	lst3.push_back(7);
	lst3.push_back(3);
	lst3.push_back(2);
	lst3.push_back(4);
	lst3.push_back(7);
	lst3.push_back(9);
	lst3.push_back(0);

	lst3.sort();

	for (auto it = lst3.begin(); it != lst3.end(); it++)
		std::cout << *it << std::endl;
}
