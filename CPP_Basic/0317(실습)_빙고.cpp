#include <iostream>
#include <time.h>

int main() {
	//�������
	/*
	1���� 25���� ���ڸ� �ް�
	5x5 �迭�� �����.
	���� ���� �밢���� ���� �ϼ��Ǿ��ٴ� ���� üũ�ϴ�
	��������� �����Ѵ�.

	1. 1~25 ���ڸ� ���´�. (���� �̿�)
	   �Ϲݹ迭, 2�����迭�� ��´�
	   �� �ڵ�� 1���� �迭�� 
	
	2. ���ڸ� �Է¹ް� �Է¹��� ���ڴ� *�� ��ü�Ѵ�.(while�� �ݺ��ǰ�) 
		* 0�� �Է¹����� �����Ѵ�.
	
	3. ���� ����üũ�� �Ѵ�.
	*/

	srand((unsigned int)time(0));
	int Random = rand();

	int Number[25] = {};
	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
	}

	//���ڸ� �����ϰ� ��ġ���ش�(����)
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

		std::cout << "���� �Է� 0: exit : ";
		int CheckNumber = 0;
		std::cin >> CheckNumber;

		if (CheckNumber == 0)
			break;

		else if (CheckNumber < 0 || CheckNumber > 25)
			continue;

		//���� ��ü
		//����ó�� 14�� 2�� �Է��Ҷ�?
		//�迭�� �� ��ҿ� üũ���� ���Ͽ� �ش� ���� �ִ��� �Ǵ��Ѵ�.
		bool Check = false;

		for (int i = 0; i < 25; i++)
		{
			if (Number[i] == CheckNumber)
			{
				Number[i] = INT_MAX;
				Check = true;
				break;
				//2147483647�� ��(*)�� ���Ѵ�.
				// 
				//���ڰ� �ִٸ� �ش� ���ڸ� *�� �ٲ��ش�.
				//*�� �ƽ�Ű�ڵ�� �����ϴ���
				//define���� ���Ѵ�. 
			}
		}
		//�̹� �Է��� ���ڸ� �ٽ� �Է��ߴٸ� check ������ 
		// false�� �����ϰ� �����Ƿ� false�� �ٽ� �Է¹ް� �Ѵ�.
		if (false == Check) //(!Check) (false == check)�� �ϸ� (false = check) �Ҷ�
			// �Ǽ��� ����ִ� ����
			continue;

		//���� ���� üũ�Ѵ�.
		//���� ���� 0���� �ʱ�ȭ ���ְ�
		int Line = 0;


		for (int i = 0; i < 5; i++)
		{
			int CheckCount = 0;
			for (int j = 0; j < 5; j++)
			{
				//���� �� üũ
				if (Number[i * 5 + j] == INT_MAX)
					CheckCount++;

				//���� �� üũ
				if (Number[j * 5 + i] == INT_MAX)
					CheckCount++;
			}
			if (CheckCount == 5)
				++Line;
				//���� �� ���� üũ�ߴµ� CheckCount ������


		}
	}



	return 0;
}