#include <vector>
#include <deque>
#include <iostream>
#include "../DeQue/Deque.cpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	std::cout << "+++Deque modifiers+++" << std::endl;
	deque<int> dek;

	std::cout << "===insert begin===" << std::endl;
	for (int i = 0; i < 15; i++)
		dek.insert(dek.begin(), i);
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	dek.clear();
	
	std::cout << "===insert end===" << std::endl;
	for (int i = 0; i < 15; i++)
		dek.insert(dek.end(), i);
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	dek.clear();

	std::cout << "===insert returns===" << std::endl;
	for (int i = 0; i < 15; i++)
	{
		auto r = dek.insert(dek.begin(), i);
		std::cout << "_" << *r << std::endl;
	}
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	//create incremental vector and deque
	vector<int> vec(10);
	for (int i = 0; i < 10; i++)
		vec[i] = i;
	
	int i = 0;
	deque<int> deke(10);
	for (auto it = deke.begin(); it != deke.end(); it++)
	{
		*it = i;
		i++;
	}

	for (auto it = deke.begin(); it != deke.end(); it++)
		std::cout << "||" << *it << std::endl;

	dek.clear();

	std::cout << "===insert with interval==" << std::endl;
	std::cout << "___________" << *(deke.begin()) << std::endl;
	dek.insert(dek.begin(), deke.begin(), deke.end());
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;

	dek.clear();

	std::cout << "===insert with vector interval==" << std::endl;
	dek.insert(dek.begin(), vec.begin(), vec.end());
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===insert itself==" << std::endl;
	auto it = dek.begin();
	it++;
	it++;
	dek.insert(it, dek.begin(), dek.end());
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	std::cout << "===assign==" << std::endl;
	dek.assign(deke.begin(), deke.end());
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign itself==" << std::endl;
	dek.assign(dek.begin(), dek.end());
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign with vector==" << std::endl;
	dek.assign(vec.begin(), vec.end());
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===assign with values==" << std::endl;
	dek.assign(13,14);
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;

	std::cout << "===push back/front==" << std::endl;
	dek.push_back(0);
	dek.push_back(1);
//	dek.push_front(42);
//	dek.push_front(3);
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;
	
	std::cout << "===pop back/front==" << std::endl;
	dek.pop_back();
	dek.pop_front();
	for (auto it = dek.begin(); it != dek.end(); it++)
		std::cout << "_" << *it << std::endl;
}
