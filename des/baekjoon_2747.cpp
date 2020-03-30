#include <iostream>
using namespace std;

int memo[46] = { 0,1, };

int fibo(int n) {
	if (n <= 1)return n;
	else if (memo[n] != 0)
		return memo[n];
	else {
		memo[n] = fibo(n-1)+ fibo(n-2);
		return memo[n];
	}
}
int main() {
	int n;
	cin >> n;
	cout<<fibo(n)<<endl;
}