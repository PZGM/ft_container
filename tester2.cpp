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

	std::cout << dek[12] << std::endl;
}
