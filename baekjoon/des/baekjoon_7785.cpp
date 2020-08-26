#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string name, el;
	set <string> s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> el;
		if (el == "enter")
			s.insert(name);
		else
			s.erase(name);
	}
	set <string> ::iterator it = s.end();
	while (1) {
		it--;
		cout << *it << "\n";
		if (it == s.begin())
			break;
	}
}