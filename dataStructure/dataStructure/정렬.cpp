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