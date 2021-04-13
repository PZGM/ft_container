#include <vector>
#include <deque>
#include <iostream>
#include "DeQue/Deque.cpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	deque<int> dek(30, 42);
	std::cout << dek.size() << std::endl;	
	for (int i = 0; i < 12; i++)
		dek[i] = i;
	auto it = dek.begin();
	for (; it != dek.end(); it++)
	{
		std::cout << "+" << &*it << std::endl;
		std::cout << "_" << *it << std::endl;
	}
}
