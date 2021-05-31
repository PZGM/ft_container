#include <vector>
#include <list>
#include <iostream>
#include "../LisT/List.cpp"
#include "../Vector/Vector.cpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

std::ostream& PrintBool(std::ostream& os, bool rhs)
{
	os << (rhs ? "True " : "FALSE");
	return os;
}

int main()
{
	vector<int> vec(20);

	int i = 1;
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		*it = i;
		i *=2;
	}
	std::cout << "===accessers===" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		std::cout << "_" << vec[i] << std::endl;
		std::cout << "^" << vec.at(i) << std::endl;
	}

	std::cout << "+++Vector relational operators+++" << std::endl;
	
	vec.clear();
	vector<int> vec2;

	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	std::cout << "  1  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;

	vec.push_back(4);

	std::cout << "  2  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;

	vec2.push_back(4);

	std::cout << "  3  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	vec.push_back(0);
	vec2.push_back(-42);

	std::cout << "  4  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	vec.clear();
	vec2.clear();
	vec.push_back(2);
	vec.push_back(13);
	vec2.push_back(1);
	vec2.push_back(13);

	std::cout << "  5  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	vec.clear();
	vec2.clear();
	vec.push_back(1);
	vec.push_back(13);
	vec2.push_back(2);
	vec2.push_back(13);

	std::cout << "  6  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	vec.clear();
	vec2.clear();
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec2.push_back(0);
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);
	vec2.push_back(4);

	std::cout << "  7  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	vec.clear();
	vec2.clear();
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec2.push_back(0);
	vec2.push_back(1);
	vec2.push_back(2);
	
	std::cout << "  8  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	vec.clear();
	vec2.clear();
	vec.push_back(-42);
	vec.push_back(-42);
	vec2.push_back(-42);
	vec2.push_back(-42);
	vec2.push_back(-42);
	
	std::cout << "  9  ";
	PrintBool(std::cout << "| == ", vec == vec2);
	PrintBool(std::cout << " | != ", vec != vec2);
	PrintBool(std::cout << " | < ", vec < vec2);
	PrintBool(std::cout << " | > ", vec > vec2);	
	PrintBool(std::cout << " | <= ", vec <= vec2);
	PrintBool(std::cout << " | >= ", vec >= vec2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	vec.clear();
	vec2.clear();
	std::cout << "===swap two vector of same size===" << std::endl;
	
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);	
	vec.push_back(3);

	vec2.push_back(100);
	vec2.push_back(200);
	vec2.push_back(300);
	vec2.push_back(400);
	
	vec.swap(vec2);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << vec.size() << "|" << vec2.size() << std::endl;
	for (auto it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it << std::endl;

	vec.clear();
	vec2.clear();

	std::cout << "===swap two vector of different size===" << std::endl;
	
	vec.push_back(0);

	vec2.push_back(100);
	vec2.push_back(200);
	vec2.push_back(300);
	vec2.push_back(400);
	
	vec2.swap(vec);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << vec.size() << "|" << vec2.size() << std::endl;
	for (auto it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it << std::endl;
	
	vec.clear();
	vec2.clear();
	
	std::cout << "===swap two vector with one empty===" << std::endl;

	vec2.push_back(100);
	vec2.push_back(200);
	vec2.push_back(300);
	vec2.push_back(400);
	
	vec2.swap(vec);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << vec.size() << "|" << vec2.size() << std::endl;
	for (auto it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it << std::endl;
	
	vec.clear();
	vec2.clear();
	
	std::cout << "===swap with non member function===" << std::endl;

	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);	
	vec.push_back(3);
	
	vec2.push_back(100);
	vec2.push_back(200);
	vec2.push_back(300);
	vec2.push_back(400);
	
	swap(vec, vec2);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << vec.size() << "|" << vec2.size() << std::endl;
	for (auto it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it << std::endl;
	
	vec.clear();
	vec2.clear();
	
	std::cout << "===swap two empty vectors with non member function===" << std::endl;

	swap(vec, vec2);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "____________________" << vec.size() << "|" << vec2.size() << std::endl;
	for (auto it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it << std::endl;
}
