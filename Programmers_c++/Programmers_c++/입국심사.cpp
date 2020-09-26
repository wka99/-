#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer;
	long long p = n;
	long long left, right, mid, done;
	sort(times.begin(), times.end());
	left = 1;
	right = p * times[times.size() - 1];
	answer = right;
	//이분 탐색
	while (left <= right) {
		mid = (left + right) / 2;
		done = 0;
		for (int i = 0; i < times.size(); i++) {
			done += (mid/times[i]);
		}
		if (n > done) {//시간 내에 작업 처리 불가 => 시간 늘리기
			left = mid + 1;
		}
		else { //시간 내에 작업 처리 가능 => 시간 줄이기
			if (answer > mid) answer = mid;
			right = mid - 1;
		}
	}
	return answer;
}
int main() {
	solution(6, { 7,10 });
}