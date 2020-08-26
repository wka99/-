#include <iostream>
using namespace std;
//ºí·¢Àè
int N, M;
int card[100] = { 0, };

int main() {
	int result = 0;
	int min = 10000000;
	int minresult = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				result = card[i] + card[j] + card[k];
				if ((M - result) < min&&M>=result) {
					minresult = result;
					min = (M - result);
				}
			}
		}
	}
	cout << minresult << endl;
}