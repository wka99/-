#include <iostream>
using namespace std;
#define MAX 100001

int nums[MAX];
int main() {
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	int left = 0, right = 0;
	int curr = 0, len = MAX;
	while (left <= right) {
		if (curr < S && right < N) {
			curr += nums[right];
			right++;
		}
		else {
			if (curr >= S) {
				len = min(len, right - left);
			}
			curr -= nums[left];
			left++;
		}
	}
	if (len == MAX) cout << 0 << endl;
	else cout << len << endl;
}