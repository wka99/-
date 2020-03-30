#include <iostream>
using namespace std;

int fact(int n) {
	if (n == 0)return 1;
	else if (n <= 2) return n;
	else {
		return n * fact(n - 1);
	}
}
int calc(int n, int k) {
	if (k == 0)return 1;
	else {
		return fact(n) / (fact(n - k) * fact(k));
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << calc(n, k)<< endl;
}