#include <iostream>

int main()
{
	/*
	1.
	*****
	 ****
	  ***
	   **
		*
	*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	/*
2.
   *
  ***
 *****
*******
//규칙: i값을 기준으로 1+(2*i)를 해주면 홀수개대로 늘어남
i = 0  * = 1 |
i = 1  * = 3 |
i = 2  * = 5 |
i = 3  * = 7 |
*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3 - i; j++)
		{
			std::cout << " ";
		}
		for (int j = 0; j <= i * 2; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	/*
	3.
	 0   *
	 1  ***
	 2 *****
	 3*******
	 4 *****
	 5  ***
	 6   *
	*/
	int temp = 0;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < abs(3 - i); j++)
		{
			std::cout << " ";
		}
		if (3 - i >= 0)
		{
			for (int j = 0; j <= i * 2; j++) {
				std::cout << "*";
			}
			temp = (i * 2) + 1;
			std::cout << std::endl;
		}
		else {
			for (int j = 0; j < temp - 2; j++) {
				std::cout << "*";
			}
			temp -= 2;
			std::cout << std::endl;
		}
	}