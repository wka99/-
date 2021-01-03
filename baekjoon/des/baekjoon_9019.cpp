#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
D: 2��, ������� 9999���� ū ��� 10000���� ���� ������
S: n���� 1�� �� ���
L: �� �ڸ����� �������� ȸ��
R: �� �ڸ����� ���������� ȸ��

a�� b�� ����� ���� �ʿ��� �ּ� ��ɾ��� ��
BFS�� Ž���ϸ鼭 ���ʷ� ����� b�� ������ ��ɾ���� ����ϸ� ��
DFS�� Ž���ϴ� ���, ��� ��츦 ���� ��, ��ɾ��� ���̰�
���� ª�� ��츦 ã�Ƴ����ϹǷ� BFS�� ���� �ð��� ���� �ɸ���
�ȴ�. ���� BFS�� ����
*/

int a, b;
void bfs() {
	queue<pair<int, string>> q;
	int f; //ť�� front �� ����
	string tmp; //ť�� front ��ɾ� ����
	int check[10001] = { 0, }; //�湮 ���� Ȯ��
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
		�������͸� ���� n�� 4���� ���ڷ� ��ȯ�Ͽ�
		��Ÿ���ٰ� �����Ƿ� L, R ������ �Ʒ��� ���� 
		��Ÿ�� �� ����

		�� ������ string���� �ٲ� substring ���ִ� ������
		���� �����Ѵٸ� �ð� �ʰ� ������ �߻����� Ȯ��
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