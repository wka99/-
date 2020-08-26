#include <iostream>
using namespace std;

int main() {
	int month,day,n,m;
	int sum=0;
	cin >> month;
	cin >> day;
	if (month >= 1 && month <= 2) {
		sum = 31 * (month - 1) + day;
	}
	else if (month >= 3) {
		if (month % 2 == 0 && month <= 8) {//Â¦¼ö ´Þ
			m = month / 2;
			n = month - 1 - m;
			sum = m * 31 + n * 30 - 2+day;
		}
		else if(month%2!=0 && month <= 8) {//È¦¼ö ´Þ
			m = month / 2;
			n = month - 1 - m;
			sum = m * 31 + n * 30 - 2+day;
		}
		else if (month >= 9&&month%2!=0) {
			m = month / 2 + 1;
			n = month - 1 - m;
			sum = 31 * m + 30 * n - 2 + day;
		}
		else if(month >= 9 && month % 2 == 0) {
			m = month / 2;
			n = month - 1 - m;
			sum = 31 * m + 30 * n - 2 + day;
		}
	}
	if (sum % 7 == 1) {
		cout << "MON";
	}
	else if (sum % 7 == 2) {
		cout << "TUE";
	}
	else if (sum % 7 == 3) {
		cout << "WED";
	}
	else if (sum % 7 == 4) {
		cout << "THU";
	}
	else if (sum % 7 == 5) {
		cout << "FRI";
	}
	else if (sum % 7 == 6) {
		cout << "SAT";
	}
	else if (sum % 7 == 0) {
		cout << "SUN";
	}
}