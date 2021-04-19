#include <vector>
#include <deque>
#include <iostream>
#include "DeQue/Deque.cpp"
#include <stack>

#ifdef STD
using namespace std;
#elif FT
using namespace ft;
#endif


int main()
{

#ifdef VEC
#define CTN vector
#endif

#ifdef DEK
#define CTN deque
#endif

#ifdef CHAR
#define TP char
#endif


#ifdef INT
#define TP int
#endif


#if defined VEC || defined DEK
	CTN<TP> inst(20);
	for (int i = 5; i < 15;i++)
#if defined CHAR || defined INT
		inst[i] = i + 50;
#else
		inst[i] = vec(10,10);
#endif
	for (auto it = inst.begin(); it != inst.end(); it++)
		std::cout << *it << std::endl;

	
#endif
	
	

/*	vector<int> vic(0,'a');
	vic.push_back(42);
  	std::cout << *vic.begin() << std::endl;
  	vector<char> vec(vic.begin(), vic.end());
	


	deque<char> dek(0, 45);
  	dek.push_back(45);
  	deque<int> dik(dek.begin(), dek.end());

  	for (int i = 0; i < 31; i++)
		dek[i] = i;
	dek.push_front(50);
	dek.push_front(50);
	dek.pop_front();
	dek.push_back(32);
	dek.push_back(32);
	dek.pop_back();
	dek.insert(dek.begin() + 6, dek.begin(), dek.end());        
  	auto it = dik.begin();
  	for (; it != dik.end(); it++)
  	{
  		std::cout << "_" << *it << std::endl;
  	}*/
}
