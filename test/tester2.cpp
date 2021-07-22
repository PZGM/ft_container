#include <vector>
#include <map>
#include <iostream>
#include "../Map/Map.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	map<char,int> mp;

	mp['a']=10;
	mp['b']=30;
	mp['c']=50;
	mp['d']=70;
}
