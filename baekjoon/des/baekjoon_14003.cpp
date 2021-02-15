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
				upper bound의 경우 key값을 초과하는 가장 첫번째 원소의 위치를 찾기 때문에 부적합.
				이분탐색을 통해 해당 원소의 위치를 찾아야하기 때문에
				key 값이 없으면 key 값보다 큰 가장 작은 정수 값의 위치를 찾는
				lower bound만을 사용해야 한다.
				(아니면 이분탐색 직접 구현...)
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