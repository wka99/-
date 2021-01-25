#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

/*
	구조체 만들어서 함수를 bool의 형태로
	0 리턴시 에러가 발생한 것으로 취급
*/
stack <long long> s;
bool numx(long long x) {
	s.push(x);
	return true;
}
bool pop() {
	if (s.empty()) return false;
	s.pop();
	return true;
}
bool inv() {
	if (s.empty()) return false;
	long long a = -1 * s.top();
	s.pop();
	s.push(a);
	return true;
}
bool dup() {
	if (s.empty()) return false;
	s.push(s.top());
	return true;
}
bool swp() {
	if (s.size() < 2) return false;
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	s.push(a);
	s.push(b);
	return true;
}
bool add() {
	if (s.size() < 2) return false;
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (abs(a + b) > 1000000000) return false;
	s.push(b + a);
	return true;
}
bool sub() {
	if (s.size() < 2) return false;
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (abs(b - a) > 1000000000) return false;
	s.push(b - a);
	return true;
}
bool mul() {
	if (s.size() < 2) return false;
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (abs(a * b) > 1000000000) return false;
	s.push(a * b);
	return true;
}
bool div() {
	if (s.size() < 2) return false;
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (a == 0) return false;
	s.push(b / a);
	return true;
}
bool mod() {
	if (s.size() < 2) return false;
	long long a = s.top();
	s.pop();
	long long b = s.top();
	s.pop();
	if (a == 0) return false;
	s.push(b % a);
	return true;
}
int main() {
	vector<string> cmds;
	string command, cNum;
	long long n, x;
	int flag = 0;
	while (1) {
		cin >> command;
		if (command == "QUIT") break;
		else if (command == "END") {
			cin >> n;
			for (int i = 0; i < n; i++) {
				flag = 0;
				cin >> x;
				s.push(x);
				for (int j = 0; j < cmds.size(); j++) {
					if (cmds[j][0] == '-' || isdigit(cmds[j][0])) {
						if (!numx(stoll(cmds[j]))) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "POP") {
						if (!pop()) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "INV") {
						if (!inv()) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "DUP") {
						if (!dup()) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "SWP") {
						if (!swp()) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "ADD") {
						if (!add()) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "SUB") {
						if (!sub()) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "MUL") {
						if (!mul()) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "DIV") {
						if (!div()) {
							flag = 1; //에러 발생
							break;
						}
					}
					else if (cmds[j] == "MOD") {
						if (!mod()) {
							flag = 1; //에러 발생
							break;
						}
					}
				}
				if (s.size() != 1 || flag) {
					cout << "ERROR" << endl;
				}
				else {
					cout << s.top() << endl;
				}
				while (!s.empty()) s.pop();
			}
			cmds.clear();
			cout << endl;
		}
		else {
			if (command == "NUM") {
				cin >> command;
			}
			cmds.push_back(command);
		}
	}
}