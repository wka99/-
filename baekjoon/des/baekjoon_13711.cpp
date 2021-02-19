#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001

int a[MAX_N], b[MAX_N], order[MAX_N];
vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) cin >> b[i];
	for (int i = 1; i <= N; i++) order[b[i]] = i;
	for (int i = 1; i <= N; i++) a[i] = order[a[i]];
	vector<int>::iterator it;
	for (int i = 1; i <= N; i++) {
		if (lis.size() == 0 || lis.back() < a[i]) {
			lis.push_back(a[i]);
		}
		else {
			it = lower_bound(lis.begin(), lis.end(), a[i]);
			*it = a[i];
		}
	}
	cout << lis.size() << endl;
}