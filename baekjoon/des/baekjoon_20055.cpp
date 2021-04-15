#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 201

int N, K;
int belt[MAX_N];
int robot[MAX_N];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N * 2; i++) cin >> belt[i];
	int start = 0, end = N - 1, broken = 0;
	int nth = 1;
	while (1) {
		//1. 벨트 회전
		start = (start - 1 + 2 * N) % (2 * N);
		end = (end - 1 + 2 * N) % (2 * N);
		if (robot[end]) robot[end] = 0;
		//2. 로봇 한칸 이동
		int curr = (end - 1 + 2 * N) % (2 * N), next;
		int bp = (start - 1 + 2 * N) % (2 * N);
		while(curr != bp) {
			next = (curr + 1) % (2 * N);
			if (!robot[curr]) {//해당 칸에 로봇 없음
				curr = next; continue;
			}
			if (robot[next] || !belt[next]) {//이동 불가 (이동하려는 칸에 로봇이 이미 있음 or 망가진 칸)
				curr = next; continue;
			}
			//이동 가능
			belt[next]--;
			if (belt[next] == 0) broken++;
			if (next == end) { //로봇이 한칸 이동해서 마지막 칸으로 이동
				robot[curr]--;
			}
			else { robot[curr]--; robot[next]++; }
			curr = (curr - 1 + 2 * N) % (2 * N);
		}
		if (broken >= K)break;
		//3. 올라가는 위치에 로봇을 올림
		if (belt[start] > 0) { //로봇을 올릴 수 있음
			belt[start]--;
			robot[start]++;
			if (belt[start] == 0) broken++;
		}
		if (broken >= K)break;
		nth++;
	}
	cout << nth << endl;
}