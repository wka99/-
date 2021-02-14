#include <iostream>
using namespace std;
#define MAX_N 100001

int number[MAX_N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
	}
	for (int i = 2; i <= N; i++) {
		number[i] += number[i - 1];
	}
	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		cout << number[to] - number[from - 1] << "\n";
	}
}