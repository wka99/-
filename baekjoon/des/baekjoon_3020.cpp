#include<iostream>
using namespace std;
#define OFFSET 524288
#define SZ_TR 1048576

int tree[SZ_TR] = { 0, };
int N, H;

int query(int idx) {
	int res = 0;
	idx += OFFSET;
	while (idx > 0) {
		res += tree[idx];
		idx /= 2;
	}
	return res;
}
void update(int from, int to) { //구간 업데이트
	from += OFFSET;
	to += OFFSET;
	while (from <= to) {
		if (from % 2 == 1) tree[from++]++;
		if (to % 2 == 0) tree[to--]++;
		from /= 2; to /= 2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (i % 2 == 0) { //석순
			update(0, t - 1);
		}
		else { //종유석
			update(H - t, H - 1);
		}
	}
	int minV = 200001, breaks, cnt = 1;
	for (int i = 0; i < H; i++) {
		breaks = query(i);
		if (minV > breaks) {
			minV = breaks;
			cnt = 1;
		}
		else if (minV == breaks) cnt++;
	}
	cout << minV << " " << cnt << endl;
}