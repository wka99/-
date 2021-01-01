#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, P, result = 0;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P;
		v.push_back(P);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < N; i++) {
		v[i] += v[i - 1];
		result += v[i];
	}
	result += v[0];
	cout << result << endl;
}