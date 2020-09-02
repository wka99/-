#include <iostream>
#include <vector>
#include <string>
using namespace std;

int check(string p) {
	int c1 = 0;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') c1++;
		else c1--;
		if (c1 < 0) return 0;
	}
	return 1;
}
vector<string> split(string p) {
	int c1 = 0;
	vector<string> strs;
	string u, v;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') c1++;
		else c1--;
		if (c1 == 0) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			strs.push_back(u);
			strs.push_back(v);
			break;
		}
	}
	return strs;
}
string flip(string p) {
	string tmp;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') tmp += ")";
		else tmp += "(";
	}
	return tmp;
}
string solution(string p) {
	string answer = "";
	if (p == "")
		return "";
	if (check(p))
		return p;
	vector<string> strs = split(p);
	string u = strs[0];
	string v = strs[1];
	if (check(u)) {
		string tmp = u;
		return tmp+solution(v);
	}
	else {
		answer += "(";
		answer += solution(v);
		answer += ")";
		u = u.substr(1, u.size() - 2);
		answer += flip(u);
	}
	return answer;
}
int main() {
	string s = "()))((()";
	cout << solution(s) << endl;
}