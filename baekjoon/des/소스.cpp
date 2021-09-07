#include <iostream>
using namespace std;
#define offset 131072
#define SZ_TR 131072*2
#define MAX_N 250001

int N, K;
int tree[SZ_TR];
int num[MAX_N];
long long ans = 0;//Áß¾Ó°ªÀÇ ÇÕ

void update(int idx, int val) {
	idx += offset;
	while (idx > 0) {
		tree[idx] += val;
		idx /= 2;
	}
}
int findKth(int kth) {
	int curr = 1;
	while (curr < offset) {
		if (kth <= tree[curr * 2]) curr = curr * 2;
		else {
			kth -= tree[curr * 2];
			curr = curr * 2 + 1;
		}
	}
	return curr - offset;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	int M = (K + 1) / 2;
	for (int i = 0; i < K; i++) {
		cin >> num[i];
		update(num[i], 1);
	}
	ans += findKth(M);
	for (int i = K; i < N; i++) {
		cin >> num[i];
		update(num[i], 1);
		update(num[i - K], -1);
		ans += findKth(M);
	}
	cout << ans << endl;
}