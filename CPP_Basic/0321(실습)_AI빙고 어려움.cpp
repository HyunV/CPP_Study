#include <iostream>
#include <time.h>

enum class AIType
{
	None,
	Easy,
	Hard,
	Max,
}; //None�� Max�� ����ó���� ����ü

int main()
{
	srand((unsigned int)time(0));
	int Random = rand();

	int AIState = 0; //AI ���̵� ���� ����


	//���� ����
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

	//������ ����
	int Number[25] = {};
	int AINumber[25] = {};

	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
		AINumber[i] = i + 1;
	}

	//���� 100��
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

	//���� �� ī��Ʈ ����
	int Line = 0, AILine = 0;

	//�ΰ������� ������ �迭 ����
	int SelectArray[25] = {};

	//AI�� ���� ������ �� �ִ� ���ڰ� ����� �����ϴ� ����?
	int SelectCount = 0;

	while (true) {
		system("cls");
		std::cout <<
			"============ Player ================================================= AI =================" << std::endl;
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

		//���� ǥ����
		std::cout << "Bingo Line : " << Line;
		std::cout << "\t\t\t\t\t\t";
		std::cout << "AI Bingo Line : " << AILine << std::endl;

		//�¸� ����
		if (Line >= 5) {
			std::cout << "Player Win" << std::endl;
			break;
		}
		else if (AILine >= 5) {
			std::cout << "AI Win" << std::endl;
			break;
		}

		//���� ���� �Է��ϱ�
		std::cout << "Input Number0 : Exit) : ";
		int CheckNumber = 0;
		std::cin >> CheckNumber;

		if (CheckNumber == 0)
			break;

		//üũ�ѹ� �����ų� 25 �ʰ��ϸ� ����
		else if (CheckNumber < 0 || CheckNumber > 25)
			continue;

		//�迭���� ���Ͽ� �ش� ���� �ִ��� �Ǵ��Ѵ�.
		//������ �� ���ڸ� *�� ǥ���Ѵ� (�÷��̾� ���� 86��° �ٿ��� �ٲ�)
		bool	 check = false;
		for (int i = 0; i < 25; i++)
		{
			if (Number[i] == CheckNumber)
			{
				Number[i] = INT_MAX;
				//���� 8�� �Է¹����� �����ǿ� �ִ� 8��
				//2147483647�� �ٲ�� �̰��� *�� ġȯ�Ͽ� ����Ѵ�
				//
				check = true;
				break;
			}
		}
		if (!check) //�ش� ���ڰ� ���� ���� ���� ��
			continue;

		//�÷��̾��� *�� ��ȯ�� �Ϸ�Ǹ� 
		//AI �����ǵ� �ش� ���ڸ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; i++)
		{
			if (AINumber[i] == CheckNumber)
			{
				AINumber[i] = INT_MAX;
				break;
			}
		}


		//AI ���̵��� switch��
		switch ((AIType)AIState)
		{
		case AIType::Easy:
			SelectCount = 0;
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

			CheckNumber = SelectArray[rand() % SelectCount];
			//AI�� ������ ���� = 0~ �� �������� �� �ϳ� ����
			break;
		case AIType::Hard:
		{
			//��ü 12��(���� 5 ���� 5 �밢��2) 
			// �� �ϼ��� ���� �����ϰ� ������ �̿ϼ��� ���� üũ�Ͽ� 
			// *�� ���� ���� ���� ���� ã�´�.
			//4���� ���� üũ���� ����? ����
			int StarCount = 0; //���� ���� ���� ī��Ʈ
			int CheckLine = 0; //����� ���� ���ɼ��� ���� ������ ����

			bool Find = false; // ���� ������ ���� ã�Ҵٴ� ǥ�⸦ �ϱ����� ����
			for (int i = 0; i < 5; i++)
			{
				//���� �� ���� �� ���� üũ�ϱ� ���� ����
				int LineStarCount = 0; //�� ���� üũ�ϴ� ��������(��� ��� �ϴϱ�)
				//������ ������: LineStarCount
				int LineStarCount1 = 0;
				for (int j = 0; j < 5; j++)
				{
					//������ ���� ���� üũ
					if (AINumber[i * 5 + j] == INT_MAX)
						LineStarCount++;
					//������ ���� ���� üũ
					if (AINumber[j * 5 + i] == INT_MAX)
						LineStarCount1++;
				}


				//������ ���� ���� ������ üũ�� ���� �� ������ ũ�ٸ�
				// ���� ���� ���ɼ��� ���� ���� ���� �ȴ�.
				// (LineStarCount < 5)�� ������ �� �� �ϼ�(5)�� ������ �ȵǴϱ�
				if ((StarCount < LineStarCount) && (LineStarCount < 5))
				{
					StarCount = LineStarCount;
					CheckLine = i; //������ 0~4 �׸� 1 ǥ ����

					// *�� 4���� ���� ���� Ȯ���� ���� ���� ���̹Ƿ� �����ϰ� �Ѵ�.
					if (StarCount == 4)
					{
						Find = true;
						break;
					}
				}

				// ������ ���� ���� ������ üũ�صξ��� ���� �� ������
				// ũ�ٸ� ���� ���� ���ɼ��� ���� ���� ���� �ȴ�.
				// LineStarCount1 < 5 �� �� ������ �� ���� �ϼ���
				// �ȵǾ��� ��쿡�� ó���� �ؾ� �ϱ� �����̴�.
				if (StarCount < LineStarCount1 && LineStarCount1 < 5)
				{
					StarCount = LineStarCount1;
					CheckLine = i + 5;
					//5, 6, 7 , 8, 9 //�׸� 1 ǥ ����

					// *�� 4����� �ٸ� ���� üũ�ϴ��� �� �̻���
					// ���� �����Ƿ� �� ���� �����ϵ��� �Ѵ�.
					if (StarCount == 4)
					{
						Find = true;
						break;
					}
				}
			}

			//Find ������  *�� 4���϶��� true �̴�.
			//false�϶��� �밢���� üũ�ϴ� �ΰ������� �����.
			if (!Find)
			{
				int LineStarCount = 0; //�� ���� üũ�ϴ� ��������
				//���� ��� -> ������ �ϴ� �밢��(10)
				for (int i = 0; i < 25; i += 6)
				{
					if (AINumber[i] == INT_MAX)
						LineStarCount++;
				}

				if (StarCount < LineStarCount && LineStarCount < 5)
				{
					StarCount = LineStarCount;
					CheckLine = 10;

					if (StarCount == 4)
					{
						Find = true;
						break;
					}
				}

				if (!Find)
				{
					LineStarCount = 0;

					for (int i = 4; i < 21; i += 4)
					{
						if (AINumber[i] == INT_MAX)
							LineStarCount++;
					}

					if (StarCount < LineStarCount && LineStarCount < 5)
					{
						StarCount = LineStarCount;
						CheckLine = 11;
					}
				}
			}

			//���� ���� �� üũ
			//���� �� �� �ϳ��� �����̸�(���� �켱)
			//���� ���� �ϳ��ϳ� üũ�Ͽ� checknumber��int max ���� �ƴѰ��� �����Ѵ�.

			// ���� ��� ���� 2��° ���� �����Ǿ��ٸ� CheckLine��
			// 1�� ����Ǿ� ���� ���̴�.
			// �� ��� 1 * 5 + 0 ~ 4 �� �ǹǷ�
			// 5 ~ 9 ���ε����� �ǹ��ϹǷ� ���� 2��° ����
			// �ϳ��� üũ�� �ϰ� �Ǵ� ���̴�.
			if (CheckLine <= 4)
			{
				for (int i = 0; i < 5; i++)
				{
					if (AINumber[CheckLine * 5 + i] != INT_MAX)
					{
						CheckNumber = AINumber[CheckLine * 5 + i];
						break;
					}
				}
			}

			//�������� ����
			else if (CheckLine <= 9)
			{
				for (int i = 0; i < 5; i++)
				{
					if (AINumber[i * 5 + (CheckLine - 5)] != INT_MAX)
					{
						CheckNumber = AINumber[i * 5 + (CheckLine - 5)];
						break;
					}
				}
			}
			//�������� �밢��
			else if (CheckLine == 10)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (AINumber[i] != INT_MAX)
					{
						CheckNumber = AINumber[i];
						break;
					}
				}
			}

			else
			{
				for (int i = 4; i < 21; i += 4)
				{
					if (AINumber[i] != INT_MAX)
					{
						CheckNumber = AINumber[i];
						break;
					}
				}
			}
		}
			break;
		}

		std::cout << "AI �� ������ ���� : " << CheckNumber << std::endl;

		//AI�� ������ ���ڸ� �÷��̾�� AI �����ǿ� ���� *�� �ٲ��ش�.
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
		//���� �� üũ
		Line = 0;
		AILine = 0;

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
	return 0;
}