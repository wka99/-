#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int cnt = 0, flag = 0;
	//getline�� �Է� ��Ʈ�� cin�� ù��° ����, 
	//�ι�° ���ڴ� string ��ü, char �迭�� �� �� ����
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