#include <iostream>
using namespace std;
#define MAX_N 101

int nos[MAX_N];
long long cnt[MAX_N][21]; 
//cnt[x][y] x번째 연산 수행결과가 y인 경우 횟수++
//중간 계산 결과의 범위가 0~20

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> nos[i];
	cnt[0][nos[0]] = 1;
	for (int i = 1; i < N-1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (cnt[i-1][j] != 0) {
				if (j + nos[i] <= 20)
					cnt[i][j + nos[i]] += cnt[i - 1][j];
				if (j - nos[i] >= 0)
					cnt[i][j - nos[i]] += cnt[i - 1][j];
			}
		}
	}
	cout << cnt[N-2][nos[N-1]] << endl;
}