#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 101

//로봇 컨테이너 위에서 스스로 이동
//1번 올라가는 위치, N번 내려가는 위치
int N, K;
int belt[MAX_N * 2];
int robot[MAX_N];

int main() {
	int a;
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) cin >> belt[i];
	int curr = 1, start = 1;
	while (1) {
		if (curr == 1) {
			if (robot[start])robot[start + 1] = robot[start];
			start = (start - 1 + 2 * N) % (2 * N);
		}

	}
}