#include <iostream>
#include <time.h>
//가위바위보

enum class SRP
{
	S = 1,
	R,
	P,
	Exit
};
void Battle(int number);
int main() {
	

	int number;
	while (1) {
		std::cout << "1. 가위" << std::endl;
		std::cout << "2. 바위" << std::endl;
		std::cout << "3. 보" << std::endl;
		std::cout << "4. 종료" << std::endl;
		std::cin >> number;

		//4번누를때 탈출
		if (number == (int)SRP::Exit)
			break;
		else if (number < (int)SRP::S || number >(int)SRP::P)
			continue;
		std::cout << Battle(number) << std::end;
		return 0;
	}
}
void Battle(int number) {
	srand((unsigned int)time(NULL));
	int random = rand();
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
		std::cout << "게임 종료" << std::endl;
		break;
	default:
		break;
	}
	int result = number - AI;
	if (result == -2 || result == -1)
		std::cout << "Player가 이김" << std::endl;
	else if (result == 0)
		std::cout << "비김" << std::endl;
	else
		std::cout << "짐" << std::endl;
	system("pause");
	return;
}