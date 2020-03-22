#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int> A;
int maxR = 0;

void swap(int i, int j) {
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
bool nextPerm() {//다음 순열이 존재하면 true 없으면 false
	int a, b;
	for (int i = N - 1; i > 0; i--) {//끝부터 탐색
		if (A[i] > A[i - 1]) {
			i--;
			for (int j = N - 1; j > i; j--) {
				if (A[i] < A[j]) {
					swap(i, j);
					break;
				}
			}
			a = i + 1; b = N - 1;
			while (a < b) { //i+1 이후 reverse
				swap(a, b);
				a++; b--;
			}
			return true;
		}
	}
	return false;
}
void findMax() {
	int result;
	do {
		result = 0;
		for (int i = 0; i < N-1; i++) {
			result += abs(A[i] - A[i + 1]);
		}
		if (maxR < result) maxR = result;
	} while (nextPerm());
}
int main() {
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	sort(A.begin(), A.end());
	findMax();
	cout << maxR << endl;
}