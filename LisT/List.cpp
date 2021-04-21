#include "List.hpp"
#include <iostream>


//constructors

template <typename T, class Alloc>
ft::list<T, Alloc>::list() : _size(0){
	std::cout << "yo" << std::endl;
}
