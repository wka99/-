#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int cnt = 0, flag = 0;
	//getline은 입력 스트림 cin이 첫번째 인자, 
	//두번째 인자는 string 객체, char 배열이 올 수 없음
	getline(cin, s); 
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			cnt += 1;
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] == ' ') {
					i = j;
					break;
				}
				if (j == s.size() - 1) i = j;
			}
		}
	}
	cout << cnt << endl;
}