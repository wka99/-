#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//���� �� �����ϴ� �κ� ����
/*
	LIS(longest increasing subsequence) �˰���
	�Ϲ������� dp�� �̿��Ͽ� �ذ�
	length �迭�� Ȱ���Ͽ� i��° �ε������� ������ ���� ���� �κ� ������ ���̸� ����
*/

int main() {
	int N, tmp, curr, maxv = 1;
	int length[1001] = { 0, };
	vector<int> a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		length[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i])
				length[i] = max(length[i], length[j] + 1);
			if (maxv < length[i]) maxv = length[i];
		}
	}
	cout << maxv << endl;
}