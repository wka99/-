#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> able[8];
int visited[8] = { 0, };
set<int> result;
int check(string a, string b) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == b[i] || a[i] == '*') continue;
		else return 0;
	}
	return 1;
}
void makeCombination(int idx, int comb) {
	if (idx == 8) {
		result.insert(comb);
		return;
	}
	if (able[idx].size() > 0) {
		for (int i = 0; i < able[idx].size(); i++) {
			if (!visited[able[idx][i]]) {
				visited[able[idx][i]] = 1;
				makeCombination(idx + 1, comb | (1 << able[idx][i]));
				visited[able[idx][i]] = 0;
			}
		}
	}
	else makeCombination(idx + 1, comb);
}
int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			if (banned_id[i].length() != user_id[j].length()) continue;
			else {
				if (check(banned_id[i], user_id[j])) {
					able[i].push_back(j);
				}
			}
		}
	}
	makeCombination(0, 0);
	answer = result.size();
	return answer;
}