#include <iostream>
#include <vector>
#include <string>
using namespace std;
int answer = 1000;

void calc(string s, int len) {
	if (len > s.length())
		return;
	string tmp;
	int i, j;
	for (i = 0; i < s.length(); ) {
		int cnt = 1;
		for (j = i+len; j < s.length(); j+=len) {
			if (s.substr(i,len) == s.substr(j, len)) {
				cnt++;
			}
			else break;
		}
		tmp += s.substr(i, len);
		if(cnt>1)
			tmp += to_string(cnt);
		i += cnt*len;
	}
	if (answer > tmp.length())
		answer = tmp.length();
	calc(s, len + 1);
}
int solution(string s) {
	calc(s,1);
	return answer;
}
int main() {
	string s;
	cin >> s;
	cout<<solution(s);
}