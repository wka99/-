#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> obj[101];
int d[101][100001] = { 0, };

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> obj[i].first >> obj[i].second;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (obj[i].first <= j) 
				d[i][j] = max(d[i - 1][j], obj[i].second + d[i - 1][j - obj[i].first]);
			else d[i][j] = d[i - 1][j];
		}
	}
	cout << d[N][K] << endl;
}