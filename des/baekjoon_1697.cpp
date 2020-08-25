#include <iostream>
#include <queue>
using namespace std;

int N, K;
int result = 2000000000;
int visit[100001] = { 0, };
queue <pair<int, int>> q;

int findBrother(int n) {
	visit[n] = 1;
	q.push({ n, 0 });
	while (!q.empty()) {
		int loc = q.front().first;
		int time = q.front().second;
		q.pop();
		if (loc == K) return time;
		if (loc < 100000 && !visit[loc + 1]) {
			q.push({ loc + 1, time + 1 });
			visit[loc + 1] = 1;
		}
		if (loc <= 50000 && !visit[loc * 2]) {
			q.push({ loc * 2, time + 1 });
			visit[loc * 2] = 1;
		}
		if (loc > 0 && !visit[loc - 1]) {
			q.push({ loc - 1, time + 1 });
			visit[loc - 1] = 1;
		}
	}
}
int main() {
	cin >> N >> K;
	cout << findBrother(N) << endl;
}