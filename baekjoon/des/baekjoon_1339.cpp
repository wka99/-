#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<char, int> &a, const pair<char, int> &b) {
	return a.second > b.second;
}
int main() {
	int n, result = 0; string s;
	vector<string> words;
	map<char, int> alpNum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		words.push_back(s);
	}
	//숫자들의 합이 최대가 되도록
	for (int i = 0; i < n; i++) {
		int tmp = 1;
		for (int j = words[i].size() - 1; j >= 0; j--) {
			alpNum[words[i][j]] += tmp;
			tmp *= 10;
		}
	}
	vector<pair<char, int>> cpy(alpNum.begin(), alpNum.end());
	sort(cpy.begin(), cpy.end(), cmp);
	int start = 9;
	for (int i = 0; i < cpy.size(); i++) {
		result += cpy[i].second * start;
		start--;
	}
	cout << result << endl;
}