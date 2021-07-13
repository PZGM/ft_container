#include <vector>
#include <deque>
#include <iostream>
#include "../DeQue/Deque.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif


//custom binary predict
bool cbp (int first, int second)
{ return ( second == first + 1); }

int main()
{
	deque<int> dek;
	deque<int> dek2;

	std::cout << "===swap two deque of same size===" << std::endl;
	
	dek.push_back(0);
	dek.push_back(1);
	dek.push_back(2);	
	dek.push_back(3);

	dek2.push_back(100);
	dek2.push_back(200);
	dek2.push_back(300);
	dek2.push_back(400);
	
	dek.swap(dek2);

	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << dek.size() << "|" << dek2.size() << std::endl;
	for (auto it = dek2.begin(); it != dek2.end(); it++)
		std::cout << *it << std::endl;

	dek.clear();
	dek2.clear();

	std::cout << "===swap two deque of different size===" << std::endl;
	
	dek.push_back(-1);

	dek2.push_back(-100);
	dek2.push_back(-200);
	dek2.push_back(-300);
	dek2.push_back(-400);
	
	dek2.swap(dek);

	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << dek.size() << "|" << dek2.size() << std::endl;
	for (auto it = dek2.begin(); it != dek2.end(); it++)
		std::cout << *it << std::endl;

	dek.clear();
	dek2.clear();
	
	std::cout << "===swap two deque with one empty===" << std::endl;

	dek2.push_back(100);
	dek2.push_back(200);
	dek2.push_back(300);
	dek2.push_back(400);
	
	dek2.swap(dek);

	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << dek.size() << "|" << dek2.size() << std::endl;
	for (auto it = dek2.begin(); it != dek2.end(); it++)
		std::cout << *it << std::endl;
	
	dek.clear();
	dek2.clear();
	
	std::cout << "===swap with non member function===" << std::endl;

	dek.push_back(0);
	dek.push_back(1);
	dek.push_back(2);	
	dek.push_back(3);
	
	dek2.push_back(100);
	dek2.push_back(200);
	dek2.push_back(300);
	dek2.push_back(400);
	
	swap(dek, dek2);

	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << dek.size() << "|" << dek2.size() << std::endl;
	for (auto it = dek2.begin(); it != dek2.end(); it++)
		std::cout << *it << std::endl;
	
	dek.clear();
	dek2.clear();
	
	std::cout << "===swap two empty deques with non member function===" << std::endl;

	swap(dek, dek2);

	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << dek.size() << "|" << dek2.size() << std::endl;
	for (auto it = dek2.begin(); it != dek2.end(); it++)
		std::cout << *it << std::endl;
}
