#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long D[31][31] = { 0, };
/*
D[a][b] => 한조각 짜리가 a개 이고 반조각 짜리가 
b개 있는 경우 약을 먹는 방법의 개수
*/
int main() {
	int N;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (i == 0)
				D[i][j] = 1;
			else if (j == 0)
				D[i][j] = D[i - 1][j + 1];
			else
				D[i][j] = D[i - 1][j + 1] + D[i][j - 1];
		}
	}
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		cout << D[N][0] << endl;
	}
}