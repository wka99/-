#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int L = 0, C = 0;
string letter[15];
vector <string> cipher;
//모음은 1개 이상, 자음은 2개 이상

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> letter[i];
	}
	sort(letter, letter + C);
}