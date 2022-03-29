#include <iostream>
#include <time.h>
//빙고 함수 정리
enum class AIType
{
	None,
	Easy,
	Hard,
	Max,
}; //None과 Max는 예외처리용 열거체

//빙고판 생성
void BingoMap(int* Number, int* AINumber) {
	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
		AINumber[i] = i + 1;
	}
}
//셔플 100회
void Shuffle(int* Number, int* AINumber) {

	for (int i = 0; i < 100; i++)
	{
		//플레이어
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
		std::cout << "1. 쉬움" << std::endl;
		std::cout << "2. 어려움" << std::endl;
		std::cout << "난이도를 선택하세요 : ";
		std::cin >> AIState;
		if (AIState > (int)AIType::None &&
			AIState < (int)AIType::Max)
			break;

		// 1, 2 중 하나 선택하면 break;
	}
}
void DrawBoard(int* Number, int* AINumber) {
	//5x5 빙고판 생성 (플레이어)
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Number[i * 5 + j] == INT_MAX)
				//공식 활용 1차원배열로 변환
				//해당 구역 인덱스(x) * 묶음 개수(5) +해당 인덱스 칸(y) 번호
				//[0,0] 부터 [4,4] 까지 1차원 배열의 눈으로 바라보면 됨.
				std::cout << "*\t";
			else
				std::cout << Number[i * 5 + j] << "\t";

		}
		std::cout << "\t\t";

		//5x5 빙고판 생성 (AI)
		for (int j = 0; j < 5; j++)
		{
			//std::cout << "*\t";
			//AI 숫자는 미공개
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
	//if (!check) //해당 숫자가 존재 하지 않을 시

	//AI 빙고판도 해당 숫자를 *로 바꿔준다.
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
		if (AINumber[i] != INT_MAX) //*이 아니면
		{
			//처음에 만들어놨던 빈 배열 SelectArray[25]에
			//입력이 안된 값(*로 표시 안된 값)들을 나열한다.
			//생각하기 힘든 구문인듯..
			SelectArray[SelectCount] = AINumber[i];
			SelectCount++;
		}
	}

	return SelectArray[rand() % SelectCount];
	//AI가 선택할 숫자 = 0~ 총 남은숫자 중 하나 랜덤
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
			//가로 체크 (Player)
			if (Number[i * 5 + j] == INT_MAX)
				CheckCount++;
			//세로 체크 (Player)
			if (Number[j * 5 + i] == INT_MAX)
				CheckCount1++;
			//가로 체크 (AI)
			if (AINumber[i * 5 + j] == INT_MAX)
				AICheckCount++;
			//세로 체크 (AI)
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
	//역슬래시 대각선 판단
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

	// /대각선
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
	int AIState = 0; //AI 난이도 선택 변수
	GameStart(AIState);

	//게임 진행
	//빙고판 생성
	int Number[25] = {};
	int AINumber[25] = {};
	BingoMap(Number, AINumber);
	Shuffle(Number, AINumber);

	//빙고 줄 카운트 변수
	int Line = 0, AILine = 0;

	//인공지능이 선택할 배열 생성
	int SelectArray[25] = {};

	while (true) {
		system("cls");
		std::cout <<
			"============ Player ================================================= AI =================" << std::endl;
		//빙고판 그리기
		DrawBoard(Number, AINumber);

		//빙고 표시줄
		std::cout << "Bingo Line : " << Line;
		std::cout << "\t\t\t\t\t\t";
		std::cout << "AI Bingo Line : " << AILine << std::endl;

		//승리 판정
		if (ResultCheck(Line, AILine) == true) {
			break;
		}

		//빙고 숫자 입력하기
		int CheckNumber = 0;
		std::cout << "Input Number0 : Exit) : ";
		std::cin >> CheckNumber;

		if (CheckNumber == 0)
			break;

		//체크넘버 음수거나 25 초과하면 빠꾸
		else if (CheckNumber < 0 || CheckNumber > 25)
			continue;

		//bingo check
		BingoCheck(Number, AINumber, CheckNumber);


		//AI 난이도별 switch문
		switch ((AIType)AIState)
		{
		case AIType::Easy:
			CheckNumber = AI_Easy_Check(SelectArray, AINumber);
			break;
		case AIType::Hard:
			CheckNumber = AI_Hard_Check(AINumber);
			break;
		}

		// AI가 선택한 숫자를 *로 바꿔주도록 한다.	
		//AI가 선택한 숫자를 플레이어와 AI 보드판에 전부 *로 바꿔준다.
		ChangeStar(Number, AINumber, CheckNumber);
		//std::cout << "AI 가 선택한 숫자 : " << CheckNumber << std::endl;

		//빙고 줄 체크
		Line = 0;
		AILine = 0;
		BingoCheck(Number, AINumber, Line, AILine);
	}
	return 0;
}