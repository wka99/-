#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Greedy ¹æ½Ä

int main() {
	int N, start, end;
	vector<vector<int>> time;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		time.push_back({ end, start });
	}
	sort(time.begin(), time.end());
	int ep = time[0][0], cnt = 1;
	for (int i = 1; i < N; i++) {
		if (ep <= time[i][1]) {
			ep = time[i][0];
			cnt++;
		}
	}
	cout << cnt << endl;
}