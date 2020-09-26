#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<int> res;
int select[10] = { 0, };

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i < n; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
void make_numbers(vector<char> paper_left, int size, string s) {
	if (size == s.size()) {
		res.insert(stoi(s));
		return;
	}
	for (int i = 0; i < paper_left.size(); i++) {
		if (select[i] == 1) continue;
		select[i] = 1;
		make_numbers(paper_left, size, s + paper_left[i]);
		select[i] = 0;
	}
}
int solution(string numbers) {
	int answer = 0;
	vector<char> paper;
	for (int i = 0; i < numbers.size(); i++) {
		paper.push_back(numbers[i]);
	}
	for (int i = 1; i <= numbers.size(); i++) {
		make_numbers(paper, i, "");
	}
	set<int>::iterator it;
	for (it = res.begin(); it != res.end(); it++) {
		if (isPrime(*it)) answer++;
	}
	return answer;
}
int main() {
	cout<<solution("17");
}