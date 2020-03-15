#include <iostream>
#include <string>
using namespace std;
//다시보자...

int main() {
	string cro;
	cin >> cro;
	int count = 0;
	for (int i = 0; i < cro.length(); i++) {
		if (cro[i] == 'c') {
			if (cro[i + 1] == '='|| cro[i + 1] == '-') {
				i++;
			}
		}
		else if (cro[i] == 'd') {
			if (cro[i + 1] == 'z'&&cro[i + 2] == '=') {
				i++;
				i++;
			}
			else if (cro[i + 1] == '-') {
				i++;
			}
		}
		else if (cro[i] == 'l') {
			if (cro[i + 1] == 'j') {
				i++;
			}
		}
		else if (cro[i] == 'n') {
			if (cro[i + 1] == 'j') {
				i++;
			}
		}
		else if (cro[i] == 's') {
			if (cro[i + 1] == '=') {
				i++;
			}
		}
		else if (cro[i] == 'z') {
			if (cro[i + 1] == '=') {
				i++;
			}
		}
		count++;
	}
	cout << count;
}