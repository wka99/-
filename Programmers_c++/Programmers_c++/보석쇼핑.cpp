#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

/*
������ ��� ������ ������ ��� 1�� �̻� �����ϴ� ���� ª�� ���� ã��
�������� ����
�Դٰ����ϸ鼭 Ȯ���� �ʿ���� �������� �ѹ� �Ȱ� �������鼭 ������ ã�� �� ����
���� O(n)�� �ð� ���⵵�� ������ �ذ��� �� �ִ�.
*/
vector<int> solution(vector<string> gems) {
	vector<int> answer = { 0,0 };
	set<string> gtype(gems.begin(), gems.end());
	int typenum = gtype.size(); //���� ���� ��
	int s = 0, e = 0, len = gems.size();
	map<string, int> gcnt;
	while (1) {
		//��� ������ �� ���� ���
		if (gcnt.size() == typenum) {
			if (len > e - s - 1) {
				len = e - s - 1;
				answer[0] = s + 1;
				answer[1] = e;
			}
			if (gcnt[gems[s]] > 1) {//���� ������ ������, s ������ �� �̵��ص���
				gcnt[gems[s]] -= 1;
				s++;
			}
			else if (gcnt[gems[s]] == 1) {//���� ������ �Ѱ�, e�� ������ �̵����Ѿ���
				gcnt.erase(gems[s]);
				s++;
			}
		}
		else if (e == gems.size()) break;
		else {//���� ���
			gcnt[gems[e++]] += 1;
		}
	}
	return answer;
}
int main() {
	solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
}