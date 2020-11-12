#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <cmath>
using namespace std;

//연산자는 3가지만 사용 + - *
char pri[3]; // 우선순위가 저장됨, 앞에 있을수록 우선 순위가 높은거
long long solution(string expression) {
	long long answer = 0;
	vector<long long> num;
	vector<char> op;
	string tmp = "";
	//문자열에서 숫자와 연산자를 분리, 따로 벡터에 저장
	for (int i = 0; i < expression.length(); i++) {
		if (isdigit(expression[i])) {
			tmp += expression[i];
		}
		else {
			num.push_back(stoll(tmp));
			tmp = "";
			op.push_back(expression[i]);
		}
	}
	num.push_back(stoll(tmp));
	//우선순위 정하기
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			for (int k = 0; k < 3; k++) {
				if (j == k || i == k) continue;
				pri[i] = '+'; pri[j] = '-'; pri[k] = '*';
				vector<long long> tmpn = num;
				vector<char> tmpo = op;
				long long cal;
				for (int a = 0; a < 3; a++) {//우선 순위에 따라 계산하기
					int idx = 0;
					while (!tmpo.empty()) {//처음부터 탐색하면서 현재 우선순위와 일치하는 연산만 수행
						if (tmpo[idx] == pri[a]) {//계산해주기
							if (tmpo[idx] == '+') cal = tmpn[idx] + tmpn[idx + 1];
							else if (tmpo[idx] == '-') cal = tmpn[idx] - tmpn[idx + 1];
							else cal = tmpn[idx] * tmpn[idx + 1];
							tmpn.erase(tmpn.begin() + idx, tmpn.begin() + idx + 2);
							tmpn.insert(tmpn.begin() + idx, cal);
							tmpo.erase(tmpo.begin() + idx, tmpo.begin() + idx + 1);
						}
						else idx++;
						if (idx >= tmpo.size()) break;
					}
					if (tmpo.empty()) {
						if (answer < abs(tmpn[0])) {
							answer = abs(tmpn[0]);
						}
					}
				}
			}
		}
	}
	return answer;
}
int main() {
	cout<<solution("2-990-5+2+3*2");
}