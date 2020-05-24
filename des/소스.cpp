#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int check(int num) {//3의 거듭 제곱으로 나타낼 수 있는지 체크
	int temp = 0;
	while (num > 0) {
		int i = 0;
		while (1) {
			if (num < pow(3, i)) {
				break;
			}
			i++;
		}
		if (temp == i - 1) // 같은 거듭 제곱 수가 나온 경우
			return 0;
		num -= pow(3, i - 1);
		temp = i - 1;
	}
	if (num == 0)
		return 1;
	else
		return 0;
}

int main() {
	int n;
	cin >> n;
	vector <int> list;
	int temp;
	int i = 0;
	list.push_back(1);
	while (list.size()<n) {
		temp = pow(3, i);
		while (temp < pow(3, i + 1)) {
			cout << "temp" << temp << endl;
			if (check(temp) == 1) {
				list.push_back(temp);
			}
			temp++;
		}
		i++;
	}
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}
	cout << list[n - 1] << endl;
}