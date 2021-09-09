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
    map<char,int> map1;

	std::cout << "===Map===" << std::endl;
	std::cout << "===Constructors===" << std::endl;
	std::cout << "___default constructor___" << std::endl;

	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "empty ? : " << map1.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	auto it = map1.begin();
	while (it != map1.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	auto ite = map1.rbegin();
	while (ite != map1.rend())
	{
		auto pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___manual fill___" << std::endl;

	map1['a'] = 75;
	map1['z'] = 32;
	map1['e'] = 42;

	std::cout << "size : " << map1.size() << std::endl;
	std::cout << "empty ? : " << map1.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = map1.begin();
	while (it != map1.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map1.rbegin();
	while (ite != map1.rend())
	{
		auto pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___range constructor___" << std::endl;

	map<char,int> map2(map1.begin(), map1.begin());

	std::cout << "size : " << map2.size() << std::endl;
	std::cout << "empty ? : " << map2.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = map2.begin();
	while (it != map2.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map2.rbegin();
	while (ite != map2.rend())
	{
		auto pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "___copy constructor___" << std::endl;

	map<char,int> map3(map1);

	std::cout << "size : " << map3.size() << std::endl;
	std::cout << "empty ? : " << map3.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = map3.begin();
	while (it != map3.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map3.rbegin();
	while (ite != map3.rend())
	{
		auto pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}


	std::cout << "___empty copy constructor___" << std::endl;

	map<char,int> map4;
	map<char,int> map5(map4);

	std::cout << "size : " << map5.size() << std::endl;
	std::cout << "empty ? : " << map5.empty() << std::endl;
	std::cout << "normal :" << std::endl;
	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map5.rbegin();
	while (ite != map5.rend())
	{
		auto pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "===MAX SIZE = " << map5.max_size() << " ===" << std::endl;

	std::cout << "===Acces Read===" << std::endl;

	std::cout << "map1['a'] = "<< map1['a'] << std::endl;
	std::cout << "map1['b'] = "<< map1['b'] << std::endl;
	std::cout << "map1['c'] = "<< map1['c'] << std::endl;

	std::cout << "===Acces Read/Write===" << std::endl;

	std::cout << "size = " << map1.size() << std::endl;
	
	map1['c'] = 46;
	map1['g'] = 451;
	map1['A'] = 421;

	std::cout << "size = " << map1.size() << std::endl;
	
	std::cout << "map1['a'] = "<< map1['a'] << std::endl;
	std::cout << "map1['b'] = "<< map1['b'] << std::endl;
	std::cout << "map1['c'] = "<< map1['c'] << std::endl;
	std::cout << "map1['g'] = "<< map1['g'] << std::endl;
	std::cout << "map1['A'] = "<< map1['A'] << std::endl;

	std::cout << "===Inserts===" << std::endl;
	
	std::cout << "size : " << map5.size() << std::endl;
	
    pair<const char, int> a('e', 42);
    map5.insert(a);

    pair<const char, int> b('c', 41);
    map5.insert(b);

    pair<const char, int> c('e', 40);
    map5.insert(c);

    pair<const char, int> d('f', 451);
    auto hint = map5.insert(c).first;
	map5.insert(hint, d);
	
	std::cout << "size : " << map5.size() << std::endl;

	std::cout << "normal :" << std::endl;
	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	std::cout << "reverse :" << std::endl;

	ite = map5.rbegin();
	while (ite != map5.rend())
	{
		auto pr = *ite;
		std::cout << pr.first << " | " << pr.second << std::endl;
		ite++;
	}

	std::cout << "===Erase===" << std::endl;

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}

	std::cout << "___erase with it___" << std::endl;
	it = map5.find('c');
	map5.erase(it);

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}

	std::cout << "___erase with key___" << std::endl;
	map5.erase('f');

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	
	std::cout << "___erase everything with range___" << std::endl;
	map5.erase(map5.begin(), map5.end());

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}

	std::cout << "===Swap===" << std::endl;

	map5['a'] = 1;
	map5['b'] = 2;
	map5['c'] = 3;
	map5['d'] = 4;

	std::cout << "A:";
	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl<< "B:";
	it = map4.begin();
	while (it != map4.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl;
	
	std::cout << "+++SWAP !+++" << std::endl;
	map4.swap(map5);

	std::cout << "A:";
	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl<< "B:";
	it = map4.begin();
	while (it != map4.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "sizeA : " << map5.size() << " | sizeB : " << map4.size() << std::endl;

	std::cout << "______________" << std::endl;
	map5['z'] = 5;
	map5['b'] = 6;
	map5['h'] = 7;
	map5['i'] = 8;

	std::cout << "A:";
	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl<< "B:";
	it = map4.begin();
	while (it != map4.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "sizeA : " << map5.size() << " | sizeB : " << map4.size() << std::endl;
	
	std::cout << "+++SWAP !+++" << std::endl;
	swap(map4,map5);

	std::cout << "A:";
	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl<< "B:";
	it = map4.begin();
	while (it != map4.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << " : ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "===Clear===" << std::endl;

	map5.clear();

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	
	std::cout << "___reclear the same map___" << std::endl;

	map5.clear();

	std::cout << "size : " << map5.size() << std::endl;

	it = map5.begin();
	while (it != map5.end())
	{
		auto pr = *it;
		std::cout << pr.first << " | " << pr.second << std::endl;
		it++;
	}
	
	std::cout << "===Find===" << std::endl;



}
