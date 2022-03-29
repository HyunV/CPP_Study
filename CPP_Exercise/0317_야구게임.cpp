#include <iostream>
#include <time.h>
//야구게임
int main() {
	srand((unsigned int)time(0));
	int StrikeNum[9];
	//배열 생성
	for (int i = 1; i <= 9; i++)
	{
		StrikeNum[i - 1] = i;
	}

	//셔플
	//StrikeNum[0] [1] [2] 를 정답으로 처리할 예정
	for (int i = 0; i < 100; i++)
	{
		int Idx1 = rand() % 9;
		int Idx2 = rand() % 9;

		int temp = StrikeNum[Idx1];
		StrikeNum[Idx1] = StrikeNum[Idx2];
		StrikeNum[Idx2] = temp;
	}
	//std::cout << "정답: " << StrikeNum[0] << " " << StrikeNum[1] << " " << StrikeNum[2] << std::endl;

	std::cout << "세 자리 숫자 입력" << std::endl;
	std::cout << "게임종료: 숫자 0 입력" << std::endl;
	std::cout << "* * *" << std::endl;
	//게임 시작
	bool exit = true;
	int strike = 0; //위치도 맞고 숫자도 맞음
	int ball = 0; //숫자만 있음
	bool out = false; //관련 숫자 없음
	while (exit) {
		strike = 0;
		ball = 0;
		out = false;
		int MyNumber[3] = {};
		//랜덤한 숫자를 표시		
		for (int i = 0; i < 3; i++)
		{
			std::cin >> MyNumber[i];

			if (MyNumber[i] == 0) { //0누르면 탈출
				std::cout << "정답: " << StrikeNum[0] << " " << StrikeNum[1] << " " << StrikeNum[2] << std::endl;
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
		//판정

		//판정 결과
		if (exit == true) {
			if (strike == 3) {
				std::cout << MyNumber[0] << MyNumber[1] << MyNumber[2] << ", 정답입니다!" << std::endl;
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
