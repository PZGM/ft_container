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
	std::cout << "+++List modifiers+++" << std::endl;
	list<int> lst;
	
	std::cout << "===insert begin===" << std::endl;
	for (int i = 0; i < 15; i++)
		lst.insert(lst.begin(), i);
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	lst.clear();
	
	std::cout << "===insert end===" << std::endl;
	for (int i = 0; i < 15; i++)
		lst.insert(lst.end(), i);
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	lst.clear();

	std::cout << "===insert returns===" << std::endl;
	for (int i = 0; i < 15; i++)
	{
		auto r = lst.insert(lst.begin(), i);
		std::cout << "_" << *r << std::endl;
	}
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	//create incremental vector and list
	vector<int> vec(10);
	for (int i = 0; i < 10; i++)
		vec[i] = i;
	
	int i = 0;
	list<int> lste(10);
	for (auto it = lste.begin(); it != lste.end(); it++)
	{
		*it = i;
		i++;
	}

	lst.clear();

	std::cout << "===insert with interval==" << std::endl;
	lst.insert(lst.begin(), lste.begin(), lste.end());
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;

	lst.clear();

	std::cout << "===insert with vector interval==" << std::endl;
	lst.insert(lst.begin(), vec.begin(), vec.end());
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===insert itself==" << std::endl;
	auto it = lst.begin();
	it++;
	it++;
	lst.insert(it, lst.begin(), lst.end());
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	std::cout << "===assign==" << std::endl;
	lst.assign(lste.begin(), lste.end());
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign itself==" << std::endl;
	lst.assign(lst.begin(), lst.end());
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign with vector==" << std::endl;
	lst.assign(vec.begin(), vec.end());
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign with values==" << std::endl;
	lst.assign(13,14);
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===push back/front==" << std::endl;
	lst.push_back(0);
	lst.push_back(1);
	lst.push_front(2);
	lst.push_front(3);
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	std::cout << "===pop back/front==" << std::endl;
	lst.pop_back();
	lst.pop_front();
	for (auto it = lst.begin(); it != lst.end(); it++)
		std::cout << "_" << *it << std::endl;
}
