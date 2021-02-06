#include <iostream>
using namespace std;
#define MAX_N 100001

int p[MAX_N]; //각 원소가 속합 집합의 대표값 표시
int d[MAX_N]; //무게 차이 저장
int r[MAX_N]; //트리의 rank를 저장, 루트 노드만 해당 트리의 값을 가지고 내부 노드는 1의 값을 가짐
/*
	union tree의 크기를 가지고 있는 배열
	두개의 트리를 합치는 경우 크기가 큰 트리에 크기가 작은
	트리를 합치는 것이 이후, find 연산을 수행할 때
	부모값 갱신 횟수가 적어지므로 효율적이게 된다.
	시간복잡도를 줄이고 최적화를 위해 필요한 배열
	7 9
	! 1 2 100
	! 2 3 100
	! 4 3 150
	! 6 7 50
	! 5 6 50
	! 5 4 10
	? 5 3
	? 5 7
	? 1 5
	0 0

	ans
	160
	100
	40
*/
int Find(int x) {
	if (x == p[x])return p[x];
	int xp = Find(p[x]);
	d[x] += d[p[x]];
	//update시 대표값의 dist만 수행되었기 때문에 find 함수를 수행하면서 
	//부모 노드의 dist까지 더해서 해당 노드 x의 dist를 갱신해주어야 함
	return p[x] = xp;
}
void Union(int x, int y, int w) {
	int xp = Find(x);
	int yp = Find(y);
	if (xp == yp) return;
	//큰 나무에 작은 나무를 붙이자
	if (r[xp] > r[yp]) {
		p[yp] = xp;
		d[yp] -= (d[y] - d[x] - w); // 붙여지는 쪽 트리의 대표값 dist 갱신
		r[xp] += r[yp];
		r[yp] = 1;
	}
	else {
		p[xp] = yp;
		d[xp] += (d[y] - d[x] - w);
		r[yp] += r[xp];
		r[xp] = 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	char c;
	int a, b, w;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) {
			p[i] = i; d[i] = 0; r[i] = 1;
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
				else
					cout << "UNKNOWN\n";
			}
		}
	}
}