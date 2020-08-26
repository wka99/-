#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int N;
pair <int, int> dots[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dots[i].first >> dots[i].second;
	}
	sort(dots, dots + N);
	for (int i = 0; i < N; i++) {
		cout << dots[i].first << " " << dots[i].second << "\n";
	}
}