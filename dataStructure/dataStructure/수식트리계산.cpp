#include <iostream>
using namespace std;

class treeNode {
public:
	char data;
	treeNode* left = NULL;
	treeNode* right = NULL;
};
int evaluate(treeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)//자식노드가 없다 == 단말노드 == 피연산자임
		return (root->data)-48;
	int x = evaluate(root->left);
	int y = evaluate(root->right);
	char op = root->data;
	if (op == '*')
		return x * y;
	else
		return x + y;
}
int main() {
	treeNode n1, n2, n3, n4, n5, n6, n7;
	n1.data = '+';
	n2.data = '*';
	n3.data = '+';
	n4.data = '3';
	n5.data = '2';
	n6.data = '5';
	n7.data = '6';
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;
	cout << evaluate(&n1);
}