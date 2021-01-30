#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 200000
/*
	Ư�� ������ �ִ밪�� �ʿ�
	x�� y ���� ������ �������� �ִ밪��
	x�� ���������� ���� ��� ���� �ȴ�.
	=> indexed tree(max)�� �̿�
*/
int N;
vector <int> years, rains;
int trees[MAX_N] = { 0, }; //��� �κ��� ������ ���� ���ϵ��� 0���� �ʱ�ȭ
int offset;

void init() {
	for (offset = 1; offset < N; offset *= 2);
	for (int i = 0; i < N; i++) {
		trees[offset + i] = rains[i];
	}
	for (int i = offset - 1; i > 0; i--) {
		trees[i] = max(trees[i * 2], trees[i * 2 + 1]);
	}
}
int query(int from, int to) {
	int res = 0;
	from += offset; to += offset;
	while (from <= to) {
		if (from % 2 == 1) {
			res = max(res, trees[from]);
			from++;
		}
		if (to % 2 == 0) {
			res = max(res, trees[to]);
			to--;
		}
		from /= 2; to /= 2;
	}
	return res;
}
int main() {
	cin >> N;
	int x, y, r, M;
	for (int i = 0; i < N; i++) {
		cin >> y >> r;
		years.push_back(y);
		rains.push_back(r);
	}
	init();
	cin >> M;
	int low, high, mid;
	int yidx, xidx;
	for (int i = 0; i < M; i++) {
		cin >> y >> x;
		low = 0; high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (years[mid] >= y) high = mid - 1;
			else low = mid + 1;
		}
		yidx = high + 1;
		low = 0; high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (years[mid] <= x) low = mid + 1;
			else high = mid - 1;
		}
		xidx = low - 1;
		if (y != years[yidx] && x != years[xidx]) {
			cout << "maybe" << endl;
		}
		else if (y != years[yidx] && x == years[xidx]) {
			if (query(yidx, xidx - 1) < rains[xidx]) cout << "maybe" << endl;
			else cout << "false" << endl;
		}
		else if (y == years[yidx] && x != years[xidx]) {
			if (query(yidx + 1, xidx) < rains[yidx]) cout << "maybe" << endl;
			else cout << "false" << endl;
		}
		else {
			if (rains[yidx] >= rains[xidx] && query(yidx+1, xidx-1)<rains[xidx]) {
				if (x - y == xidx - yidx) cout << "true" << endl;
				else cout << "maybe" << endl;
			}
			else cout << "false" << endl;
		}
	}
}