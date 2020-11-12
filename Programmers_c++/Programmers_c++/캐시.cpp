#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;

vector<pair<int, string>> cache; //사용 시간, 도시 이름
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
		if (cache.size() == 0 || cacheSize == 0) {//캐시 miss or 캐시 크기 0
			answer += 5;
			cache.push_back({ i, cities[i] });
		}
		else {
			int idx = addidx(cities[i]);
			if (idx != -1) {//캐시 hit
				cache[idx].first = i;
				answer += 1;
			}
			else {//캐시 miss
				if (cache.size() == cacheSize) {//캐시 full, 교체해줘야 함
					sort(cache.begin(), cache.end());
					cache[0].first = i;
					cache[0].second = cities[i];
				}
				else if (cache.size() < cacheSize) {//그냥 캐시에 추가
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