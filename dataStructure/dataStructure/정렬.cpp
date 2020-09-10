#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
정렬되지 않은 리스트에서 가장 작은 값을 찾아
정렬된 값이 저장되는 리스트로 옮기는 과정을
정렬되지 않은 리스트가 빌때까지 반복하는 정렬 방식
"선택 정렬"
- 시간 복잡도
비교 횟수 = (n-1)+(n-2)+...+1=n*(n-1)/2
교환 횟수 = (n-1)*3
== O(n^2)
*/
void selection_sort(vector<int> &v) {
	int minidx, tmp;
	for (int i = 0; i < v.size() - 1; i++) {
		minidx = i;
		for (int j = i; j < v.size(); j++) {
			if (v[minidx] > v[j]) minidx = j;
		}
		//SWAP
		tmp = v[minidx];
		v[minidx] = v[i];
		v[i] = tmp;
	}
}
/*
빈 리스트에 정렬되지 않은 리스트의 요소를 올바른 위치에 
삽입하는 과정을 정렬되지 않은 리스트가 빌때까지 
반복하는 정렬 방식
"삽입정렬"
- 시간 복잡도
비교 횟수 = 1+2+...(n-2)+(n-1) = (n-1)n/2
== O(n^2)
*/
void insert_sort(vector<int> &v) {
	int tmp;
	for (int i = 0; i < v.size() - 1; i++) {
		int minidx = i + 1;
		for (int j = 0; j <= i; j++) {
			if (v[j] < v[minidx])continue;
			else {
				tmp = v[minidx];
				v.erase(v.begin() + minidx);
				v.insert(v.begin() + j, tmp);
				break;
			}
		}
	}
}
/*
인접한 두개의 레코드를 비교하여 크기가 순서대로가 
아닌 경우 교환하는 과정을 리스트의 왼쪽 끝부터
오른쪽 끝까지 진행한다. 이 비교-교환 과정을 전체 숫자가
정렬될 때까지 반복하는 정렬 방식
"버블 정렬"
-시간 복잡도
이중 for문 O(n^2)
*/
void bubble_sort(vector<int>& v) {
	int tmp;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}
/*
Divide and Conquer 방법에 바탕을 둔 정렬 방식
주어진 리스트를 동일한 크기의 부분 리스트로 분할하고
각 부분 리스트를 정렬한 후, 병합해나가면서 전체 리스트
를 정렬하는 방식
"합병 정렬"
- 시간 복잡도
합병 과정의 개수 log2 n 
각 합병 과정에서의 비교 연산 개수 n개
O(nlog2 n)
*/
void merge(vector<int>&v, int left, int mid, int right) {
	vector<int> sorted(v.size(), 0);
	int x = left;
	int y = mid + 1;
	int z = left;
	while (x <= mid && y <= right) {
		if (v[x] < v[y])sorted[z++] = v[x++];
		else sorted[z++] = v[y++];
	}
	for (; x <= mid; x++) {
		sorted[z++] = v[x];
	}
	for (; y <= right; y++) {
		sorted[z++] = v[y];
	}
	for (int i = left; i <= right; i++) {
		v[i] = sorted[i];
	}
}
void merge_sort(vector<int>&v, int left, int right) { //리스트 분할->정렬->합병 과정
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(v, left, mid); //왼쪽 리스트 정렬
		merge_sort(v, mid + 1, right); //오른쪽 리스트 정렬
		merge(v, left, mid, right);//두 부분 리스트 합병
	}
}
/*
Divide and Conquer 방법을 바탕에 둔 정렬 방식
리스트 중 하나의 수를 피벗으로 정하고 
피벗보다 큰 수는 피벗의 오른쪽에, 작은 수는 왼쪽에
위치하도록 한 후, 피벗을 제외한 두개의 부분 리스트에
대하여 피벗을 정하고 정렬하는 과정을 반복하는 정렬 방식
"퀵 정렬"
- 시간 복잡도
최선의 경우 = 리스트의 분할이 항상 가운데에서 이루어지는 경우
이 경우 log2 n 개의 패스가 필요하며 각 패스에서 n번정도의 비교
== O(nlog2 n)
최악의 경우 = 리스트의 분할이 불균형하게 일어나는 경우
이 경우 n개의 패스가 필요하며 각 패스에서 n번 정도의 비교
== O(n^2)
평균적인 경우 O(nlog2 n)
*/
int partition(vector<int>& v, int left, int right) {
	int low = left + 1;
	int high = right;
	int pivot = v[left];
	while (low < high) {
		while (low <= high && pivot > v[low]) low++;
		while (high >= low && pivot < v[high]) high--;
		if (low < high) {
			int tmp = v[high];
			v[high] = v[low];
			v[low] = tmp;
			low++; high--;
		}
	}
	int tmp = v[high];
	v[high] = v[left];
	v[left] = tmp;
	return high;
}
void quick_sort(vector<int>&v, int left, int right) {
	if (left < right) {
		int q = partition(v, left, right);
		quick_sort(v, left, q - 1);
		quick_sort(v, q + 1, right);
	}
}
void print(vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
int main() {
	vector<int> v = { 5,3,8,1,2,7 };
	quick_sort(v,0,v.size()-1);
	print(v);
}