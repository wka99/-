#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <cmath>
using namespace std;

//�����ڴ� 3������ ��� + - *
char pri[3]; // �켱������ �����, �տ� �������� �켱 ������ ������
long long solution(string expression) {
	long long answer = 0;
	vector<long long> num;
	vector<char> op;
	string tmp = "";
	//���ڿ����� ���ڿ� �����ڸ� �и�, ���� ���Ϳ� ����
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
	//�켱���� ���ϱ�
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			for (int k = 0; k < 3; k++) {
				if (j == k || i == k) continue;
				pri[i] = '+'; pri[j] = '-'; pri[k] = '*';
				vector<long long> tmpn = num;
				vector<char> tmpo = op;
				long long cal;
				for (int a = 0; a < 3; a++) {//�켱 ������ ���� ����ϱ�
					int idx = 0;
					while (!tmpo.empty()) {//ó������ Ž���ϸ鼭 ���� �켱������ ��ġ�ϴ� ���길 ����
						if (tmpo[idx] == pri[a]) {//������ֱ�
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