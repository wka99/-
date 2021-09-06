#include <iostream>
using namespace std;
#define MAX_N 10001

int postTree[MAX_N];
int preTree[MAX_N];
int N = 0, idx;

void makePost(int f1, int t1, int f2, int t2) {
	if (f1 > t1 || f2 > t2 || f1 < 0 || f2 < 0 || t1 >= N || t2 >= N)return;
	int root = preTree[f1];
	postTree[t2] = root;
	int i = f1 + 1;
	while (i <= t1 && root > preTree[i])i++;
	i--;
	//L
	makePost(f1 + 1, i, f2, f2 + i - f1 - 1);
	//R
	makePost(i + 1, t1, f2 + i - f1, t2 - 1);
}
void makePost2(int from, int to) {
	int root = preTree[from];
	postTree[idx--] = root;
	int i = from + 1;
	while (i <= to && root > preTree[i])i++;
	if (i <= to)//R
		makePost2(i, to);
	if (i > from + 1)//L
		makePost2(from + 1, i - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tmp;
	while (cin >> tmp) {
		preTree[N++] = tmp;
	}
	//makePost(0, N - 1, 0, N - 1);
	idx = N - 1;
	makePost2(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << postTree[i] << "\n";
	}
}
/*
#include <iostream>
using namespace std;
#define MAX 10001

int preorder[MAX]; //전위 순회
int postorder[MAX]; //후위 순회
int N = 0; //원소의 개수
int idx = 0;

void pre2post(int from, int to) {
	if (from > to || from >= N || to >= N || idx == -1) return;
	int root = preorder[from], i;
	postorder[idx] = root; idx--; //V
	for (i = from + 1; i <= to; i++) {
		if (preorder[i] > root) break;
	}
	pre2post(i, to); //R
	pre2post(from + 1, i - 1);//L
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> preorder[N++]); N--;
	idx = N - 1;
	pre2post(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << postorder[i] << "\n";
	}
}
*/