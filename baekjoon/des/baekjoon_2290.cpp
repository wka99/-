#include <iostream>
#include <string>
using namespace std;

int s = 0;//크기
string n = "";//모니터에 나타낼 수
char LCD[23][130];

void printLCD(int cnt, char nc) {
	int hor = s + 2;
	int ver = 2 * s + 3;
	switch (nc) {
	case '0':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver-1) {
				for (int j = 1; j < s+1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else if (i != ver / 2) {
				LCD[i][cnt*(hor + 1) + 0] = '|';
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	case '1':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver - 1|| i == ver / 2) {
			}
			else {
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	case '2':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver - 1 || i == ver / 2) {
				for (int j = 1; j < s + 1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else if (i < ver / 2) {
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
			else {
				LCD[i][cnt*(hor + 1) + 0] = '|';
			}
		}
		break;
	case '3':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver - 1 || i == ver / 2) {
				for (int j = 1; j < s + 1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else {
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	case '4':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver - 1) {
			}
			else if (i == ver / 2) {
				for (int j = 1; j < s + 1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else if(i<ver/2){
				LCD[i][cnt*(hor + 1) + 0] = '|';
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
			else {
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	case '5':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver - 1 || i == ver / 2) {
				for (int j = 1; j < s + 1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else if (i < ver / 2) {
				LCD[i][cnt*(hor + 1) + 0] = '|';
			}
			else {
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	case '6':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver - 1 || i == ver / 2) {
				for (int j = 1; j < s + 1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else if (i < ver / 2) {
				LCD[i][cnt*(hor + 1) + 0] = '|';
			}
			else {
				LCD[i][cnt*(hor + 1) + 0] = '|';
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	case '7':
		for (int i = 0; i < ver; i++) {
			if (i == 0) {
				for (int j = 1; j < s + 1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else if (i == ver / 2|| i == ver - 1) {
			}
			else {
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	case '8':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver - 1 || i == ver / 2) {
				for (int j = 1; j < s + 1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else {
				LCD[i][cnt*(hor + 1) + 0] = '|';
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	case '9':
		for (int i = 0; i < ver; i++) {
			if (i == 0 || i == ver - 1||i == ver / 2) {
				for (int j = 1; j < s + 1; j++) {
					LCD[i][cnt*(hor + 1) + j] = '-';
				}
			}
			else if (i < ver / 2) {
				LCD[i][cnt*(hor + 1) + 0] = '|';
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
			else {
				LCD[i][cnt*(hor + 1) + hor - 1] = '|';
			}
		}
		break;
	}
}
int main() {
	cin >> s >> n;
	int len = n.length();
	int count = 0;
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 130; j++) {
			LCD[i][j] = ' ';
		}
	}
	for (int i = 0; i < len; i++) {
		printLCD(count, n[i]);
		count++;
	}
	for (int i = 0; i < 2 * s + 3; i++) {
		for (int j = 0; j < (s + 2)*len+len; j++) {
			cout << LCD[i][j];
		}cout << endl;
	}
}