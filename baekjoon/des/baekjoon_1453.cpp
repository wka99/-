#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int want, rej = 0;
	int seat[101] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> want;
		if (!seat[want]) {
			seat[want] = 1;
		}
		else {
			rej++;
		}
	}
	cout << rej << endl;
}