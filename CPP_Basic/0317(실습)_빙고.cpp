#include <iostream>
#include <time.h>

int main() {
	//빙고게임
	/*
	1부터 25까지 숫자를 받고
	5x5 배열을 만든다.
	가로 세로 대각선의 줄이 완성되었다는 것을 체크하는
	빙고게임을 제작한다.

	1. 1~25 숫자를 섞는다. (난수 이용)
	   일반배열, 2차원배열에 담는다
	   본 코드는 1차원 배열로 
	
	2. 숫자를 입력받고 입력받은 숫자는 *로 대체한다.(while로 반복되게) 
		* 0을 입력받으면 종료한다.
	
	3. 빙고 라인체크를 한다.
	*/

	srand((unsigned int)time(0));
	int Random = rand();

	int Number[25] = {};
	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
	}

	//숫자를 랜덤하게 배치해준다(셔플)
	for (int i = 0; i < 100; i++)
	{
		int Idx1 = rand() % 25;
		int Idx2 = rand() % 25;

		int Temp = Number[Idx1];
		Number[Idx1] = Number[Idx2];
		Number[Idx2] = Temp;
	}



	while (true) {
		system("cls");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (Number[i * 5 + j] == INT_MAX)
					std::cout << "*\t";
				
				else
				std::cout << Number[i * 5 + j] << "\t";
			}
			std::cout << std::endl;
		}

		std::cout << "숫자 입력 0: exit : ";
		int CheckNumber = 0;
		std::cin >> CheckNumber;

		if (CheckNumber == 0)
			break;

		else if (CheckNumber < 0 || CheckNumber > 25)
			continue;

		//별로 대체
		//예외처리 14를 2번 입력할때?
		//배열의 각 요소와 체크값을 비교하여 해당 값이 있는지 판단한다.
		bool Check = false;

		for (int i = 0; i < 25; i++)
		{
			if (Number[i] == CheckNumber)
			{
				Number[i] = INT_MAX;
				Check = true;
				break;
				//2147483647을 별(*)로 정한다.
				// 
				//숫자가 있다면 해당 숫자를 *로 바꿔준다.
				//*은 아스키코드로 저장하던지
				//define으로 정한다. 
			}
		}
		//이미 입력한 숫자를 다시 입력했다면 check 변수는 
		// false를 유지하고 있으므로 false면 다시 입력받게 한다.
		if (false == Check) //(!Check) (false == check)로 하면 (false = check) 할때
			// 실수를 잡아주는 잡기술
			continue;

		//빙고 줄을 체크한다.
		//빙고 줄을 0으로 초기화 해주고
		int Line = 0;


		for (int i = 0; i < 5; i++)
		{
			int CheckCount = 0;
			for (int j = 0; j < 5; j++)
			{
				//가로 줄 체크
				if (Number[i * 5 + j] == INT_MAX)
					CheckCount++;

				//세로 줄 체크
				if (Number[j * 5 + i] == INT_MAX)
					CheckCount++;
			}
			if (CheckCount == 5)
				++Line;
				//가로 한 줄을 체크했는데 CheckCount 변수가


		}
	}



	return 0;
}