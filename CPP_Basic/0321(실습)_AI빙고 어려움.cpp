#include <iostream>
#include <time.h>

enum class AIType
{
	None,
	Easy,
	Hard,
	Max,
}; //None과 Max는 예외처리용 열거체

int main()
{
	srand((unsigned int)time(0));
	int Random = rand();

	int AIState = 0; //AI 난이도 선택 변수


	//게임 진행
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

	//빙고판 생성
	int Number[25] = {};
	int AINumber[25] = {};

	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
		AINumber[i] = i + 1;
	}

	//셔플 100배
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

	//빙고 줄 카운트 변수
	int Line = 0, AILine = 0;

	//인공지능이 선택할 배열 생성
	int SelectArray[25] = {};

	//AI가 현재 선택할 수 있는 숫자가 몇개인지 저장하는 변수?
	int SelectCount = 0;

	while (true) {
		system("cls");
		std::cout <<
			"============ Player ================================================= AI =================" << std::endl;
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

		//빙고 표시줄
		std::cout << "Bingo Line : " << Line;
		std::cout << "\t\t\t\t\t\t";
		std::cout << "AI Bingo Line : " << AILine << std::endl;

		//승리 판정
		if (Line >= 5) {
			std::cout << "Player Win" << std::endl;
			break;
		}
		else if (AILine >= 5) {
			std::cout << "AI Win" << std::endl;
			break;
		}

		//빙고 숫자 입력하기
		std::cout << "Input Number0 : Exit) : ";
		int CheckNumber = 0;
		std::cin >> CheckNumber;

		if (CheckNumber == 0)
			break;

		//체크넘버 음수거나 25 초과하면 빠꾸
		else if (CheckNumber < 0 || CheckNumber > 25)
			continue;

		//배열값을 비교하여 해당 값이 있는지 판단한다.
		//있으면 그 숫자를 *로 표시한다 (플레이어 기준 86번째 줄에서 바꿈)
		bool	 check = false;
		for (int i = 0; i < 25; i++)
		{
			if (Number[i] == CheckNumber)
			{
				Number[i] = INT_MAX;
				//숫자 8을 입력받으면 빙고판에 있는 8은
				//2147483647로 바뀌고 이것을 *로 치환하여 출력한다
				//
				check = true;
				break;
			}
		}
		if (!check) //해당 숫자가 존재 하지 않을 시
			continue;

		//플레이어의 *로 변환이 완료되면 
		//AI 빙고판도 해당 숫자를 *로 바꿔준다.
		for (int i = 0; i < 25; i++)
		{
			if (AINumber[i] == CheckNumber)
			{
				AINumber[i] = INT_MAX;
				break;
			}
		}


		//AI 난이도별 switch문
		switch ((AIType)AIState)
		{
		case AIType::Easy:
			SelectCount = 0;
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

			CheckNumber = SelectArray[rand() % SelectCount];
			//AI가 선택할 숫자 = 0~ 총 남은숫자 중 하나 랜덤
			break;
		case AIType::Hard:
		{
			//전체 12줄(가로 5 세로 5 대각선2) 
			// 중 완성된 줄을 제외하고 나머지 미완성된 줄을 체크하여 
			// *의 수가 가장 많은 줄을 찾는다.
			//4개의 줄은 체크하지 않음? 왜지
			int StarCount = 0; //실제 별이 찍힌 카운트
			int CheckLine = 0; //별찍기 좋은 가능성이 높은 라인을 저장

			bool Find = false; // 빙고에 적합한 값을 찾았다는 표기를 하기위한 변수
			for (int i = 0; i < 5; i++)
			{
				//가로 한 줄의 별 수를 체크하기 위한 변수
				int LineStarCount = 0; //별 갯수 체크하는 지역변수(계속 써야 하니까)
				//현재의 가로줄: LineStarCount
				int LineStarCount1 = 0;
				for (int j = 0; j < 5; j++)
				{
					//가로줄 별의 갯수 체크
					if (AINumber[i * 5 + j] == INT_MAX)
						LineStarCount++;
					//세로줄 별의 갯수 체크
					if (AINumber[j * 5 + i] == INT_MAX)
						LineStarCount1++;
				}


				//현재의 가로 줄이 기존에 체크한 줄의 별 수보다 크다면
				// 현재 줄이 가능성이 가장 높은 줄이 된다.
				// (LineStarCount < 5)인 이유는 한 줄 완성(5)은 넘으면 안되니까
				if ((StarCount < LineStarCount) && (LineStarCount < 5))
				{
					StarCount = LineStarCount;
					CheckLine = i; //가로줄 0~4 그림 1 표 참고

					// *이 4개인 곳이 빙고 확률이 가장 높은 곳이므로 선택하게 한다.
					if (StarCount == 4)
					{
						Find = true;
						break;
					}
				}

				// 현재의 세로 줄이 기존에 체크해두었던 줄의 별 수보다
				// 크다면 현재 줄이 가능성이 가능 높은 줄이 된다.
				// LineStarCount1 < 5 를 한 이유는 한 줄이 완성이
				// 안되었을 경우에만 처리를 해야 하기 때문이다.
				if (StarCount < LineStarCount1 && LineStarCount1 < 5)
				{
					StarCount = LineStarCount1;
					CheckLine = i + 5;
					//5, 6, 7 , 8, 9 //그림 1 표 참고

					// *이 4개라면 다른 줄을 체크하더라도 이 이상의
					// 줄이 없으므로 이 줄을 선택하도록 한다.
					if (StarCount == 4)
					{
						Find = true;
						break;
					}
				}
			}

			//Find 변수는  *이 4개일때만 true 이다.
			//false일때만 대각선을 체크하는 인공지능을 만든다.
			if (!Find)
			{
				int LineStarCount = 0; //별 갯수 체크하는 지역변수
				//왼쪽 상단 -> 오른쪽 하단 대각선(10)
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

			//최종 선정 줄 체크
			//가로 줄 중 하나가 최종이면(가로 우선)
			//가로 줄을 하나하나 체크하여 checknumber를int max 값이 아닌것을 선정한다.

			// 예를 들어 가로 2번째 줄이 선정되었다면 CheckLine은
			// 1이 저장되어 있을 것이다.
			// 이 경우 1 * 5 + 0 ~ 4 가 되므로
			// 5 ~ 9 번인덱스를 의미하므로 가로 2번째 줄을
			// 하나씩 체크를 하게 되는 것이다.
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

			//세로줄이 최종
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
			//역슬래시 대각선
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

		std::cout << "AI 가 선택한 숫자 : " << CheckNumber << std::endl;

		//AI가 선택한 숫자를 플레이어와 AI 보드판에 전부 *로 바꿔준다.
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
		//빙고 줄 체크
		Line = 0;
		AILine = 0;

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
	return 0;
}