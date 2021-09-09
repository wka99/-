#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool bfs(int x, int y, vector<string> curr) {
    queue<vector<int>> q;
    int visited[5][5] = { 0, };
    q.push({ x, y, 0 });
    int mx, my, dist;
    while (!q.empty()) {
        x = q.front()[0];
        y = q.front()[1];
        dist = q.front()[2];
        q.pop();
        if (dist == 2) continue; //거리두기 준수 => 그 이상 확인할 필요 없음
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            mx = x + dx[i]; my = y + dy[i];
            if (mx < 0 || mx >= 5 || my < 0 || my >= 5) continue;
            if (curr[mx][my] == 'X') continue; //파티션이 있는 경우, 이동 불가
            if (!visited[mx][my]) {
                if (curr[mx][my] == 'P') return false; //맨해튼 거리가 2이하
                q.push({ mx, my, dist + 1 });
            }
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int flag = 0;
    for (int i = 0; i < places.size(); i++) {
        flag = 0;
        for (int j = 0; j < places[i].size(); j++) {
            for (int k = 0; k < places[i][j].size(); k++) {
                if (places[i][j][k] == 'P') { //사람이 앉아 있는 경우, 해당 사람을 중심으로 거리두기 준수 여부 확인
                    if (!bfs(j, k, places[i])) { //지키지 못함 => 더 확인할 필요 없음
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        if (flag) answer.push_back(0); //지키지 못합
        else answer.push_back(1); //지킴
    }
    return answer;
}