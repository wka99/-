#include <iostream>
#include <string>
using namespace std;
#define k "koosaga"
#define c "cubelover"
#define MAX_N 101

int N;
int rock[MAX_N];
long long total = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> rock[i];
		total += rock[i];
	}
	if (N == 1) {
		if (N % 2 == 0) cout << c << endl;
		else cout << k << endl;
	}
	else {
		int curr = rock[0];
		for (int i = 1; i < N; i++) {
			curr ^= rock[i];
		}
		if (!curr)cout << k << endl;
		else cout << c << endl;
	}
}