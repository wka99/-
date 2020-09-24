#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int size = skill_trees.size();
	for (int i = 0; i < skill_trees.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			int idx = skill.find(skill_trees[i][j]);
			if (idx == -1)continue;
			else if (idx == cnt) cnt++;
			else {
				size--;
				break;
			}
		}
	}
	answer = size;
	return answer;
}
int main() {
	vector<string> v = { "BACDE","CBADF","AECB","BDA" };
	cout<<solution("CBD", v);
}