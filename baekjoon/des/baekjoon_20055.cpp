#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 101

//�κ� �����̳� ������ ������ �̵�
//1�� �ö󰡴� ��ġ, N�� �������� ��ġ
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