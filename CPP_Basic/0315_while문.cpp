#include <iostream>
#include <time.h>

int main()
{
	//while�� ���� while��
	int i = 0;
	while (i < 10) {
		int j = 0;

		while (j < 10) {
			std::cout << "i : " << i << "j : " << j << std::endl;
			++j;
		}
		++i;
	}
	//rand �Լ�
	/*
	srand() C++���� �����ϴ� ���� ���̺�
	srand(10) ���� 10�� �õ尪�̶� �θ���.

	*/
	//srand(10);
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		std::cout << rand()%9+1 << std::endl;
	}
	return 0;
}