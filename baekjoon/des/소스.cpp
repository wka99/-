#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 1000001

int N, B, C;
long long test[MAX_N];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> test[i];
	}
	cin >> B >> C;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		test[i] -= B; ans++;
		if (test[i] > 0) {
			if (test[i] % C == 0) {
				ans += test[i] / C;
			}
			else {
				ans += test[i] / C + 1;
			}
		}
	}
	cout << ans << endl;
}