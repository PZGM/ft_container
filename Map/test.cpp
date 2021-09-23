#include <map>
#include "Map.hpp"
#include <iostream>

int main() {
  ft::map<char,int> mymap;

	mymap['a']=20;
	// mymap['b']=40;
	// mymap['c']=60;
	// mymap['d']=80;
	mymap['e']=100;


	ft::map<char, int>::iterator	itow = mymap.lower_bound ('b');  // itlow points to b
	ft::map<char, int>::iterator	itp = mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itow,itp);        // erases [itlow,itup)

	for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << (*it).first << " =er> " << (*it).second << '\n';


  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << (*ret.first).first << " => " << (*ret.first).second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << (*ret.second).first << " => " << (*ret.second).second << '\n';

  std::map<char,int> mmap;

	mmap['a']=20;
	// mmap['b']=40;
	// mmap['c']=60;
	// mmap['d']=80;
	mmap['e']=100;

	std::map<char, int>::iterator	itlow = mmap.lower_bound ('b');  // itlow points to b
	std::map<char, int>::iterator	itlp = mmap.upper_bound ('d');   // itup points to e (not d!)

	mmap.erase(itlow,itlp);        // erases [itlow,itup)

	for (std::map<char,int>::iterator it = mmap.begin(); it != mmap.end(); ++it)
		std::cout << (*it).first << " =et> " << (*it).second << '\n';


  std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> rt = mmap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << (*rt.first).first << " => " << (*rt.first).second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << (*rt.second).first << " => " << (*rt.second).second << '\n';

  return 0;
}