#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	set<string> only;
	multiset<string> part1;
	for (int i = 0; i < str1.size()-1; i++) {
		string tmp = "";
		for (int j = 0; j < 2; j++) {
			if (isalpha(str1[i+j])) tmp += tolower(str1[i+j]);
			else break;
		}
		if (tmp.size() == 2) {
			part1.insert(tmp);
			only.insert(tmp);
		}
	}
	multiset<string> part2;
	for (int i = 0; i < str2.size() - 1; i++) {
		string tmp = "";
		for (int j = 0; j < 2; j++) {
			if (isalpha(str2[i + j])) tmp += tolower(str2[i + j]);
			else break;
		}
		if (tmp.size() == 2) {
			part2.insert(tmp);
			only.insert(tmp);
		}
	}
	set<string>::iterator it = only.begin();
	float inter = 0;
	float uni = 0;
	for (; it!=only.end(); it++) {
		int cnt1 = part1.count(*it);
		int cnt2 = part2.count(*it);
		inter += min(cnt1, cnt2);
		uni += max(cnt1, cnt2);
	}
	if (inter == 0 && uni == 0)
		return 65536;
	answer = (inter / uni) * 65536;
	return answer;
}
int main() {
	cout<<solution("EeMmC^2", "e=m*c^2");
}