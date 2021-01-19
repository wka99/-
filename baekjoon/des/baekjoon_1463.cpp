#include <iostream>
using namespace std;

int minN = 1000000;
void DFS(int curr, int cnt) {
	if (cnt > minN) return;
	if (curr == 1) {
		if (minN > cnt)
			minN = cnt;
		return;
	}
	if (curr % 3 == 0)
		DFS(curr / 3, cnt + 1);
	if (curr % 2 == 0)
		DFS(curr / 2, cnt + 1);
	DFS(curr - 1, cnt + 1);
}
int main() {
	int x;
	cin >> x;
	DFS(x, 0);
	cout << minN << endl;
}