#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long answer = 0;
	string tmp = to_string(N);
	int len = tmp.length();
	for (int i = 1; i < len; i++) {
		answer += (pow(10, i) - pow(10,i-1))*i;
	}
	answer += (N - pow(10, len - 1) + 1)*len;
	cout << answer << endl;
}