#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	while (1) {
		cin >> N;
		if (N == "0")
			break;
		else {
			for (int i = 0; i < N.length(); i++) {
				if (N[i] != N[N.length() - i - 1]) {
					cout << "no" << endl;
					break;
				}
				if (i == N.length() - 1)
					cout << "yes" << endl;
			}
		}
	}
}