#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> a) {
	int answer = 0;
	vector<int>map[a.size()];
	int left = 2000000000;
	int right = 2000000000;
	for (int i = 0; i < a.size(); i++) {
		if (left < a[i]) left = a[i];
		map[i].push_back(left);
	}
	for (int i = a.size() - 1; i >= 0; i--) {
		if (right < a[i]) right = a[i];
		map[i].push_back(right);
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > map[i][0] && a[i] > map[i][1])continue;
		answer++;
	}
	return answer;
}
int main() {
	vector<int> a = { -16,27,65,-2,58,-92,-71,-68,-61,-33 };
	solution(a);
}