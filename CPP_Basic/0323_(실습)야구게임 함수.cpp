#include <iostream>
#include <time.h>
//야구게임
//※ 직접 짠 코드
void Shuffle(int* Array) { //매개변수: 배열을 넘겨받아 쓸 수 있게
	//StrikeNum[0] [1] [2] 를 정답으로 처리할 예정
	//배열 생성
	for (int i = 1; i <= 9; i++)
	{
		Array[i - 1] = i;
	}

	//셔플
	for (int i = 0; i < 100; i++)
	{
		int Idx1 = rand() % 9;
		int Idx2 = rand() % 9;

		int temp = Array[Idx1];
		Array[Idx1] = Array[Idx2];
		Array[Idx2] = temp;
	}
} 

bool ResultCheck(int strike, int ball, bool exit, bool fail) { //판정
	//판정 결과
	if (exit == true && fail == false) {
		if (strike == 3) {
			//std::cout << MyNumber[0] << MyNumber[1] << MyNumber[2] << ", 정답입니다!" << std::endl;
			std::cout << "정답!" << std::endl;
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
		std::cout << "유효하지 않은 숫자입니다." << std::endl;
		fail = false;
		return false;
	}
}
void Check(int& strike, int& ball, bool& exit, bool& fail) {

}

int main() {
	srand((unsigned int)time(0));
	int StrikeNum[9];
	//배열 생성 및 섞기
	Shuffle(StrikeNum);

	//std::cout << "정답: " << StrikeNum[0] << " " << StrikeNum[1] << " " << StrikeNum[2] << std::endl;
	std::cout << "세 자리 숫자 입력" << std::endl;
	std::cout << "게임종료: 숫자 0 입력" << std::endl;
	std::cout << "* * *" << std::endl;
	//게임 시작
	bool exit = true;
	int strike = 0; //위치도 맞고 숫자도 맞음
	int ball = 0; //숫자만 있음
	bool out = false; //관련 숫자 없음

	Check(strike, ball, exit, out);
	while (exit) {
		strike = 0;
		ball = 0;
		out = false;
		int MyNumber[3] = {};

		bool fail = false; // 숫자 잘못 입력했을때 쓰는 변수
		for (int i = 0; i < 3; i++)
		{
			std::cin >> MyNumber[i]; //숫자 3번 입력받기

			//숫자 검증
			if (MyNumber[i] < 0 || MyNumber[i] > 9) {
				fail = true;
				break;
			}//숫자 검증 끝

			//0누르면 답 알려주고 게임 종료
			if (MyNumber[i] == 0) { //0누르면 탈출
				std::cout << "정답: " << StrikeNum[0] << " " << StrikeNum[1] << " " << StrikeNum[2] << std::endl;
				exit = false;
				break;
			}
			//스트라이크 볼 검증
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
		//중복 체크
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

		//판정
		if (ResultCheck(strike, ball, exit, fail) == true) {
			break;
		}

	}
	return 0;
}