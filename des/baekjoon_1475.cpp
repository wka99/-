#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string input;
	int roomnum[10];
	double sixnine = 0;
	int max = 0;
	for (int i = 0; i < 10; i++) {
		roomnum[i] = 0;
	}
	int len = 0;
	cin >> input;
	len = input.length();
	for (int i = 0; i < len; i++) {
		roomnum[int(input[i]) - 48] += 1;
	}
	for (int i = 0; i < 10; i++) {
		if (max < roomnum[i] && i != 9 && i != 6) {
			max = roomnum[i];
		}
		else if (i == 6 || i == 9) {
			sixnine += roomnum[i];
		}
	}
	if (max < ceil(sixnine / 2)) {
		max = ceil(sixnine / 2);
	}
	cout << max;
}