#include <iostream>
#include <vector>
using namespace std;

//��Ϲ��� ����
vector <char> wheel[4];
int K;

void turn(int num, int dir) { //��Ϲ��� ȸ�� �Լ�
	char tmp;
	if (dir > 0) { //�ð����
		tmp = wheel[num][7];
		wheel[num].pop_back();
		wheel[num].insert(wheel[num].begin(), tmp);
	}
	else if (dir < 0) { //�ݽð����
		tmp = wheel[num][0];
		wheel[num].erase(wheel[num].begin());
		wheel[num].push_back(tmp);
	}
}

int main() {
	char t;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> t;
			wheel[i].push_back(t);
		}
	}
	cin >> K;
	int num, dir;
	for (int i = 0; i < K; i++) {
		cin >> num >> dir;
		num -= 1;
		int dirs[4] = { 0, };
		dirs[num] = dir;
		//���� ��Ϲ��� ����
		for (int j = num-1; j >= 0; j--) {
			if (wheel[j][2] != wheel[j+1][6]) {
				dirs[j] = -dirs[j+1];
			}
			else break; //�� �� ������ �� ���� �ִ� ��Ϲ��� Ȯ�� ���ص� ��
		}
		//���� ��Ϲ��� ������
		for (int j = num + 1; j < 4; j++) {
			if (wheel[j][6] != wheel[j-1][2]) {
				dirs[j] = -dirs[j-1];
			}
			else break;
		}
		//���� ������ �����ֱ�
		for (int j = 0; j < 4; j++) {
			if (dirs[j] == 0) continue;
			else {
				turn(j, dirs[j]);
			}
		}
	}
	int sum = 0;
	for (int i = 3; i >= 0; i--) {
		sum *= 2;
		if (wheel[i][0] != '0') {
			sum += 1;
		}
	}
	cout << sum << endl;
}