#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v = { 1,2,3,4,5,6,7,8 };
	vector <int> t;
	vector <int> t2;

	t.resize((int)(v.size()));
	copy(v.begin(), v.end(), t.begin());
	for (int i = 0; i < t.size(); i++) {
		cout << t[i] << " ";
	}cout << endl;

	t.clear();
	t.resize(3);
	copy(v.begin() + 1, v.begin() + 4, t.begin());
	for (int i = 0; i < t.size(); i++) {
		cout << t[i] << " ";
	}cout << endl;

	t2.assign(v.begin(), v.end());
	for (int i = 0; i < t2.size(); i++) {
		cout << t2[i] << " ";
	}cout << endl;

	t2.clear();
	t2.assign(v.begin() + 2, v.begin() + 5);
	for (int i = 0; i < t2.size(); i++) {
		cout << t2[i] << " ";
	}cout << endl;
}