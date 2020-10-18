#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int asize = number.length() - k;//answer string�� ����
	int nsize = number.length();//number�� ����
	int cnt = 0; //answer�� ���� ���� ����
	int checksize, max, idx = 0; //�˻� ����, �ִ밪 �ε���, �˻� ���� �ε���

	//�˻� ���� �ε����� �����ϹǷ� number�� ������ �ʿ� ����, ��ġ�� ����
	while (cnt < asize) {
		max = idx;
		checksize = (nsize - idx) - (asize - cnt - 1);//�˻� ����
		if ((asize - cnt) > 1) {//������ �������� ���, �˻� �������� �ϳ� ����
			for (int i = idx; i < idx + checksize; i++) {
				if (number[max] < number[i]) max = i;
			}
		}
		else {//������ �ϳ��� ���, ��ü üũ ������� �ϳ� ����
			for (int i = idx; i < number.length(); i++) {
				if (number[max] < number[i]) max = i;
			}
		}
		idx = max + 1;
		answer += number[max];
		cnt++;
	}
	return answer;
}
int main() {
	string a = "4177252841";
	int b = 4;
	string s = solution(a, b);
	cout << s << endl;
}