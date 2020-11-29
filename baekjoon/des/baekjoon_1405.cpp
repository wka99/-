#include <iostream>
using namespace std;

/*
로봇이 같은 곳을 한번보다 많이 이동하지 않을 때
이동 경로가 단순하다고 한다.
*/
int map[30][30] = { 0, };
int n;//움직일 수 있는 횟수
double Eprob, Wprob, Sprob, Nprob;
double answer = 0;
void robotMove(int x, int y, double prob, int cnt) {
	if (cnt == n) {
		answer += prob;
		return;
	}
	if (!map[x][y - 1]) { //동
		map[x][y - 1] = 1;
		robotMove(x, y - 1, prob*Eprob, cnt + 1);
		map[x][y - 1] = 0;
	}
	if (!map[x][y + 1]) { //서
		map[x][y + 1] = 1;
		robotMove(x, y + 1, prob*Wprob, cnt + 1);
		map[x][y + 1] = 0;
	}
	if (!map[x+1][y]) { //남
		map[x + 1][y] = 1;
		robotMove(x + 1, y, prob*Sprob, cnt + 1);
		map[x + 1][y] = 0;
	}
	if (!map[x-1][y]) { //북
		map[x - 1][y] = 1;
		robotMove(x - 1, y, prob*Nprob, cnt + 1);
		map[x - 1][y] = 0;
	}
}
int main() {
	cin >> n >> Eprob >> Wprob >> Sprob >> Nprob;
	Eprob /= 100; Wprob /= 100;  Sprob /= 100; Nprob /= 100;
	map[14][14] = 1;
	robotMove(14, 14, 1, 0);
	cout.precision(10);
	cout << answer << endl;
}