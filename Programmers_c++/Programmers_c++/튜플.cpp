#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a.length() < b.length();
}
vector<int> solution(string s) {
	vector<int> answer;
	vector<string> rearr;
	int visited[100000] = { 0, };
	s = s.substr(1, s.length() - 2);
	int idx = s.find("},");
	string tmp;
	while (idx != -1) {
		tmp = s.substr(1, idx - 1);
		rearr.push_back(tmp);
		s = s.substr(idx + 2);
		idx = s.find("},");
	}
	s = s.substr(1, s.length() - 2);
	rearr.push_back(s);

	sort(rearr.begin(), rearr.end(), cmp);

	string number;
	for (int i = 0; i < rearr.size(); i++) {
		idx = rearr[i].find(",");
		while (idx != -1) {
			number = rearr[i].substr(0, idx);
			if (!visited[stoi(number)]) {
				visited[stoi(number)] = 1;
				answer.push_back(stoi(number));
			}
			rearr[i] = rearr[i].substr(idx + 1);
			idx = rearr[i].find(",");
		}
		if (!visited[stoi(rearr[i])]) {
			visited[stoi(rearr[i])] = 1;
			answer.push_back(stoi(rearr[i]));
		}
	}
	return answer;
}
int main() {
	solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}