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
	map<char, int>				mmap;

	mmap['a']=20;
	mmap['b']=40;
	mmap['c']=60;
	mmap['d']=80;
	mmap['e']=100;

	map<char, int>::const_iterator	itow = mmap.lower_bound ('b');  // itlow points to b
	map<char, int>::const_iterator	itp = mmap.upper_bound ('d');   // itup points to e (not d!)

	mmap.erase(itow,itp);        // erases [itlow,itup)

	for (map<char,int>::iterator it = mmap.begin(); it != mmap.end(); ++it)
		std::cout << (*it).first << " => " << (*it).second << '\n';



  pair<map<char,int>::iterator,map<char,int>::iterator> ret = mmap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << (*ret.first).first << " => " << (*ret.first).second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << (*ret.second).first << " => " << (*ret.second).second << '\n';



  return 0;
}