#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> prices = { 1,2,3,2,3 };
	vector <int> answer;
	for (int i = 0; i < prices.size(); i++) {
		int cnt = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			cnt++;
			if (prices[i] > prices[j]) {
				break;
			}
		}
		answer.push_back(cnt);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}cout << endl;
}