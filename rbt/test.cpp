#include "rbt.cpp"

using namespace ft;

int main()
{
	rbt<int> mdr;
//	mdr.insert(5);
	mdr.insert(87);
	mdr.insert(6);
	mdr.insert(15);
	mdr.insert(56);
	mdr.insert(8);
	mdr.insert(479);
	mdr.insert(45);
	mdr.insert(8);
	mdr.insert(89);
	mdr.insert(75);
	mdr.insert(5);
	mdr.insert(68);
	mdr.insert(48979);
	mdr.insert(1);
	mdr.insert(-45);
	mdr.insert(7889);
	mdr.insert(895);
	mdr.print();
	mdr.DeleteValue(6);
	mdr.DeleteValue(5);
	mdr.print();
}
