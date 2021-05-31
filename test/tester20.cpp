#include <list>
#include <iostream>
#include <queue>
#include <vector>
#include "../Queue/Queue.hpp"
#include "../LisT/List.cpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	list<int> lst(10);
	int i = 0;
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		*it = i;
		i++;
	}
	deque<int> dek(10, 42);
	i = 10;
	for (auto it = dek.begin(); it != dek.end(); it++)
	{
		*it = i;
		i++;
	}
	
	std::cout << "===default constructor with default underlying container===" << std::endl;
	queue<int> ke;
	std::cout << "size = " << ke.size() << " _ empty = " << ke.empty() << std::endl;
	
	ke.push(42);;
	std::cout << "size = " << ke.size() << " _ empty = " << ke.empty() << " _ front = " << ke.front() << " _ back = " << ke.back() << std::endl;

	ke.push(21);
	std::cout << "size = " << ke.size() << " _ empty = " << ke.empty() << " _ front = " << ke.front() << " _ back = " << ke.back() << std::endl;

	ke.pop();
	std::cout << "size = " << ke.size() << " _ empty = " << ke.empty() << " _ front = " << ke.front() << " _ back = " << ke.back() << std::endl;

	ke.pop();
	std::cout << "size = " << ke.size() << " _ empty = " << ke.empty() << std::endl;
	
	std::cout << "===copy constructor with default underlying container===" << std::endl;
	queue<int> ke2(dek);

	std::cout << "size = " << ke2.size() << " _ empty = " << ke2.empty() << " _ front = " << ke2.front() << " _ back = " << ke2.back() << std::endl;
	
	ke2.push(42);;
	std::cout << "size = " << ke2.size() << " _ empty = " << ke2.empty() << " _ front = " << ke2.front() << " _ back = " << ke2.back() << std::endl;

	ke2.push(21);
	std::cout << "size = " << ke2.size() << " _ empty = " << ke2.empty() << " _ front = " << ke2.front() << " _ back = " << ke2.back() << std::endl;

	ke2.pop();
	std::cout << "size = " << ke2.size() << " _ empty = " << ke2.empty() << " _ front = " << ke2.front() << " _ back = " << ke2.back() << std::endl;

	ke2.pop();
	std::cout << "size = " << ke2.size() << " _ empty = " << ke2.empty() << " _ front = " << ke2.front() << " _ back = " << ke2.back() << std::endl;

	ke2.pop();
	std::cout << "size = " << ke2.size() << " _ empty = " << ke2.empty() << " _ front = " << ke2.front() << " _ back = " << ke2.back() << std::endl;


	std::cout << "===copy constructor with list as underlying container===" << std::endl;
	queue<int, list<int>> ke3(lst);

	std::cout << "size = " << ke3.size() << " _ empty = " << ke3.empty() << " _ front = " << ke3.front() << " _ back = " << ke3.back() << std::endl;
	
	ke3.push(42);;
	std::cout << "size = " << ke3.size() << " _ empty = " << ke3.empty() << " _ front = " << ke3.front() << " _ back = " << ke3.back() << std::endl;

	ke3.push(21);
	std::cout << "size = " << ke3.size() << " _ empty = " << ke3.empty() << " _ front = " << ke3.front() << " _ back = " << ke3.back() << std::endl;

	ke3.pop();
	std::cout << "size = " << ke3.size() << " _ empty = " << ke3.empty() << " _ front = " << ke3.front() << " _ back = " << ke3.back() << std::endl;

	ke3.pop();
	std::cout << "size = " << ke3.size() << " _ empty = " << ke3.empty() << " _ front = " << ke3.front() << " _ back = " << ke3.back() << std::endl;

	ke3.pop();
	std::cout << "size = " << ke3.size() << " _ empty = " << ke3.empty() << " _ front = " << ke3.front() << " _ back = " << ke3.back() << std::endl;

}
