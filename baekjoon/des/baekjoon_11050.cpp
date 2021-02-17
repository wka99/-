#include <iostream>
using namespace std;

int main() {
	int n, k;
	int res = 1;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		res *= (n-i);
	}
	for (int i = 1; i <= k; i++) {
		res /= i;
	}
	cout << res << endl;
}