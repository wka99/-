#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001

int a[MAX_N], b[MAX_N], order[MAX_N], c[MAX_N];
//c[x]���� a�迭�� x��° ���ڰ� b�迭�� ���°�� �����ϴ����� ����ȴ�.
/*
	���� ���� �κ� ����
	1. a�迭�� b�迭�� ���ÿ� ����
	2. �����ϴ� ������ ���ƾ�
	ex) a{1, 2, 3} b{1, 3, 2} a�� b �迭 ��ο� 1, 2, 3�� ���������� ���� ������ �ٸ�
	=> a�� b�迭�� ���ÿ� �����ϴ� ���� && �ش� ���ڵ��� �ε����� ���������̾��
	���� ���ǿ��� 1���� N������ ������ �迭 a�� �迭 b�� ��� �ѹ��� �����Ѵٰ� ����
	=> ��� ���ڰ� a�� b�迭�� ���ÿ� ����

	"���ڵ��� ���� ������ �������� Ȯ�����ָ� ��"
	���� c[x]�迭�� LIS�� ���� LCS�� ���̸� ���� �� �ִ�
	ex) a{1,3,5,2,4,6} b{4,3,2,6,5,1}
	c{6,2,5,3,1,4} => LIS�� {2, 3, 4}
	=> LCS = {b[2],b[3],b[4]} = {3, 2, 6}
*/
vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) cin >> b[i];
	for (int i = 1; i <= N; i++) order[b[i]] = i;
	for (int i = 1; i <= N; i++) c[i] = order[a[i]];
	vector<int>::iterator it;
	for (int i = 1; i <= N; i++) {
		if (lis.size() == 0 || lis.back() < c[i]) {
			lis.push_back(c[i]);
		}
		else {
			it = lower_bound(lis.begin(), lis.end(), c[i]);
			*it = c[i];
		}
	}
	cout << lis.size() << endl;
}