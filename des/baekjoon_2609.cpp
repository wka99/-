#include <iostream>
using namespace std;

int GCD(int a, int b) {//최대공약수
	int tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int LCD(int a, int b) {//최소공약수
	return a * b / GCD(a, b);
}
/*int main() { //2609
	int a, b;
	cin >> a >> b;
	cout << GCD(a, b) << endl;
	cout << LCD(a, b) << endl;
}*/
int main() { //1934번
	int T;
	int a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << LCD(a, b) << endl;
	}
}
