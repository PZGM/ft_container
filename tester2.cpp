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
	deque<int> dek(123, 42);
	
	for (int i = 0; i < 123; i++)
		dek[i] = i;
	for (int i = 0; i < 123; i++)
		std::cout << i << std::endl;
}
