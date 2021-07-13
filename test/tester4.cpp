#include <vector>
#include <list>
#include <set>
#include <iostream>
#include "../Set/Set.hpp"
#include "../LisT/List.hpp"


#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main ()
{
	set<int> myset;
	set<int>::iterator itlow;
	set<int>::iterator itup;

	std::cout << "===Find===" << std::endl;

	myset.insert(42);
	myset.insert(42);
	myset.insert(21);
	myset.insert(0);
	myset.insert(-1);

	auto it = myset.find(42);
	std::cout << "value 42 : " << ((it == myset.end()) ? "not found" : "FOUND=") << std::endl;

	myset.erase(42);

	it = myset.find(42);
	std::cout << "value 42 : " << ((it == myset.end()) ? "not found" : "FOUND=") << std::endl;

	it = myset.find(50);
	std::cout << "value 50 : " << ((it == myset.end()) ? "not found" : "FOUND=") << std::endl;

	myset.insert(50);

	it = myset.find(50);
	std::cout << "value 50 : " << ((it == myset.end()) ? "not found" : "FOUND=") << std::endl;

	it = myset.find(0);
	std::cout << "value 0 : " << ((it == myset.end()) ? "not found" : "FOUND=") << std::endl;

	myset.erase(0);

	it = myset.find(0);
	std::cout << "value 0 : " << ((it == myset.end()) ? "not found" : "FOUND=") << std::endl;

	it = myset.find(-1);
	std::cout << "value -1 : " << ((it == myset.end()) ? "not found" : "FOUND=") << std::endl;

	myset.erase(-1);

	std::cout << "===count===" << std::endl;

	myset.insert(0);
	myset.insert(42);
	myset.insert(0);
	myset.insert(11);
	myset.insert(0);
	myset.insert(42);

	int ret = myset.count(0);
	std::cout << "value 0 : " << ret << std::endl;
	ret = myset.count(42);
	std::cout << "value 42 : " << ret << std::endl;
	ret = myset.count(10);
	std::cout << "value 10 : " << ret << std::endl;
	ret = myset.count(11);
	std::cout << "value 11 : " << ret << std::endl;
	myset.erase(42);
	ret = myset.count(42);
	std::cout << "value 42 : " << ret << std::endl;
	myset.insert(11);
	ret = myset.count(11);
	std::cout << "value 11 : " << ret << std::endl;

	std::cout << "===lower bound===" << std::endl;

	myset.insert(0);
	myset.insert(2);
	myset.insert(5);
	myset.insert(6);
	myset.insert(7);
	myset.insert(9);

	it = myset.lower_bound(-1);
	std::cout << "value -1 : " << *it << std::endl;
	it = myset.lower_bound(0);
	std::cout << "value 0 : " << *it << std::endl;
	it = myset.lower_bound(1);
	std::cout << "value 1 : " << *it << std::endl;
	it = myset.lower_bound(2);
	std::cout << "value 2 : " << *it << std::endl;
	it = myset.lower_bound(3);
	std::cout << "value 3 : " << *it << std::endl;
	it = myset.lower_bound(4);
	std::cout << "value 4 : " << *it << std::endl;
	it = myset.lower_bound(5);
	std::cout << "value 5 : " << *it << std::endl;
	it = myset.lower_bound(6);
	std::cout << "value 6 : " << *it << std::endl;
	it = myset.lower_bound(7);
	std::cout << "value 7 : " << *it << std::endl;
	it = myset.lower_bound(8);
	std::cout << "value 8 : " << *it << std::endl;
	it = myset.lower_bound(9);
	std::cout << "value 9 : " << *it << std::endl;
	it = myset.lower_bound(10);
	std::cout << "value 10 : " << *it << std::endl;

	std::cout << "===upper bound===" << std::endl;

	it = myset.upper_bound(-1);
	std::cout << "value -1 : " << *it << std::endl;
	it = myset.upper_bound(0);
	std::cout << "value 0 : " << *it << std::endl;
	it = myset.upper_bound(1);
	std::cout << "value 1 : " << *it << std::endl;
	it = myset.upper_bound(2);
	std::cout << "value 2 : " << *it << std::endl;
	it = myset.upper_bound(3);
	std::cout << "value 3 : " << *it << std::endl;
	it = myset.upper_bound(4);
	std::cout << "value 4 : " << *it << std::endl;
	it = myset.upper_bound(5);
	std::cout << "value 5 : " << *it << std::endl;
	it = myset.upper_bound(6);
	std::cout << "value 6 : " << *it << std::endl;
	it = myset.upper_bound(7);
	std::cout << "value 7 : " << *it << std::endl;
	it = myset.upper_bound(8);
	std::cout << "value 8 : " << *it << std::endl;
	it = myset.upper_bound(9);
	std::cout << "value 9 : " << *it << std::endl;
	it = myset.upper_bound(10);
	std::cout << "value 10 : " << *it << std::endl;

	std::cout << "===equal range===" << std::endl;

	auto pair = myset.equal_range(-1);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(0);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(1);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(2);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(3);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(4);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(5);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(6);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(7);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(8);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(9);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
	pair = myset.equal_range(10);
	std::cout << *(pair.first) << " _ " << *(pair.second) << " " << ((pair.first == pair.second) ? "EQUALS" : "not equals") << std::endl;
}
