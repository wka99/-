#include <iostream>
using namespace std;
#define MAX_N 100001

int par[MAX_N]; //각 원소가 속한 집합의 대표값 표시
int d[MAX_N]; //무게 차이 저장
int r[MAX_N];
/*
	union tree의 크기를 가지고 있는 배열
	두개의 트리를 합치는 경우 크기가 큰 트리에 크기가 작은 
	트리를 합치는 것이 이후, find 연산을 수행할 때
	부모값 갱신 횟수가 적어지므로 효율적이게 된다.
	시간복잡도를 줄이고 최적화를 위해 필요한 배열
*/

int Find(int x) {
	if (par[x] == x) return par[x];
	int xp = Find(par[x]);
	d[x] += d[par[x]];
	return par[x] = xp;
}
void Union(int x, int y, int w) { //y가 x보다 w 무거움
	int xp = Find(x);
	int yp = Find(y);
	//큰 트리에 작은 트리 붙이기
	if (r[xp] > r[yp]) { //큰 트리 xp, 작은 트리 yp
		par[yp] = xp;
		d[yp] -= (d[y] - d[x] - w);
		r[xp] += r[yp];
		r[yp] = 1; //대표값 노드가 아닌 경우 모두 1
	}
	else {
		par[xp] = yp;
		d[xp] += (d[y] - d[x] - w);
		r[yp] += r[xp];
		r[xp] = 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	char c;
	int a, b, w;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) {
			par[i] = i; d[i] = 0; r[i] = 1;
		}
		for (int i = 0; i < M; i++) {
			cin >> c;
			if (c == '!') { //무게 측정
				cin >> a >> b >> w;
				Union(a, b, w);
			}
			else { //교수님 질문
				cin >> a >> b;
				if (Find(a) == Find(b)) {
					cout << d[b] - d[a] << "\n";
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
		}
	}
}