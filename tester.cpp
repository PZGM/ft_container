#include "Vector/Vector.cpp"
#include <iostream>
#include <vector>

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	vector<int> vec;

	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	vec.insert(vec.begin(), 4, 5);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	vector<int>  vec2 = vec;
	for (auto ite = vec.begin(); ite != vec.end(); ite++)
		std::cout << "_" << *ite << std::endl;

	vec.insert(vec.end(), vec2.begin(), vec2.end());
	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	vec.insert(vec.begin() + 3, vec.begin(), vec.end());
	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

}
