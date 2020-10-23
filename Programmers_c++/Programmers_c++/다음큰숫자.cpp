#include <string>
#include <vector>
#include <iostream>

using namespace std;

int tobinary(int n) {
	string tmp;
	int cnt = 0;
	while (n > 0) {
		tmp = to_string(n % 2);
		if (tmp == "1")cnt++;
		n = n / 2;
	}
	return cnt;
}
int findNext(int n, int cnt) {
	int cnt2;
	while (1) {
		n += 1;
		cnt2 = tobinary(n);
		if (cnt == cnt2) break;
	}
	return n;
}
int solution(int n) {
	int answer = 0;
	int onecnt = tobinary(n);
	answer = findNext(n, onecnt);
	return answer;
}