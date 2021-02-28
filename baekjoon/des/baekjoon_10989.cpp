#include <iostream>
using namespace std;

int num[10001];
int main() {
	int t;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		num[t]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++) {
			cout << i << "\n";
		}
	}
}