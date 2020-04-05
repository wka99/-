#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N;
	pair <int, string> word[20000];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word[i].second;
		word[i].first = word[i].second.length();
	}
	sort(word, word + N);
	string temp="";
	for (int i = 0; i < N; i++) {
		if(temp!=word[i].second)
			cout << word[i].second << endl;
		temp = word[i].second;
	}
}