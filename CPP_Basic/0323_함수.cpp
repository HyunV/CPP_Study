#include <iostream>
using namespace std;
// 함수 : 원하는 코드를 모아서 구현을 해놓은 뒤에
// 원할때마다 해당 코드를 동작시켜줄 수 있게 해주는 기능

//인자:
//해당 함수의 기능을 수행하기 위해 이 함수의 오부에서 어떤 값을 넘겨주어야 할 경우 사용한다.
//인자에 변수를 선언해서 이 함수를 호출할때 해당 변수에 값을 넘겨주도록 하여 함수 내에서 코드가 동작될 때 
//그 값을 이용하여 원하는 기능을 만들어주는 개념이다.
int Add(int Number1, int Number2)
{
	//인자로 들어온 2개의 정수를 서로 더하여 그 결과를 반환하게 한다.
	return Number1 + Number2;
}

void Test(int* number) {
	int Number2 = 500;

	number = &Number2;

	//Number2와 number는 함수가 종료된 후 지워져버려 값을 메인으로 가져올 수 없다.
}

void Test2(int** Number)
{
	int Number2 = 500;

	*Number = &Number2;
	cout <<"함수2" << &Number2 << endl;
}	

void Test3(int*& Number)
{
	int Number2 = 500;

	Number = &Number2; //Test2 함수와 비교, 역참조 없어도 주소 지정이 가능
	cout << "함수3" << &Number2 << endl;
}

int main() 
{
	//함수를 호출하여 함수에 구현되어 있는 코드를 동작되게 한다.
	int A= 10;
	int B = 20;
	int sum = Add(A, B);
	//cout << Add(20, 10);

	//포인터 함수
	int* pNumber1 = nullptr;
	Test(pNumber1); //함수를 작동시켜 Num2의 주소값을 넣었는데 왜 0일까?
					//함수가 끝나고 소멸되었기 때문이다.
					//갖고오고싶을땐 어떻게 해야될까? -> 이중포인터를 사용한다.
	cout << pNumber1 << std::endl;

	//이중포인터로 값 가져오기
	// 일반포인터일 경우 일반 변수에 메모리주소를 넣어주면 되는거고
	// 이중포인터일 경우 포인터 변수에 메모리주소를 넣어주면 된다. or 포인터 레퍼런스를 넣어준다.

	// pNumber1을 이중포인터로 해서 pNumber1의 주소를 저장한다.
	Test2(&pNumber1);
	std::cout <<"이거랑" << pNumber1 << std::endl;
	//pNumber1은 여기 있던애라 저장해놓은 공간이 소멸되지 않ㅇ므
	//pNumber1은 현재 함수2에있던 Number2의 주소공간을 저장했는데 500이 들어있던 Number2는 소멸했으므로
	//*pNumber1을 하면 댕글링 포인터가 발생.
	

	//레퍼런스
	cout << *pNumber1 << endl;
	Test3(pNumber1); //주소값 안붙여도 알아서 됨
	cout <<"이거랑 같은 메모리" << pNumber1 << endl;
	//함수 2를 실행시켜 종료하면 변수들은 모두 휘발될텐데 pNumber1이 같은건
	//메모리를 비우지만 앞으로 계속 이 메모리를 스택으로 쓰는것으로 인식되어 있기 때문에
	//같은 메모리 공간을 사용하게 된다.
	return 0;
}