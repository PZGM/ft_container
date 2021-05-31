#include <list>
#include <iostream>
#include <queue>
#include <vector>
#include "../Queue/Queue.hpp"
#include "../LisT/List.cpp"

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

void clear(queue<int> & ke)
{
	while (ke.size())
		ke.pop();
}

int main()
{
				
	std::cout << "+++Queue relational operators+++" << std::endl;
	
	queue<int> ke;
	queue<int> ke2;

	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	std::cout << "  1  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;

	ke.push(4);

	std::cout << "  2  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;

	ke2.push(4);

	std::cout << "  3  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	ke.push(0);
	ke2.push(-42);

	std::cout << "  4  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(ke);
	clear(ke2);
	ke.push(2);
	ke.push(13);
	ke2.push(1);
	ke2.push(13);

	std::cout << "  5  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(ke);
	clear(ke2);
	ke.push(1);
	ke.push(13);
	ke2.push(2);
	ke2.push(13);

	std::cout << "  6  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(ke);
	clear(ke2);
	ke.push(0);
	ke.push(1);
	ke.push(2);
	ke.push(3);
	ke2.push(0);
	ke2.push(1);
	ke2.push(2);
	ke2.push(3);
	ke2.push(4);

	std::cout << "  7  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(ke);
	clear(ke2);
	ke.push(0);
	ke.push(1);
	ke.push(2);
	ke.push(3);
	ke2.push(0);
	ke2.push(1);
	ke2.push(2);
	
	std::cout << "  8  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
	
	clear(ke);
	clear(ke2);
	ke.push(-42);
	ke.push(-42);
	ke2.push(-42);
	ke2.push(-42);
	ke2.push(-42);
	
	std::cout << "  9  ";
	PrintBool(std::cout << "| == ", ke == ke2);
	PrintBool(std::cout << " | != ", ke != ke2);
	PrintBool(std::cout << " | < ", ke < ke2);
	PrintBool(std::cout << " | > ", ke > ke2);	
	PrintBool(std::cout << " | <= ", ke <= ke2);
	PrintBool(std::cout << " | >= ", ke >= ke2) << " |" << std::endl;;
	std::cout << "-----|----------|----------|---------|---------|----------|----------|" << std::endl;
}
