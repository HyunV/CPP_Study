#include <iostream>
using namespace std;

int main() {
	//const 포인터를 선언하는 방법에는 2가지가 있다..
	//1. 왼쪽에다 선언하는 방법
	//2. 오른쪽에다 선언하는 방법

	//■1■ 포인터 타입 왼쪽에 const를 붙일 경우
	const int Number = 999;
	int Number1 = 1010;
	

	// 포인터 타입 왼쪽에 const를 붙여줄 경우 해당 포인터 변수는
	// 다른 변수의 메모리 주소로 값을 변경하는 것이 가능하다.
	// ※ 단, 해당 주소에 접근하여(역참조) 값을 변경하는것은
	// 불가능하다. 값을 가져다 사용하는 용도로는 가능하다.
	
	// ※ 친곳 부가 설명
	// 메모리 주소를 바꾼다. 가능
	// 역참조로 값을 가져온다 -> 가능
	// 역참조로 값을 수정한다 -> 불가능
	
	//■ 일반 int 포인터 변수에 const 변수를 집어 넣을 순 없다.
	//■ 단, const 포인터 주소에는 일반 변수의 주소를 집어 넣을 수 있다.
	// int* pNumber = &Number; //(불가능)
	// const int *pNumber2 = &Number2; //(가능)
	
	const int* pNumber = &Number;
	const int* pNumber1 = &Number1;
	//*pNumber = 500; //식이 수정할 수 있는 lvalue 여야 합니다 (해당 주소에 접근하여 역참조 하는것이 불가능하다)
	 
	//■2■ 포인터 타입 오른쪽에 const를 붙일 경우
	// ■ const int 타입의 메모리주소는 지정이 불가능하다.
	int	Number2 = 3030;
	//int* const pNumber2 = &Number; -> Number가 const int 타입이무로 지정이 불가능하다.
	
	//■ 처음에 지정한 주소 이외에 다른 변수의 주소로 변경이 불가능하다.
	int* const pNumber2 = &Number1; // pNumber2가 const가 되었다.
									// 왼쪽은 포인터 자료형이 const가 되었는데?
	//pNumber2 = &Number2;// const pNumber2는 이미 &Number1을 할당받았기 때문에 더이상 변경은 불가능하다.
	// 마치 상수값 바꿀 수 없는 것처럼..
	// 단 얘는 왼쪽과 다르게 역참조 가능

	//요약
	/*
	포인터 타입변수 왼쪽 const (실제)값변경불가(역참조 불가), 
	포인터 타입변수 오른쪽 const 주소변경 불가
	*/
	
	//기출변형
	const int* const pNumber3 = &Number1;
	//얘는 역참조도 못하고 주소도 못바꿈
	//그냥 가져다 그 값을 쓸 수만 있게 만들어놓음


	//●VOID 포인터
	//타입이 없는 포인터 타입
	//특징: 모든 포인터변수 타입의 메모리 주소를 저장이 가능
	// 이렇게 유도리 있는만큼 기본적으로는 역참조가 불가능
	// 단 형변환을 통해 역참조를 사용할 수 있고 포인터 변수와 맞지 않는 형변환 시 이상한 값이 나옴

	
	void* pNumber4 = &Number2; //&Number2는 일반 int형 Number2의 주소

	*((int*)pNumber4) = 191919; //형변환 해주고 역참조
	//*((float*)pNumber4) = 3.14f;
	std::cout << Number2 << std::endl;

	return 0;
}