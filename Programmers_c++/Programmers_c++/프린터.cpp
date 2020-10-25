#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<pair<int, int>> p;
	priority_queue<int> sp;
	for (int i = 0; i < priorities.size(); i++) {
		p.push_back({ priorities[i],i });
		sp.push(priorities[i]);
	}
	int max, cnt = 0;
	pair<int, int> tmp;
	while (!p.empty()) {
		max = sp.top();
		if (max == p[0].first) {
			cnt++;
			if (p[0].second == location) {
				answer = cnt;
				break;
			}
			p.erase(p.begin());
			sp.pop();
		}
		else {
			tmp = p[0];
			p.erase(p.begin());
			p.push_back(tmp);
		}
	}
	return answer;
}