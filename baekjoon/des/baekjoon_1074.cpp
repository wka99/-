#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int n = -1;

void divide(int x, int y, int s) {
	if (s < 2) return;
	if (s == 2) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				n++;
				if (x + i == r && y + j == c) {
					cout << n << endl;
					return;
				}
			}
		}
	}
	if (x <= r && y <= c && x + s / 2 - 1 >= r && y + s / 2 - 1 >= c)
		divide(x, y, s / 2);
	else
		n += pow(s / 2, 2);
	if (x <= r && y + s / 2 <= c && x + s / 2 - 1 >= r && y + s - 1 >= c)
		divide(x, y + s / 2, s / 2);
	else
		n += pow(s / 2, 2);
	if (x + s / 2 <= r && y <= c && x + s - 1 >= r && y + s / 2 - 1 >= c)
		divide(x + s / 2, y, s / 2);
	else
		n += pow(s / 2, 2);
	if (x + s / 2 <= r && y + s / 2 <= c && x + s - 1 >= r && y + s - 1 >= c)
		divide(x + s / 2, y + s / 2, s / 2);
	else
		n += pow(s / 2, 2);
}
int main() {
	int s_size;
	cin >> N >> r >> c;
	s_size = pow(2, N);
	int x = 0, y = 0, mx, my;
	divide(0, 0, s_size);
}