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
	deque<int> dek(32, 33);
	for (int i = 0; i < 32; i++)
		dek[i] = i;
	dek.push_front(424242);
	dek.push_front(424242);
	//dek.pop_front();
	dek.push_back(3232);
	dek.push_back(3232);
	//dek.pop_back();
	auto it = dek.begin();
	for (; it != dek.end(); it++)
	{
		std::cout << "_" << *it << std::endl;
	}
}
