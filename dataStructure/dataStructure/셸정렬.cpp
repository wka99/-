#include <iostream>
using namespace std;

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