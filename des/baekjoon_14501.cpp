#include <iostream>
#include <algorithm>
using namespace std;

/*
������ ���� �ִ�� �� �� �ִ� ���� ���ϸ�
�ִ� ������ ���� �� ����
���� brute force ������ �ƴ� dp ����
����� �ϴ� ���� ����� ���� �ʴ� ��츦
��� ���� �ִ��� ���� �� �ֵ��� �ؾ���
*/

int N;
int T[17] = { 0, };
int P[17] = { 0, };
int DP[17] = { 0, };

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			DP[i + T[i]] = max(DP[i + T[i]], DP[i] + P[i]);
		}
		DP[i + 1] = max(DP[i], DP[i + 1]);
	}
	cout << DP[N + 1] << endl;
} 