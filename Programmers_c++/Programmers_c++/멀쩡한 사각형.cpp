#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(int w, int h) {
	long long answer = 1;
	long long width = w;
	long long height = h;
	long long m = min(width, height);
	long long gcd = 1;
	for (int i = 1; i <= m; i++) {
		if (w%i == 0 && h%i == 0) {
			gcd = i;
		}
	}
	answer = width * height - (width + height - gcd);
	return answer;
}