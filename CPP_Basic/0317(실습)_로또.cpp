#include <iostream>

int main() {
	/*int Array[10][5] = {};

	int Array1[3] = 30;
	int Array1[50] = { 30 };
	
	Array1[3] = 30;
	Array[0][3] = 30;

	Array1[6] = 100;
	Array[1][1] = 100;*/


	//�ζ� ���α׷�
	
	//����
	//int Number1 = 20;
	//int Number2 = 30;
	
	//1~45���� ���ڰ� �ְ� �� ���ڰ� �ߺ��Ǹ� �ȵǰ�
	// 6���� ������ ���ڸ� ���;� �Ѵ�.
	srand((unsigned int)time(0));
	int Random = rand();

	std::cout << rand() % 45 + 1 << std::endl;
	std::cout << rand() % 45 + 1 << std::endl;
	std::cout << rand() % 45 + 1 << std::endl;
	std::cout << rand() % 45 + 1 << std::endl;
	std::cout << rand() % 45 + 1 << std::endl;
	//�ߺ��� �Ǿ�������??

	//1. �ߺ� �Ǿ����� �ѹ� �� �̾Ƽ� �ٸ������� �ٲ۴�.
	// -> �̷����ϸ� �������� �ݺ��� ���� �߻��Ѵ�.
	//2.

	int Number[45] = {};
	for (int i = 0; i < 45; ++i) {
		//���̷��� ī�嵦 �����ϸ�
		//1���� 45���� ����ִ� �迭 ����
		Number[i] = i + 1;
		//���� �˰���
		//�ε��� �����ϰ� 2���� �����ϰ�
		//���� ��ġ(��)�� �ٲ��ش�
		//�̰� ������ �ݺ��Ѵ�.
	}
	//���� �迭 ��ҵ��� ���� ���� �ٲ� ������ ��ġ�� �й��Ѵ�.

	for (int i = 0; i < 100; i++)
	{
		int Idx1 = rand() % 45;
		int Idx2 = rand() % 45;

		int Temp = Number[Idx1];
		Number[Idx1] = Number[Idx2];
		Number[Idx2] = Temp;
	}

	//���� �˰���
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (Number[i] > Number[j])
			{
				int Temp = Number[i];
				Number[i] = Number[j];
				Number[j] = Temp;
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		std::cout << Number[i] <<"\t";
	}
	std::cout << std::endl;
	//* �Է¹��� ���� Ƚ����ŭ �ζ� Ƚ�� 
	// ������ġ(10ȸ)
	//* ��÷��ȣ�� �����ϰ� ���� ������� Ȯ���ϱ�
	return 0;


}