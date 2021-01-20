#include <iostream>
using namespace std;

//divde and conquer(분할 정복)

int N;
int paper[129][129] = { 0, };
int colors[2] = { 0, };//white, blue;

int check(int x, int y, int wid) {
	int start = paper[x][y];
	for (int i = x; i < x + wid; i++) {
		for (int j = y; j < y + wid; j++) {
			if (paper[i][j] != start)
				return -1; //색이 한가지가 아닌 경우
		}
	}
	return start;//색이 한가지, 해당 색 리턴
}

void divide(int x, int y, int width) { //한가지 색이 아닌 종이들을 divide & check
	int c1, c2, c3, c4;
	if (width < 1) return;
	//4등분
	c1 = check(x, y, width);//왼위
	c2 = check(x + width, y, width);//왼아래
	c3 = check(x, y + width, width);//오위
	c4 = check(x + width, y + width, width);//오아래

	if (c1 != -1) // 한가지색
		colors[c1]++;
	else // width/2인 작은 조각들로 한번 더 divide
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
	int c = check(0, 0, N);//이미 한가지 색으로 이루어져있는지 체크
	if (c == -1)
		divide(0, 0, N / 2);
	else
		colors[c]++;
	cout << colors[0] << endl << colors[1] << endl;
}