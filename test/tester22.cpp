#include <vector>
#include <deque>
#include <iostream>
#include "../DeQue/Deque.cpp"
//#include "../Vector/Vector.cpp"

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif

int main()
{
	std::cout << "+++Deque constructor and basics with int+++" << std::endl;
	std::cout << "===Default constructor===" << std::endl;
	deque<int> dek1;
	std::cout << dek1.size() << std::endl;
	for (auto it = dek1.begin(); it != dek1.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek1.rbegin(); it != dek1.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor===" << std::endl;
	deque<int> dek2(10,10);
	std::cout << dek2.size() << std::endl;
	for (auto it = dek2.begin(); it != dek2.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek2.rbegin(); it != dek2.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor to empty===" << std::endl;
	deque<int> dek3(0,10);
	std::cout << dek3.size() << std::endl;
	for (auto it = dek3.begin(); it != dek3.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek3.rbegin(); it != dek3.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor with default values===" << std::endl;
	deque<int> dek4(15);
	std::cout << dek4.size() << std::endl;
	for (auto it = dek4.begin(); it != dek4.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek4.rbegin(); it != dek4.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Fill constructor with implicit cast===" << std::endl;
	deque<int> dek5(8,'b');
	std::cout << dek5.size() << std::endl;
	for (auto it = dek5.begin(); it != dek5.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek5.rbegin(); it != dek5.rend(); it++)
		std::cout << "^" << *it << std::endl;

	std::cout << "===Range constructor with empty deque===" << std::endl;
	deque<int> dek6(dek3.begin(), dek3.end());
	std::cout << dek6.size() << std::endl;
	for (auto it = dek6.begin(); it != dek6.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek6.rbegin(); it != dek6.rend(); it++)
		std::cout << "^" << *it << std::endl;

	//change values of dek5 for incremental values
	
	int i = 0;
	for (auto it = dek5.begin(); it!= dek5.end(); it++)
		*it = i++;

	std::cout << "===Range constructor===" << std::endl;
	deque<int> dek7(dek5.begin(), dek5.end());
	std::cout << dek7.size() << std::endl;
	for (auto it = dek7.begin(); it != dek7.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek7.rbegin(); it != dek7.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Range constructor with reverse iterator===" << std::endl;
	deque<int> dek8(dek5.rbegin(), dek5.rend());
	std::cout << dek8.size() << std::endl;
	for (auto it = dek8.begin(); it != dek8.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek8.rbegin(); it != dek8.rend(); it++)
		std::cout << "^" << *it << std::endl;

	//initialize a vector
	vector<int> vec(6, 8);
	i = 0;
	for (auto it = vec.begin(); it != vec.end(); it++)
		*it = i++;

	std::cout << "===Range constructor with vector iterators===" << std::endl;
	deque<int> dek9(vec.begin(), vec.end());
	std::cout << dek9.size() << std::endl;
	for (auto it = dek9.begin(); it != dek9.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek9.rbegin(); it != dek9.rend(); it++)
		std::cout << "^" << *it << std::endl;	


	std::cout << "===Range constructor with partial vector iterators===" << std::endl;
	deque<int> dek10(vec.begin() + 2, vec.end() - 1);
	std::cout << dek10.size() << std::endl;
	
	dek10.insert(dek10.begin(), vec.begin(), vec.end());

	for (auto it = dek10.begin(); it != dek10.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek10.rbegin(); it != dek10.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Copy constructor===" << std::endl;
	deque<int> dek11(dek5);
	std::cout << dek11.size() << std::endl;
	for (auto it = dek11.begin(); it != dek11.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek11.rbegin(); it != dek11.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Copy constructor with empty deque===" << std::endl;
	deque<int> dek12(dek3);
	std::cout << dek12.size() << std::endl;
	for (auto it = dek12.begin(); it != dek12.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek12.rbegin(); it != dek12.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	std::cout << "===Assign operator with empty deque===" << std::endl;
	dek11 = dek3;
	std::cout << dek11.size() << std::endl;
	for (auto it = dek11.begin(); it != dek11.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek11.rbegin(); it != dek11.rend(); it++)
		std::cout << "^" << *it << std::endl;	
	
	std::cout << "===Assign operator===" << std::endl;
	dek12 = dek5;
	std::cout << dek12.size() << std::endl;
	for (auto it = dek12.begin(); it != dek12.end(); it++)
		std::cout << "_" << *it << std::endl;
	for (auto it = dek12.rbegin(); it != dek12.rend(); it++)
		std::cout << "^" << *it << std::endl;	

	std::cout<< "===empty===" << std::endl;
	std::cout << dek1.empty() << std::endl;
	std::cout << dek2.empty() << std::endl;
	std::cout << dek3.empty() << std::endl;
	std::cout << dek4.empty() << std::endl;
	std::cout << dek5.empty() << std::endl;
	std::cout << dek6.empty() << std::endl;
	std::cout << dek7.empty() << std::endl;
	std::cout << dek8.empty() << std::endl;
	std::cout << dek9.empty() << std::endl;
	std::cout << dek10.empty() << std::endl;
	std::cout << dek11.empty() << std::endl;
	std::cout << dek12.empty() << std::endl;


	std::cout<< "===size===" << std::endl;
	std::cout << dek1.size() << std::endl;
	std::cout << dek2.size() << std::endl;
	std::cout << dek3.size() << std::endl;
	std::cout << dek4.size() << std::endl;
	std::cout << dek5.size() << std::endl;
	std::cout << dek6.size() << std::endl;
	std::cout << dek7.size() << std::endl;
	std::cout << dek8.size() << std::endl;
	std::cout << dek9.size() << std::endl;
	std::cout << dek10.size() << std::endl;
	std::cout << dek11.size() << std::endl;
	std::cout << dek12.size() << std::endl;

	std::cout << "===max size===" << std::endl;
	std::cout << dek1.max_size() << std::endl;

	
	std::cout<< "===front===" << std::endl;
	if (!dek1.empty())
	std::cout << dek1.front() << std::endl;
	if (!dek2.empty())
	std::cout << dek2.front() << std::endl;
	if (!dek3.empty())
	std::cout << dek3.front() << std::endl;
	if (!dek4.empty())
	std::cout << dek4.front() << std::endl;
	if (!dek5.empty())
	std::cout << dek5.front() << std::endl;
	if (!dek6.empty())
	std::cout << dek6.front() << std::endl;
	if (!dek7.empty())
	std::cout << dek7.front() << std::endl;
	if (!dek8.empty())
	std::cout << dek8.front() << std::endl;
	if (!dek9.empty())
	std::cout << dek9.front() << std::endl;
	if (!dek10.empty())
	std::cout << dek10.front() << std::endl;
	if (!dek11.empty())
	std::cout << dek11.front() << std::endl;
	if (!dek12.empty())
	std::cout << dek12.front() << std::endl;
	
	std::cout<< "===back===" << std::endl;
	if (!dek1.empty())
	std::cout << dek1.back() << std::endl;
	if (!dek2.empty())
	std::cout << dek2.back() << std::endl;
	if (!dek3.empty())
	std::cout << dek3.back() << std::endl;
	if (!dek4.empty())
	std::cout << dek4.back() << std::endl;
	if (!dek5.empty())
	std::cout << dek5.back() << std::endl;
	if (!dek6.empty())
	std::cout << dek6.back() << std::endl;
	if (!dek7.empty())
	std::cout << dek7.back() << std::endl;
	if (!dek8.empty())
	std::cout << dek8.back() << std::endl;
	if (!dek9.empty())
	std::cout << dek9.back() << std::endl;
	if (!dek10.empty())
	std::cout << dek10.back() << std::endl;
	if (!dek11.empty())
	std::cout << dek11.back() << std::endl;
	if (!dek12.empty())
	std::cout << dek12.back() << std::endl;

}
