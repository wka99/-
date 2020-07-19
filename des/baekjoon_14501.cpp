#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <pair <int, int>> task;
int main() {
	cin >> N;
	int t, p;
	for (int i = 0; i < N; i++) {
		cin >> t >> p;
		task.push_back(make_pair(t, p));
	}
}