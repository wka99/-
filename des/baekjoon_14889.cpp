#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int statis[21][21];
vector <int> link;
vector <int> start;

int check(int cur, int ind) {
	int t1 = 0;
	int t2 = 0;
	if (ind == N / 2) {
		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				if (i == j)continue;
				t1 += statis[link[i]][link[j]];
			}
		}
		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				if (i == j)continue;
				t2 += statis[start[i]][start[j]];
			}
		}
		return abs(t1 - t2);
	}
	int ans = -1;
	for (int i = cur; i < start.size(); i++) {
		int tmp = start[i];
		link.push_back(tmp);
		start.erase(start.begin() + i);
		t1 = check(i, ind + 1);
		link.pop_back();
		start.insert(start.begin() + i, tmp);
		if (ans == -1 || (t1 != -1 && ans > t1))
			ans = t1;
	}
	return ans;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		start.push_back(i);
		for (int j = 0; j < N; j++) {
			cin >> statis[i][j];
		}
	}
	cout << check(0, 0);
}
