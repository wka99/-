#include <iostream>
#include <vector>
#include <string>
using namespace std;

//��Ŭ���� ȣ����

vector<int> solution(int n, int m) {
	vector<int> answer;
	int r = -1;
	int cn = n, cm = m;
	while (r != 0) {
		r = m % n;
		m = n;
		n = r;
		if (r == 0)
			answer.push_back(m); //�ִ�����
	}
	answer.push_back(cm*cn / m); //�ּҰ����
	return answer;
}