#include <iostream>
using namespace std;

//divde and conquer(���� ����)

int N;
int paper[129][129] = { 0, };
int colors[2] = { 0, };//white, blue;

int check(int x, int y, int wid) {
	int start = paper[x][y];
	for (int i = x; i < x + wid; i++) {
		for (int j = y; j < y + wid; j++) {
			if (paper[i][j] != start)
				return -1; //���� �Ѱ����� �ƴ� ���
		}
	}
	return start;//���� �Ѱ���, �ش� �� ����
}

void divide(int x, int y, int width) { //�Ѱ��� ���� �ƴ� ���̵��� divide & check
	int c1, c2, c3, c4;
	if (width < 1) return;
	//4���
	c1 = check(x, y, width);//����
	c2 = check(x + width, y, width);//�޾Ʒ�
	c3 = check(x, y + width, width);//����
	c4 = check(x + width, y + width, width);//���Ʒ�

	if (c1 != -1) // �Ѱ�����
		colors[c1]++;
	else // width/2�� ���� ������� �ѹ� �� divide
		divide(x, y, width / 2);

	if (c2 != -1)
		colors[c2]++;
	else
		divide(x + width, y, width / 2);

	if (c3 != -1)
		colors[c3]++;
	else
		divide(x, y + width, width / 2);

	if (c4 != -1)
		colors[c4]++;
	else
		divide(x + width, y + width, width / 2);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	int c = check(0, 0, N);//�̹� �Ѱ��� ������ �̷�����ִ��� üũ
	if (c == -1)
		divide(0, 0, N / 2);
	else
		colors[c]++;
	cout << colors[0] << endl << colors[1] << endl;
}