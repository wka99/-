#include <iostream>
#include <vector>
using namespace std;

//톱니바퀴 복사
vector <char> wheel[4];
int K;

void turn(int num, int dir) { //톱니바퀴 회전 함수
	char tmp;
	if (dir > 0) { //시계방향
		tmp = wheel[num][7];
		wheel[num].pop_back();
		wheel[num].insert(wheel[num].begin(), tmp);
	}
	else if (dir < 0) { //반시계방향
		tmp = wheel[num][0];
		wheel[num].erase(wheel[num].begin());
		wheel[num].push_back(tmp);
	}
}

int main() {
	char t;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> t;
			wheel[i].push_back(t);
		}
	}
	cin >> K;
	int num, dir;
	for (int i = 0; i < K; i++) {
		cin >> num >> dir;
		num -= 1;
		int dirs[4] = { 0, };
		dirs[num] = dir;
		//기준 톱니바퀴 왼쪽
		for (int j = num-1; j >= 0; j--) {
			if (wheel[j][2] != wheel[j+1][6]) {
				dirs[j] = -dirs[j+1];
			}
			else break; //돌 일 없으면 그 옆에 있는 톱니바퀴 확인 안해도 됨
		}
		//기준 톱니바퀴 오른쪽
		for (int j = num + 1; j < 4; j++) {
			if (wheel[j][6] != wheel[j-1][2]) {
				dirs[j] = -dirs[j-1];
			}
			else break;
		}
		//구한 방향대로 돌려주기
		for (int j = 0; j < 4; j++) {
			if (dirs[j] == 0) continue;
			else {
				turn(j, dirs[j]);
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