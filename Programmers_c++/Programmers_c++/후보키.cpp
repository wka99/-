#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> ans, int now) { //최소성 만족 여부 확인
	for (int i = 0; i < ans.size(); i++) {
		if ((ans[i] & now) == ans[i])return false;
	}return true;
}
int solution(vector<vector<string>> relation) { 
	int n = relation.size(); //row 개수
	int m = relation[0].size(); //column 개수
	vector<int> ans; //후보키 조합이 저장될 벡터

	/*
		[학번, 이름, 전공, 학년]
		key - 학번 / 0001
		key - 학번, 전공 / 0101
		key - 학년, 이름 / 1010
	*/

	for (int i = 1; i < (1 << m); i++) { //0001 부터 1111까지 (0000 제외)
		set<string> s;
		for (int j = 0; j < n; j++) {
			string now = "";
			for (int k = 0; k < m; k++) {
				if (i&(1 << k))now += relation[j][k];
			}
			s.insert(now);
		}
		if (s.size() == n && check(ans, i)) // 유일성 만족 && 최소성 만족
			ans.push_back(i);
	}
	return ans.size();
}

int main() {
	vector<vector<string>> relation = { {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} };
	cout << solution(relation) << endl;
}