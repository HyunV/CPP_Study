#include <iostream>
using namespace std;

//strcpy_s, strlen, strcat_s, strcmp �����ϱ�
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
//input �迭�� �� ���̺��� change �迭�� �� Ŀ������ ������ �߻��ϱ� ������
//ũ�⸦ �Ǻ��ϰ� �ø��� �˰��� �ʿ�
void my_strcat(char* input, const char* change) { //�ٿ��ֱ�
	int length = my_strlen(input);
	for (int i = length; i < 64; i++)
	{
		input[i] = change[i - length];
	}
	cout << input << endl;
}
bool my_strcmp(char* input, const char* change) { //�� �ϴ� ����
	//�񱳴���� ������ 0 �ٸ��� 1�� ��ȯ�Ѵ�.
	int length = my_strlen(input);
	for (int i = 0; i < length; i++) {
		if (input[i] != change[i])
			//���� ������
			return 1;
	}
	return 0;
}
int main() {
	char input[64] = {};
	
	cout << "���ڿ� �Է�" << endl;
	cin >> input;
	cout << "�� ó���� �Է��� ���ڿ�: " << input << " �� \n" << endl;

	cout << "�� ���ڿ� ����(strlen) : " << my_strlen(input) << "\n" << endl;

	cout << "�� �� ���ڿ�(strcmp)" << endl;
	if (my_strcmp(input, "same?")) {
		cout << "same? �� ���� ����\n" << endl;
	}else
		cout << "same? �� ����\n" << endl;

	cout << "�� �ٲ� ���ڿ�(strcpy_s): " << endl;
	my_strcpy(input, "str_change");
	
	cout << "�� ���ڿ� �߰��Ͽ� �ٿ��ֱ�(strcat_s)" << endl;
	my_strcat(input, " �� ���⼭���� ���ڿ� �߰���");
	cout << endl;




	return 0;
}