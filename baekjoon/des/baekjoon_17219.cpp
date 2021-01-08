#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, string> m;
	int N, M;
	string site, pwd;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> site >> pwd;
		m[site] = pwd;
	}
	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << m[site] << endl;
	}
}