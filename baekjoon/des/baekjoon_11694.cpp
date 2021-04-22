#include <iostream>
#include <string>
using namespace std;
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
		if (total % 2 == 1) cout << "cubelover" << endl;
		else cout << "koosaga" << endl;
	}
	else {
		int curr = 0;
		for (int i = 0; i < N; i++) {
			if (rock[i] == 1) {
				cout << "koosaga" << endl;
				return 0;
			}
			curr ^= rock[i];
		}
		if (curr)cout << "koosaga" << endl;
		else cout << "cubelover" << endl;
	}
}