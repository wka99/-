#include <iostream>
using namespace std;
#define ADD 10000000

int cards[20000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, t;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		cards[t+ADD] += 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> t;
		cout << cards[t+ADD] << " ";
	}cout << "\n";
}