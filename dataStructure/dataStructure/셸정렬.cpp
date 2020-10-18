#include <iostream>
using namespace std;

/*
삽입정렬이 어느정도 정렬된 상태의 배열에 대해서
효율이 높다는 것을 이용한 정렬 방식으로 
부분 집합을 만들고 이를 정렬하는 과정을
반복하고 이를 합쳐, 배열을 어느 정도 정렬된 상태로 만들어
시간 복잡도를 줄이는 정렬 방식
*/
void insertion_sort(int list[], int start, int end, int gap) {
	int val, i, j;
	for (i = start + gap; i <= end; i += gap) {
		val = list[i];
		for (j = i - gap; j >= 0; j -= gap) {
			if (list[j] > val) {
				list[j + gap] = list[j];
			}
			else break;
		}
		list[j + gap] = val;
	}
}
void shell_sort(int list[], int n) {
	int gap;
	for (gap = n / 2; gap > 0; gap /= 2) {
		if (gap % 2 == 0)gap++;
		for (int i = 0; i < gap; i++) {
			insertion_sort(list, i, n - 1, gap);
		}
	}
}
int main() {
	int list[10] = { 9,2,5,3,1,4,7,8,0,6 };
	shell_sort(list, 10);
	for (int i = 0; i < 10; i++) {
		cout << list[i] << " ";
	}
}