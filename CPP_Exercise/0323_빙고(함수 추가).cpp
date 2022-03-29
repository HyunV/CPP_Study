#include <iostream>
#include <time.h>
//���� �Լ� ����
enum class AIType
{
	None,
	Easy,
	Hard,
	Max,
}; //None�� Max�� ����ó���� ����ü

//������ ����
void BingoMap(int* Number, int* AINumber) {
	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
		AINumber[i] = i + 1;
	}
}
//���� 100ȸ
void Shuffle(int* Number, int* AINumber) {

	for (int i = 0; i < 100; i++)
	{
		//�÷��̾�
		int idx1 = rand() % 25;
		int idx2 = rand() % 25;

		int temp = Number[idx1];
		Number[idx1] = Number[idx2];
		Number[idx2] = temp;

		//AI
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = AINumber[idx1];
		AINumber[idx1] = AINumber[idx2];
		AINumber[idx2] = temp;
	}
}
void GameStart(int& AIState) {
	while (true)
	{
		system("cls");
		std::cout << "1. ����" << std::endl;
		std::cout << "2. �����" << std::endl;
		std::cout << "���̵��� �����ϼ��� : ";
		std::cin >> AIState;
		if (AIState > (int)AIType::None &&
			AIState < (int)AIType::Max)
			break;

		// 1, 2 �� �ϳ� �����ϸ� break;
	}
}
void DrawBoard(int* Number, int* AINumber) {
	//5x5 ������ ���� (�÷��̾�)
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Number[i * 5 + j] == INT_MAX)
				//���� Ȱ�� 1�����迭�� ��ȯ
				//�ش� ���� �ε���(x) * ���� ����(5) +�ش� �ε��� ĭ(y) ��ȣ
				//[0,0] ���� [4,4] ���� 1���� �迭�� ������ �ٶ󺸸� ��.
				std::cout << "*\t";
			else
				std::cout << Number[i * 5 + j] << "\t";

		}
		std::cout << "\t\t";

		//5x5 ������ ���� (AI)
		for (int j = 0; j < 5; j++)
		{
			//std::cout << "*\t";
			//AI ���ڴ� �̰���
			if (AINumber[i * 5 + j] == INT_MAX)
				std::cout << "*\t";

			else
				std::cout << AINumber[i * 5 + j] << "\t";
		}
		std::cout << std::endl;
	}
}
bool ResultCheck(int& Line, int& AILine) {
	if (Line >= 5) {
		std::cout << "Player Win" << std::endl;
		return true;
	}
	else if (AILine >= 5) {
		std::cout << "AI Win" << std::endl;
		return true;
	}
	else
		return false;
}
void BingoCheck(int* Number, int* AINumber, int& CheckNumber) {
	bool	 check = false;
	for (int i = 0; i < 25; i++)
	{
		if (Number[i] == CheckNumber)
		{
			Number[i] = INT_MAX;
			check = true;
			break;
		}
	}
	//if (!check) //�ش� ���ڰ� ���� ���� ���� ��

	//AI �����ǵ� �ش� ���ڸ� *�� �ٲ��ش�.
	for (int i = 0; i < 25; i++)
	{
		if (AINumber[i] == CheckNumber)
		{
			AINumber[i] = INT_MAX;
			break;
		}
	}
}
int AI_Easy_Check(int* SelectArray, int* AINumber) {
	int SelectCount = 0;
	for (int i = 0; i < 25; i++)
	{
		if (AINumber[i] != INT_MAX) //*�� �ƴϸ�
		{
			//ó���� �������� �� �迭 SelectArray[25]��
			//�Է��� �ȵ� ��(*�� ǥ�� �ȵ� ��)���� �����Ѵ�.
			//�����ϱ� ���� �����ε�..
			SelectArray[SelectCount] = AINumber[i];
			SelectCount++;
		}
	}

	return SelectArray[rand() % SelectCount];
	//AI�� ������ ���� = 0~ �� �������� �� �ϳ� ����
}
int AI_Hard_Check(int* AINumber) {
	{
		int	StarCount = 0;
		int	CheckLine = 0;

		bool	Find = false;
		for (int i = 0; i < 5; ++i)
		{
			int	LineStarCount = 0;
			int	LineStarCount1 = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (AINumber[i * 5 + j] == INT_MAX)
					++LineStarCount;

				if (AINumber[j * 5 + i] == INT_MAX)
					++LineStarCount1;
			}

			if (StarCount < LineStarCount && LineStarCount < 5)
			{
				StarCount = LineStarCount;
				CheckLine = i;

				if (StarCount == 4)
				{
					Find = true;
					break;
				}
			}

			if (StarCount < LineStarCount1 && LineStarCount1 < 5)
			{
				StarCount = LineStarCount1;
				CheckLine = i + 5;

				if (StarCount == 4)
				{
					Find = true;
					break;
				}
			}
		}

		if (!Find)
		{
			int	LineStarCount = 0;

			for (int i = 0; i < 25; i += 6)
			{
				if (AINumber[i] == INT_MAX)
					++LineStarCount;
			}

			if (StarCount < LineStarCount && LineStarCount < 5)
			{
				StarCount = LineStarCount;
				CheckLine = 10;

				if (StarCount == 4)
				{
					Find = true;
					//break;
				}
			}

			if (!Find)
			{
				LineStarCount = 0;

				for (int i = 4; i < 21; i += 4)
				{
					if (AINumber[i] == INT_MAX)
						++LineStarCount;
				}

				if (StarCount < LineStarCount && LineStarCount < 5)
				{
					StarCount = LineStarCount;
					CheckLine = 11;
				}
			}
		}

		if (CheckLine <= 4)
		{
			for (int i = 0; i < 5; ++i)
			{
				if (AINumber[CheckLine * 5 + i] != INT_MAX)
				{
					return AINumber[CheckLine * 5 + i];
					//break;
				}
			}
		}

		else if (CheckLine <= 9)
		{
			for (int i = 0; i < 5; ++i)
			{
				if (AINumber[i * 5 + (CheckLine - 5)] != INT_MAX)
				{
					return AINumber[i * 5 + (CheckLine - 5)];
					//break;
				}
			}
		}

		else if (CheckLine == 10)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (AINumber[i] != INT_MAX)
				{
					return  AINumber[i];
					//break;
				}
			}
		}

		else
		{
			for (int i = 4; i < 21; i += 4)
			{
				if (AINumber[i] != INT_MAX)
				{
					return  AINumber[i];
					//break;
				}
			}
		}
	}
}
void ChangeStar(int* Number, int* AINumber, int& CheckNumber) {
	for (int i = 0; i < 25; ++i)
	{
		if (Number[i] == CheckNumber)
		{
			Number[i] = INT_MAX;
			break;
		}
	}

	for (int i = 0; i < 25; ++i)
	{
		if (AINumber[i] == CheckNumber)
		{
			AINumber[i] = INT_MAX;
			break;
		}
	}

	for (int i = 0; i < 25; i++)
	{
		if (Number[i] == CheckNumber)
		{
			Number[i] = INT_MAX;
			break;
		}
	}
	for (int i = 0; i < 25; i++)
	{
		if (AINumber[i] == CheckNumber)
		{
			AINumber[i] = INT_MAX;
			break;
		}
	}
}
void BingoCheck(int* Number, int*AINumber, int& Line, int& AILine) {
	for (int i = 0; i < 5; i++)
	{
		int CheckCount = 0, CheckCount1 = 0;
		int AICheckCount = 0, AICheckCount1 = 0;

		for (int j = 0; j < 5; j++)
		{
			//���� üũ (Player)
			if (Number[i * 5 + j] == INT_MAX)
				CheckCount++;
			//���� üũ (Player)
			if (Number[j * 5 + i] == INT_MAX)
				CheckCount1++;
			//���� üũ (AI)
			if (AINumber[i * 5 + j] == INT_MAX)
				AICheckCount++;
			//���� üũ (AI)
			if (AINumber[j * 5 + i] == INT_MAX)
				AICheckCount1++;
		}
		if (CheckCount == 5)
			Line++;
		if (CheckCount1 == 5)
			Line++;
		if (AICheckCount == 5)
			AILine++;
		if (AICheckCount1 == 5)
			AILine++;
	}
	//�������� �밢�� �Ǵ�
	int CheckCount2 = 0, AICheckCount2 = 0;
	for (int i = 0; i < 25; i += 6)
	{
		if (Number[i] == INT_MAX)
			++CheckCount2;
		if (AINumber[i] == INT_MAX)
			++AICheckCount2;
	}
	if (CheckCount2 == 5)
		Line++;
	if (AICheckCount2 == 5)
		AILine++;

	CheckCount2 = 0;
	AICheckCount2 = 0;

	// /�밢��
	for (int i = 4; i <= 20; i += 4)
	{
		if (Number[i] == INT_MAX)
			CheckCount2++;
		if (AINumber[i] == INT_MAX)
			AICheckCount2++;
	}
	if (CheckCount2 == 5)
		Line++;
	if (AICheckCount2 == 5)
		AILine++;

}
int main()
{
	srand((unsigned int)time(0));
	int Random = rand();
	int AIState = 0; //AI ���̵� ���� ����
	GameStart(AIState);

	//���� ����
	//������ ����
	int Number[25] = {};
	int AINumber[25] = {};
	BingoMap(Number, AINumber);
	Shuffle(Number, AINumber);

	//���� �� ī��Ʈ ����
	int Line = 0, AILine = 0;

	//�ΰ������� ������ �迭 ����
	int SelectArray[25] = {};

	while (true) {
		system("cls");
		std::cout <<
			"============ Player ================================================= AI =================" << std::endl;
		//������ �׸���
		DrawBoard(Number, AINumber);

		//���� ǥ����
		std::cout << "Bingo Line : " << Line;
		std::cout << "\t\t\t\t\t\t";
		std::cout << "AI Bingo Line : " << AILine << std::endl;

		//�¸� ����
		if (ResultCheck(Line, AILine) == true) {
			break;
		}

		//���� ���� �Է��ϱ�
		int CheckNumber = 0;
		std::cout << "Input Number0 : Exit) : ";
		std::cin >> CheckNumber;

		if (CheckNumber == 0)
			break;

		//üũ�ѹ� �����ų� 25 �ʰ��ϸ� ����
		else if (CheckNumber < 0 || CheckNumber > 25)
			continue;

		//bingo check
		BingoCheck(Number, AINumber, CheckNumber);


		//AI ���̵��� switch��
		switch ((AIType)AIState)
		{
		case AIType::Easy:
			CheckNumber = AI_Easy_Check(SelectArray, AINumber);
			break;
		case AIType::Hard:
			CheckNumber = AI_Hard_Check(AINumber);
			break;
		}

		// AI�� ������ ���ڸ� *�� �ٲ��ֵ��� �Ѵ�.	
		//AI�� ������ ���ڸ� �÷��̾�� AI �����ǿ� ���� *�� �ٲ��ش�.
		ChangeStar(Number, AINumber, CheckNumber);
		//std::cout << "AI �� ������ ���� : " << CheckNumber << std::endl;

		//���� �� üũ
		Line = 0;
		AILine = 0;
		BingoCheck(Number, AINumber, Line, AILine);
	}
	return 0;
}