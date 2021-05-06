#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T;
long long Y;
bool check(string year, long long curr) {
	bool res = false;
	if (year == "") return true;
	if (year[0] == '0') return false;
	for (int i = 1; i <= year.size(); i++) {
		long long tmp = stoll(year.substr(0, i));
		if (curr+1 == tmp) {
			res = check(year.substr(i), tmp);
		}
		if (res) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> Y;
		while (1) {
			Y++;
			int flag = 0;
			string year = to_string(Y);
			for (int j = 1; j < year.size(); j++) {
				long long tmp = stoll(year.substr(0, j));
				if (check(year.substr(j), tmp)) {
					cout << "Case #" << i << ": " << Y << "\n";
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		
	}
}