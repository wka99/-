#include <iostream>
using namespace std;

int main() {
	int on, bef, flag = 0;
	cin >> bef;
	for (int i = 1; i < 8; i++) {
		cin >> on;
		if (bef < on) flag += 1;
		else if (bef > on) flag -= 1;
		bef = on;
	}
	if (flag == 7) cout << "ascending" << endl;
	else if (flag == -7) cout << "descending" << endl;
	else cout << "mixed" << endl;
}