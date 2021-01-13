#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N, a, b, maxV = 0;
	vector<pair<int, int>> v;
	int length[501] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		length[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second) {
				length[i] = max(length[i], length[j] + 1);
				if (maxV < length[i]) maxV = length[i];
			}
		}
	}
	cout << N - maxV << endl;
}