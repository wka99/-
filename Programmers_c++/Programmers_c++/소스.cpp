#include <iostream>
#include <vector>
#include <string>
using namespace std;

int answer = 1000;

void check(string s, int len) {
	string tmp = "";
	if (len > s.size()) return;
	for (int i = 0; i < s.size();) {
		int cnt = 1;
		for (int j = i+len; j < s.size(); j+=len) {
			if (s.substr(i, len) == s.substr(j, len)) {
				cnt++;
			}
			else break;
		}
		tmp += s.substr(i, len);
		if (cnt > 1) tmp += to_string(cnt);
		i += cnt * len;
	}
	cout << tmp << endl;
	if (answer > tmp.length())
		answer = tmp.length();
	check(s, len+1);
}
int solution(string s) {
	check(s, 1);
	return answer;
}
int main() {
	string s = "ababcdcdababcdcd";
	cout << solution(s) << endl;
}