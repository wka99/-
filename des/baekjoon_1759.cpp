#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int L = 0, C = 0;
string letter[15];
vector <string> cipher;
//������ 1�� �̻�, ������ 2�� �̻�

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> letter[i];
	}
	sort(letter, letter + C);
}