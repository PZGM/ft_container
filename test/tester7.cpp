#include <vector>
#include <list>
#include <iostream>
#include "../LisT/List.hpp"
#include "../Vector/Vector.hpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	std::cout << "+++List constructor and basics with int+++" << std::endl;
	std::cout << "===Default constructor===" << std::endl;
	list<int> lst1;
	std::cout << lst1.size() << std::endl;
	for (list<int>::iterator it = lst1.begin(); it != lst1.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst1.rbegin(); it != lst1.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor===" << std::endl;
	list<int> lst2(10,10);
	std::cout << lst2.size() << std::endl;
	for (list<int>::iterator it = lst2.begin(); it != lst2.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst2.rbegin(); it != lst2.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor to empty===" << std::endl;
	list<int> lst3(0,10);
	std::cout << lst3.size() << std::endl;
	for (list<int>::iterator it = lst3.begin(); it != lst3.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst3.rbegin(); it != lst3.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor with default values===" << std::endl;
	list<int> lst4(15);
	std::cout << lst4.size() << std::endl;
	for (list<int>::iterator it = lst4.begin(); it != lst4.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst4.rbegin(); it != lst4.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor with implicit cast===" << std::endl;
	list<int> lst5(8,'b');
	std::cout << lst5.size() << std::endl;
	for (list<int>::iterator it = lst5.begin(); it != lst5.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst5.rbegin(); it != lst5.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Range constructor with empty list===" << std::endl;
	list<int> lst6(lst3.begin(), lst3.end());
	std::cout << lst6.size() << std::endl;
	for (list<int>::iterator it = lst6.begin(); it != lst6.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst6.rbegin(); it != lst6.rend(); it++)
		std::cout << "^" << *it << std::endl;

	//change values of lst5 for incremental values
	
	int i = 0;
	for (list<int>::iterator it = lst5.begin(); it!= lst5.end(); it++)
		*it = i++;

	std::cout << "===Range constructor===" << std::endl;
	list<int> lst7(lst5.begin(), lst5.end());
	std::cout << lst7.size() << std::endl;
	for (list<int>::iterator it = lst7.begin(); it != lst7.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst7.rbegin(); it != lst7.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Range constructor with reverse iterator===" << std::endl;
	list<int> lst8(lst5.rbegin(), lst5.rend());
	std::cout << lst8.size() << std::endl;
	for (list<int>::iterator it = lst8.begin(); it != lst8.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst8.rbegin(); it != lst8.rend(); it++)
		std::cout << "^" << *it << std::endl;

	//initialize a vector
	vector<int> vec(6, 8);
	i = 0;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		*it = i++;

	std::cout << "===Range constructor with vector iterators===" << std::endl;
	list<int> lst9(vec.begin(), vec.end());
	std::cout << lst9.size() << std::endl;
	for (list<int>::iterator it = lst9.begin(); it != lst9.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst9.rbegin(); it != lst9.rend(); it++)
		std::cout << "^" << *it << std::endl;	


	std::cout << "===Range constructor with partial vector iterators===" << std::endl;
	list<int> lst10(vec.begin() + 2, vec.end() - 1);
	std::cout << lst10.size() << std::endl;
	
	lst10.insert(lst10.begin(), vec.begin(), vec.end());

	for (list<int>::iterator it = lst10.begin(); it != lst10.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst10.rbegin(); it != lst10.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Copy constructor===" << std::endl;
	list<int> lst11(lst5);
	std::cout << lst11.size() << std::endl;
	for (list<int>::iterator it = lst11.begin(); it != lst11.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst11.rbegin(); it != lst11.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Copy constructor with empty list===" << std::endl;
	list<int> lst12(lst3);
	std::cout << lst12.size() << std::endl;
	for (list<int>::iterator it = lst12.begin(); it != lst12.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst12.rbegin(); it != lst12.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	std::cout << "===Assign operator with empty list===" << std::endl;
	lst11 = lst3;
	std::cout << lst11.size() << std::endl;
	for (list<int>::iterator it = lst11.begin(); it != lst11.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst11.rbegin(); it != lst11.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Assign operator===" << std::endl;
	lst12 = lst5;
	std::cout << lst12.size() << std::endl;
	for (list<int>::iterator it = lst12.begin(); it != lst12.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (list<int>::reverse_iterator it = lst12.rbegin(); it != lst12.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	std::cout<< "===empty===" << std::endl;
	std::cout << lst1.empty() << std::endl;
	std::cout << lst2.empty() << std::endl;
	std::cout << lst3.empty() << std::endl;
	std::cout << lst4.empty() << std::endl;
	std::cout << lst5.empty() << std::endl;
	std::cout << lst6.empty() << std::endl;
	std::cout << lst7.empty() << std::endl;
	std::cout << lst8.empty() << std::endl;
	std::cout << lst9.empty() << std::endl;
	std::cout << lst10.empty() << std::endl;
	std::cout << lst11.empty() << std::endl;
	std::cout << lst12.empty() << std::endl;


	std::cout<< "===size===" << std::endl;
	std::cout << lst1.size() << std::endl;
	std::cout << lst2.size() << std::endl;
	std::cout << lst3.size() << std::endl;
	std::cout << lst4.size() << std::endl;
	std::cout << lst5.size() << std::endl;
	std::cout << lst6.size() << std::endl;
	std::cout << lst7.size() << std::endl;
	std::cout << lst8.size() << std::endl;
	std::cout << lst9.size() << std::endl;
	std::cout << lst10.size() << std::endl;
	std::cout << lst11.size() << std::endl;
	std::cout << lst12.size() << std::endl;

	std::cout << "===max size===" << std::endl;
	std::cout << lst1.max_size() << std::endl;

	
	std::cout<< "===front===" << std::endl;
	if (!lst1.empty())
	std::cout << lst1.front() << std::endl;
	if (!lst2.empty())
	std::cout << lst2.front() << std::endl;
	if (!lst3.empty())
	std::cout << lst3.front() << std::endl;
	if (!lst4.empty())
	std::cout << lst4.front() << std::endl;
	if (!lst5.empty())
	std::cout << lst5.front() << std::endl;
	if (!lst6.empty())
	std::cout << lst6.front() << std::endl;
	if (!lst7.empty())
	std::cout << lst7.front() << std::endl;
	if (!lst8.empty())
	std::cout << lst8.front() << std::endl;
	if (!lst9.empty())
	std::cout << lst9.front() << std::endl;
	if (!lst10.empty())
	std::cout << lst10.front() << std::endl;
	if (!lst11.empty())
	std::cout << lst11.front() << std::endl;
	if (!lst12.empty())
	std::cout << lst12.front() << std::endl;
	
	std::cout<< "===back===" << std::endl;
	if (!lst1.empty())
	std::cout << lst1.back() << std::endl;
	if (!lst2.empty())
	std::cout << lst2.back() << std::endl;
	if (!lst3.empty())
	std::cout << lst3.back() << std::endl;
	if (!lst4.empty())
	std::cout << lst4.back() << std::endl;
	if (!lst5.empty())
	std::cout << lst5.back() << std::endl;
	if (!lst6.empty())
	std::cout << lst6.back() << std::endl;
	if (!lst7.empty())
	std::cout << lst7.back() << std::endl;
	if (!lst8.empty())
	std::cout << lst8.back() << std::endl;
	if (!lst9.empty())
	std::cout << lst9.back() << std::endl;
	if (!lst10.empty())
	std::cout << lst10.back() << std::endl;
	if (!lst11.empty())
	std::cout << lst11.back() << std::endl;
	if (!lst12.empty())
	std::cout << lst12.back() << std::endl;

}
