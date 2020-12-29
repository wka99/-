#include <iostream>
#include <vector>
#include <string>
using namespace std;

//유클리드 호제법

vector<int> solution(int n, int m) {
	vector<int> answer;
	int r = -1;
	int cn = n, cm = m;
	while (r != 0) {
		r = m % n;
		m = n;
		n = r;
		if (r == 0)
			answer.push_back(m); //최대공약수
	}
	answer.push_back(cm*cn / m); //최소공배수
	return answer;
}