#include <iostream>
#include <algorithm>
using namespace std;

int Dmax[3] = { 0, };
int Dmin[3] = { 0, };
int main() {
	int N;
	int maxv = 0, minv = 1000000, tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tDmax[3], tDmin[3];
		for (int j = 0; j < 3; j++) {
			cin >> tmp;
			if (j == 0) {
				tDmax[j] = max(tmp + Dmax[j], tmp + Dmax[j + 1]);
				tDmin[j] = min(tmp + Dmin[j], tmp + Dmin[j + 1]);
			}
			else if (j == 1) {
				tDmax[j] = max(tmp + Dmax[j - 1], max(tmp + Dmax[j], tmp + Dmax[j + 1]));
				tDmin[j] = min(tmp + Dmin[j - 1], min(tmp + Dmin[j], tmp + Dmin[j + 1]));
			}
			else {
				tDmax[j] = max(tmp + Dmax[j], tmp + Dmax[j - 1]);
				tDmin[j] = min(tmp + Dmin[j], tmp + Dmin[j - 1]);
			}
		}
		for (int j = 0; j < 3; j++) {
			Dmax[j] = tDmax[j];
			Dmin[j] = tDmin[j];
		}
	}
	for (int j = 0; j < 3; j++) {
		if (maxv < Dmax[j]) maxv = Dmax[j];
		if (minv > Dmin[j]) minv = Dmin[j];
	}
	cout << maxv << " " << minv << endl;
}