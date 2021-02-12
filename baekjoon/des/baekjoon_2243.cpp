#include <iostream>
using namespace std;
#define MAX 1000001
#define OFFSET 1048576
#define SZ_TR 2097152

int tree[SZ_TR] = { 0, };

void update(int idx, int data) {
	idx += OFFSET;
	while (idx > 0) {
		tree[idx] += data;
		idx /= 2;
	}
}
int findKth(int k) {
	int cur = 1;
	while (cur < OFFSET) {
		if (tree[cur * 2] >= k) cur *= 2;
		else {
			k -= tree[cur * 2];
			cur = cur * 2 + 1;
		}
	}
	int idx = cur - OFFSET;
	update(idx, -1); //�����ϳ� ���ֱ�
	return idx;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, a, b, c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == 1) { //���� ����, b�� ���� ���� ����
			cin >> b;
			cout << findKth(b) << "\n";
		}
		else { //���� ��/��, b�� ���� ������ ��, c�� ����
			cin >> b >> c;
			update(b, c);
		}
	}
}