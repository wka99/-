#include <iostream>
#include <vector>
using namespace std;
#define MAX 2000

vector <int> relat[MAX];
int visited[MAX] = { 0, };
int n = 0;//사람 수
int m = 0;//관계 수
void dfs(int v, int cnt);
int check = 0;

void dfs(int v, int cnt) {
	if (cnt == 4) {
		check = 1;
		return;
	}
	visited[v] = 1;
	for (int i = 0; i < relat[v].size(); i++) {
		if (!visited[relat[v][i]]) {
			dfs(relat[v][i], cnt + 1);
		}
		if (check == 1)return;
	}
	visited[v] = 0;
}
void initvisit() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
}
int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		relat[a].push_back(b);
		relat[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		initvisit();
		dfs(i, 0);
		if (check == 1)break;
	}
	if (check == 1)cout << 1 << endl;
	else cout << 0 << endl;
}
