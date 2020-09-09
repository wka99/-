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
void print(vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
int main() {
	vector<int> v = { 5,3,8,1,2,7 };
	bubble_sort(v);
	print(v);
}