#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 4001

int N;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
int a[MAX_N * MAX_N], b[MAX_N * MAX_N];
long long ans = 0;
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
			a[idx] = A[i] + B[j];
			b[idx++] = C[i] + D[j];
		}
	}
	sort(a, a + N * N);
	sort(b, b + N * N);
	int l = 0, r = N * N - 1, curr;
	while (l < N * N && r >= 0) {
		curr = a[l] + b[r];
		if (curr == 0) {
			long long c1 = 0, c2 = 0;
			int tmp = a[l];
			while (l < N * N && tmp == a[l]) {
				c1++; l++;
			}
			tmp = b[r];
			while (r >= 0 && tmp == b[r]) {
				c2++; r--;
			}
			ans += c1 * c2;
		}
		else if (curr < 0) l++;
		else r--;
	}
	cout << ans << "\n";
}