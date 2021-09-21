#include <map>
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

    std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['a']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}