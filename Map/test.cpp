#include <map>
#include "Map.hpp"
#include <iostream>

int main() {
  std::map<char,int> mmap;
  std::map<char,int>::iterator itow,itp;

  mmap['a']=20;
  mmap['b']=40;
  mmap['c']=60;
  mmap['d']=80;
  mmap['e']=100;

  // std::cout << "begin = " << (mmap.begin())->first << std::endl;

  itow=mmap.lower_bound ('b');  // itlow points to b
  itp=mmap.upper_bound ('d');   // itup points to e (not d!)

std::cout << "itow = " << itow->first << " = " << itow->second << std::endl;
std::cout << "itp = " << itp->first << " = " << itp->second << std::endl;
  mmap.erase(itow,itp);        // erases [itlow,itup)

  for (std::map<char,int>::iterator it=mmap.begin(); it!=mmap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

std::cout << "" << std::endl;
std::cout << "" << std::endl;
std::cout << "" << std::endl;

    ft::map<char,int> mymap;
  // ft::map<char,int>::iterator itlow,itup;

	ft::pair<const char, int> pr('a', 20);
	mymap.insert(pr);
	ft::pair<const char, int> pr1('b', 40);
	mymap.insert(pr1);
	ft::pair<const char, int> pr2('c', 60);
	mymap.insert(pr2);
	ft::pair<const char, int> pr3('d', 80);
	mymap.insert(pr3);
	ft::pair<const char, int> pr4('e', 100);
	mymap.insert(pr4);

// std::cout << "my begin = " << (*mymap.begin()).first << std::endl;

  auto itlow=mymap.lower_bound('b');  // itlow points to b
  auto itup=mymap.upper_bound('d');   // itup points to e (not d!)

std::cout << "itlow = " << (*itlow).first << " = " << (*itlow).second << std::endl;
std::cout << "itup = " << (*itup).first << " = " << (*itup).second << std::endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)

  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  return 0;
}