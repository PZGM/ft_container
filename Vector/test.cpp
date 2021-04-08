#include <iostream>
#include "Vector.cpp"

using namespace ft;

int main()
{
	vector<int> vec(5);
	vector<int> vic(5);

	vic.at(4) = 56;
	if (vec == vic)
		std::cout << "mdr" << std::endl;
	else
		std::cout << "tamer" << std::endl;

	return 0;
}
