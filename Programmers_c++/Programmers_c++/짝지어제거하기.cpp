#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//스택을 쓰자
//while문 돌면서 string 삭제해나가는것은 string을 여러번 검사해야함
//스택을 사용하게 되면 string을 한번만 검사하면 바로 결과를 얻을 수 있음

int solution(string s)
{
	stack <char> letters;
	char tmp;
	for (int i = 0; i < s.size(); i++) {
		if (letters.size() > 0) {
			tmp = letters.top();
			if (tmp == s[i]) {
				letters.pop();
			}
			else letters.push(s[i]);
		}
		else
			letters.push(s[i]);
	}
	if (letters.size() == 0) return 1;
	else return 0;
}