#include <iostream>
using namespace std;
#define MAX_H 500005

//누적합 이용

int N, H, t;
int num[MAX_H] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (i % 2 == 0) { //석순
			num[1] += 1;
			num[t + 1] -= 1;
		}
		else { //종유석
			num[H - t + 1] += 1;
			num[H + 1] -= 1;
		}
	}
	for (int i = 1; i <= H; i++) {
		num[i] += num[i - 1];
	}
	int minV = 200001, cnt = 1;
	for (int i = 1; i <= H; i++) {
		if (minV > num[i]) {
			minV = num[i];
			cnt = 1;
		}
		else if (minV == num[i]) cnt++;
	}
	cout << minV << " " << cnt << "\n";
}