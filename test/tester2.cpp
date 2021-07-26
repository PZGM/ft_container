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

	//insert

    pair<const char, int> a('e', 42);
    mp.insert(a);

    pair<const char, int> b('a', 40);
    mp.insert(b);

    pair<const char, int> c('b', 451);
    auto hint = mp.insert(c).first;

    pair<const char, int> d('d', 5678);
    mp.insert(hint, d);

    pair<const char, int> e('a', 58);
    mp.insert(e);

    pair<const char, int> f('z', 46);
     mp.insert(hint, f);

	std::cout << "Size: " << mp.size() << " Empty: " << mp.empty() << std::cout;

	map<char, int> mp2;
	mp2['a'] = 10;
	mp2['v'] = 11;
	mp2['z'] = 12;

	mp.insert(mp2.begin(), mp2.end());
	
	std::cout << "Size: " << mp.size() << " Empty: " << mp.empty() << std::cout;

	auto it = mp.begin();
	while (it != mp.end())
	{
		std::cout << (*it).first << " | " << (*it).second << std::endl;
		it++;
	}

}
