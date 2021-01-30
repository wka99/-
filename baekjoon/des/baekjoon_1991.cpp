#include <iostream>
using namespace std;

class node {
public:
	char left;
	char right;
};
node alpha[26];
void preorder(char x) {
	if (x == '.') return;
	cout << x;
	preorder(alpha[x - 'A'].left);
	preorder(alpha[x - 'A'].right);
}
void inorder(char x) {
	if (x == '.') return;
	inorder(alpha[x - 'A'].left);
	cout << x;
	inorder(alpha[x - 'A'].right);
}
void postorder(char x) {
	if (x == '.') return;
	postorder(alpha[x - 'A'].left);
	postorder(alpha[x - 'A'].right);
	cout << x;
}
int main() {
	int N;
	cin >> N;
	char p, l, r;
	for (int i = 0; i < N; i++) {
		cin >> p >> l >> r;
		alpha[p - 'A'].left = l;
		alpha[p - 'A'].right = r;
	}
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;
}