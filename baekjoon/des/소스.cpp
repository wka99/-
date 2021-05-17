#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> peop;
int visited[5][5];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool check(int x, int y, vector<string> p, int cnt) {
    if (p[x][y] == 'P' && cnt <= 2) return 0;
    int mx, my;
    for (int i = 0; i < 4; i++) {
        mx = x + dx[i];
        my = y + dy[i];
        if (mx < 0 || my < 0 || mx >= 5 || my >= 5) continue;//범위밖
        if (p[mx][my] == 'X') continue;//막힌곳
        if (!visited[mx][my]) {
            visited[mx][my] = 1;
            check(mx, my, p, cnt + 1);
            visited[mx][my] = 0;
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        for (int j = 0; j < places[i].size(); j++) {
            for (int k = 0; k < places[i][j].size(); j++) {
                if (places[i][j][k] == 'P') peop.push_back({ j,k });
            }
        }
        int flag = 0;
        for (int j = 0; j < peop.size(); j++) {
            if (!check(peop[j].first, peop[j].second, places[i], 0)) {
                flag = 1;
                break;
            }
        }
        if (flag) answer.push_back(0);
        else answer.push_back(1);
        peop.clear();
        memset(visited, 0, sizeof(visited));
    }
    return answer;
}
int main() {
    solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
}