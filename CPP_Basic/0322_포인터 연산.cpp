#include <iostream>
using namespace std;

int main()
{
	/*
	
	*/
	int Array[10] = {};

	for (int i = 0; i < 10; i++) {
		Array[i] = i + 1;
	}
	int* pArray = Array;

	bool Array1[10] = {};
	bool* pArray1 = Array1;

	//int형 포인터 배열 메모리 주소 접근
	std::cout << "pArray : " << pArray << std::endl;

	//pArray+1 -> int 형이니 4바이트 이동(인덱스 1 이동)
	std::cout << "pArray + 1 : " << pArray + 1 << std::endl;
	std::cout << "pArray + 2 : " << pArray + 2 << std::endl;
	std::cout << "pArray - 1 : " << pArray - 1 << std::endl;
	std::cout << "pArray - 2 : " << pArray - 2 << std::endl;

	//bool 배열의 포인터 는 1바이트씩 이동
	std::cout << "pArray1 : " << pArray1 << std::endl;
	std::cout << "pArray1 + 1 : " << pArray1 + 1 << std::endl;
	std::cout << "pArray1 + 2 : " << pArray1 + 2 << std::endl;

	pArray[1] = 300; //300 넣으라고 조종
	std::cout << "pArray[1] : " << pArray[1] << std::endl;
	*(pArray + 1) = 600;  //괄호 안쳐주면 우선순위에 의해서 *pArray먼저 됨 이건 Array[1]과 같은건가?
	
	std::cout << "pArray[1] : " << pArray[1] << std::endl;

	++pArray; // 포인터 시작 값이 [0]이 아닌 [1]이 됨.

	pArray[0] = 900; //포인터 시작값이 [1]이니 [1]을 600에서 900으로 바꿔줌

	std::cout << "Array[1]dd : " << Array[1] << std::endl;

	//int* pNumber 5 = &Number



	return 0;
}