#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 101

int T, N, C, ans = 0;
int numbers[MAX_N];
int visited[MAX_N];
int ret[MAX_N];
int flag = 0;

void reverse(int i, int j, int *cpy) {
	vector<int>tmp;
	for (int a = j; a >= i; a--) tmp.push_back(cpy[a]);
	for (int a = 0; a < tmp.size(); a++) {
		cpy[a + i] = tmp[a];
	}
}
void reversort(int * cpy) {
	for (int i = 1; i < N; i++) {
		int* loc = min_element(cpy + i, cpy + N + 1);
		ans += loc - (cpy + i) + 1;
		if (i != (loc - cpy)) reverse(i, loc - cpy, cpy);
	}
}
void makeComb(int idx) {
	if (idx > N) {
		int cpy[MAX_N];
		for (int j = 1; j <= N; j++) cpy[j] = numbers[j];
		reversort(cpy);
		if (ans == C) {
			flag = 1;
			for (int j = 1; j <= N; j++) ret[j] = numbers[j];
		}
		ans = 0;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (flag) return;
		if (!visited[i]) {
			visited[i] = 1;
			numbers[idx] = i;
			makeComb(idx + 1);
			numbers[idx] = 0;
			visited[i] = 0;
		}
	}
}
void init() {
	ans = 0; flag = 0;
	for (int i = 0; i < MAX_N; i++) {
		visited[i] = 0;
		ret[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> C;
		init();
		makeComb(1);
		cout << "Case #" << i << ": ";
		if (ret[1] == 0) cout << "IMPOSSIBLE\n";
		else {
			for (int j = 1; j < N; j++) cout << ret[j] << " ";
			cout << ret[N] << "\n";
		}
	}
}