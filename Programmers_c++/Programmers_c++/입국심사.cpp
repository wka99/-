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
	//�̺� Ž��
	while (left <= right) {
		mid = (left + right) / 2;
		done = 0;
		for (int i = 0; i < times.size(); i++) {
			done += (mid/times[i]);
		}
		if (n > done) {//�ð� ���� �۾� ó�� �Ұ� => �ð� �ø���
			left = mid + 1;
		}
		else { //�ð� ���� �۾� ó�� ���� => �ð� ���̱�
			if (answer > mid) answer = mid;
			right = mid - 1;
		}
	}
	return answer;
}
int main() {
	solution(6, { 7,10 });
}