#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;
	int * check = new int[n + 1]{ 0, };
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			for (int j = i * 2; j <= n; j += i) {
				check[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!check[i]) answer++;
	}
	return answer;
}