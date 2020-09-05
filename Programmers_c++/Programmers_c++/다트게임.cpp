#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int tmp, tmp2;
	stack<int> q;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] == '1') {
			if (dartResult[i+1] == '0') {
				tmp = 10;
				i++;
			}
			else tmp = 1;
			q.push(tmp);
		}
		else if (dartResult[i] == '0'||(dartResult[i]>49&&dartResult[i]<58)) {
			tmp = dartResult[i] - 48;
			q.push(tmp);
		}
		else {
			if (dartResult[i] == 'D') {
				tmp = pow(q.top(), 2);
				q.pop();
				q.push(tmp);
			}
			else if (dartResult[i] == 'T') {
				tmp = pow(q.top(), 3);
				q.pop();
				q.push(tmp);
			}
			else if (dartResult[i] == '*') {
				tmp = q.top() * 2;
				q.pop();
				if (q.size() >= 1) {
					tmp2 = q.top() * 2;
					q.pop();
					q.push(tmp2);
				}
				q.push(tmp);
			}
			else if (dartResult[i] == '#') {
				tmp = q.top()*(-1);
				q.pop();
				q.push(tmp);
			}
		}
	}
	int size = q.size();
	for (int i = 0; i < size; i++) {
		answer += q.top();
		q.pop();
	}
	return answer;
}
int main() {
	string s = "1D2S#10S";
	cout<<solution(s);
}