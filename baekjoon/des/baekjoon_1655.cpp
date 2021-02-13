#include <iostream>
#include <queue>
using namespace std;

//����� ���ؿ� ����
/*
	minheap�� ��� ���Ҵ� maxheap�� ��� ���Һ��� Ŀ�� ��
	minheap�� ũ��� maxheap�� ũ�⺸�� �۰ų� ���ƾ� ��
	1)������ ������ ¦���� ���
	minheap top�� maxheap top�� �������� �߰���
	2)������ ������ Ȧ���� ���
	maxheap�� top�� �߰���
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, tmp, a, b;
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (maxheap.size() == minheap.size()) 
			maxheap.push(tmp);
		else minheap.push(tmp);
		/*
			�ϳ��� �Է��ϸ鼭 Ȯ���ϱ� ������ while���� ���� �ʿ����
			�Է¹��������� top�� Ȯ���ϸ� �ȴ�
			minheap�� ��� ���Ҵ� maxheap�� ��� ���Һ��� Ŀ�� �ϱ� ������
			minheap.top() < maxheap.top()�� ��� �߸��� ��
			top ������ ���� swap���־�� �Ѵ�.
		*/
		if (minheap.size() > 0 && maxheap.size() > 0 && maxheap.top() > minheap.top()) {
			a = maxheap.top(); maxheap.pop();
			b = minheap.top(); minheap.pop();
			maxheap.push(b);
			minheap.push(a);
		}
		if (i % 2 == 0) cout << maxheap.top() << "\n";
		else {
			a = maxheap.top();
			b = minheap.top();
			if (a < b) cout << a << "\n";
			else cout << b << "\n";
		}
	}
}