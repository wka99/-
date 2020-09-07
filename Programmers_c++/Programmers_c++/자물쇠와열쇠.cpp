#include <iostream>
#include <vector>
#include <string>
using namespace std;

//brute force
bool check(vector<vector<int>> back, vector<vector<int>> tmpk) {
	int a = back.size();
	int b = tmpk.size();
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < b; k++) {
				for (int l = 0; l < b; l++) {
					if (!(back[i + k][j + l] ^ tmpk[k][l])) return false;
				}
			}
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
		if (check(back, tmpk)) return true;
		tmpk = turnkey(tmpk);
	}
	return answer;
}
int main() {
	vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
	vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };
	cout<<solution(key, lock);
}