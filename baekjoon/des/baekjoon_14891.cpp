#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector <char> wheel[4];

void turn(int num, int dir) {
	char tmp;
	if (dir > 0) { //시계 방향
		tmp = wheel[num][7];
		wheel[num].pop_back();
		wheel[num].insert(wheel[num].begin(), tmp);
	}
	else if (dir < 0) { //반시계 방향
		tmp = wheel[num][0];
		wheel[num].erase(wheel[num].begin());
		wheel[num].push_back(tmp);
	}
}
int main() {
	char t;
	int wnum, dir, K;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> t;
			wheel[i].push_back(t);
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> wnum >> dir;
		wnum -= 1;
		int d[4] = { 0, };
		d[wnum] = dir;
		//기준 톱니바퀴 오른쪽 모두 조사
		for (int j = wnum + 1; j < 4; j++) {
			if (wheel[j - 1][2] != wheel[j][6]) {
				d[j] = -d[j - 1];
			}
			else break;
		}
		//기준 톱니바퀴 왼쪽 모두 조사
		for (int j = wnum-1; j >= 0; j--) {
			if (wheel[j][2] != wheel[j + 1][6]) {
				d[j] = -d[j + 1];
			}
			else break;
		}
		for (int j = 0; j < 4; j++) {
			if (d[j] != 0) {
				turn(j, d[j]);
			}
		}
	}
	int sum = 0;
	for (int i = 3; i >= 0; i--) {
		sum *= 2;
		if (wheel[i][0] != '0') {
			sum += 1;
		}
	}
	cout << sum << endl;
}