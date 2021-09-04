#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> s;
string gwalho;

int main() {
	cin >> gwalho;
	for (int i = 0; i < gwalho.length(); i++) {
		string curr = "";
		curr += gwalho[i];
		if (curr == "(" || curr == "[")
			s.push(curr);
		else { // ), ]
			if (s.empty()) { //올바르지 않은 괄호
				cout << 0 << endl;
				return 0;
			}
			string top = s.top(); s.pop();
			if (top == "(" && curr == ")") s.push("2");
			else if (top == "[" && curr == "]")s.push("3");
			else if (isdigit(top[0])) { //괄호 안에 값 존재
				int sum = stoi(top);
				while (1) {
					if (s.empty()) { //올바르지 않은 괄호
						cout << 0 << endl;
						return 0;
					}
					top = s.top(); s.pop();
					if (isdigit(top[0])) sum += stoi(top);
					else break;
				}
				if (top == "(" && curr == ")") //(X) = 2*X
					s.push(to_string(sum * 2));
				else if (top == "[" && curr == "]") //[X] = 3*X
					s.push(to_string(sum * 3));
				else { //올바르지 않은 괄호
					cout << 0 << endl;
					return 0;
				}
			}
			else { //올바르지 않은 괄호
				cout << 0 << endl;
				return 0;
			}
		}
	}
	int res = 0; string curr;
	while (!s.empty()) {
		curr = s.top(); s.pop();
		if (curr == "(" || curr == "[") {
			cout << 0 << endl;
			return 0;
		}
		res += stoi(curr);
	}
	cout << res << endl;
}