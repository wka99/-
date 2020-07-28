#include <iostream>
using namespace std;

int N, K;
char S[31];
bool D[31][31][31][436];

bool check(int i, int a, int b, int k) {
	if (i == N) {
		if (k == K) {
			return true;
		}
		else return false;
	}
	if (D[i][a][b][k]) return false; //이미 고려한 사항을 또 고려할 필요가 없음
	D[i][a][b][k] = true; //방문 기록
	S[i] = 'A';//문자열 뒤에 A추가
	if (check(i + 1, a + 1, b, k)) return true;
	S[i] = 'B';//문자열 뒤에 A추가
	if (check(i + 1, a, b + 1, k + a)) return true;
	S[i] = 'C';//문자열 뒤에 A추가
	if (check(i + 1, a, b, k + a + b)) return true;
	return false;
}
int main() {
	cin >> N >> K;
	if (check(0, 0, 0, 0)) {
		cout << S << endl;
	}
	else {
		cout << -1 << endl;
	}
}