#include <iostream>
using namespace std;

/*
������ ��(EOF)�� �ùٸ��� �Ǵ��ϴ� ����� �����ϴ� ����
������ �־����ٴ� ������ �Է����� �־����� ����
�� �̻� ���� �� ���� ��� ���α׷��� ���� �ǵ���
���������� ��� EOF�� ��Ʈ�� Z
�� �Ѳ����� ����� �ʿ� ����
��� ��Ʈ���� �Է� ��Ʈ���� ����
*/

int main() {
	int a = 0;
	int b = 0;
	/*while(scanf("%d %d",a,b)) {
		cout <<a + b<<endl;
	}*/
	while (true) {
		cin >> a >> b;
		if (cin.eof() == true) {
			break;
		}
		cout << a + b << endl;
	}
}