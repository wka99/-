#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a = 0, b = 0, c = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}

}