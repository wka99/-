#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> solution(int n) {
	vector<int> answer;
	int tmp[1001][1001];
	int total = (n + 1)*n / 2;
	int dir = 0;//우선 아래로
	int x = 0, y = 0;
	int cnt = 1;
	for (int i = 0; i < n; i++){
		switch(dir) {
			case 0: //아래쪽
				for (int j = i; j < n; j++) {
					tmp[x++][y] = cnt++;
				}
				x--;
				y++;
				dir = 1;
				break;
			case 1: //오른쪽
				for (int j = i; j < n; j++) {
					tmp[x][y++] = cnt++;
				}
				x--;
				y -= 2;
				dir = 2;
				break;
			case 2: //위쪽
				for (int j = i; j < n; j++) {
					tmp[x--][y--] = cnt++;
				}
				x += 2;
				y++;
				dir = 0;
				break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer.push_back(tmp[i][j]);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}cout << endl;
	return answer;
}
int main() {
	solution(5);
}