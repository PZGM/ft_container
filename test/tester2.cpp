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

    pair<const char, int> x('e', 42);
    mp.insert(x);

    pair<const char, int> y('a', 40);
    auto bate = mp.insert(y).first;

    pair<const char, int> z('b', 451);
    mp.insert(z);

    pair<const char, int> t('d', 5678);
    mp.insert(t);

    pair<const char, int> u('a', 5678);
    mp.insert(u);

    pair<const char, int> v('z', 5678);
    auto chibre = mp.insert(v).first;

    mp.erase(chibre);
    mp.erase('e');

    pair<const char, int> w('Z', 5678);
    mp.insert(w);

    map<char, int> pm;
    pm.insert(mp.begin(), mp.end());

    std::cout << mp.count('a') << std::endl;
    std::cout << "|||||||"  << std::endl;
    std::cout << mp.count('j') << std::endl;
    std::cout << "|||||||"  << std::endl;

    std::cout << (*mp.lower_bound('a')).first << std::endl;
    std::cout << "-----"  << std::endl;
    std::cout <<(*mp.lower_bound('c')).first << std::endl;
    std::cout << "-----"  << std::endl;
    std::cout << (*mp.lower_bound('X')).first << std::endl;
    std::cout << "-----"  << std::endl;

    std::cout << (*mp.upper_bound('a')).first << std::endl;
    std::cout << "++++++"  << std::endl;
    std::cout << (*mp.upper_bound('c')).first << std::endl;
    std::cout << "++++++"  << std::endl;
    std::cout << (*mp.upper_bound('X')).first << std::endl;
    std::cout << "++++++"  << std::endl;


    //mp['d'] = 34567;

    std::cout << mp.size() << std::endl;

    auto it = pm.begin();
    while (it != pm.end())
    {
        std::cout << (*it).first << " | " << (*it).second << std::endl;
        it++;
    }

}
