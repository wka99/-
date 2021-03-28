#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 101

int T, N, ans = 0;
int numbers[MAX_N];

void reverse(int i, int j) {
	vector<int>tmp;
	for (int a = j; a >= i; a--) tmp.push_back(numbers[a]);
	for (int a = 0; a < tmp.size(); a++) {
		numbers[a + i] = tmp[a];
	}
}
void reversort() {
	for (int i = 1; i < N; i++) {
		int *loc = min_element(numbers + i, numbers + N + 1);
		ans += loc - (numbers + i) + 1;
		if(i!=(loc-numbers)) reverse(i, loc - numbers);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) cin >> numbers[j];
		reversort();
		cout << "Case #" << i << ": " << ans << endl;
		ans = 0;
	}
}