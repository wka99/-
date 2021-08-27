#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> num;
	int n;
	double sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		num.push_back(n);
		sum += n;
	}
	sort(num.begin(), num.end());
	cout << sum / 10 << endl;
	int curr = num[0];
	int cnt = 1;
	int maxCnt = 0;
	int maxVal = 0;
	for (int i = 1; i < 10; i++) {
		if (curr == num[i]) cnt++;
		else {
			if (maxCnt < cnt) {
				maxCnt = cnt;
				maxVal = curr;
			}
			curr = num[i];
			cnt = 1;
		}
	}
	cout << maxVal << endl;
}