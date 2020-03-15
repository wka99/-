#include <iostream>
using namespace std;

/*
파일의 끝(EOF)을 올바르게 판단하는 방법을 연습하는 문제
몇줄이 주어진다는 정보가 입력으로 주어지지 않음
더 이상 읽을 게 없을 경우 프로그램이 종료 되도록
윈도우즈의 경우 EOF는 컨트롤 Z
꼭 한꺼번에 출력할 필요 없음
출력 스트림과 입력 스트림은 별개
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