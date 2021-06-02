#include <vector>
#include <set>
#include <iostream>
#include "../Set/Set.cpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	set<int> sat;
	std::cout << "iterator pair " <<sat.insert(42).second << std::endl;
	std::cout << "iterator pair " <<sat.insert(42).second << std::endl;
//	std::cout << sat.size() << std::endl;
	for (int i = 0; i < 100 ; i += 2)
		sat.insert(i);
//	std::cout << sat.empty() << std::endl;
	set<int> stonks;
	std::cout << (sat > stonks) << std::endl;
	auto it = sat.begin();
	for( ; it != sat.end(); it++) {
		std::cout <<"size =  " << "sat.size()" <<  " it = " << *it << std::endl;
	}
	it++;
	std::cout <<"end = " << *it << std::endl;
	it++;
	std::cout << "end + 1 = " << *it << std::endl;
	it++;
	std::cout << "end + 2 = " << *it << std::endl;
}
