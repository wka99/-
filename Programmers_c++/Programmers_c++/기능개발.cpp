#include <iostream>
#include <string>
#include <vector>

using namespace std;
int done[101] = { 0, };
int count(vector<int> progresses) {
	int cnt = 0;
	for (int i = 0; i < progresses.size(); i++) {
		if (done[i] == 0) { //아직 완료가 안된 작업에 대해서만 check
			if (progresses[i] >= 100) { //완료
				done[i] = 1;
				cnt++;
			}
			else break; //연속적으로 완료된 경우만 한꺼번에 빼줄 수 있으므로 break해줘야 함
		}
	}
	return cnt;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	for (int i = 0; i < progresses.size(); i++) {
		if (done[i]) continue;
		float left = 100 - progresses[i]; //나누어 떨어지지 않는 경우를 위해 float형
		int day = ceil(left / speeds[i]);
		for (int j = i; j < progresses.size(); j++) {
			progresses[j] += day * speeds[j];
		}
		answer.push_back(count(progresses));
	}
	return answer;
}
int main() {
	solution({ 95,90,99,99,80,99 }, { 1,1,1,1,1,1 });
}