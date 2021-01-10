#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, result = 0;
	string s;
	cin >> N;
	cin >> s;
	for (int i = 0; i < N; i++) {
		result += s[i] - '0';
	}
	cout << result << endl;
}