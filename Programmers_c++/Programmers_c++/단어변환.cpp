#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int check[50] = { 0, };
int usage = 0;
int answer = 1000000;
void DFS(string b, string t, vector<string> w) {
	if (b == t) {
		if (answer > usage) answer = usage;
		return;
	}
	for (int i = 0; i < w.size(); i++) {
		if (!check[i]) {
			string curr = w[i];
			int cnt = 0;
			for (int j = 0; j < curr.size(); j++) {
				if (curr[j] != b[j]) cnt++;
				if (cnt > 1) break;
			}
			if (cnt == 1) {
				usage++;
				check[i] = 1;
				DFS(curr, t, w);
				check[i] = 0;
				usage--;
			}
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	vector<string>::iterator it; //targetÀÇ À§Ä¡
	it = find(words.begin(), words.end(), target);
	if (it == words.end()) return 0;
	DFS(begin, target, words);
	return answer;
}