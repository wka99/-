#include <iostream>
#include <list>
using namespace std;

list <int> p;
list <int>::iterator it;

int main() {
	int N, K;
	int cnt = 0;
	cin >> N >> K;
	for (int i = 1; i < N + 1; i++) {
		p.push_back(i);
	}
	it = p.begin();
	cout << "<";
	while (p.size() > 0) {
		cnt++;
		if (cnt%K==0) {
			cout << *it;
			if (p.size() > 1)cout << ", ";
			it = p.erase(it);
			cnt = 0;
		}
		else it++;
		if (it == p.end())it = p.begin();
	}cout << ">" << endl;
}