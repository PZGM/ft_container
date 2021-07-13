#include <vector>
#include <set>
#include <iostream>
#include "../Set/Set.hpp"
#include "../Vector/Vector.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	std::cout << "===Default constructor===" << std::endl;
	set<int> st1;
	std::cout << st1.size() << std::endl;
	for (auto it = st1.begin(); it != st1.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st1.rbegin(); it != st1.rend(); it++)
		std::cout << "^" << *it << std::endl;

	//create a vector with incremental values
	vector<int> vec(6, 8);
	int i = 0;
	for (auto it = vec.begin(); it != vec.end(); it++)
		*it = i++;

	std::cout << "===Range constructor===" << std::endl;
	set<int> st3(vec.begin(), vec.end());
	std::cout << st3.size() << std::endl;
	for (auto it = st3.begin(); it != st3.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st3.rbegin(); it != st3.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Range constructor with reverse iterator===" << std::endl;
	set<int> st4(vec.rbegin(), vec.rend());
	std::cout << st4.size() << std::endl;
	for (auto it = st4.begin(); it != st4.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st4.rbegin(); it != st4.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Range constructor with partial vector iterators===" << std::endl;
	set<int> st5(vec.begin() + 2, vec.end() - 1);
	std::cout << st5.size() << std::endl;
	
	st5.insert(vec.begin(), vec.end());

	for (auto it = st5.begin(); it != st5.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st5.rbegin(); it != st5.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Range constructor with set iterators===" << std::endl;
	set<int> st6(vec.begin(), vec.end());
	std::cout << st6.size() << std::endl;
	for (auto it = st6.begin(); it != st6.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st6.rbegin(); it != st6.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	std::cout << "===Copy constructor===" << std::endl;
	set<int> st7(st5);
	std::cout << st7.size() << std::endl;
	for (auto it = st7.begin(); it != st7.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st7.rbegin(); it != st7.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Copy constructor with empty set===" << std::endl;
	set<int> st8(st1);
	std::cout << st8.size() << std::endl;
	for (auto it = st8.begin(); it != st8.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st8.rbegin(); it != st8.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	set<int> st9;

	std::cout << "===Assign operator with empty set===" << std::endl;
	st9 = st1;
	std::cout << st9.size() << std::endl;
	st9.insert(5);
	for (auto it = st9.begin(); it != st9.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st9.rbegin(); it != st9.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Assign operator===" << std::endl;

	set<int> st10;
	st10 = st5;
	std::cout << st10.size() << std::endl;
	for (auto it = st10.begin(); it != st10.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = st10.rbegin(); it != st10.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	std::cout<< "===empty===" << std::endl;
	std::cout << st1.empty() << std::endl;
	std::cout << st3.empty() << std::endl;
	std::cout << st4.empty() << std::endl;
	std::cout << st5.empty() << std::endl;
	std::cout << st6.empty() << std::endl;
	std::cout << st7.empty() << std::endl;
	std::cout << st8.empty() << std::endl;
	std::cout << st9.empty() << std::endl;
	std::cout << st10.empty() << std::endl;

	std::cout<< "===size===" << std::endl;
	std::cout << st1.size() << std::endl;
	std::cout << st3.size() << std::endl;
	std::cout << st4.size() << std::endl;
	std::cout << st5.size() << std::endl;
	std::cout << st6.size() << std::endl;
	std::cout << st7.size() << std::endl;
	std::cout << st8.size() << std::endl;
	std::cout << st9.size() << std::endl;
	std::cout << st10.size() << std::endl;

	std::cout << "===max size===" << std::endl;
	std::cout << st1.max_size() << std::endl;


	std::cout << "===swap===" << std::endl;
	for (auto it = st1.begin(); it != st1.end(); it++)
		std::cout << "1 : " << *it << std::endl;
	for (auto it = st3.begin(); it != st3.end(); it++)
		std::cout << "3 : " << *it << std::endl;
	
	st1.swap(st3);

	for (auto it = st1.begin(); it != st1.end(); it++)
		std::cout << "1 : " << *it << std::endl;
	for (auto it = st3.begin(); it != st3.end(); it++)
		std::cout << "3 : " << *it << std::endl;

}
