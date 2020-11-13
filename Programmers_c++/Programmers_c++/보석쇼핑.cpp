#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

/*
진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간 찾기
투포인터 문제
왔다갔다하면서 확인할 필요없이 보석들을 한번 훑고 지나가면서 구간을 찾을 수 있음
따라서 O(n)의 시간 복잡도로 문제를 해결할 수 있다.
*/
vector<int> solution(vector<string> gems) {
	vector<int> answer = { 0,0 };
	set<string> gtype(gems.begin(), gems.end());
	int typenum = gtype.size(); //보석 종류 수
	int s = 0, e = 0, len = gems.size();
	map<string, int> gcnt;
	while (1) {
		//모든 보석이 다 담기는 경우
		if (gcnt.size() == typenum) {
			if (len > e - s - 1) {
				len = e - s - 1;
				answer[0] = s + 1;
				answer[1] = e;
			}
			if (gcnt[gems[s]] > 1) {//남은 보석이 여러개, s 앞으로 더 이동해도됨
				gcnt[gems[s]] -= 1;
				s++;
			}
			else if (gcnt[gems[s]] == 1) {//남은 보석이 한개, e를 앞으로 이동시켜야함
				gcnt.erase(gems[s]);
				s++;
			}
		}
		else if (e == gems.size()) break;
		else {//보석 담기
			gcnt[gems[e++]] += 1;
		}
	}
	return answer;
}
int main() {
	solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
}