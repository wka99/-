#include <iostream>
#include <string>
#include <map>
using namespace std;

//�̱� ������ �������� �־����� �� �� ���� ��ü�� �� % ?
//map�� Ű�� ���������� �ڵ����� ���Ľ�Ŵ
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