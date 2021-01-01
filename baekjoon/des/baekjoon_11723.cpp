#include <iostream>
#include <string>
using namespace std;

bool checkNum[21];
int main() {
	ios_base::sync_with_stdio(0);//입출력 속도 향상
	cin.tie();
	int M;
	cin >> M;
	while (M > 0) {
		int x;
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			checkNum[x] = true;
		}
		else if (cmd == "remove") {
			cin >> x;
			checkNum[x] = false;
		}
		else if (cmd == "check") {
			cin >> x;
			checkNum[x] ? (puts("1")) : (puts("0"));
		}
		else if (cmd == "toggle") {
			cin >> x;
			checkNum[x] ? (checkNum[x] = false) : (checkNum[x] = true);
		}
		else if (cmd == "all") {
			memset(checkNum, true, sizeof(checkNum));
		}
		else {
			memset(checkNum, false, sizeof(checkNum));
		}
		M--;
	}
	return 0;
}