#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000

vector<int> list = { 5,3,8,1,2,7,9,4 };
int N = list.size();

/*
	[���� ����]
	���ĵ��� ���� �� �߿��� ���� ���� ���� ã�� ���ĵ� ����Ʈ��
	�ڿ� ���̴� ������ ���ĵ��� ���� ���� ������ ������ �ݺ�

	���� Ƚ�� (n-1)+(n-2)+...+1 ���� �ð� ���⵵ O(n^2)
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
	[���� ����]
	���ĵ��� ���� ���ڸ� �ùٸ� ��ġ�� �����ϴ� ������ �ݺ���
	����Ʈ�� �����ϴ� ���

	���� Ƚ�� (n-1)+(n-2)+...+1 ���� �ð� ���⵵ O(n^2)
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