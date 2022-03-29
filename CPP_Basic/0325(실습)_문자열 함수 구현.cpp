#include <iostream>
using namespace std;

//strcpy_s, strlen, strcat_s, strcmp 구현하기
int my_strlen(char* input) {
	int len = 0;
	for (int i = 0; i < 64; i++)
	{
		if (input[i] != 0)
			len++;
	}
	return len;
}
void my_strcpy(char* input, const char* change) {	
	memset(input, 0, 64);
	int length = my_strlen((char*)change);
	for (int i = 0; i < length; i++)
	{
		input[i] = change[i];
	}
	
	//input = (char*)change;
	cout << input << "\n" << endl;
}
//input 배열의 총 길이보다 change 배열이 더 커버리면 문제가 발생하기 때문에
//크기를 판별하고 늘리는 알고리즘 필요
void my_strcat(char* input, const char* change) { //붙여넣기
	int length = my_strlen(input);
	for (int i = length; i < 64; i++)
	{
		input[i] = change[i - length];
	}
	cout << input << endl;
}
bool my_strcmp(char* input, const char* change) { //비교 하는 문자
	//비교대상이 같으면 0 다르면 1을 반환한다.
	int length = my_strlen(input);
	for (int i = 0; i < length; i++) {
		if (input[i] != change[i])
			//같지 않으면
			return 1;
	}
	return 0;
}
int main() {
	char input[64] = {};
	
	cout << "문자열 입력" << endl;
	cin >> input;
	cout << "■ 처음에 입력한 문자열: " << input << " ■ \n" << endl;

	cout << "■ 문자열 길이(strlen) : " << my_strlen(input) << "\n" << endl;

	cout << "■ 비교 문자열(strcmp)" << endl;
	if (my_strcmp(input, "same?")) {
		cout << "same? 과 같지 않음\n" << endl;
	}else
		cout << "same? 과 같음\n" << endl;

	cout << "■ 바꾼 문자열(strcpy_s): " << endl;
	my_strcpy(input, "str_change");
	
	cout << "■ 문자열 추가하여 붙여넣기(strcat_s)" << endl;
	my_strcat(input, " ★ 여기서부터 문자열 추가★");
	cout << endl;




	return 0;
}