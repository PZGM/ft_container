#include <vector>
#include <list>
#include <iostream>
#include "../LisT/List.hpp"

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
	std::cout << "+++List relational operators+++" << std::endl;
	
	list<int> lst;
	list<int> lst2;

	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	std::cout << "  1  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;

	lst.push_back(4);

	std::cout << "  2  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;

	lst2.push_back(4);

	std::cout << "  3  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	lst.push_back(0);
	lst2.push_back(-42);

	std::cout << "  4  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	lst.clear();
	lst2.clear();
	lst.push_back(2);
	lst.push_back(13);
	lst2.push_back(1);
	lst2.push_back(13);

	std::cout << "  5  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	lst.clear();
	lst2.clear();
	lst.push_back(1);
	lst.push_back(13);
	lst2.push_back(2);
	lst2.push_back(13);

	std::cout << "  6  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	lst.clear();
	lst2.clear();
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst2.push_back(0);
	lst2.push_back(1);
	lst2.push_back(2);
	lst2.push_back(3);
	lst2.push_back(4);

	std::cout << "  7  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	lst.clear();
	lst2.clear();
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst2.push_back(0);
	lst2.push_back(1);
	lst2.push_back(2);
	
	std::cout << "  8  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	lst.clear();
	lst2.clear();
	lst.push_back(-42);
	lst.push_back(-42);
	lst2.push_back(-42);
	lst2.push_back(-42);
	lst2.push_back(-42);
	
	std::cout << "  9  ";
	PrintBool(std::cout << "| == ", lst == lst2);
	PrintBool(std::cout << " | != ", lst != lst2);
	PrintBool(std::cout << " | < ", lst < lst2);
	PrintBool(std::cout << " | > ", lst > lst2);	
	PrintBool(std::cout << " | <= ", lst <= lst2);
	PrintBool(std::cout << " | >= ", lst >= lst2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
}
