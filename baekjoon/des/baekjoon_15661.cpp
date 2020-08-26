#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int statis[21][21];
vector <int> link;
vector <int> start;

int check(int ind) {
	int t1 = 0;
	int t2 = 0;
	if (ind == N) {
		if (link.size() == 0)
			return -1;
		if (start.size() == 0)
			return -1;
		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				if (i == j) continue;
				t1 += statis[link[i]][link[j]];
			}
		}
		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				if (i == j) continue;
				t2 += statis[start[i]][start[j]];
			}
		}
		return abs(t1 - t2);
	}
	int ans = -1;
	link.push_back(ind);
	t1 = check(ind + 1);
	if (ans == -1 || (t1 != -1 && ans > t1))
		ans = t1;
	link.pop_back();
	start.push_back(ind);
	t2 = check(ind + 1);
	if (ans == -1 || (t2 != -1 && ans > t2))
		ans = t2;
	start.pop_back();
	return ans;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> statis[i][j];
		}
	}
	cout<<check(0);
}