#include <string>
#include <vector>
#include <iostream>

using namespace std;
//오른쪽과 아래쪽으로만 움직여 학교로 갈 수 있는 최단 경로의 개수
//(X+Y)%A == ((X%A)+(Y%A))%A
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int map[101][101] = { 0, };
	for (int i = 0; i < puddles.size(); i++) {
		map[puddles[i][1] - 1][puddles[i][0] - 1] = -1;//물 웅덩이 체크
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//위쪽, 왼쪽 물웅덩이 없는지 확인하고 더하기
			if (map[i][j] == -1) continue;
			if (i == 0 && j == 0) { //집을 1로 초기화
				map[i][j] = 1;
				continue;
			}
			if (i == 0) { //좌측에서 오는 것만 고려
				if (map[i][j - 1] != -1)//좌측에 웅덩이 없음
					map[i][j] += map[i][j - 1] % 1000000007;
			}
			else if (j == 0) {//위에서 오는 것만 고려
				if (map[i - 1][j] != -1)//위쪽 웅덩이 없음
					map[i][j] += map[i - 1][j] % 1000000007;
			}
			else {//위쪽, 좌측에서 오는 것을 모두 고려
				if (map[i][j - 1] != -1)
					map[i][j] += map[i][j - 1] % 1000000007;
				if (map[i - 1][j] != -1)
					map[i][j] += map[i - 1][j] % 1000000007;
			}
		}
	}
	answer = map[n - 1][m - 1] % 1000000007;
	return answer;
}