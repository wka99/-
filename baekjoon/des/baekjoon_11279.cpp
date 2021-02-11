#include <iostream>
using namespace std;
#define MAX_N 100001

int maxHeap[MAX_N] = { 0, };
int idx = 1;

void push_back(int x) {
	maxHeap[idx] = x;
	int cur = idx, par = cur / 2, tmp;
	while (par > 0) {
		if (maxHeap[cur] > maxHeap[par]) { //swap
			tmp = maxHeap[cur];
			maxHeap[cur] = maxHeap[par];
			maxHeap[par] = tmp;
			cur = par;
			par = cur / 2;
		}
		else break;
	}
}
void pop() {
	if (idx == 1) {
		cout << 0 << "\n";
		return;
	}
	cout << maxHeap[1] << "\n";
	maxHeap[1] = maxHeap[idx - 1];
	maxHeap[idx - 1] = 0;
	idx--;
	int cur = 1, tmp;
	int son1, son2, target;
	while (cur < idx) {
		son1 = cur * 2;
		son2 = cur * 2 + 1;
		if (son1 < idx) {
			target = son1;
			if (son2 < idx) {
				if (maxHeap[son1] < maxHeap[son2])
					target = son2;
			}
			if (maxHeap[target] > maxHeap[cur]) {
				tmp = maxHeap[target];
				maxHeap[target] = maxHeap[cur];
				maxHeap[cur] = tmp;
				cur = target;
			}
			else break;
		}
		else break;
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