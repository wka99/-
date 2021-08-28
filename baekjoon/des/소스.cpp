#include <iostream>
using namespace std;

long long x, y, z;

int main() {
	cin >> x >> y;
	z = y * 100 / x;
	if (z >= 99) { //�Ҽ��� ���ϸ� ������ ������ �� �̻� ���� �� ����
		cout << -1 << endl;
	}
	else {
		// y:980000000, x:1000000000 �� ��� �ִ� 1000000000���� ���ؾ� z���� 1 �ø� �� �ִ�.
		int low = 0, high = 1000000000, mid;
		long long score;
		int ans = -1;
		while (low <= high) {
			mid = (low + high) / 2;
			score = (y + mid) * 100 / (x + mid);
			if (z >= score) {
				//score�� z���� �۰ų� ������ ���ִ� �����뼱�� �����ϴ� ���Ӽ��� 1��
				//���� ���� �·��� ���̱� ���� �ּҷ� �÷����ؾ� �ϴ� ������ ���̴�.
				low = mid + 1;
				ans = mid + 1;
			}
			else high = mid - 1;
		}
		cout << ans << endl;
	}
}