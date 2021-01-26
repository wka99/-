#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, tmp;
	vector<int> trees;
	cin >> N >> M;
	int high = 0, low = 0, mid;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		trees.push_back(tmp);
		if (high < tmp) high = tmp;
	}
	int result = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (trees[i] - mid > 0) {
				sum += (trees[i] - mid);
			}
		}
		if (sum >= M) {
			if (result < mid)result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result << endl;
}