#include <iostream>
#include <list>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	list <int> ls;
	list <int>::iterator p;
	int count = 0;

	for (int i = 1; i <= k; i++) {//����Ʈ �ʱ�ȭ
		ls.push_back(i);
	}

	p = ls.begin();//����Ʈ�� ó���� ����Ű�� iterator

	cout << "<";
	while (ls.size() > 0) {//����Ʈ�� ũ�Ⱑ 0�� �ɶ�����
		count++;
		if (count % n == 0) {//n��° �����
			if (ls.size() > 1)
				cout << *p << ", ";
			else
				cout << *p;
			p=ls.erase(p);//p�� ����Ű�� ���Ҹ� �����ϰ� ���� ���Ҹ� ����Ű�� iterator�� ��ȯ
		}
		else {
			p++;//���� ���Ҹ� ����ų �� �ֵ���
		}
		if (p == ls.end()) {//���� ����
			p = ls.begin();//��ó������ ������
		}
	}cout << ">" << endl;
}
