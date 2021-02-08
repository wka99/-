#include <iostream>
#include <queue>
using namespace std;

//����� ���ؿ� ����
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, tmp;
	priority_queue<int, vector<int>, greater<int>> minheap;
	priority_queue<int> maxheap;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		if (maxheap.size() > minheap.size()) minheap.push(tmp);
		else maxheap.push(tmp);
		if (!minheap.empty() && !maxheap.empty() && minheap.top() < maxheap.top()) {
			int a = minheap.top();
			int b = maxheap.top();
			minheap.pop(); maxheap.pop();
			minheap.push(b); maxheap.push(a);
		}
		if (i % 2 == 0) { //¦����
			int a = minheap.top();
			int b = maxheap.top();
			if (a < b) cout << a << "\n";
			else cout << b << "\n";
		}
		else { //Ȧ����
			cout << maxheap.top() << "\n";
		}
	}

	/*
		1 5 2 10 -99 7 5
		minheap�� maxheap�� ����Ͽ� ���� �ذ�

		minheap�� ��� ��Ҵ� maxheap���� ũ����
		minheap�� size�� �׻� maxheap���� �۵� ũ�����̰� 1�̻� ������ �ȵ�
		�߰����� ������ Ȧ������ ���, maxheap�� top ������ ¦������ ���, 
		minheap�� top�� maxheap�� top�� ���� ���� �ȴ�.
	*/
}