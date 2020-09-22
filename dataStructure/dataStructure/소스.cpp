#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int a = 3;
	int b = 4;
	int r[5] = { 1,2,3,4,5 };
	vector<int> v = { 1,2,3,4,5 };
	reverse(r, r + 5);
	reverse(v.begin(), v.end());
	for (int i = 0; i < 5; i++) {
		cout << r[i] << endl;
	}
	for (int i = 0; i < 5; i++) {
		cout << v[i] << endl;
	}
}