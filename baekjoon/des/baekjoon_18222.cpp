#include <iostream>
using namespace std;

/*
�ð��ʰ�
int main() {
	long long K, idx = 0;
	string x = "0";
	cin >> K;
	while (idx < K) {
		string append = "";
		for (int i = 0; i < x.length(); i++) {
			if (x[i] == '0')append += "1";
			else append += "0";
		}
		x += append;
		idx++;
	}
	cout << x[K - 1] << endl;
}
*/
//���� �������� �غ� ����
long long K;
int DivNConq(long long idx) {
	if (idx == 1) return 0;
	long long twice = 1, loc;
	while (twice < idx) twice *= 2;
	twice /= 2;
	loc = idx - twice;
	char res = DivNConq(loc);
	return !res;
}
int main() {
	cin >> K;
	cout << DivNConq(K) << endl;
}