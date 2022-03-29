// 0316.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
enum class SRP
{
	S =1,
	R,
	P,
	Exit
};

int main()
{
	system("cls");
	//가위바위보 게임
	srand(time(NULL));
	int Random = rand();

	while (true)
	{
		system("cls");
		std::cout << "1. 가위" << std::endl;
		std::cout << "2. 바위" << std::endl;
		std::cout << "3. 보" << std::endl;
		std::cout << "4. 종료" << std::endl;
		std::cout << "Input Player : ";
		int Player;
		std::cin >> Player;

		if (Player == (int)SRP::Exit)
			break;
		else if (Player <(int)SRP::S || Player > (int)SRP::Exit)
			//시저(1)보다 작은값 혹은 나가는 수(4)보다 큰값일때 빠꾸
			continue;
		//인공지능 메커니즘 1, 2, 3중에 하나를 택한다.
		int AI = rand() % 3 + 1;

		switch ((SRP)AI)
		{
		case SRP::S:
			std::cout << "AI: 가위" << std::endl;
			break;
		case SRP::R:
			std::cout << "AI: 바위" << std::endl;
			break;
		case SRP::P:
			std::cout << "AI: 보" << std::endl;
			break;
		case SRP::Exit:
			break;
		default:
			break;
		}

		int Result = Player - AI;
		if (Result == 1 || Result == -2)
			std::cout << "플레이어 승리" << std::endl;
		else if (Result == 0)
			std::cout << "비김" << std::endl;
		else
			std::cout << "AI 승리" << std::endl;
			system("pause");
	}
	
}