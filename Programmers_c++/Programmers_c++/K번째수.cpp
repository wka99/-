#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> arr = { 1,5,2,6,3,7,4 };
	vector <vector<int>> com = { {2,5,3},{4,4,1},{1,7,3} };
	vector <int> answer;
	vector <int> tmp;

	for (int i = 0; i < com.size(); i++) {
		int a = com[i][0];
		int b = com[i][1];
		tmp.clear();
		tmp.assign(arr.begin() + a - 1, arr.begin() + b);
		sort(tmp.begin(), tmp.end());
		int c = com[i][2];
		answer.push_back(tmp[c-1]);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}