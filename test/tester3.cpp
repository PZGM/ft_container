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

	std::cout << "=============Bound Basic Test==========" << std::endl;
	for (int i = 1; i < 10; i++)
		myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
	itlow	= myset.lower_bound(30);
	itup	= myset.upper_bound(60);
	std::cout<< "lower = " << *itlow <<" upper = " << *itup << std::endl;
	myset.erase(itlow,itup);                     // 10 20 70 80 90
	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	for (auto it = myset.rbegin(); it != myset.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "=============Insert Basic Test==========" << std::endl;
	myset.insert(9);
	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	for (auto it = myset.rbegin(); it != myset.rend(); ++it)
		std::cout << ' ' << *it;
	myset.insert(10);
	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	for (auto it = myset.rbegin(); it != myset.rend(); ++it)
		std::cout << ' ' << *it;
	myset.insert(11);
	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	for (auto it = myset.rbegin(); it != myset.rend(); ++it)
		std::cout << ' ' << *it;

	list<int> lst;
	lst.push_front(17);
	lst.push_front(19);
	lst.push_front(20);
	lst.push_front(31);
	lst.push_front(99);

	myset.insert(lst.rbegin(), lst.rend());

	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	for (auto it = myset.rbegin(); it != myset.rend(); ++it)
		std::cout << ' ' << *it << std::endl;

	std::cout << "=============Erase Basic Test==========" << std::endl;

	myset.erase(17);

	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout <<  std::endl;
	for (auto it = myset.rbegin(); it != myset.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout <<  std::endl;
	myset.erase(30);

	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout <<  std::endl;
	for (auto it = myset.rbegin(); it != myset.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout <<  std::endl;
	//myset.erase(myset.begin() + 2, myset.end() - 2);
	std::cout << "begin = " << *(myset.begin()) << std::endl;
	myset.erase(myset.begin());
	if (myset.begin() != myset.end())
		std::cout << "lol" << std::endl;
	std::cout << "begin = " << *(myset.begin()) << std::endl;
	myset.erase(myset.begin());
	std::cout << "begin = " << *(myset.begin()) << std::endl;
	myset.erase(myset.begin());
	std::cout << "begin = " << *(myset.begin()) << std::endl;
	myset.erase(myset.begin());
	std::cout << "++++++++" << myset.size() << std::endl;
	for (auto it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it; 
	std::cout <<  std::endl;
	for (auto it = myset.rbegin(); it != myset.rend(); ++it)
		std::cout << ' ' << *it;
}
