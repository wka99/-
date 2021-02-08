#include <iostream>
#include <queue>
using namespace std;
#define MAX_K 101
//소수들의 곱 중 N번째 수를 구해보자

int num[MAX_K];
//소수는 오름차순으로 주어짐
int main() {
	int K, N;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> num[i];
	}
	//이분탐색으로 들어갈곳 찾기...?
	//priority_queue 사용?
}