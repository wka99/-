#include<iostream>
using namespace std;
#define MAX_N 501

int tri[MAX_N][MAX_N] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	int maxV = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			tri[i][j] = max(tri[i][j] + tri[i - 1][j], tri[i][j] + tri[i - 1][j - 1]);
			if (maxV < tri[i][j])maxV = tri[i][j];
		}
	}
	cout << maxV << "\n";
}