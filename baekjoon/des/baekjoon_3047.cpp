#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[3];
char abc[3];
vector <pair <char, int>> pairs;

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> abc[i];
	}
	sort(num, num + 3);
	for (int i = 0; i < 3; i++) {
		if (abc[i] == 'A')
			cout << num[0] << " ";
		else if (abc[i] == 'B')
			cout << num[1] << " ";
		else
			cout << num[2] << " ";
	}cout << endl;
}