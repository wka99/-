#include <iostream>
using namespace std;
class treeNode {
public:
	int data;
	treeNode *left = NULL;
	treeNode *right = NULL;
};
void insertNode(treeNode *root, int data) {
	treeNode *p, *t; //�θ� ���, ���� ���
	treeNode *n = new treeNode; //�߰��� ���
	p = NULL;
	t = root;
	while (t != NULL) {
		if (t->data == data) return;
		p = t;
		if (p->data < data) t = p->right;
		else t = p->left;
	}
	n->data = data;
	if (p != NULL) {
		if (data > p->data) p->right = n;
		else p->left = n;
	}
	else root = n;
}
void delete_node(treeNode *root, int data) {
	treeNode *p, *t; //�θ� ���, ���� ���
	treeNode *succ, *succp;
	p = NULL;
	t = root;
	while (t != NULL&& t->data != data) {
		p = t;
		if (p->data < data) t = p->right;
		else if (p->data > data)t = p->left;
	}
	if (t == NULL) {
		cout << "Ʈ���� �������� �ʽ��ϴ�" << endl;
		return;
	}
	//data�� ��ġ�� t�� ����Ǿ�����
	if (t->left == NULL && t->right == NULL) {
		if (p != NULL) {
			if (p->left == t) p->left = NULL;
			else p->right = NULL;
		}
		else
			root = NULL;
	}
	else if (t->left == NULL || t->right == NULL) {
		treeNode *child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t) p->left = child;
			else p->right = child;
		}
		else
			root = child;
	}
	else {
		succp = t;
		succ = t->right;
		while (succ->left != NULL) {
			succp = succ;
			succ = succ->left;
		}
		succp->left = NULL;
		t->data = succ->data;
	}
}
void preorder(treeNode *root) { //������ȸ
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
int main() {
	treeNode t1;
	t1.data = 35;
	insertNode(&t1, 18);
	insertNode(&t1, 68);
	insertNode(&t1, 7);
	insertNode(&t1, 26);
	insertNode(&t1, 99);
	insertNode(&t1, 3);

	insertNode(&t1, 12);
	insertNode(&t1, 22);
	insertNode(&t1, 30);
	delete_node(&t1, 18);
	preorder(&t1);
}