#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//수 찾기 (이분탐색)
int N, M;
vector <int> num;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int left=0, right=N-1, mid;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] > temp)
				right = mid - 1;
			else if (num[mid] < temp)
				left = mid + 1;
			else {
				cout << 1 << "\n";
				break;
			}
		}
		if (left > right)cout << 0 << "\n";
		left = 0; right = N - 1;

	}
}
/*int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());
	vector <int>::iterator it;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		it = lower_bound(num.begin(), num.end(), temp);
		if (*it != temp)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}
}*/