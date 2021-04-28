#include <vector>
#include <list>
#include <iostream>

#ifdef STD
using namespace std;
#elif FT
#include "List.cpp"
using namespace ft;
#endif

int main()
{
	list<int> lst(15, 10);
	int i = 50;
	for (auto a = lst.rbegin(); a != lst.rend(); a++)
	{
		*a = i;
		i++;
	}
	auto it = lst.begin();
	it++;
	lst.insert(it, 4222222);
	for (auto a = lst.begin(); a != lst.end(); a++)
	{
		std::cout << *a << std::endl;
	}
	std::cout << lst.max_size() << std::endl;
}