#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//아기상어

struct fish {
	int fishi = 0;
	int fishj = 0;
	int dist = 0;
};
struct babyshark {
	int ssize = 2;//아기상어의 크기
	int sharki = 0;//상어의 위치
	int sharkj = 0;
	int cnt = 0;//먹은 생선 수
	int time = 0;//물고기를 잡아먹을 수 있는 시간
};
int N;

int main() {
	cin >> N;
	babyshark bs;
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 9) {
				bs.sharki = i; bs.sharkj = j;
			}
			else if (temp > 0 && temp <= 6) {

			}
		}
	}
	cout << bs.time << endl;
}