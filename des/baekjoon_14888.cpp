#include <iostream>
#include <vector>
using namespace std;
//������ �����ֱ�

int minR = 1000000000; //�ּ� ���� ���
int maxR = -1000000000; //�ִ� ���� ���
int N = 0; //���� ����
int number[11]; //����
int opnum[4] = { 0, }; //�� ������ ����

int maxResult(int a, int b) {
	if (a > b)return a;
	else return b;
}
int minResult(int a, int b) {
	if (a < b)return a;
	else return b;
}
void dfs(int plus, int minus, int mul, int div, int sum, int n) {
	if (n == N-1) {
		minR = minResult(minR, sum);
		maxR = maxResult(maxR, sum);
	}
	if (plus > 0) {
		dfs(plus - 1, minus, mul, div, sum + number[n+1], n + 1);
	}
	if (minus > 0) {
		dfs(plus, minus-1, mul, div, sum - number[n+1], n + 1);
	}
	if (mul > 0) {
		dfs(plus, minus, mul-1, div, sum * number[n+1], n + 1);
	}
	if (div > 0) {
		dfs(plus, minus, mul, div-1, sum / number[n+1], n + 1);
	}
}

int main() {

	int result;
	cin >> N;
	for(int i=0; i < N; i++) {
		cin >> number[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> opnum[i];
	}
	result = number[0];
	dfs(opnum[0], opnum[1], opnum[2], opnum[3], result, 0);

	cout << maxR << endl;
	cout << minR<<endl;
}