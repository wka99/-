#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//�Ʊ���

struct fish {
	int fishi = 0;
	int fishj = 0;
	int dist = 0;
};
struct babyshark {
	int ssize = 2;//�Ʊ����� ũ��
	int sharki = 0;//����� ��ġ
	int sharkj = 0;
	int cnt = 0;//���� ���� ��
	int time = 0;//����⸦ ��Ƹ��� �� �ִ� �ð�
};
int N;

int main() {
	cin >> N;
	babyshark bs;
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 9) {
				bs.sharki = i; bs.sharkj = j;
			}
			else if (temp > 0 && temp <= 6) {

			}
		}
	}
	cout << bs.time << endl;
}