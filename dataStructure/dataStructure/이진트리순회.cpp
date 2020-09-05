#include <iostream>
#include <queue>
#include <string>
using namespace std;

class treeNode {
public:
	int data;
	treeNode *l = NULL;
	treeNode *r = NULL;
};
void preorder(treeNode *root) { //전위순회
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->l);
	preorder(root->r);
}
void inorder(treeNode *root) { //중위순회
	if (root == NULL)
		return;
	inorder(root->l);
	cout << root->data << " ";
	inorder(root->r);
}
void postorder(treeNode *root) { //후위순회
	if (root == NULL)
		return;
	postorder(root->l);
	postorder(root->r);
	cout << root->data << " ";
}
void levelorder(treeNode *root) { //레벨순회
	queue<treeNode*>q;
	if (root == NULL)return;
	q.push(root);
	while (!q.empty()) {
		treeNode *tmp = q.front();
		q.pop();
		cout << tmp->data << " ";
		if (tmp->l != NULL)
			q.push(tmp->l);
		if (tmp->r != NULL)
			q.push(tmp->r);
	}
}
int main() {
	treeNode n1, n2, n3, n4, n5, n6;
	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n5.data = 5;
	n6.data = 6;
	n1.l = &n2;
	n1.r = &n3;
	n2.l = &n4;
	n2.r = &n5;
	n3.l = &n6;
	preorder(&n1);
	cout << endl;
	inorder(&n1);
	cout << endl;
	postorder(&n1);
	cout << endl;
	levelorder(&n1);
}