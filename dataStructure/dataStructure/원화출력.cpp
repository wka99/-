#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int won = 1000000000;
	string sw = to_string(won);
	int wlength = sw.length();
	int idx;
	int ridx=0; //�޸��� ���� �ϴ� �ڸ�
	while (wlength > 0) {
		idx = wlength % 3;
		ridx += idx;
		wlength -= (3 + idx);
		if (ridx != 0) {
			sw.insert(ridx, ",");
			ridx += 4; //�޸����� ����
		}
		else ridx += 3;
	}
	cout << sw << endl;
}