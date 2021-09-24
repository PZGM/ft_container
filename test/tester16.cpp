#include <iostream>
#include <iterator>
#include <typeinfo>
#include <map>
#include "../Map/Map.hpp"
#include "../traits.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	std::cout << "++++Iterator traits with map++++"<<std::endl;
	map<int, int> mp;

	for (int i = 0; i < 10; i++) {
		mp[i] = i;
	}
	typedef iterator_traits<int *> traits;
  	if (typeid(traits::value_type)==typeid((*mp.begin()).first))
    	std::cout << "the key of map<int, int> is a int INCROYABLE"<<std::endl;

  	return 0;
}
