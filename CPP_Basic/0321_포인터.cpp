#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	int Num = 1246;
	int* point = &Num;
	*point = 1111;
	int** point2 = &point;
	std::cout << point2 << std::endl;
	std::cout << point << std::endl;
	std::cout << &point << std::endl;
	//cout << typeid(&Num).name() << std::endl;
	return 0;
}