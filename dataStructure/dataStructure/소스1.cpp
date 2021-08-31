#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> list = { 2,1,4,9,8,3,6,7,5 };
int N = list.size();

void selectionSort() { //선택 정렬
	for (int i = 0; i < N - 1; i++) {
		int idx = i; //최솟값 위치
		for (int j = i + 1; j < N; j++) {
			if (list[idx] > list[j]) 
				idx = j;
		}
		swap(list[idx], list[i]);
	}
}
void insertionSort() { //삽입 정렬
	for (int i = 1; i < N; i++) {
		int j = i - 1;
		int key = list[i];
		while (j >= 0) {
			if (key < list[j]) list[j + 1] = list[j];
			else break;
			j--;
		}
		list[j + 1] = key;
	}
}
void bubbleSort() {
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1])
				swap(list[j], list[j + 1]);
		}
	}
}
void merge(int left, int right, int mid) { //합병 정렬 
	int i = left, j = mid + 1;
	vector<int> sorted;
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) {
			sorted.push_back(list[i]);
			i++;
		}
		else {
			sorted.push_back(list[j]);
			j++;
		}
	}
	while (i <= mid) {
		sorted.push_back(list[i]);
		i++;
	}
	while (j <= right) {
		sorted.push_back(list[j]);
		j++;
	}
	for (int i = left; i <= right; i++) {
		list[i] = sorted[i-left];
	}
}
void mergeSort(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, right, mid);
	}
}
int partition(int left, int right) { //퀵정렬
	//피벗을 정하고 피벗을 기준으로 정렬 => 피벗의 위치 반환
	int pivot = list[left];//첫번째 수를 피벗으로 정함
	int low = left + 1, high = right;
	while (low < high) {
		while (low <= right && pivot <= list[low]) low++;
		while (high >= left && pivot >= list[high]) high--;
		if (low < high) swap(list[low], list[high]);
	}
	swap(list[left], list[high]);
	return high;
}
void quickSort(int left, int right) {
	if (left < right) {
		int p_idx = partition(left, right); //피벗 위치 반환 => 피벗은 이미 정렬된 상태
		//따라서 피벗을 제외한 나머지만 퀵소트 수행
		quickSort(left, p_idx - 1);
		quickSort(p_idx + 1, right);
	}
}
int main() {
	for (int i = 0; i < N; i++) cout << list[i] << " ";
	cout << "\n";
	bubbleSort();
	for (int i = 0; i < N; i++) cout << list[i] << " ";
	cout << "\n";
}