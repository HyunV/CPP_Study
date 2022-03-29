#include <iostream>

int main() {
	/*int Array[10][5] = {};

	int Array1[3] = 30;
	int Array1[50] = { 30 };
	
	Array1[3] = 30;
	Array[0][3] = 30;

	Array1[6] = 100;
	Array[1][1] = 100;*/


	//로또 프로그램
	
	//스왑
	//int Number1 = 20;
	//int Number2 = 30;
	
	//1~45개의 숫자가 있고 이 숫자가 중복되면 안되게
	// 6개의 랜덤한 숫자를 얻어와야 한다.
	srand((unsigned int)time(0));
	int Random = rand();

	std::cout << rand() % 45 + 1 << std::endl;
	std::cout << rand() % 45 + 1 << std::endl;
	std::cout << rand() % 45 + 1 << std::endl;
	std::cout << rand() % 45 + 1 << std::endl;
	std::cout << rand() % 45 + 1 << std::endl;
	//중복이 되었을때는??

	//1. 중복 되었을때 한번 더 뽑아서 다른값으로 바꾼다.
	// -> 이렇게하면 쓸데없는 반복이 많이 발생한다.
	//2.

	int Number[45] = {};
	for (int i = 0; i < 45; ++i) {
		//하이랜더 카드덱 생각하며
		//1부터 45까지 들어있는 배열 생성
		Number[i] = i + 1;
		//셔플 알고리즘
		//인덱스 랜덤하게 2개를 선정하고
		//둘의 위치(값)를 바꿔준다
		//이걸 여러번 반복한다.
	}
	//위의 배열 요소들의 값을 서로 바꿔 랜덤한 위치에 분배한다.

	for (int i = 0; i < 100; i++)
	{
		int Idx1 = rand() % 45;
		int Idx2 = rand() % 45;

		int Temp = Number[Idx1];
		Number[Idx1] = Number[Idx2];
		Number[Idx2] = Temp;
	}

	//정렬 알고리즘
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
	//* 입력받은 게임 횟수만큼 로또 횟수 
	// 만원어치(10회)
	//* 당첨번호를 저장하고 내가 몇등인지 확인하기
	return 0;


}