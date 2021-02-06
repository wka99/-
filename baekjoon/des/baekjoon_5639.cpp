#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 10001

//전위 순회를 후위 순회로 바꿔서 출력
int preTree[MAX_N];
int postTree[MAX_N];
int idx;

void makePost(int f1, int t1, int f2, int t2) {
	if (f1 > t1 || f2 > t2 || f1 < 0 || f2 < 0 || t1 >= idx || t2 >= idx)return;
	int root = preTree[f1];
	postTree[t2] = root;
	int i = f1 + 1;
	while (i <= t1 && preTree[i] < root) ++i;
	i--;
	makePost(f1 + 1, i, f2, f2 + i - f1 - 1); //left subtree
	makePost(i + 1, t1, f2 + i - f1, t2 - 1); //right subtree
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	idx = 0;
	while (cin >> n) {
		preTree[idx++] = n;
		//if (idx == 9)break;
	}
	makePost(0, idx - 1, 0, idx - 1);
	for (int i = 0; i < idx; i++) {
		cout << postTree[i] << "\n";
	}
}