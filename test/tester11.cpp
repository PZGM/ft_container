#include <vector>
#include <list>
#include <iostream>
#include "../LisT/List.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

//custom comparison
bool mycomparison (double first, double second)
{ return ( int(first)>int(second) ); }

int main()
{
	list<char> lst;
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


	list<int> lst4;
	list<int> lst5;
	list<int> lst6;

	std::cout << "===remove if===" << std::endl;

	//is_odd
	struct is_odd {
		bool operator() (const int& value) { return (value%2)==1; }
	};

	for (int i = 0; i < 10; i++)
	{
		lst4.push_back(i);
		lst5.push_back(i * 10);
		lst6.push_back(i * 10 + 1);
	}
	
	lst4.remove_if(is_odd());
	lst5.remove_if(is_odd());
	lst6.remove_if(is_odd());
	
	for (auto it = lst4.begin(); it != lst4.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst5.begin(); it != lst5.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << lst.size() << "|" << lst2.size() << std::endl;
	for (auto it = lst6.begin(); it != lst6.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "===sort===" << std::endl;

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

	std::cout << "===sort with custom comparison===" << std::endl;

	lst3.sort(mycomparison);

	for (auto it = lst3.begin(); it != lst3.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "===reverse===" << std::endl;

	lst3.reverse();
	
	for (auto it = lst3.begin(); it != lst3.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "===reverse with one elem===" << std::endl;
	
	lst3.resize(1);
	lst3.reverse();

	for (auto it = lst3.begin(); it != lst3.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "===reverse with no elem===" << std::endl;
	
	lst3.clear();
	lst3.reverse();

	for (auto it = lst3.begin(); it != lst3.end(); it++)
		std::cout << *it << std::endl;

}
