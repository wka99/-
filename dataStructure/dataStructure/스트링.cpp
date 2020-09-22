#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
	string s;
	cin >> s;
	int startIndex = 0;
	int sum = 0;
	while (true) {
		int fIndex = s.find("+", startIndex);
		if (fIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "")break;
			sum += stoi(part);
			break;
		}
		string part = s.substr(startIndex, fIndex - startIndex);
		sum += stoi(part);
		startIndex = fIndex + 1;
	}
	cout << sum << endl;
}