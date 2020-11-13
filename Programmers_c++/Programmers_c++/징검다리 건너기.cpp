#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
완전 탐색으로는 효율성이 떨어짐. 건널 수 있는 사람의 수를 "이분법"으로 탐색
징검다리가 더이상 건널 수 없는 상태가 되는 경우 중 사람의 수가 가장 적은 것이
최대로 건널 수 있는 사람의 수가 됨
*/
int solution(vector<int> stones, int k) {
	int answer = 200000000;
	int right = 0, left = 1, mid, cnt, flag;
	for (int i = 0; i < stones.size(); i++) {
		if (right < stones[i]) right = stones[i];
	}
	mid = (right + left) / 2;
	while (left <= right) {
		cnt = 0;
		flag = 0;
		for (int i = 0; i < stones.size(); i++) {
			if (stones[i] - mid > 0) cnt = 0;
			else cnt++;
			if (cnt == k) {
				flag = 1;
				break;
			}
		}
		if (flag) {//더 건널 수 없음. mid를 줄이자
			if (answer > mid) answer = mid;
			right = mid - 1;
			mid = (right + left) / 2;
		}
		else {//더 건널 수 있음 mid를 늘리자
			left = mid + 1;
			mid = (right + left) / 2;
		}
	}
	return answer;
}
int main() {
	cout<<solution({ 2,4,5,3,2,1,4,2,5,1 }, 2);
}