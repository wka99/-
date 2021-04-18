#include <iostream>
#include <string>
using namespace std;

int cnt = 0;
int main() {
	int N;
	cin >> N;
	/*
	곱한값이 10으로 나누어 떨어질때 10으로 나눠주고 개수 세는 방식 => 오버플로가 발생
	소인수분해를 통해 5의 개수를 세는 것이 더욱 적절
	0은 2와 5가 곱해지는 경우 생기게 된다.
	2의 경우 모든 짝수에 존재하지만, 5는 모든 소수에 존재하지 않음
	따라서 5의 개수는 2보다 항상 적으므로 0의 개수는 5의 개수에 의해 결정된다.*/

	for (int i = 1; i <= N; i++) {
		int curr = i;
		while (curr % 5 == 0) {
			cnt++; curr /= 5;
		}
	}
	cout << cnt << endl;
}