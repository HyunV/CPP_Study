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

	//int�� ������ �迭 �޸� �ּ� ����
	std::cout << "pArray : " << pArray << std::endl;

	//pArray+1 -> int ���̴� 4����Ʈ �̵�(�ε��� 1 �̵�)
	std::cout << "pArray + 1 : " << pArray + 1 << std::endl;
	std::cout << "pArray + 2 : " << pArray + 2 << std::endl;
	std::cout << "pArray - 1 : " << pArray - 1 << std::endl;
	std::cout << "pArray - 2 : " << pArray - 2 << std::endl;

	//bool �迭�� ������ �� 1����Ʈ�� �̵�
	std::cout << "pArray1 : " << pArray1 << std::endl;
	std::cout << "pArray1 + 1 : " << pArray1 + 1 << std::endl;
	std::cout << "pArray1 + 2 : " << pArray1 + 2 << std::endl;

	pArray[1] = 300; //300 ������� ����
	std::cout << "pArray[1] : " << pArray[1] << std::endl;
	*(pArray + 1) = 600;  //��ȣ �����ָ� �켱������ ���ؼ� *pArray���� �� �̰� Array[1]�� �����ǰ�?
	
	std::cout << "pArray[1] : " << pArray[1] << std::endl;

	++pArray; // ������ ���� ���� [0]�� �ƴ� [1]�� ��.

	pArray[0] = 900; //������ ���۰��� [1]�̴� [1]�� 600���� 900���� �ٲ���

	std::cout << "Array[1]dd : " << Array[1] << std::endl;

	//int* pNumber 5 = &Number



	return 0;
}