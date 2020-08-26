#include <iostream>
#include <algorithm>
using namespace std;
//수 정렬하기2
int N;
int num[1000000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	for (int i = 0; i < N; i++) {
		cout << num[i] << "\n";
	}
}