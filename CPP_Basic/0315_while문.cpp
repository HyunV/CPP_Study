#include <iostream>
#include <time.h>

int main()
{
	//while문 이중 while문
	int i = 0;
	while (i < 10) {
		int j = 0;

		while (j < 10) {
			std::cout << "i : " << i << "j : " << j << std::endl;
			++j;
		}
		++i;
	}
	//rand 함수
	/*
	srand() C++에서 제공하는 난수 테이블
	srand(10) 에서 10은 시드값이라 부른다.

	*/
	//srand(10);
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		std::cout << rand()%9+1 << std::endl;
	}
	return 0;
}