#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int square[1001][1001];
int check[1001][1001];
int ssize = 0;
string s;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			square[i][j] = s[j] - 48;
			check[i][j] = square[i][j];
			if (square[i][j] == 1)
				ssize = 1;
		}
	}
	//가장 큰 정사각형 찾기
	int tmp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (square[i][j] == 1) {
				if (square[i - 1][j - 1] == 1 && square[i - 1][j] == 1 && square[i][j - 1] == 1) {
					check[i][j] = min(check[i - 1][j - 1], check[i][j - 1]);
					check[i][j] = min(check[i][j], check[i - 1][j]) + 1;
				}
				ssize = max(ssize, check[i][j]);
			}
		}
	}
	cout << ssize*ssize << endl;
}