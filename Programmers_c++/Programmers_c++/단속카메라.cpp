#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	//진입한 순서대로 정렬
	sort(routes.begin(), routes.end());
	int ent = routes[0][0];
	int ext = routes[0][1];
	for (int i = 1; i < routes.size(); i++) {
		//현재 차의 진출 지점이 이전 차의 진출 지점보다 앞
		if (ext >= routes[i][1]) { //cctv 같이 사용 가능
			ext = routes[i][1];
		}
		else if (ext < routes[i][0]) { //현재 차의 진입 지점이 이전 차의 진출 지점보다 뒤
			//cctv 추가
			ext = routes[i][1];
			answer++;
		}
	}
	return answer;
}
int main() {
	cout << solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} });
}