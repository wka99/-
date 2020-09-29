#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	string curr;
	for (int i = 0; i < phone_book.size() - 1; i++) {
		curr = phone_book[i];
		int idx = phone_book[i + 1].find(curr);
		if (idx == 0)
			return false;
	}
	return answer;
}
int main() {
	cout << solution({"119","97674223","1195523321"});
}