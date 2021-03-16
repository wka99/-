#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001

int main() {
	long long ans = 0;
	int T, N, M;
	int A[MAX], B[MAX];
	vector<int> sumA, sumB;
	cin >> T >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> B[i];
	int s;
	for (int i = 0; i < N; i++) {
		s = 0;
		for (int j = i; j < N; j++) {
			s += A[j];
			sumA.push_back(s);
		}
	}
	for (int i = 0; i < M; i++) {
		s = 0;
		for (int j = i; j < M; j++) {
			s += B[j];
			sumB.push_back(s);
		}
	}
	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());
	//정렬시 크기가 같은 값은 인접하게 위치하게 된다.
	int l = 0, r = sumB.size() - 1, cur;
	while (l < sumA.size() && r >= 0) {
		cur = sumA[l] + sumB[r];
		if (cur == T) {
			//T와 같은 경우, 
			//현재 subA[i]와 같은 원소의 개수 * 현재 subB[j]와 같은 원소의 개수
			//=> 가능한 조합의 개수
			long long c1 = 0, c2 = 0;
			int tmp = sumA[l];
			while (l < sumA.size() && tmp == sumA[l]) {
				c1++; l++;
			}
			tmp = sumB[r];
			while (r >= 0 && tmp == sumB[r]) {
				c2++; r--;
			}
			ans += c1 * c2;
		}
		else if (cur < T) l++;
		else r--;
	}
	cout << ans << endl;
}