#include <iostream>
using namespace std;

int people(int k, int n) {
	int result = 0;
	if (k == 0) {
		return n;
	}
	else {
		for (int i = 1; i <= n; i++) {
			result += people(k - 1, i);
		}
		return result;
	}
}

int main() {
	int test_case;//�׽�Ʈ ���̽� ��
	cin >> test_case;
	int k; //��
	int n; //ȣ
	int result[100];
	int r;
	for (int i = 0; i < test_case; i++) {
		cin >> k;
		cin >> n;
		result[i] = people(k, n);
	}
	for (int i = 0; i < test_case; i++) {
		cout << result[i]<<endl;
	}
}