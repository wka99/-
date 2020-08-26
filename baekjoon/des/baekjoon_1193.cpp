#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//1 5 13 
	int input;
	int num=0;
	int first;
	int left;
	int right;
	cin >> input;
	for (int i = 1; i <4475 ; i++) {
		if (input == (i + 1)*i / 2) {
			num = i+1;
			if (i % 2 != 0) {//¿À
				left = 1;
				right = i;
				cout << left << "/" << right;
			}
			else {//¿Þ
				left = i;
				right = 1;
				cout << left << "/" << right;
			}

			break;
		}
		else if (input < ((i + 1)*i / 2) && input > ((i - 1)*i / 2)) {
			num = i+1;
			first = (i - 1)*i / 2+1;
			if (i % 2 == 0) {//¿À
				left = 1+(input-first);
				right = num-left;
				cout << left << "/" << right;
			}
			else {//¿Þ
				right = 1+(input-first);
				left = num - right;
				cout << left << "/" << right;
			}
			break;
		}
	}
	
}