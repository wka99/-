#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> ans, int now) { //�ּҼ� ���� ���� Ȯ��
	for (int i = 0; i < ans.size(); i++) {
		if ((ans[i] & now) == ans[i])return false;
	}return true;
}
int solution(vector<vector<string>> relation) { 
	int n = relation.size(); //row ����
	int m = relation[0].size(); //column ����
	vector<int> ans; //�ĺ�Ű ������ ����� ����

	/*
		[�й�, �̸�, ����, �г�]
		key - �й� / 0001
		key - �й�, ���� / 0101
		key - �г�, �̸� / 1010
	*/

	for (int i = 1; i < (1 << m); i++) { //0001 ���� 1111���� (0000 ����)
		set<string> s;
		for (int j = 0; j < n; j++) {
			string now = "";
			for (int k = 0; k < m; k++) {
				if (i&(1 << k))now += relation[j][k];
			}
			s.insert(now);
		}
		if (s.size() == n && check(ans, i)) // ���ϼ� ���� && �ּҼ� ����
			ans.push_back(i);
	}
	return ans.size();
}

int main() {
	vector<vector<string>> relation = { {"100", "ryan", "music", "2"},{"200", "apeach", "math", "2"},{"300", "tube", "computer", "3"},{"400", "con", "computer", "4"},{"500", "muzi", "music", "3"},{"600", "apeach", "music", "2"} };
	cout << solution(relation) << endl;
}