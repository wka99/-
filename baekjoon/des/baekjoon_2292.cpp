#include <iostream>
using namespace std;

int main() {//1,6,12,18...
	int input;
	int room_count = 0;
	int sum = 0;
	int sum_1, sum_2;
	cin >> input;
	if (input == 1) {
		room_count = 1;
		cout << room_count;
		return 0;
	}
	for (int i = 2; i < 166666670; i++) {
		sum_1 = 1 + 6 * ((i - 1)*i / 2);
		sum_2 = 1 + 6 * ((i - 2)*(i - 1) / 2);
		if (sum_1>=input&&sum_2<input) {
			room_count = i;
			break;
		}
	}
	cout << room_count;
}