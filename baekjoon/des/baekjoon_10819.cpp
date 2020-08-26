#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 차이를 최대로

int N;
vector <int> A;
int maxR = 0;

void findMax() { //using STL
	int result = 0;
	do {
		for (int i = 0; i < N - 1; i++) {
			result += abs(A[i] - A[i + 1]);
		}
		if (maxR < result) maxR = result;
		result = 0;
	} while (next_permutation(A.begin(), A.end()));
}
void swap(int i, int j) {
	int temp = 0;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
bool nextPerm() { //next permutation 구현
	int k, ti;
	for (int i = N - 1; i > 0; i--) {
		if (A[i] > A[i - 1]) {
			i--;
			for (int j = N - 1; j > i; j--) {
				if(A[j]>A[i]){
					swap(i, j);
					break;
				}
			}
			k = N - 1;
			ti = i + 1;
			while (ti < k) {
				swap(ti, k);
				ti++; k--;
			}
			return true;
		}
	}
	return false;
}
void findMax2() {
	int result = 0;
	do {
		for (int i = 0; i < N - 1; i++) {
			result += abs(A[i] - A[i + 1]);
		}
		if (maxR < result) maxR = result;
		result = 0;
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
	findMax2();
	cout << maxR << endl;
}