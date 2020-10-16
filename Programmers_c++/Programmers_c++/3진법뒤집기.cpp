#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 0;
	string gin3 = "";
	while (n > 0) {
		gin3 += to_string(n % 3);
		n /= 3;
	}
	for (int i = 0; i < gin3.length(); i++) {
		answer *= 3;
		answer += gin3[i] - '0';
	}
	return answer;
}