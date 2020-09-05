#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<int> cans;
	int tmp;
	for (int i = 0; i < n; i++) {
		tmp = arr1[i] | arr2[i];
		cans.push_back(tmp);
	}
	string s;
	int c, cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		c = cans[i];
		s = "";
		while (c > 0||cnt<n) {
			if (c % 2 == 1) s = "#" + s;
			else s = " " + s;
			c = c / 2;
			cnt++;
		}
		cout << s << endl;
		answer.push_back(s);
	}
	return answer;
}
int main() {
	int n = 6;
	vector<int> arr1 = { 46, 33, 33 ,22, 31, 50 };
	vector<int> arr2 = { 27 ,56, 19, 14, 14, 10 };
	solution(n, arr1, arr2);
}