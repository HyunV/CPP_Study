#include <iostream>
using namespace std;

int main() {
	//문자열
//char 1바이트를 차지하는 문자
//wchar_t 2바이트(유니코드)를 차지하는 문자
//* 한글은 2바이트 이므로 wchar_t로 사용
//* 문자열의 끝은 0(널문자) 로 표현이 되어야 한다.

	char Text[64] = "문자열입니다.";
	//총 14바이트 필요 
	//문자열 한글(12) .(1) 마지막 0(1)

	//1. strcpy_s 문자열 복사 함수
	strcpy_s(Text, "TestCopy");

	cout << Text << endl;
	char* pText = Text;
	strcpy_s(pText, 10, "다시 복사"); 
	//다시 복사(2,2,1,2)의 길이가 9이다. 하지만 길이는 10으로 해주어야한다. 
	//공백문자도 포함되어야 하기 때문 
	cout << Text << endl; //문자열입니다 -> TestCopy -> 다시 복사로 바뀌었음
	
	int arr[10] = { 1,2,3,4,5 };
	//memset (메모리주소, 채워줄 값, 채워줄 메모리 크기);
	//메모리 안에 원하는 값을 채워준다.
	
	//memcpy (메모리 주소, 복사할 메모리 주소, 복사할 메모리 크기)
	//1번 인자의 주소에 2번 인자의 주소로부터 3번인자의 크기만큼 복사
	memset(arr, 1, sizeof(int) * 10); 
	//인트 배열이니 sizeof(int) * 10 해서 4바이트 10공간의 크기
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
		//출력을 해보면 이상한 값으로 나오는데 이는
		//memset는 1바이트 단위로 숫자를 할당하기 때문이다.
		//int 배열이면 인덱스 하나에 4바이트이니 1111이 되어버리는것. 
	}
	return 0;
}