#include <iostream>
#include <stack>
using namespace std;

int N, ans = 0;
int arr[1001];
stack<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int p, l;
	int maxV = 0, idx;
	int low = 1001, high = 0;
	for (int i = 0; i < N; i++) {
		cin >> p >> l;
		if (low > p) low = p;
		if (high < p) high = p;
		arr[p] = l;
		if (maxV < l) {
			maxV = l;
			idx = p;
		}
	}
	for (int i = low; i <= idx; i++) {
		if (arr[i]) {
			if (st.empty())st.push(arr[i]);
			else if (arr[i] > st.top())st.push(arr[i]);
		}
		ans += st.top();
	}
	while (!st.empty()) st.pop();
	for (int i = high; i > idx; i--) {
		if (arr[i]) {
			if (st.empty())st.push(arr[i]);
			else if (arr[i] > st.top())st.push(arr[i]);
		}
		ans += st.top();
	}
	cout << ans << endl;
}