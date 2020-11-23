#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//������ ����
//while�� ���鼭 string �����س����°��� string�� ������ �˻��ؾ���
//������ ����ϰ� �Ǹ� string�� �ѹ��� �˻��ϸ� �ٷ� ����� ���� �� ����

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