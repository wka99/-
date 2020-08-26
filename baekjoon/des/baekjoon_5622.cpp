#include <iostream>
#include <string>
using namespace std;

int main() {
	int i = 0;
	string phone_alpha;
	int phone_time = 0;
	cin >> phone_alpha;
	for (i = 0; i < phone_alpha.length(); i++) {
		if (phone_alpha[i] == 'A' || phone_alpha[i] == 'B' || phone_alpha[i] == 'C') {
			phone_time += 3;
		}
		else if (phone_alpha[i] == 'D' || phone_alpha[i] == 'E' || phone_alpha[i] == 'F') {
			phone_time += 4;
		}
		else if (phone_alpha[i] == 'G' || phone_alpha[i] == 'H' || phone_alpha[i] == 'I') {
			phone_time += 5;
		}
		else if (phone_alpha[i] == 'J' || phone_alpha[i] == 'K' || phone_alpha[i] == 'L') {
			phone_time += 6;
		}
		else if (phone_alpha[i] == 'M' || phone_alpha[i] == 'N' || phone_alpha[i] == 'O') {
			phone_time += 7;
		}
		else if (phone_alpha[i] == 'P' || phone_alpha[i] == 'Q' || phone_alpha[i] == 'R'|| phone_alpha[i]=='S') {
			phone_time += 8;
		}
		else if (phone_alpha[i] == 'T' || phone_alpha[i] == 'U' || phone_alpha[i] == 'V') {
			phone_time += 9;
		}
		else {
			phone_time += 10;
		}
	}
	cout << phone_time;
}