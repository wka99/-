#include<iostream>
using namespace std;
#define MAX_N 200001
#define OFFSET 524288
#define SZ_TR 1048576

int N, H;
int tree[SZ_TR];

void update(int from, int to) {
	from += OFFSET;
	to += OFFSET;
	while (from <= to) {
		if (from % 2 == 1) {
			tree[from]++; from++;
		}
		if (to % 2 == 0) {
			tree[to]++; to--;
		}
		from /= 2; to /= 2;
	}
}
int query(int idx) {
	int ret = 0;
	idx += OFFSET;
	ret += tree[idx];
	idx /= 2;
	while (idx > 0) {
		ret += tree[idx];
		idx /= 2;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> H;
	int h;
	for (int i = 0; i < N; i++) {
		cin >> h;
		if (i % 2 == 0) {//석순
			update(0, h - 1);
		}
		else {//종유석
			update(H - h, H - 1);
		}
	}
	int cnt, minVal = MAX_N, breaks;
	for (int i = 0; i < H; i++) {
		breaks = query(i);
		if (minVal > breaks) {
			minVal = breaks;
			cnt = 1;
		}
		else if (minVal == breaks)cnt++;
	}
	cout << minVal << " " << cnt << "\n";
}