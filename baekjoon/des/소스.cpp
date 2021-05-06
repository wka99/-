#include <iostream>
using namespace std;
#define MAX_N 17

int N;
int w[MAX_N][MAX_N];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}
}