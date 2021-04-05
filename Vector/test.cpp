#include <vector>
#include <iostream>
#include "Vector.cpp"

using namespace std;

int main()
{
	vector<int> bite(3);
	vector<int> vic(10);
	for (int i = 0; i < 10; i++)
		vic[i] = i;
	vector<int>::iterator itbite = vic.begin();
//	vic.assign(bite.begin(), bite.end());
	vic.insert(itbite, (size_t)-7, 7);
//	vic.insert(itbite, bite.begin(), bite.begin() + 2);
	vector<int>::iterator it = vic.begin();
	for (; it != vic.end(); it++)
		std::cout << *it << std::endl;

	return 0;
}
