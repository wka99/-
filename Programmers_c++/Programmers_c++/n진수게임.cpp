#include <string>
#include <vector>
#include <iostream>

using namespace std;

string makeN(int n, int num) {
	string s = "";
	if (num == 0)
		return "0";
	while (num > 0) {
		int one = num % n;
		if (one >= 10) {
			char c = 'A' + one - 10;
			s = c + s;
		}
		else
			s = to_string(one) + s;
		num = num / n;
	}
	return s;
}
string solution(int n, int t, int m, int p) {
	string answer = "";
	int cnt = 0;
	string tmp = "";
	while (tmp.size() < t*m) {
		tmp += makeN(n, cnt++);
	}
	for (int i = p - 1; i < tmp.size(); i += m) {
		answer += tmp[i];
		if (answer.size() == t)break;
	}
	return answer;
}
int main() {
	solution(2, 4, 2, 1);
}