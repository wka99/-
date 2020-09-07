#include <iostream>
#include <vector>
#include <string>
using namespace std;

//brute force
bool check(vector<vector<int>> back, vector<vector<int>> tmpk, int i, int j) {
	int b = tmpk.size();
	for (int k = 0; k < b; k++) {
		for (int l = 0; l < b; l++) {
			back[i + k][j + l] += tmpk[k][l];
			if (back[i + k][j + l] > 1) return false;
		}
	}
	for (int k = b - 1; k <= back.size() - b; k++) {
		for (int l = b - 1; l <= back.size() - b; l++) {
			if (back[k][l] == 1) continue;
			return false;
		}
	}
	return true;
}

vector<vector<int>> turnkey(vector<vector<int>> key) {
	vector<vector<int>> tmp = key;
	int x = key.size()-1;
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < key.size(); j++) {
			tmp[j][x] = key[i][j];
		}
		x--;
	}
	return tmp;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	int size = lock.size() + (key.size() - 1) * 2;
	vector<vector<int>> back(size, vector<int>(size, 0)); //초기화하는거 기억하기
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock.size(); j++) {
			back[i + key.size() - 1][j + key.size() - 1] = lock[i][j];
		}
	}
	vector<vector<int>>tmpk = key;
	for (int x = 0; x < 4; x++) {
		for (int i = 0; i <= back.size()-key.size(); i++) {
			for (int j = 0; j <= back.size()-key.size(); j++) {
				if (check(back, tmpk, i, j)) return true;
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