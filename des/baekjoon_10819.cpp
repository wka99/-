#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 차이를 최대로

int N;
vector <int> A;
int maxR = 0;

void findMax() {
	int result=0;
	do {
		for (int i = 0; i < N-1; i++) {
			result += abs(A[i] - A[i + 1]);
		}
		if (maxR < result) maxR = result;
		result = 0;
	}
	while (next_permutation(A.begin(), A.end()));
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