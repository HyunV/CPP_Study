#include <iostream>
#include <time.h>
//����������

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
		std::cout << "1. ����" << std::endl;
		std::cout << "2. ����" << std::endl;
		std::cout << "3. ��" << std::endl;
		std::cout << "4. ����" << std::endl;
		std::cin >> number;

		//4�������� Ż��
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
		std::cout << "AI: ����" << std::endl;
		break;
	case SRP::R:
		std::cout << "AI: ����" << std::endl;
		break;
	case SRP::P:
		std::cout << "AI: ��" << std::endl;
		break;
	case SRP::Exit:
		std::cout << "���� ����" << std::endl;
		break;
	default:
		break;
	}
	int result = number - AI;
	if (result == -2 || result == -1)
		std::cout << "Player�� �̱�" << std::endl;
	else if (result == 0)
		std::cout << "���" << std::endl;
	else
		std::cout << "��" << std::endl;
	system("pause");
	return;
}