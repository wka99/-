#include <iostream>
using namespace std;
//마지막 요세푸스 문제

long long josep(long long n, long long k) {
	if (n == 1) return 0;
	if (k == 1) return n - 1;
	if (k > n) return (josep(n - 1, k) + k) % n;
	long long cnt = n / k;
	long long res = josep(n - cnt, k);
	res -= n % k;
	if (res < 0) res += n;
	else res += res / (k - 1);
	return res;
}
int main() {
	long long N = 0, K = 0;
	cin >> N >> K;
	cout<<josep(N, K)+1<<endl;
}