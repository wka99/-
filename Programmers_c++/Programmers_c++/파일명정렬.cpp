#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> cp;
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> cp;
bool cmp(string a, string b) {
	int idx1, idx2, an, bn, flag = 0;
	string ahead = "", bhead = "", anum = "", bnum = "";
	for (int i = 0; i < a.size(); i++) {
		if (isdigit(a[i])) { //number
			anum += a[i];
			flag = 1;
		}
		else if (!flag) ahead += tolower(a[i]); //head
		else break; //tail�� �� ����� �ƴ�
	}
	flag = 0;
	for (int i = 0; i < b.size(); i++) {
		if (isdigit(b[i])) {
			bnum += b[i];
			flag = 1;
		}
		else if (!flag) bhead += tolower(b[i]);
		else break;
	}
	an = stoi(anum); bn = stoi(bnum);
	if (ahead != bhead) return ahead < bhead; //���� head�� �������� ����
	else if (an != bn) return an < bn; //head�� ���� ���, number�� �������� ����
	else { //�Ѵ� ���� ���, ������ ������ �����ϵ��� index�� ��
		for (int i = 0; i < cp.size(); i++) {
			if (cp[i] == a) idx1 = i;
			else if (cp[i] == b) idx2 = i;
		}
		return idx1 < idx2; //���� ������ ���� ������
	}
}
vector<string> solution(vector<string> files) {
	cp = files;
	sort(files.begin(), files.end(), cmp);
	return files;
}
int main() {
	solution({"a10dsfae", "b10fdsko", "a01fwef", "fiwoej10"});
}