#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	//a-z�� �ƽ�Ű�ڵ� 97-122
	int i, j, k;
	int c = 0;
	char text[101];
	int flag = 0;
	int find_alpha[101];
	cin.getline(text, 101);
	for (i = 97; i < 123; i++) {
		for (k = 0; k < strlen(text); k++) {
			if (int(text[k]) == i) {
				find_alpha[c] = k;
				c++;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			find_alpha[c] = -1;
			c++;
		}
		else {
			flag = 0;
		}
	}
	for (i = 0; i < c ; i++) {
		cout << find_alpha[i] << " ";
	}
}