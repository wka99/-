#include <iostream>
using namespace std;
#define MAX_N 1000001
#define SZ_TR 10000000

int N, M, K;
long long nos[MAX_N], tree[SZ_TR];
int OFFSET;

void init() {
	for (OFFSET = 1; OFFSET < N; OFFSET *= 2);
	for (int i = 0; i < N; i++) { //리프 노드에 숫자들 넣기
		tree[OFFSET + i] = nos[i];
	}
	for (int i = N; i < OFFSET; i++) { //빈 리프 노드
		tree[OFFSET + i] = 0;
	}
	for (int i = OFFSET - 1; i > 0; i--) { //부모 노드들 채우기
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}
long long query(int from, int to) {
	long long res = 0;
	from += OFFSET; to += OFFSET;
	while (from <= to) {
		if (from % 2 == 1) {
			res += tree[from];
			++from;
		}
		if (to % 2 == 0) {
			res += tree[to];
			--to;
		}
		from /= 2;
		to /= 2;
	}
	return res;
}
void update(int idx, long long val) {
	idx += OFFSET;
	tree[idx] = val;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> nos[i];
	}
	init();
	long long a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(b - 1, c);
		else
			cout << query(b - 1, c - 1) << endl;
	}
}