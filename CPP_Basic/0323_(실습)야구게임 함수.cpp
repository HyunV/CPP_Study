#include <iostream>
#include <time.h>
//�߱�����
//�� ���� § �ڵ�
void Shuffle(int* Array) { //�Ű�����: �迭�� �Ѱܹ޾� �� �� �ְ�
	//StrikeNum[0] [1] [2] �� �������� ó���� ����
	//�迭 ����
	for (int i = 1; i <= 9; i++)
	{
		Array[i - 1] = i;
	}

	//����
	for (int i = 0; i < 100; i++)
	{
		int Idx1 = rand() % 9;
		int Idx2 = rand() % 9;

		int temp = Array[Idx1];
		Array[Idx1] = Array[Idx2];
		Array[Idx2] = temp;
	}
} 

bool ResultCheck(int strike, int ball, bool exit, bool fail) { //����
	//���� ���
	if (exit == true && fail == false) {
		if (strike == 3) {
			//std::cout << MyNumber[0] << MyNumber[1] << MyNumber[2] << ", �����Դϴ�!" << std::endl;
			std::cout << "����!" << std::endl;
			exit = false;
			return true;
		}
		else if (strike == 0 && ball == 0) {
			std::cout << "Out" << std::endl;
			return false;
		}
		else {
			std::cout << strike << " strike " << ball << " ball" << std::endl;
			return false;
		}
	}
	else if (fail) {
		std::cout << "��ȿ���� ���� �����Դϴ�." << std::endl;
		fail = false;
		return false;
	}
}
void Check(int& strike, int& ball, bool& exit, bool& fail) {

}

int main() {
	srand((unsigned int)time(0));
	int StrikeNum[9];
	//�迭 ���� �� ����
	Shuffle(StrikeNum);

	//std::cout << "����: " << StrikeNum[0] << " " << StrikeNum[1] << " " << StrikeNum[2] << std::endl;
	std::cout << "�� �ڸ� ���� �Է�" << std::endl;
	std::cout << "��������: ���� 0 �Է�" << std::endl;
	std::cout << "* * *" << std::endl;
	//���� ����
	bool exit = true;
	int strike = 0; //��ġ�� �°� ���ڵ� ����
	int ball = 0; //���ڸ� ����
	bool out = false; //���� ���� ����

	Check(strike, ball, exit, out);
	while (exit) {
		strike = 0;
		ball = 0;
		out = false;
		int MyNumber[3] = {};

		bool fail = false; // ���� �߸� �Է������� ���� ����
		for (int i = 0; i < 3; i++)
		{
			std::cin >> MyNumber[i]; //���� 3�� �Է¹ޱ�

			//���� ����
			if (MyNumber[i] < 0 || MyNumber[i] > 9) {
				fail = true;
				break;
			}//���� ���� ��

			//0������ �� �˷��ְ� ���� ����
			if (MyNumber[i] == 0) { //0������ Ż��
				std::cout << "����: " << StrikeNum[0] << " " << StrikeNum[1] << " " << StrikeNum[2] << std::endl;
				exit = false;
				break;
			}
			//��Ʈ����ũ �� ����
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
		//�ߺ� üũ
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (MyNumber[i] == MyNumber[j]) {
					fail = true;
					break;
				}
			}
		}

		//����
		if (ResultCheck(strike, ball, exit, fail) == true) {
			break;
		}

	}
	return 0;
}