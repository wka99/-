#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 250000
#define SZ_TR 131072
#define OFFSET 65536
//중앙값의 합을 출력하는 프로그램

int N, K;
int nos[MAX_N];
int trees[SZ_TR] = { 0, };

void update(int idx, int data) {
	idx += OFFSET;
	while (idx > 0) {
		trees[idx] += data;
		idx /= 2;
	}
}
int findKth(int kth) {
	int cur = 1;
	while (cur < OFFSET) {
		if (trees[cur * 2] >= kth) cur *= 2;
		else {
			kth -= trees[cur * 2];
			cur = cur * 2 + 1;
		}
	}
	return cur - OFFSET;
}
int main() {
	int t, M;
	long long ans = 0;
	cin >> N >> K;
	M = (K + 1) / 2;
	for (int i = 0; i < K; i++) {
		cin >> nos[i];
		update(nos[i], 1);
	}
	ans = findKth(M);
	for (int i = K; i < N; i++) {
		cin >> nos[i];
		update(nos[i], 1);
		update(nos[i - K], -1);
		ans += findKth(M);
	}
	cout << ans << endl;
}