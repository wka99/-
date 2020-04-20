#include <iostream>
using namespace std;
//°ö¼À
long long A, B, C;
int pow(long long A, long long B) {
	if (B == 0)return 1;
	else if (B == 1)return A;
	else {
		long long temp = pow(A, B / 2);
		if (B % 2 == 1)
			return ((temp*temp) % C*A) % C;
		else
			return (temp*temp) % C;
	}
}
int main() {
	long long result = 0;
	cin >> A >> B >> C;
	cout << pow(A, B) % C << endl;
}