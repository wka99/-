#include <iostream>
#include <string>
#include <vector>

using namespace std;
int done[101] = { 0, };
int count(vector<int> progresses) {
	int cnt = 0;
	for (int i = 0; i < progresses.size(); i++) {
		if (done[i] == 0) { //���� �Ϸᰡ �ȵ� �۾��� ���ؼ��� check
			if (progresses[i] >= 100) { //�Ϸ�
				done[i] = 1;
				cnt++;
			}
			else break; //���������� �Ϸ�� ��츸 �Ѳ����� ���� �� �����Ƿ� break����� ��
		}
	}
	return cnt;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	for (int i = 0; i < progresses.size(); i++) {
		if (done[i]) continue;
		float left = 100 - progresses[i]; //������ �������� �ʴ� ��츦 ���� float��
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