#include <iostream>
#include <vector>
using namespace std;
//1, 2, 3 더하기

int result = 0;
int dpm[11] = { 1,2,4, };

void dp(int n) {
	if (n == 0)result++;
	if (n - 1 >= 0) { dp(n - 1); }
	if (n - 2 >= 0) { dp(n - 2); }
	if (n - 3 >= 0) { dp(n - 3); }
}
int dp2(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (dpm[n] != 0) return dpm[n];
	else return dp2(n - 1)+ dp2(n - 2) + dp2(n - 3);
}
int main() {
	int T=0; //테스트 케이스의 개수
	vector <int> n; //정수
	int temp = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		n.push_back(temp);
	}
	for (int i = 0; i < T; i++) {
		dp(n[i]);
		cout << result<<endl;
		result = 0;
	}
	for (int i = 0; i < T; i++) {
		cout << dp2(n[i]) << endl;
	}
}