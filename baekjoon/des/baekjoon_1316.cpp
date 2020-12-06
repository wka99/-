#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, answer = 0, flag = 0;
	char curr;
	string tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		flag = 0;
		cin >> tmp;
		int alpha[26] = { 0, };
		for (int j = 0; j < tmp.size(); j++) {
			curr = tmp[j];
			if (!alpha[curr - 'a']) {
				alpha[curr - 'a'] = 1;
				while (1) {
					j++;
					if (curr != tmp[j]) {
						j--;
						break;
					}
				}
			}
			else {
				flag = 1;
				break;
			}
		}
		if (!flag) answer++;
	}
	cout << answer << endl;
}