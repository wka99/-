#include <iostream>
using namespace std;
#define SZ_TR	2000000

int trees[SZ_TR] = { 0, };
int offset;
int N, H;

//구간 업데이트, 특정값 조회

void init() {
	for (offset = 1; offset < H; offset *= 2);
}
void update(int from, int to) { //해당 자식을 완전히 포함하는 부모만을 update
	from += offset;
	to += offset;
	while (from <= to) {
		if (from % 2 == 1) {
			trees[from]++;
			from++;
		}
		if (to % 2 == 0) {
			trees[to]++;
			to--;
		}
		from /= 2; to /= 2;
	}
}
int query(int idx) { //쿼리시 자기자신부터 부모를 타고 올라가서 전부 더한것이 파괴해야 하는 장애물 개수
	int res = 0;
	idx += offset;
	res += trees[idx];
	idx /= 2;
	while (idx > 0) {
		res += trees[idx];
		idx /= 2;
	}
	return res;
}
int main() {
	cin >> N >> H;
	init();
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (i % 2 == 1) { //종유석
			update(H - tmp, H - 1);
		}
		else { //석순
			update(0, tmp - 1);
		}
	}
	int breaks, cnt = 0;
	int minV = 200001;
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