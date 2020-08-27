#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int c[31];
	for (int i = 0; i < 31; i++) c[i] = 1;
	for (int i = 0; i < lost.size(); i++) c[lost[i]]--;
	for (int i = 0; i < reserve.size(); i++) c[reserve[i]]++;
	for (int i = 0; i < lost.size(); i++) {
		if (c[lost[i]]==0) {
			if (c[lost[i] - 1] > 1) {
				c[lost[i]]++;
				c[lost[i] - 1]--;
				continue;
			}
			if (c[lost[i] + 1] > 1) {
				c[lost[i]]++;
				c[lost[i] + 1]--;
				continue;
			}
			answer++;
		}
	}
	answer = n - answer;
	return answer;
}
int main() {
	vector<int> lost = { 1,2,3 };
	vector<int> reserve = { 2,3 };
	cout << solution(3, lost, reserve) << endl;
}