#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int number[1000] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	sort(number, number + N);
	for (int i = 0; i < N; i++) {
		cout << number[i] << endl;
	}
}