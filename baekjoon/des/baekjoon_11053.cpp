#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//가장 긴 증가하는 부분 수열
/*
	LIS(longest increasing subsequence) 알고리즘
	일반적으로 dp를 이용하여 해결
	length 배열을 활용하여 i번째 인덱스에서 끝나는 최장 증가 부분 수열의 길이를 저장
*/

int main() {
	int N, tmp, curr, maxv = 1;
	int length[1001] = { 0, };
	vector<int> a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		length[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i])
				length[i] = max(length[i], length[j] + 1);
			if (maxv < length[i]) maxv = length[i];
		}
	}
	cout << maxv << endl;
}