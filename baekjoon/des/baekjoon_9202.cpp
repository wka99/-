#include <iostream>
using namespace std;
#define MAX_W 300001
#define MAX_N 8

struct trie {
	bool is_terminal;
	int child[26];
	int visited;
}trie[MAX_W*8];

int tidx = 0;
int score, maxLen, found, seq = 0;
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int scores[9] = { 0,0,0,1,1,2,3,5,11 };
int maps[4][4]; //4*4 boggle 판
int visited[4][4] = { 0, };
char s[9], longs[9];

bool comp() {
	bool res = true;
	for (int i = 0; i < 8; i++) {
		if (s[i] < longs[i]) {
			res = false;
			break;
		}
		else if(s[i] > longs[i]) break;
	}
	return res;
}
void backtracking(int trieIdx, int loc, int row, int col) {
	if (trie[trieIdx].is_terminal && trie[trieIdx].visited != seq) {
		++found; score += scores[loc];
		trie[trieIdx].visited = seq;
		if (loc > maxLen) {
			maxLen = loc;
			for (int i = 0; i < loc; i++) longs[i] = s[i];
			longs[loc] = '\0';
		}
		else if (loc == maxLen && !comp()) { //알파벳 순으로 먼저 나오는거
			for (int i = 0; i < loc; i++) longs[i] = s[i];
		}
	}
	int x, y;
	for (int m = 0; m < 8; m++) { //상하좌우대각선
		x = row + dx[m];
		y = col + dy[m];
		if (x < 0 || y < 0 || x >= 4 || y >= 4 || visited[x][y] || trie[trieIdx].child[maps[x][y]] == 0) continue;
		visited[x][y] = true;
		s[loc] = maps[x][y] + 'A';
		backtracking(trie[trieIdx].child[maps[x][y]], loc + 1, x, y);
		visited[x][y] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int w, b, t, c, j;
	cin >> w;
	trie[tidx].is_terminal = false;
	trie[tidx].visited = 0;
	for (int j = 0; j < 26; j++)trie[tidx].child[j] = 0;
	for (int i = 0; i < w; i++) { //string을 입력받으면서 trie 생성
		cin >> s;
		c = 0, j = -1;
		while(s[++j]!='\0'){
			t = s[j] - 'A';
			if (trie[c].child[t] == 0) { //아직 자식이 없음
				trie[c].child[t] = ++tidx;
				trie[tidx].is_terminal = false;
				trie[tidx].visited = 0;
				for (int j = 0; j < 26; j++)trie[tidx].child[j] = 0;
			}
			c = trie[c].child[t];
		}
		trie[c].is_terminal = true;
	}
	cin >> b;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> s;
			for (int k = 0; k < 4; k++) maps[j][k] = s[k] - 'A';
		}
		score = 0, maxLen = 0, found = 0, seq++;
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				if (trie[0].child[maps[a][b]] != 0) {
					visited[a][b] = 1;
					s[0]= maps[a][b] + 'A';
					backtracking(trie[0].child[maps[a][b]], 1, a, b);
					visited[a][b] = 0;
				}
			}
		}
		cout << score << " " << longs << " " << found << "\n";
	}
}