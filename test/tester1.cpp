 #include <list>
#include <vector>
#include <iostream>
#include "../Vector/Vector.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	std::cout << "+++Vector constructor and basics with int+++" << std::endl;
	std::cout << "===Default constructor===" << std::endl;
	vector<int> vec1;
	std::cout << vec1.size() << std::endl;
	for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec1.rbegin(); it != vec1.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor===" << std::endl;
	vector<int> vec2(10,10);
	std::cout << vec2.size() << std::endl;
	for (vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec2.rbegin(); it != vec2.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor to empty===" << std::endl;
	vector<int> vec3(0,10);
	std::cout << vec3.size() << std::endl;
	for (vector<int>::iterator it = vec3.begin(); it != vec3.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec3.rbegin(); it != vec3.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor with default values===" << std::endl;
	vector<int> vec4(15);
	std::cout << vec4.size() << std::endl;
	for (vector<int>::iterator it = vec4.begin(); it != vec4.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec4.rbegin(); it != vec4.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor with implicit cast===" << std::endl;
	vector<int> vec5(8,'b');
	std::cout << vec5.size() << std::endl;
	for (vector<int>::iterator it = vec5.begin(); it != vec5.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec5.rbegin(); it != vec5.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Range constructor with empty vector===" << std::endl;
	vector<int> vec6(vec3.begin(), vec3.end());
	std::cout << vec6.size() << std::endl;
	for (vector<int>::iterator it = vec6.begin(); it != vec6.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec6.rbegin(); it != vec6.rend(); it++)
		std::cout << "^" << *it << std::endl;

	//change values of vec5 for incremental values
	
	int i = 0;
	for (vector<int>::iterator it = vec5.begin(); it!= vec5.end(); it++)
		*it = i++;

	for (vector<int>::iterator it = vec5.begin(); it!= vec5.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "===Range constructor===" << std::endl;
	vector<int> vec7(vec5.begin(), vec5.end());
	std::cout << vec7.size() << std::endl;
	for (vector<int>::iterator it = vec7.begin(); it != vec7.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec7.rbegin(); it != vec7.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Range constructor with reverse iterator===" << std::endl;
	vector<int> vec8(vec5.rbegin(), vec5.rend());
	std::cout << vec8.size() << std::endl;
	for (vector<int>::iterator it = vec8.begin(); it != vec8.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec8.rbegin(); it != vec8.rend(); it++)
		std::cout << "^" << *it << std::endl;

	//initialize a list
	std::list<int> lst(6, 8);
	i = 0;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		*it = i++;

	std::cout << "===Range constructor with lst iterators===" << std::endl;
	vector<int> vec9(lst.begin(), lst.end());
	std::cout << vec9.size() << std::endl;
	for (vector<int>::iterator it = vec9.begin(); it != vec9.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec9.rbegin(); it != vec9.rend(); it++)
		std::cout << "^" << *it << std::endl;	


	std::cout << "===Range constructor with partial vector iterators===" << std::endl;
	
	std::list<int>::iterator it = lst.begin();
	it++;
	it++;

	std::list<int>::iterator it2 = lst.end();
	it2--;

	vector<int> vec10(it, it2);
	std::cout << vec10.size() << std::endl;

	vec10.insert(vec10.begin(), lst.begin(), lst.end());

	for (vector<int>::iterator it = vec10.begin(); it != vec10.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec10.rbegin(); it != vec10.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Copy constructor===" << std::endl;
	vector<int> vec11(vec5);
	std::cout << vec11.size() << std::endl;
	for (vector<int>::iterator it = vec11.begin(); it != vec11.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec11.rbegin(); it != vec11.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Copy constructor with empty vector===" << std::endl;
	vector<int> vec12(vec3);
	std::cout << vec12.size() << std::endl;
	for (vector<int>::iterator it = vec12.begin(); it != vec12.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec12.rbegin(); it != vec12.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	std::cout << "===Assign operator with empty vector===" << std::endl;
	vec11 = vec3;
	std::cout << vec11.size() << std::endl;
	for (vector<int>::iterator it = vec11.begin(); it != vec11.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec11.rbegin(); it != vec11.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Assign operator===" << std::endl;
	vec12 = vec5;
	std::cout << vec12.size() << std::endl;
	for (vector<int>::iterator it = vec12.begin(); it != vec12.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (vector<int>::reverse_iterator it = vec12.rbegin(); it != vec12.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	std::cout<< "===empty===" << std::endl;
	std::cout << vec1.empty() << std::endl;
	std::cout << vec2.empty() << std::endl;
	std::cout << vec3.empty() << std::endl;
	std::cout << vec4.empty() << std::endl;
	std::cout << vec5.empty() << std::endl;
	std::cout << vec6.empty() << std::endl;
	std::cout << vec7.empty() << std::endl;
	std::cout << vec8.empty() << std::endl;
	std::cout << vec9.empty() << std::endl;
	std::cout << vec10.empty() << std::endl;
	std::cout << vec11.empty() << std::endl;
	std::cout << vec12.empty() << std::endl;


	std::cout<< "===size===" << std::endl;
	std::cout << vec1.size() << std::endl;
	std::cout << vec2.size() << std::endl;
	std::cout << vec3.size() << std::endl;
	std::cout << vec4.size() << std::endl;
	std::cout << vec5.size() << std::endl;
	std::cout << vec6.size() << std::endl;
	std::cout << vec7.size() << std::endl;
	std::cout << vec8.size() << std::endl;
	std::cout << vec9.size() << std::endl;
	std::cout << vec10.size() << std::endl;
	std::cout << vec11.size() << std::endl;
	std::cout << vec12.size() << std::endl;

	std::cout << "===max size===" << std::endl;
	std::cout << vec1.max_size() << std::endl;

	
	std::cout<< "===front===" << std::endl;
	if (!vec1.empty())
	std::cout << vec1.front() << std::endl;
	if (!vec2.empty())
	std::cout << vec2.front() << std::endl;
	if (!vec3.empty())
	std::cout << vec3.front() << std::endl;
	if (!vec4.empty())
	std::cout << vec4.front() << std::endl;
	if (!vec5.empty())
	std::cout << vec5.front() << std::endl;
	if (!vec6.empty())
	std::cout << vec6.front() << std::endl;
	if (!vec7.empty())
	std::cout << vec7.front() << std::endl;
	if (!vec8.empty())
	std::cout << vec8.front() << std::endl;
	if (!vec9.empty())
	std::cout << vec9.front() << std::endl;
	if (!vec10.empty())
	std::cout << vec10.front() << std::endl;
	if (!vec11.empty())
	std::cout << vec11.front() << std::endl;
	if (!vec12.empty())
	std::cout << vec12.front() << std::endl;
	
	std::cout<< "===back===" << std::endl;
	if (!vec1.empty())
	std::cout << vec1.back() << std::endl;
	if (!vec2.empty())
	std::cout << vec2.back() << std::endl;
	if (!vec3.empty())
	std::cout << vec3.back() << std::endl;
	if (!vec4.empty())
	std::cout << vec4.back() << std::endl;
	if (!vec5.empty())
	std::cout << vec5.back() << std::endl;
	if (!vec6.empty())
	std::cout << vec6.back() << std::endl;
	if (!vec7.empty())
	std::cout << vec7.back() << std::endl;
	if (!vec8.empty())
	std::cout << vec8.back() << std::endl;
	if (!vec9.empty())
	std::cout << vec9.back() << std::endl;
	if (!vec10.empty())
	std::cout << vec10.back() << std::endl;
	if (!vec11.empty())
	std::cout << vec11.back() << std::endl;
	if (!vec12.empty())
	std::cout << vec12.back() << std::endl;

	std::cout<< "===reserve===" << std::endl;
	std::cout << vec5.capacity() << "|" << vec5.size() << std::endl;
	vec5.reserve(40);
	std::cout << vec5.capacity() << "|" << vec5.size() << std::endl;


	std::cout<< "===iterator comparison===" << std::endl;

	vector<int>::iterator iter = vec1.begin();
	vector<int>::const_iterator const_iter = vec1.begin();

	if (const_iter == iter)
		std::cout << "Iterators equals" << std::endl;
	else
		std::cout << "Iterators not equals" << std::endl;

	iter = vec1.begin() + 1;

	if (const_iter == iter)
		std::cout << "Iterators equals" << std::endl;
	else
		std::cout << "Iterators not equals" << std::endl;

}
