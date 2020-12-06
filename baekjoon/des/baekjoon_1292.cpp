#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int a, b, len, answer = 0;
	vector<string> s;
	cin >> a >> b;
	len = b - a + 1;
	int start = 1;
	while (s.size() < b) {
		for (int i = 0; i < start; i++) {
			s.push_back(to_string(start));
		}
		start++;
	}
	for (int i = a - 1; i < b; i++) {
		answer += stoi(s[i]);
	}
	cout << answer << endl;
}