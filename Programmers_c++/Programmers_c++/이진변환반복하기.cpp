#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int len, cnt = 0, delzero = 0;
	string tmp;
	while (s.size() > 1) {
		len = 0;
		tmp = "";
		cnt++;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') len++;
			else delzero++;
		}
		//이진수로 다시 변환
		while (len > 0) {
			if (len % 2 == 0)
				tmp = "0" + tmp;
			else
				tmp = "1" + tmp;
			len /= 2;
		}
		s = tmp;
	}
	answer.push_back(cnt);
	answer.push_back(delzero);
	return answer;
}