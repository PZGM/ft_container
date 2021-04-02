#include <vector>
#include <iostream>
#include "Vector.cpp"

using namespace std;

int main()
{
	vector<int> vec(5);
	for (int i = 0; i < 5; i++)
		vec[i] = i;
	for (int i = 0; i < 5; i++)
		std::cout << vec[i] << std::endl;
	vector<int> vic(5);
	//size_type a = 10;
	int b = 42;
	vic.assign(10, 42);
//	vic.assign(vic.begin(), vic.end());
	vector<int>::iterator it = vic.begin();
	for (; it != vic.end(); it++)
		std::cout << *it << std::endl;

	return 0;
}
