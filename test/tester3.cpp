#include <vector>
#include <deque>
#include <iostream>
#include <stack>
#include "../Stack/Stack.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif


int main()
{
	stack<int> stk;
	stk.push(42);
	stk.push(42);
	stk.pop();
	std::cout << stk.size() << std::endl;
	for (int i = 0; i < 50 ; i++)
		stk.push(i);
	for (int i = 50; i; i--)
	{
		std::cout <<stk.size() << ":"<< stk.top() << std::endl;
		stk.pop();
	}
	std::cout << stk.empty() << std::endl;
	stack<int> stonks;
	std::cout << (stk > stonks) << std::endl;
}
