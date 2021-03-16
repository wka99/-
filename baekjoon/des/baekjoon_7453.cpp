#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 4001
//투포인터
/*
	완전 탐색시 최악의 경우 4000^4	다른 방법이 필요
	두개씩 나눠서 풀기
	4000^2 와 4000^2의 조합들을 구해 정렬
	투포인터로 둘의 합이 0이 되는 것을 찾자
*/
int N;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
int arr1[MAX_N * MAX_N], arr2[MAX_N * MAX_N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr1[idx] = A[i] + B[j];
			arr2[idx++] = C[i] + D[j];
		}
	}
	sort(arr1, arr1 + N * N);
	sort(arr2, arr2 + N * N);
	int l = 0, r = N * N - 1, curr;
	long long ans = 0;
	while (l < N * N && r >= 0) {
		curr = arr1[l] + arr2[r];
		if (curr == 0) {
			int tmp = arr1[l];
			long long c1 = 0, c2 = 0;
			while (l < N * N && tmp == arr1[l]) {
				l++; c1++;
			}
			tmp = arr2[r];
			while (r >= 0 && tmp == arr2[r]) {
				r--; c2++;
			}
			ans += c1 * c2;
		}
		else if (curr < 0) l++;
		else r--;
	}
	cout << ans << endl;
}