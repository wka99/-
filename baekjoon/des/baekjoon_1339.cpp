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
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<string> num;
int alpha[26];
vector<pair<int, int>> greedy;
int match[26];

int main() {
	string tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num.push_back(tmp);
		for (int j = 0; j < tmp.size(); j++) {
			alpha[tmp[j] - 'A'] += pow(10, tmp.size() - 1 - j);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i]) {
			greedy.push_back({ alpha[i], i });
		}
	}
	sort(greedy.begin(), greedy.end());
	int start = 9;
	for (int i = greedy.size()-1; i >= 0; i--) {
		int idx = greedy[i].second;
		match[idx] = start--;
	}
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		int tmp = match[num[i][0]-'A'];
		for (int j = 1; j < num[i].size(); j++) {
			tmp *= 10;
			tmp += match[num[i][j] - 'A'];
		}
		sum += tmp;
	}
	cout << sum << endl;
}
*/