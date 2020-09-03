#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool possi(vector<int> ans, int now) {
	for(int i = 0; i < ans.size(); i++) {
		if ((ans[i] & now) == ans[i])return false;
	}return true;
}
int solution(vector<vector<string>> relation) {
	int n = relation.size();
	int m = relation[0].size();
	vector<int> ans;
	/*
		[학번, 이름, 전공, 학년]
		key - 학번 / 0001
		key - 학번, 전공 / 0101
		key - 학년, 이름 / 1010
	*/
	for (int i = 1; i < (1 << m); i++) { //0001 부터 1111까지
		set<string> s;
		for (int j = 0; j < n; j++) {
			string now = "";
			for (int k = 0; k < m; k++) {
				if (i&(1 << k))now += relation[j][k];
			}
			s.insert(now);
		}
		if (s.size() == n && possi(ans, i))
			ans.push_back(i);
	}
	return ans.size();
}

int main() {
	vector<vector<string>> relation = { {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} };
	cout << solution(relation) << endl;
}