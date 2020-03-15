#include <iostream>
#include <vector>
using namespace std;
//1, 2, 3 더하기
int result = 0;

void dfs(int n, int sum, int count) {
	int a, b, c;
	if (sum == n) {
		count++;
		sum = 0;
	}
	if (sum + 1 <= n) {
		dfs(n, sum + 1, count);
	}
	if (sum + 2 <= n) {
		dfs(n, sum + 2, count);
	}
	if (sum + 3 <= n) {
		dfs(n, sum + 3, count);
	}
}
int main() {
	int T=0; //테스트 케이스의 개수
	vector <int> n; //정수
	int temp = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		n.push_back(temp);
	}
	for (int i = 0; i < T; i++) {
		dfs(n[i], 0, result);
		cout << result << endl;
		result = 0;
	}
}