#include <iostream>
#include <time.h>
using namespace std;

enum class AIType
{
    None,
    Easy,
    Hard,
    Max
};

//★ ★ ★ 보드 클래스
//역할: 플레이어의 보드 혹은 AI의 보드를 만드는 객체이다.
//이걸 C매니저가 관리하게 하는 구조이다.
class CBoard {
public:
    CBoard()
        //@3. 이니셜라이저를 이용한 초기화
        :
        m_BingoLine(0),
        m_Name{},
        m_Number{}
    {

        memset(m_Name, 0, 32); // @2. 멤셋 이용, 32바이트를 0으로 초기화하는 m_Name 방식
        // 이건 근데 선언과 동시에 초기화 방법이 아님, 
        // 즉 int a = 10; 이 아닌 int a; a=10 이거랑 같다는 뜻
        //메모리를 미리 만들어 놓고 그다음에 값을 넣는거라 엄연히 다름
        //??? 그럼 선언과 동시에 초기화를 하고 싶다면? -> 생성자에 있는 이니셜라이저를 이용

    }
    ~CBoard()
    {}

private:
    //★★★★중요★★★★ (＠로 표시)멤버변수 생성자에 선언하는 방법
    //char m_Name[32] = {}; @1. 여기서 초기화 하는 것도 방법.
    char m_Name[32];
    int m_Number[25]; //보드판 생성
    int m_BingoLine; // @3 생성자 부분 참고
public: //간단한 함수들

    //AI 함수에서 써먹기 위한 배열 받아오기
    int* GetNuomberArray()
    {
        return m_Number; //m_Number 배열 주소를 통으로 보낸다.
    }
    void SetName(const char* Name) //보드에 이름짓는 함수
    {
        strcpy_s(m_Name, Name); //받아온 이름을 m_Name에 넣어준다.
    }
   
    bool CheckWin() { //승리 여부 함수
        return m_BingoLine >= 5;
    }
public:
    void Init() //초기화 함수
    //보드판 초기화의 기능: 숫자를 배치하고, 섞어준다.
    {
        //배열에 숫자 깔기
        for (int i = 0; i < 25; i++)
        {
            m_Number[i] = i + 1;
            //m_Number은 private 형태지만 클래스 내부에 있기 때문에
            // 불러올 수 있다.
        }
        //셔플
        for (int i = 0; i < 100; i++)
        {
            int idx1 = rand() % 25;
            int idx2 = rand() % 25;

            int Temp = m_Number[idx1];
            m_Number[idx1] = m_Number[idx2];
            m_Number[idx2] = Temp;
        }
    }
    void Output() //보드판 출력함수
    {
        cout << "====================" << m_Name << "=====================" << endl;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (m_Number[i * 5 + j] == INT_MAX)
                    cout << "*\t";
                else
                    cout << m_Number[i * 5 + j] << "\t";
            }
            cout << endl;
        }
        std::cout << "BingoLine : " << m_BingoLine <<
            std::endl;
    }

    bool ChangeNumber(int Number) { //입력한 값을 찾아내어 INT_MAX로 바꿈
        for (int i = 0; i < 25; i++)
        {
            if (m_Number[i] == Number) 
            {
                m_Number[i] = INT_MAX;
                return false;
            }
        }
        return true;
    }
    void CheckLine()
    {
        m_BingoLine = 0;

        for (int i = 0; i < 5; ++i)
        {
            int	CheckCount = 0, CheckCount1 = 0;

            for (int j = 0; j < 5; ++j)
            {
                // 가로 줄 체크
                if (m_Number[i * 5 + j] == INT_MAX)
                    ++CheckCount;

                // 세로 줄 체크
                if (m_Number[j * 5 + i] == INT_MAX)
                    ++CheckCount1;
            }

            // 가로 한 줄을 체크했는데 CheckCount 변수가
            // 5라면 해당 줄은 모두 *로 변경되어 있다는 것이다.
            if (CheckCount == 5)
                ++m_BingoLine;

            if (CheckCount1 == 5)
                ++m_BingoLine;
        }

        int	CheckCount2 = 0;
        // 왼쪽 상단 -> 오른쪽 하단
        for (int i = 0; i < 25; i += 6)
        {
            if (m_Number[i] == INT_MAX)
                ++CheckCount2;
        }

        if (CheckCount2 == 5)
            ++m_BingoLine;

        CheckCount2 = 0;

        // 오른쪽 상단 -> 왼쪽 하단
        for (int i = 4; i <= 20; i += 4)
        {
            if (m_Number[i] == INT_MAX)
                ++CheckCount2;
        }

        if (CheckCount2 == 5)
            ++m_BingoLine;
    }
};

class CAI { //인공지능 클래스
public:
    CAI() :
        m_AIType(AIType::None) //이니셜라이즈
    {

    }
    ~CAI()
    {

    }
private:
    AIType	m_AIType;
public:
    AIType GetAIType() //ai 타입 반환 함수
    {
        return m_AIType;
    }
    void SelectAI() //AI 난이도 선택 함수
    {
        while (true)
        {
            system("cls");
            std::cout << "1. Easy" << std::endl;
            std::cout << "2. Hard" << std::endl;
            std::cout << "Input : ";
            int	Input;

            std::cin >> Input;

            if (Input > (int)AIType::None &&
                Input < (int)AIType::Max)
            {
                m_AIType = (AIType)Input;
                break;
            }
        }
    }

    int SelectNumber(const int* Number) //숫자배열을 가지고온다.
    {
        // 플레이어가 선택한 숫자를 모두 바꾸었다면 인공지능이
        // 선택할 수 있도록 한다.
        switch ((AIType)m_AIType)
        {
        case AIType::Easy:
        {
            // 인공지능이 선택을 하기 위해서 현재 안바뀐 값을 저장할
            // 배열을 만들어준다.
            int	SelectArray[25] = {};
            // AI가 현재 선택할 수 있는 숫자가 몇개인지를 저장할 변수를
            // 만들어준다.
            int	SelectCount = 0;
            // 현재 입력 안된 값들을 찾아서 배열에 넣어준다.
            SelectCount = 0;

            for (int i = 0; i < 25; ++i)
            {
                // *이 아닌 일반 값일 경우
                if (Number[i] != INT_MAX)
                {
                    // 배열에 이 값을 넣어준다.
                    SelectArray[SelectCount] = Number[i];
                    ++SelectCount;
                }
            }

            return SelectArray[rand() % SelectCount];
        }
        case AIType::Hard:
        {
            // 전체 12줄 중 완성된 줄을 제외하고 나머지 미완성된 줄을
            // 체크하여 *의 수가 가장 많은 줄을 찾는다.
            int	StarCount = 0;
            int	CheckLine = 0;
            // Find는 한 줄에 별이 4개짜리 줄이 있을 경우
            // true로 바꾸어서 대각선 줄을 체크 안하도록 해주는\
				// 변수이다.
            bool	Find = false;
            for (int i = 0; i < 5; ++i)
            {
                // 가로 한 줄의 별 수를 체크하기 위한 변수.
                int	LineStarCount = 0;
                int	LineStarCount1 = 0;
                for (int j = 0; j < 5; ++j)
                {
                    // 가로 줄 체크를 하는데 값이 *로 표시되는
                    // INT_MAX일 경우 이 줄의 별 수를 증가시킨다.
                    if (Number[i * 5 + j] == INT_MAX)
                        ++LineStarCount;

                    // 세로 줄 체크를 하는데 값이 *로 표시되는
                    // INT_MAX일 경우 이 줄의 별 수를 증가시킨다.
                    if (Number[j * 5 + i] == INT_MAX)
                        ++LineStarCount1;
                }

                // 현재의 가로 줄이 기존에 체크해두었던 줄의 별 수보다
                // 크다면 현재 줄이 가능성이 가능 높은 줄이 된다.
                // LineStarCount < 5 를 한 이유는 한 줄이 완성이
                // 안되었을 경우에만 처리를 해야 하기 때문이다.
                if (StarCount < LineStarCount && LineStarCount < 5)
                {
                    StarCount = LineStarCount;
                    CheckLine = i;

                    // *이 4개라면 다른 줄을 체크하더라도 이 이상의
                    // 줄이 없으므로 이 줄을 선택하도록 한다.
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

                    // *이 4개라면 다른 줄을 체크하더라도 이 이상의
                    // 줄이 없으므로 이 줄을 선택하도록 한다.
                    if (StarCount == 4)
                    {
                        Find = true;
                        break;
                    }
                }
            }

            // Find변수는 *이 4개짜리인 줄을 찾았을때 true가 되므로
            // false일때만 대각선을 체크해주도록 한다.
            if (!Find)
            {
                int	LineStarCount = 0;

                // 왼쪽 상단 -> 오른쪽 하단 대각선
                for (int i = 0; i < 25; i += 6)
                {
                    if (Number[i] == INT_MAX)
                        ++LineStarCount;
                }

                if (StarCount < LineStarCount && LineStarCount < 5)
                {
                    StarCount = LineStarCount;
                    CheckLine = 10;

                    // *이 4개라면 다른 줄을 체크하더라도 이 이상의
                    // 줄이 없으므로 이 줄을 선택하도록 한다.
                    if (StarCount == 4)
                    {
                        Find = true;
                        break;
                    }
                }

                if (!Find)
                {
                    LineStarCount = 0;

                    // 오른쪽 상단 -> 왼쪽 하단 대각선
                    for (int i = 4; i < 21; i += 4)
                    {
                        if (Number[i] == INT_MAX)
                            ++LineStarCount;
                    }

                    if (StarCount < LineStarCount && LineStarCount < 5)
                    {
                        StarCount = LineStarCount;
                        CheckLine = 11;
                    }
                }
            }

            // 가로줄 중 하나가 최종 줄로 선정되었을 경우
            if (CheckLine <= 4)
            {
                // 예를 들어 가로 2번째 줄이 선정되었다면 CheckLine은
                // 1이 저장되어 있을 것이다.
                // 이 경우 1 * 5 + 0 ~ 4 가 되므로
                // 5 ~ 9 번인덱스를 의미하므로 가로 2번째 줄을
                // 하나씩 체크를 하게 되는 것이다.
                for (int i = 0; i < 5; ++i)
                {
                    if (Number[CheckLine * 5 + i] != INT_MAX)
                    {
                        return Number[CheckLine * 5 + i];
                    }
                }
            }

            // 세로줄 중 하나가 최종 줄로 선정되었을 경우
            else if (CheckLine <= 9)
            {
                for (int i = 0; i < 5; ++i)
                {
                    if (Number[i * 5 + (CheckLine - 5)] != INT_MAX)
                    {
                        return Number[i * 5 + (CheckLine - 5)];
                    }
                }
            }

            // 왼쪽 상단 -> 오른쪽 하단
            else if (CheckLine == 10)
            {
                for (int i = 0; i < 25; i += 6)
                {
                    if (Number[i] != INT_MAX)
                    {
                        return Number[i];
                    }
                }
            }

            // 오른쪽 상단 -> 왼쪽 하단
            else
            {
                for (int i = 4; i < 21; i += 4)
                {
                    if (Number[i] != INT_MAX)
                    {
                        return Number[i];
                    }
                }
            }
        }
        }

        // 인공지능이 잘못되었을 경우 -1을 리턴하여 알려준다.
        return -1;
    }
};
//★ ★ ★ 전체 게임을 관리하는 관리자 클래스 생성
class CGameManager
{
public:
    //생성자: 클래스로 인해 객체가 생성되면 자동으로 호출이 되는 함수
            /*특징
            - 따로 안만들면 기본생성자 호출
            - 초기화 작업할 때 많이 씀
            - 오버로딩으로 쓸 수 있음(매개변수 없는 생성자, 있는 생성자)
           */
    CGameManager()
    {
        cout << "CGameManager 생성자" << std::endl;
    }
    //클래스가 끝나 객체가 소멸(메모리 해제)되면 호출되는 함수
    //지역변수면 해당 코드블록이 종료될 때 호출되고 
    //동적할당이면 delete 될때 호출이 된다.
    ~CGameManager()
    {
        cout << "소멸자 on" << endl;
    }
private: //보드 클래스 에 사용되는 변수
    CBoard m_PlayerBoard;
    CBoard m_AIBoard;
    CAI m_AI;

public:
    void Init()
    {
        //인공지능을 선택한다.
        m_AI.SelectAI();

        // 2개의 보드를 초기화한다.
        m_PlayerBoard.Init();
        m_AIBoard.Init();

        //각각 만든 보드에 이름을 지어준다.
        m_PlayerBoard.SetName("Player");
        m_AIBoard.SetName("AI");

        //이걸 메인에서 Manager.Init(); 하면
        //2개의 보드를 초기화 해주겠다는거
    }

    void Run() //전체적인 게임을 작동시킨다.
    {
        while (true)
        {
            system("cls");


            m_PlayerBoard.Output();
            m_AIBoard.Output();

            if (m_PlayerBoard.CheckWin())
            {
                cout << "Player Win" << endl;
                break;
            }
            else if (m_AIBoard.CheckWin())
            {
                cout << "AI Win" << endl;
                break;
            }

            //입력 받기
            int Input;
            cout << "숫자를 입력하세요(0: 종료) : ";
            cin >> Input;

            if (Input == 0)
                break;

            else if (Input < 0 || Input > 25) //이상한 숫자 입력받으면 빠꾸
                continue;

            if (m_PlayerBoard.ChangeNumber(Input)) //참값이면 중복이라는 소리
                continue;

            m_AIBoard.ChangeNumber(Input);
           

            //AI의 선택
            Input = m_AI.SelectNumber(m_AIBoard.GetNuomberArray());
            //AI보드판의 주소를 가져와 숫자를 고르는 함수에 전달

            m_PlayerBoard.ChangeNumber(Input);
            m_AIBoard.ChangeNumber(Input);
            
            m_PlayerBoard.CheckLine();
            m_AIBoard.CheckLine();
        }
    }
};

int main()
{
    srand((unsigned int)time(0));
    int Random = rand();
    /* {//소멸자 상태도 보기 위해 코드블럭을 집어넣었음
        CGameManager Manager; //이거 선언할때 생성자 소멸자 다 불러짐
        int Number = 100;

        cout << Number << endl;
    }//이 코드블럭이 끝나는 순간 끝났다는걸 감지하고 소멸자를 자동으로 호출

    cout << "생성자 아직 안부르고 매니저 선언만 한 상태" << endl;
    */

    CGameManager Manager;
   
    Manager.Init(); //초기화

    Manager.Run(); //게임 시작
    return 0;
}
