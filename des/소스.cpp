#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[1500001] = { 0, };
int P[1500001] = { 0, };
int D[1500001] = { 0, };

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <= N; i++) {
		if (i + T[i] <= N + 1) {
			D[i + T[i]] = max(D[i + T[i]], D[i] + P[i]);
		}
		D[i + 1] = max(D[i], D[i + 1]);
	}
	cout << D[N + 1] << endl;
}