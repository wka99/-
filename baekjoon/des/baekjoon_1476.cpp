#include <iostream>
using namespace std;
//날짜 계산

int main() {
	int earth = 0;
	int sun = 0;
	int moon = 0;
	int year = 1; //실제 연도
	cin >> earth >> sun >> moon;
	while (1) {
		if ((year-earth)%15==0&&(year-sun)%28==0&&(year-moon)%19==0) {
			break;
		}
		year++;
	}
	cout << year << endl;
}