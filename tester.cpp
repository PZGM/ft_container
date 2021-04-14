#include "Vector/Vector.cpp"
#include <iostream>
#include <vector>

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	vector<int> vec;

	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	vec.insert(vec.begin(), 4, 5);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	vector<int>  vec2 = vec;
	for (auto ite = vec.begin(); ite != vec.end(); ite++)
		std::cout << "_" << *ite << std::endl;

	vec.insert(vec.end(), vec2.begin(), vec2.end());
	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "----------------------" << std::endl;
	vec.insert(vec.begin() + 3, vec.begin(), vec.end());
	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

	std::cout << "empty vec2: " << vec2.empty() << std::endl;

	std::cout << "size vec: " << vec.size() << std::endl;
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		vec.pop_back();

	std::cout << "empty vec: " << vec.empty() << std::endl;
	std::cout << "capacity vec: " << vec.capacity() << std::endl;
	std::cout << "size vec: " << vec.size() << std::endl;
	std::cout << "size_max vec: " << vec.max_size() << std::endl;

	vec.push_back(42);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);

	std::cout << vec.front() << std::endl;
	std::cout << vec.back() << std::endl;

	vec2.insert(vec2.end(), vec.begin(), vec.end());
	vec2.insert(vec2.end(), vec.begin(), vec.end());
	vec.insert(vec.end(), vec.begin(), vec.end());

	std::cout << vec.front() << std::endl;

	vec2.swap(vec);
	vec2.swap(vec);
	vec2.swap(vec);
	vec2.swap(vec2);
	vec2.swap(vec);
	vec2.swap(vec);
	vec.swap(vec);
	vec2.swap(vec);
	vec2.swap(vec);
	vec2.swap(vec);
	vec.swap(vec2);
	vec2.swap(vec);
	vec.swap(vec);
	vec2.swap(vec);
	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it<< std::endl;

	for (auto it = vec2.begin(); it != vec2.end(); it++)
		std::cout << *it<< std::endl;


	vec.assign(vec.begin(), vec.end());
	
	vector<char> chat;

	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	chat.push_back('1');
	vector<vector<char> > *oof = new vector<vector<char> >();

	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);
	oof->push_back(chat);

	vec.clear();
	vec.insert(vec.begin(), chat.begin(), chat.end());

	vector<vector<int> > vic = vector<vector<int> >(5, vec);
	std::cout << "adieu monde cruel, je vais crasher" << std::endl;
	vic.erase(vic.begin());
	delete oof;
}
