#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int F, S, G, U, D;
int visited[1000001] = { 0, };
queue <pair<int, int>> q;

void BFS(int s) {
	q.push({ s, 0 });
	visited[s] = 1;
	while (!q.empty()) {
		int loc = q.front().first;
		int button = q.front().second;
		q.pop();
		if (loc == G) {
			cout << button << endl;
			return;
		}
		if (loc + U <= F && !visited[loc + U]) {
			q.push({ loc + U,button + 1 });
			visited[loc + U] = 1;
		}
		if (loc - D >= 1 && !visited[loc - D]) {
			q.push({ loc - D,button + 1 });
			visited[loc - D] = 1;
		}
	}
	cout << "use the stairs" << endl;
}
int main() {
	cin >> F >> S >> G >> U >> D;
	BFS(S);
}