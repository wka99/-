#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000

vector<int> list = { 5,3,8,1,2,7,9,4 };
int N = list.size();

/*
	[선택 정렬]
	정렬되지 않은 수 중에서 가장 작은 수를 찾아 정렬된 리스트의
	뒤에 붙이는 과정을 정렬되지 않은 수가 없어질 때까지 반복

	연산 횟수 (n-1)+(n-2)+...+1 따라서 시간 복잡도 O(n^2)
*/
void selectionSort() {
	for (int i = 0; i < N-1; i++) {
		int idx = i;
		for (int j = i + 1; j < N; j++)
			if (list[idx] > list[j])idx = j;
		swap(list[idx], list[i]);
	}
}
/*
	[삽입 정렬]
	정렬되지 않은 숫자를 올바른 위치에 삽입하는 과정을 반복해
	리스트를 정렬하는 방법

	연산 횟수 (n-1)+(n-2)+...+1 따라서 시간 복잡도 O(n^2)
*/
void insertionSort() {
	for (int i = 1; i < N; i++) {
		int idx = i - 1;
		int key = list[i];
		while (idx >= 0) {
			if (key < list[idx])
				list[idx + 1] = list[idx];
			else break;
			idx--;
		}
		list[idx + 1] = key;
	}
}
int main() {
	for (int i = 0; i < list.size(); i++) cout << list[i] << " ";
	cout << endl;
	insertionSort();
	for (int i = 0; i < list.size(); i++) cout << list[i] << " ";
	cout << endl;
}