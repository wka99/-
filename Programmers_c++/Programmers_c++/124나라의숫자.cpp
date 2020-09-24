#include <iostream>
#include <string>
using namespace std;

string solution(int n) {
	string answer = "";
	while (n>0) {
		if (n % 3 == 0) {
			answer = "4" + answer;
			n = n / 3 - 1;
		}
		else {
			answer = to_string(n % 3) + answer;
			n = n / 3;
		}	
	}
	cout << answer << endl;
	return answer;
}
int main() {
	solution(1);
	solution(10);
	solution(6);
	solution(5);
	solution(11);
}