#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;

vector<pair<int, string>> cache; //��� �ð�, ���� �̸�
int addidx(string c) {
	for (int i = 0; i < cache.size(); i++) {
		if (cache[i].second == c) {
			return i;
		}
	}
	return -1;
}
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].size(); j++) {
			cities[i][j] = tolower(cities[i][j]);
		}
	}
	for (int i = 0; i < cities.size(); i++) {
		if (cache.size() == 0 || cacheSize == 0) {//ĳ�� miss or ĳ�� ũ�� 0
			answer += 5;
			cache.push_back({ i, cities[i] });
		}
		else {
			int idx = addidx(cities[i]);
			if (idx != -1) {//ĳ�� hit
				cache[idx].first = i;
				answer += 1;
			}
			else {//ĳ�� miss
				if (cache.size() == cacheSize) {//ĳ�� full, ��ü����� ��
					sort(cache.begin(), cache.end());
					cache[0].first = i;
					cache[0].second = cities[i];
				}
				else if (cache.size() < cacheSize) {//�׳� ĳ�ÿ� �߰�
					cache.push_back({ i, cities[i] });
				}
				answer += 5;
			}
		}
	}
	return answer;
}
int main() {
	cout<<solution(2, { "Jeju", "Pangyo", "NewYork", "newYork" });
}