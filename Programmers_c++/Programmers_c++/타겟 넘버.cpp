#include <iostream>
#include <vector>
using namespace std;

vector <int> numbers = { 1,1,1,1,1 };
int target = 3;
int cnt = 0;

void DFS(int idx, int result) {
	if (idx == numbers.size() && result == 3) {
		cnt++;
		return;
	}
	if (idx == numbers.size())
		return;
	//���ϴ� ���
	DFS(idx + 1, result + numbers[idx]);
	//���� ���
	DFS(idx + 1, result - numbers[idx]);
}
int main() {
	DFS(0, 0);
	cout << cnt << endl;
}