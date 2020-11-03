#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int answer = 0;
int N, M;
vector<int> num;
void check(int idx, int sum) {
	sum += num[idx];
	if (sum == M) {
		answer++;
		return;
	}
	if (idx + 1 < N)
		check(idx + 1, sum);
	else return;
}
int main() {
	int tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < N; i++) { //시작 인덱스 결정
		check(i,0);
	}
	cout << answer << endl;
}