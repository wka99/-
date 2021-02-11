#include <iostream>
using namespace std;
#define MAX_N 100001

int minHeap[MAX_N] = { 0, };
int idx = 1;

void push_back(int x) {
	//�ּ��� �� �ڿ� �ְ� �θ� ���� ��
	int i = idx;
	minHeap[i] = x;
	int par = i / 2, tmp;
	while (par > 0 && minHeap[par] > minHeap[i]) {
		tmp = minHeap[par];
		minHeap[par] = minHeap[i];
		minHeap[i] = tmp;
		i = par;
		par = i / 2;
	}
}
void pop() {
	if (idx == 1) {
		cout << 0 << "\n";
		return;
	}
	cout << minHeap[1] << "\n";
	minHeap[1] = minHeap[idx - 1];
	minHeap[idx - 1] = 0;
	idx--;
	int par = 1, tmp;
	int son1, son2, target;
	while (par < idx) {
		son1 = par * 2; son2 = par * 2 + 1;
		if (son1 < idx) { //�ڽ��� �Ѱ� ����
			target = son1;
			if (son2 < idx) { //�ڽ��� �ΰ� ����
				//�ڽ��� ũ�Ⱑ �����Ű� target
				if (minHeap[son1] > minHeap[son2]) target = son2;
			}
			if (minHeap[target] < minHeap[par]) { //SWAP
				tmp = minHeap[target];
				minHeap[target] = minHeap[par];
				minHeap[par] = tmp;
				par = target;
			}
			else break; //�̹� �������
		}
		else //�ڽ��� ����
			break;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, t;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t == 0) pop();
		else {
			push_back(t);
			idx++;
		}
	}
}