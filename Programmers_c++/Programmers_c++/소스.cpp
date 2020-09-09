#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> turnkey(vector<vector<int>>key) { //키 돌리는 함수
	vector<vector<int>> tmpk(key.size(), vector<int>(key.size()));
	int a = key.size();
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			tmpk[i][j] = key[j][a - i - 1];
		}
	}
	return tmpk;
}
bool check(vector<vector<int>> back, vector<vector<int>>key, int i, int j) {
	int a = key.size();
	int b = back.size();
	for (int n = 0; n < a; n++) {
		for (int m = 0; m < a; m++) {
			back[n + i][m + j] += key[n][m];
		}
	}
	for (int n = a-1; n <= b - a; n++) {
		for (int m = a-1; m <= b - a; m++) {
			if (back[n][m] == 1) continue;
			return false;
		}
	}
	return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	int size = lock.size() + (key.size() - 1) * 2;
	//백그라운드 0으로 초기화
	vector<vector<int>> back(size, vector<int>(size, 0));
	//백그라운드 중심에 lock 복사해서 넣어놓기
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			back[i + key.size() - 1][j + key.size() - 1] = lock[i][j];
		}
	}
	vector<vector<int>> tmpk = key;
	for (int i = 0; i < 4; i++) {//4번돌리고
		//이동시키면서 확인
		for (int j = 0; j <= size - key.size(); j++) {
			for (int k = 0; k <= size - key.size(); k++) {
				if (check(back, tmpk, j, k)) return true;
			}
		}
		tmpk = turnkey(tmpk);
	}
	return answer;
}
int main() {
	vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
	vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };
	cout<<solution(key, lock);
}