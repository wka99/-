#include <iostream>
#include <string>
#include <map>
using namespace std;

//미국 전역의 나무들이 주어졌을 때 각 종이 전체의 몇 % ?
//map은 키를 사전순으로 자동으로 정렬시킴
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string trees;
	double cnt = 0;
	map<string, double> dist;
	while (getline(cin, trees)) {
		dist[trees] += 1;
		cnt++;
	}
	map<string, double>::iterator it;
	cout << fixed;
	cout.precision(4);
	for (it = dist.begin(); it != dist.end(); it++) {
		double tnum = (it->second) * 100 / cnt;
		cout << it->first << " ";
		cout << tnum << "\n";
	}
}