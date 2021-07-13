#include "../DeQue/Deque.hpp"
#include <iostream>
#include <deque>

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	deque<int> dek;

	dek.push_back(0);
	dek.push_back(0);
	dek.push_back(0);
	dek.push_back(1);
	dek.push_back(2);

	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	dek.insert(dek.begin(), 4, 5);

	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	deque<int>  dek2 = dek;
	for (auto ite = dek.begin(); ite != dek.end(); ite++)
		std::cout << "_" << *ite << std::endl;

	dek.insert(dek.end(), dek2.begin(), dek2.end());
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	dek.insert(dek.begin() + 3, dek.begin(), dek.end());
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "empty dek2: " << dek2.empty() << std::endl;

	std::cout << "size dek: " << dek.size() << std::endl;
	for (deque<int>::reverse_iterator it = dek.rbegin(); it != dek.rend(); it++)
		dek.pop_back();

	std::cout << "empty dek: " << dek.empty() << std::endl;
	std::cout << "size dek: " << dek.size() << std::endl;
	std::cout << "size_max dek: " << dek.max_size() << std::endl;

	dek.push_back(42);
	dek.push_back(2);
	dek.push_back(3);
	dek.push_back(4);
	dek.push_back(5);
	dek.push_back(6);

	std::cout << dek.front() << std::endl;
	std::cout << dek.back() << std::endl;

	dek2.insert(dek2.end(), dek.begin(), dek.end());
	dek2.insert(dek2.end(), dek.begin(), dek.end());
	dek.insert(dek.end(), dek.begin(), dek.end());

	std::cout << dek.front() << std::endl;

	dek2.swap(dek);
	dek2.swap(dek);
	dek2.swap(dek);
	dek2.swap(dek2);
	dek2.swap(dek);
	dek2.swap(dek);
	dek.swap(dek);
	dek2.swap(dek);
	dek2.swap(dek);
	dek2.swap(dek);
	dek.swap(dek2);
	dek2.swap(dek);
	dek.swap(dek);
	dek2.swap(dek);
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << *it<< std::endl;

	for (auto it = dek2.begin(); it != dek2.end(); it++)
		std::cout << *it<< std::endl;


	dek.assign(dek.begin(), dek.end());
	
	deque<char> chat;

	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	deque<deque<char> > *oof = new deque<deque<char> >();

	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);

	dek.clear();
	dek.insert(dek.begin(), chat.begin(), chat.end());

	deque<deque<int> > vic = deque<deque<int> >(5, dek);
	vic.erase(vic.begin());
	delete oof;
}
