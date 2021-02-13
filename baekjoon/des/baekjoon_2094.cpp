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
		//������ ������������ �־�����
		//���Ϳ� ������� �����ϰ� �̺�Ž������ ã�Ƴ���
		cin >> y >> r;
		years.push_back(y);
		rains.push_back(r);
		update(i, r);
	}
	cin >> M;
	int yidx, xidx, low, high, mid;
	for (int i = 0; i < M; i++) {
		//y�⵵�� x�⵵ ���̿� ��� �⵵�� �����ϴ���
		//Ȯ���ϱ� ���ؼ��� �ε���Ʈ���� �ε��� ���� x, y�� ���� ������ Ȯ���ϸ��
		cin >> y >> x;
		//1. y����
		low = 0; high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (years[mid] >= y) {
				yidx = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}
		//2. x����
		low = 0; high = N - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (years[mid] <= x) {
				xidx = mid;
				low = mid + 1;
			}
			else high = mid - 1;
		}
		//x������ y������ ���� ������ ��� ����
		if (years[yidx] != y && years[xidx] != x) cout << "maybe\n";
		else if (years[yidx] == y && years[xidx] != x) { //y���� �����͸� ����
			if (find(yidx + 1 , xidx) < rains[yidx]) cout << "maybe\n";
			else cout << "false\n";
		}
		else if (years[yidx] != y && years[xidx] == x) { //x���� �����͸� ����
			if (find(yidx, xidx - 1) < rains[xidx]) cout << "maybe\n";
			else cout << "false\n";
		}
		else { //x������ y���� ���� ��� ����
			if (rains[yidx] >= rains[xidx] && find(yidx + 1, xidx - 1) < rains[xidx]) {
				//x������ y���� ���̰� ��� ����
				if (xidx - yidx == x - y) cout << "true\n";
				else cout << "maybe\n";
			}
			else cout << "false\n";
		}
	}
}