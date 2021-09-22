#include <map>
#include "Map.hpp"
#include <iostream>

int main() {
    // std::map<char, int> map;
    // map['a'] = 14;
    // auto it = map.begin();
    // std::cout << "yo" << std::endl;
    // std::cout << (*it).first << std::endl;
    // it++;
    // it++;
    // std::cout << "ya" << std::endl;
    // std::cout << (*it).first << std::endl;
    // std::cout << "yi" << std::endl;

    ft::map<char,int> mymap;
  // std::map<char,int>::iterator itlow,itup;

	ft::pair<const char, int> pr('a', 20);
	mymap.insert(pr);
	ft::pair<const char, int> pr1('a', 40);
	mymap.insert(pr1);
	ft::pair<const char, int> pr2('c', 60);
	mymap.insert(pr2);
	ft::pair<const char, int> pr3('d', 80);
	mymap.insert(pr3);
	ft::pair<const char, int> pr4('e', 100);
	mymap.insert(pr4);

  // mymap['a']=20;
  // mymap['a']=40;
  // mymap['c']=60;
  // mymap['d']=80;
  // mymap['e']=100;

  auto itlow=mymap.lower_bound('b');  // itlow points to b
  auto itup=mymap.upper_bound('d');   // itup points to e (not d!)

  // mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  // for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  return 0;
}