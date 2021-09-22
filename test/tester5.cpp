#include <iostream>
#include <iterator>
#include <typeinfo>
#include <vector>
#include "../Vector/Vector.hpp"
#include "../traits.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	std::cout << "++++Iterator traits with vector++++"<<std::endl;
	vector<int> vec1(10);
	for (int i = 0; i < 10; i++) {
		vec1[i] = i;
	}
	typedef iterator_traits<int *> traits;
  	if (typeid(traits::value_type)==typeid(*vec1.begin()))
    	std::cout << "vec(int) is a int INCROYABLE"<<std::endl;
  	return 0;
}
