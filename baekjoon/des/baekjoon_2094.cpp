#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define OFFSET 65536
#define SZ_TR 131072

int tree[SZ_TR] = { 0, };
vector<int> years, rains;

int find(int from, int to) {
	int res = 0;
	from += OFFSET;
	to += OFFSET;
	while (from <= to) {
		if (from % 2 == 1) {
			res = max(res, tree[from]);
			from++;
		}
		if (to % 2 == 0) {
			res = max(res, tree[to]);
			to--;
		}
		from /= 2; to /= 2;
	}
	return res;
}
void update(int idx, int data) {
	idx += OFFSET;
	tree[idx] = data;
	idx /= 2;
	while (idx > 0) {
		tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
		idx /= 2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, x, y, r;
	cin >> N;
	for (int i = 0; i < N; i++) { 
		//연도는 오름차순으로 주어진다
		//벡터에 순서대로 저장하고 이분탐색으로 찾아내자
		cin >> y >> r;
		years.push_back(y);
		rains.push_back(r);
		update(i, r);
	}
	cin >> M;
	int yidx, xidx, low, high, mid;
	for (int i = 0; i < M; i++) {
		//y년도와 x년도 사이에 모든 년도가 존재하는지
		//확인하기 위해서는 인덱스트리의 인덱스 차와 x, y의 차가 같은지 확인하면됨
		cin >> y >> x;
		//1. y연도
		low = 0; high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (years[mid] >= y) {
				yidx = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}
		//2. x연도
		low = 0; high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (years[mid] <= x) {
				xidx = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}
		//x연도와 y연도에 대한 정보가 모두 없음
		if (years[yidx] != y && years[xidx] != x) cout << "maybe\n";
		else if (years[yidx] == y && years[xidx] != x) { //y연도 데이터만 존재
			if (find(yidx + 1 , xidx) < rains[yidx]) cout << "maybe\n";
			else cout << "false\n";
		}
		else if (years[yidx] != y && years[xidx] == x) { //x연도 데이터만 존재
			if (find(yidx, xidx - 1) < rains[xidx]) cout << "maybe\n";
			else cout << "false\n";
		}
		else { //x연도와 y연도 정보 모두 존재
			if (rains[yidx] >= rains[xidx] && find(yidx + 1, xidx - 1) < rains[xidx]) {
				//x연도와 y연도 사이값 모두 존재
				if (xidx - yidx == x - y) cout << "true\n";
				else cout << "maybe\n";
			}
			else cout << "false\n";
		}
	}
}