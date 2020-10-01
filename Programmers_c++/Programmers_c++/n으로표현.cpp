#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = -1;
void dfs(int number, int N, int cnt, int sum) {
	if (cnt > 8) return;
	if (sum == number) {
		if (answer==-1||answer > cnt) answer = cnt;
		return;
	}
	int nn = 0;
	for (int i = 0; i < 8; i++) {
		nn = nn * 10 + N;
		dfs(number, N, cnt + i + 1, sum + nn);
		dfs(number, N, cnt + i + 1, sum - nn);
		dfs(number, N, cnt + i + 1, sum * nn);
		dfs(number, N, cnt + i + 1, sum / nn);
	}
}
int solution(int N, int number) {
	dfs(number, N, 0, 0);
	return answer;
}

int main() {
	cout<<solution(5, 12);
}