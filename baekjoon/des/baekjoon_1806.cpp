#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100001

int main() {
	int N, S, tmp;
	cin >> N >> S;
	vector<int> numbers;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}
	int left = 0, right = 0;
	long long sum = 0;
	int result = MAX_N;
	while (left <= right) {
		if (sum < S) {
			if (right >= N) break;
			sum += numbers[right];
			right++;
		}
		else if(sum >= S){
			if (result > right - left) {
				result = right - left;
			}
			sum -= numbers[left];
			left++;
		}
	}
	if (result == MAX_N)
		cout << 0 << endl;
	else
		cout << result << endl;
}