#include <iostream>
//#define 매크로 상수이지만 반드시 상수로 사용하는것은 아니다
//그리고 디버깅이 안되니 남발하지 말자
//'코드 치환' 이라고 보면 된다.
#define OUTPUTTEXT std::cout << "TestOutput" << std::endl;
#define TESTF(Number) std::cout << Number <<std::endl;
using namespace std;

//일반적인 재귀
int factorial(int Number) {
	if (Number == 1)
		return 1;
	return Number * factorial(Number - 1);
}
//꼬리재귀
int factorialtail(int Number, int Result = 1) {
	if (Number == 1)
		return Result;

	return factorialtail(Number - 1, Number * Result);
}
//일반적인 재귀함수는 컴파일러가 재귀로 판단하지만 꼬리재귀는 do-while문으로 취급하여 처리한다.
// 이러한 과정에서 효율의 차이가 발생한다.
/* 5를 연산할 때
FT(5, 1)
N: 5
R: 1
FT(5-1, 5*1) //□return 120
		FT(5-1, 5*1)
		N: 4
		R: 5
		FT(4-1, 4*5) //□return 120
				FT(4-1, 4*5)
				N: 3
				R: 20
				FT(3-1, 3*20) //□return 120
						FT(3-1, 3*20)
						N: 2
						R: 60
						FT(2-1, 2*60)  //□return 120
								FT(2-1, 2*60)
								N: 1 //N이 1이 되었으니 리턴
								R: 120
								return 120 //■이 리턴이 나오면 □친 곳들이 전부 120으로 바뀜
											//기존 재귀는 연산을 왼쪽에 FT를 수행할 것
*/

int main() {
	OUTPUTTEXT //define으로 선언한것
	TESTF(100)

	return 0;
}