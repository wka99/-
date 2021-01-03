#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
D: 2배, 결과값이 9999보다 큰 경우 10000으로 나눈 나머지
S: n에서 1을 뺀 결과
L: 각 자릿수를 왼쪽으로 회전
R: 각 자릿수를 오른쪽으로 회전

a를 b로 만들기 위해 필요한 최소 명령어의 수
BFS로 탐색하면서 최초로 결과값 b를 만들어내는 명령어들을 출력하면 됨
DFS로 탐색하는 경우, 모든 경우를 구한 후, 명령어의 길이가
가장 짧은 경우를 찾아내야하므로 BFS에 비해 시간이 많이 걸리게
된다. 따라서 BFS가 적합
*/

int a, b;
void bfs() {
	queue<pair<int, string>> q;
	int f; //큐의 front 값 저장
	string tmp; //큐의 front 명령어 저장
	int check[10001] = { 0, }; //방문 여부 확인
	check[a] = 1;
	q.push({ a,"" });
	while (!q.empty()) {
		f = q.front().first;
		tmp = q.front().second;
		if (f == b) {
			cout << tmp << endl;
			break;
		}
		q.pop();
		if (!check[(f * 2) % 10000]) { //D
			q.push({ (f * 2) % 10000 , tmp+"D"});
			check[(f * 2) % 10000] = 1;
		}
		if (f == 0) { //S
			if (!check[9999]) {
				q.push({ 9999,tmp + "S" });
				check[9999] = 1;
			}
		}
		else {
			if (!check[f - 1]) { //S
				q.push({ f-1,tmp + "S" });
				check[f - 1] = 1;
			}
		}
		/*
		레지스터를 숫자 n을 4개의 숫자로 변환하여
		나타낸다고 했으므로 L, R 연산을 아래와 같이 
		나타낼 수 있음

		이 연산을 string으로 바꿔 substring 해주는 과정을
		통해 구현한다면 시간 초과 오류가 발생함을 확인
		*/
		if (!check[(f%1000)*10+f/1000]) { //L
			q.push({ (f % 1000) * 10 + f / 1000, tmp + "L" });
			check[(f % 1000) * 10 + f / 1000] = 1;
		}
		if (!check[(f % 10) * 1000 + f / 10]) { //R
			q.push({ (f % 10) * 1000 + f / 10, tmp + "R" });
			check[(f % 10) * 1000 + f / 10] = 1;
		}
	}
}
int main() {
	int T;
	string cmd = "";
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		bfs();
	}
}