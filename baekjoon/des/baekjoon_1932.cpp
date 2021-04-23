#include<iostream>
using namespace std;
#define MAX_N 501

int tri[MAX_N][MAX_N] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	int maxV = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			tri[i][j] = max(tri[i][j] + tri[i - 1][j], tri[i][j] + tri[i - 1][j - 1]);
			if (maxV < tri[i][j])maxV = tri[i][j];
		}
	}
	cout << maxV << "\n";
}
/*
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 501

int triangle[MAX_N];
int N;
int main() {
	cin >> N;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		int tmp[MAX_N];
		for (int j = 0; j < cnt; j++) {
			cin >> tmp[j];
		}
		for (int j = 0; j < cnt; j++) {
			if (j == 0) tmp[j] = triangle[j] + tmp[j];
			else if (j == cnt - 1)tmp[j] = triangle[j-1] + tmp[j];
			else {
				tmp[j] = max(triangle[j - 1], triangle[j]) + tmp[j];
			}
		}
		for (int j = 0;j < N; j++) triangle[j] = tmp[j];
		cnt++;
	}
	cout << *max_element(triangle, triangle + N) << endl;
}
*/