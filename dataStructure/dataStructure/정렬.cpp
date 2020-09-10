#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
���ĵ��� ���� ����Ʈ���� ���� ���� ���� ã��
���ĵ� ���� ����Ǵ� ����Ʈ�� �ű�� ������
���ĵ��� ���� ����Ʈ�� �������� �ݺ��ϴ� ���� ���
"���� ����"
- �ð� ���⵵
�� Ƚ�� = (n-1)+(n-2)+...+1=n*(n-1)/2
��ȯ Ƚ�� = (n-1)*3
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
�� ����Ʈ�� ���ĵ��� ���� ����Ʈ�� ��Ҹ� �ùٸ� ��ġ�� 
�����ϴ� ������ ���ĵ��� ���� ����Ʈ�� �������� 
�ݺ��ϴ� ���� ���
"��������"
- �ð� ���⵵
�� Ƚ�� = 1+2+...(n-2)+(n-1) = (n-1)n/2
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
������ �ΰ��� ���ڵ带 ���Ͽ� ũ�Ⱑ ������ΰ� 
�ƴ� ��� ��ȯ�ϴ� ������ ����Ʈ�� ���� ������
������ ������ �����Ѵ�. �� ��-��ȯ ������ ��ü ���ڰ�
���ĵ� ������ �ݺ��ϴ� ���� ���
"���� ����"
-�ð� ���⵵
���� for�� O(n^2)
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
Divide and Conquer ����� ������ �� ���� ���
�־��� ����Ʈ�� ������ ũ���� �κ� ����Ʈ�� �����ϰ�
�� �κ� ����Ʈ�� ������ ��, �����س����鼭 ��ü ����Ʈ
�� �����ϴ� ���
"�պ� ����"
- �ð� ���⵵
�պ� ������ ���� log2 n 
�� �պ� ���������� �� ���� ���� n��
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
void merge_sort(vector<int>&v, int left, int right) { //����Ʈ ����->����->�պ� ����
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(v, left, mid); //���� ����Ʈ ����
		merge_sort(v, mid + 1, right); //������ ����Ʈ ����
		merge(v, left, mid, right);//�� �κ� ����Ʈ �պ�
	}
}
/*
Divide and Conquer ����� ������ �� ���� ���
����Ʈ �� �ϳ��� ���� �ǹ����� ���ϰ� 
�ǹ����� ū ���� �ǹ��� �����ʿ�, ���� ���� ���ʿ�
��ġ�ϵ��� �� ��, �ǹ��� ������ �ΰ��� �κ� ����Ʈ��
���Ͽ� �ǹ��� ���ϰ� �����ϴ� ������ �ݺ��ϴ� ���� ���
"�� ����"
- �ð� ���⵵
�ּ��� ��� = ����Ʈ�� ������ �׻� ������� �̷������ ���
�� ��� log2 n ���� �н��� �ʿ��ϸ� �� �н����� n�������� ��
== O(nlog2 n)
�־��� ��� = ����Ʈ�� ������ �ұ����ϰ� �Ͼ�� ���
�� ��� n���� �н��� �ʿ��ϸ� �� �н����� n�� ������ ��
== O(n^2)
������� ��� O(nlog2 n)
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