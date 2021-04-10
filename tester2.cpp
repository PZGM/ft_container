#include <vector>
#include <iostream>
#include "DeQue/Deque.cpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	vector<int> dek(121, 42);
	
	for (int i = 0; i < 121; i++)
		dek[i] = i;
	dek.pop_back();
	auto it = dek.rbegin();
	for (; it != dek.rend(); it++)
		std::cout << "_" << *it << std::endl;
}
