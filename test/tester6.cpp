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
	for (int i = 0; i < 80 ; i += 2)
		sat.insert(i);
//	std::cout << sat.empty() << std::endl;
//	set<int> stonks;
//	std::cout << (sat > stonks) << std::endl;

//	sat.print();
	auto it = sat.begin();
	for( ; it != sat.end(); it++) {
		std::cout << "it = "  << *it << std::endl;
	}
	std::cout <<"end = " << *it << std::endl;
/*	it++;
	std::cout << "begin + 1 = " << *it << std::endl;
	it++;
	std::cout << "begin + 2 = " << *it << std::endl;
*/
	}
