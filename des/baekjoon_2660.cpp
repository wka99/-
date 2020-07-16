#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//�÷��̵�-�ͼ� �˰���

int N;
int club[51][51];

void init() {
	//�׷��� �ʱ�ȭ
	for (int i = 1; i < 51; i++) {
		for (int j = 1; j < 51; j++) {
			if (i == j)
				club[i][j] = 0;
			else
				club[i][j] = 100;
		}
	}
}
int main() {
	cin >> N;
	int a, b;
	init();
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		club[a][b] = 1;
		club[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) { //���İ��� ���� ����
		for (int j = 1; j <= N; j++) { //��� ���
			for (int k = 1; k <= N; k++) { //���� ���
				club[j][k] = min(club[j][k],club[j][i]+club[i][k]);
			}
		}
	}
	int score[51];
	int min = 100;
	vector <int> rep;
	for (int j = 1; j <= N; j++) {
		score[j] = club[j][1];
		for (int k = 1; k <= N; k++) {
			if (score[j] < club[j][k])
				score[j] = club[j][k];
		}
		if (min > score[j])
			min = score[j];
	}
	for (int j = 1; j <= N; j++) {
		if (score[j] == min)
			rep.push_back(j);
	}
	cout << min << " " << rep.size() << endl;
	for (int i = 0; i < rep.size(); i++) {
		cout << rep[i] << " ";
	}cout << endl;
}