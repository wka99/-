#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> a) {
	int answer = 0;
	int size = a.size();
	/*
		map에는 pivot 기준 왼쪽 배열과 오른쪽 배열의 최소값
		map[pivot][0] -> 왼쪽 최소값
		map[pivot][1] -> 오른쪽 최소값
	*/
	int **map = new int*[size];
	for (int i = 0; i < size; i++)
		map[i] = new int[2];
	int left = INT_MAX;
	int right = INT_MAX;
	for (int i = 0; i < size; i++) {
		if (left > a[i])left = a[i];
		map[i][0] = left;
	}
	for (int i = size - 1; i >= 0; i--) {
		if (right > a[i])right = a[i];
		map[i][1] = right;
	}
	for (int i = 0; i < size; i++) {
		if (map[i][0] < a[i] && map[i][1] < a[i]) continue;
		answer++;
	}
	return answer;
}
int main() {
	vector<int> a = { -16,27,65,-2,58,-92,-71,-68,-61,-33 };
	cout<<solution(a);
}