#include <iostream>
#include <time.h>
//�߱�����
int main() {
	srand((unsigned int)time(0));
	int StrikeNum[9];
	//�迭 ����
	for (int i = 1; i <= 9; i++)
	{
		StrikeNum[i - 1] = i;
	}

	//����
	//StrikeNum[0] [1] [2] �� �������� ó���� ����
	for (int i = 0; i < 100; i++)
	{
		int Idx1 = rand() % 9;
		int Idx2 = rand() % 9;

		int temp = StrikeNum[Idx1];
		StrikeNum[Idx1] = StrikeNum[Idx2];
		StrikeNum[Idx2] = temp;
	}
	//std::cout << "����: " << StrikeNum[0] << " " << StrikeNum[1] << " " << StrikeNum[2] << std::endl;

	std::cout << "�� �ڸ� ���� �Է�" << std::endl;
	std::cout << "��������: ���� 0 �Է�" << std::endl;
	std::cout << "* * *" << std::endl;
	//���� ����
	bool exit = true;
	int strike = 0; //��ġ�� �°� ���ڵ� ����
	int ball = 0; //���ڸ� ����
	bool out = false; //���� ���� ����
	while (exit) {
		strike = 0;
		ball = 0;
		out = false;
		int MyNumber[3] = {};
		//������ ���ڸ� ǥ��		
		for (int i = 0; i < 3; i++)
		{
			std::cin >> MyNumber[i];

			if (MyNumber[i] == 0) { //0������ Ż��
				std::cout << "����: " << StrikeNum[0] << " " << StrikeNum[1] << " " << StrikeNum[2] << std::endl;
				exit = false;
				break;
			}
			for (int j = 0; j < 3; j++)
			{
				if (MyNumber[i] == StrikeNum[j]) {
					if (i == j)
						strike++;
					else
						ball++;
				}
			}
		}
		//����

		//���� ���
		if (exit == true) {
			if (strike == 3) {
				std::cout << MyNumber[0] << MyNumber[1] << MyNumber[2] << ", �����Դϴ�!" << std::endl;
				exit = false;
			}
			else if (strike == 0 && ball == 0) {
				std::cout << "Out" << std::endl;
			}
			else {
				std::cout << strike << " strike " << ball << " ball" << std::endl;
			}
		}
	}
}
