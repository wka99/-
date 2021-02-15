#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1000001

int N;
int nums[MAXN];
int idx[MAXN];
vector<int> LIS, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int>::iterator it;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < N; i++) {
		if (i == 0 || LIS[LIS.size() - 1] < nums[i]) {
			LIS.push_back(nums[i]);
			idx[i] = LIS.size()-1;
		}
		else {
			/*
				upper bound�� ��� key���� �ʰ��ϴ� ���� ù��° ������ ��ġ�� ã�� ������ ������.
				�̺�Ž���� ���� �ش� ������ ��ġ�� ã�ƾ��ϱ� ������
				key ���� ������ key ������ ū ���� ���� ���� ���� ��ġ�� ã��
				lower bound���� ����ؾ� �Ѵ�.
				(�ƴϸ� �̺�Ž�� ���� ����...)
			*/
			it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
			*it = nums[i];
			idx[i] = it - LIS.begin();
		}
	}
	int sz = LIS.size();
	sz--;
	for (int i = N - 1; i >= 0; i--) {
		if (sz == idx[i]) {
			ans.push_back(nums[i]);
			sz--;
		}
	}
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}cout << "\n";
}