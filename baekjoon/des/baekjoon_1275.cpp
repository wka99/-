#include <iostream>
using namespace std;
#define MAX_N 100001
#define SZ_TR 1000001

long long trees[SZ_TR], nos[MAX_N];
int offset;
int N, Q;

void init() {
	for (offset = 1; offset < N; offset *= 2);
	for (int i = 0; i < N; i++) {
		trees[i + offset] = nos[i];
	}
	for (int i = N; i < offset; i++) {
		trees[i + offset] = 0;
	}
	for (int i = offset - 1; i > 0; i--) {
		trees[i] = trees[i * 2] + trees[i * 2 + 1];
	}
}
long long query(int from, int to) {
	long long res = 0;
	from += offset; to += offset;
	while (from <= to) {
		if (from % 2 == 1) {
			res += trees[from++];
		}
		if (to % 2 == 0) {
			res += trees[to--];
		}
		from /= 2; to /= 2;
	}
	return res;
}
void update(int idx, int val) {
	idx += offset;
	trees[idx] = val;
	idx /= 2;
	while (idx > 0) {
		trees[idx] = trees[idx * 2] + trees[idx * 2 + 1];
		idx /= 2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> nos[i];
	}
	init();
	int x, y, a, b;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		if (x < y) cout << query(x - 1, y - 1) << "\n";
		else cout << query(y - 1, x - 1) << "\n";
		update(a - 1, b);
	}
}