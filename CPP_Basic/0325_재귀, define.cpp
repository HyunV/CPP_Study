#include <iostream>
//#define ��ũ�� ��������� �ݵ�� ����� ����ϴ°��� �ƴϴ�
//�׸��� ������� �ȵǴ� �������� ����
//'�ڵ� ġȯ' �̶�� ���� �ȴ�.
#define OUTPUTTEXT std::cout << "TestOutput" << std::endl;
#define TESTF(Number) std::cout << Number <<std::endl;
using namespace std;

//�Ϲ����� ���
int factorial(int Number) {
	if (Number == 1)
		return 1;
	return Number * factorial(Number - 1);
}
//�������
int factorialtail(int Number, int Result = 1) {
	if (Number == 1)
		return Result;

	return factorialtail(Number - 1, Number * Result);
}
//�Ϲ����� ����Լ��� �����Ϸ��� ��ͷ� �Ǵ������� ������ʹ� do-while������ ����Ͽ� ó���Ѵ�.
// �̷��� �������� ȿ���� ���̰� �߻��Ѵ�.
/* 5�� ������ ��
FT(5, 1)
N: 5
R: 1
FT(5-1, 5*1) //��return 120
		FT(5-1, 5*1)
		N: 4
		R: 5
		FT(4-1, 4*5) //��return 120
				FT(4-1, 4*5)
				N: 3
				R: 20
				FT(3-1, 3*20) //��return 120
						FT(3-1, 3*20)
						N: 2
						R: 60
						FT(2-1, 2*60)  //��return 120
								FT(2-1, 2*60)
								N: 1 //N�� 1�� �Ǿ����� ����
								R: 120
								return 120 //���� ������ ������ ��ģ ������ ���� 120���� �ٲ�
											//���� ��ʹ� ������ ���ʿ� FT�� ������ ��
*/

int main() {
	OUTPUTTEXT //define���� �����Ѱ�
	TESTF(100)

	return 0;
}