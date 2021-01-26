#include <iostream>
using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;
	long long z = y * 100 / x;
	int low = 0, high = 1000000000, mid;
	if (z >= 99) { //�Ҽ��� ���ϸ� ������ ������ z�� 99�� ��쿡�� 100�� �� �� ����
		cout << -1 << endl;
		return 0;
	}
	int ans = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		long long tmpZ = (y + mid) * 100 / (x + mid);
		if (tmpZ <= z) {
			//tmpZ�� z���� �۰ų� ������ ���ִ� �����뼱�� �����ϴ� ���Ӽ� ���� 1��
			//���� ���� �ּҷ� �÷����ؾ� �ϴ� ������ ���̴�.
			ans = mid + 1 ;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans << endl;
}