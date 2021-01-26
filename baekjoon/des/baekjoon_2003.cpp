#include <iostream>
#include <vector>
using namespace std;

//투 포인터
int main() {
	int N, M, K;
	int A[10000];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int left = 0, right = 0, cnt = 0;
	long long s = 0;
	while (left <= right) {
		if (s == M) {
			s -= A[left];
			left++;
			cnt++;
		}
		else if (s < M) {
			if (right >= N) break;
			s += A[right];
			right++;
		}
		else {
			s -= A[left];
			left++;
		}
	}
	cout << cnt << endl;
}