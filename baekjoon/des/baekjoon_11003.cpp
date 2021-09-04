#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int N, L; //���� ����, ������ ũ��
deque<pair<int,int>> dq; //����, �ε��� | �ּڰ��� deque�� front�� �����ϵ��� ����� ��
queue<int> window; //���� �����쿡 �ִ� ����� �ε���

int main() {
	int num;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	int top = -1; //������ ������ ��� ����� �ε��� ����
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (window.size() == L) { //slide window
			top = window.front();
			window.pop();
		}
		else top = -1;
		window.push(i); //�����쿡 ���� ������ ���
		//������ ���� ��� ��� ����
		if (!dq.empty() && top == dq.front().second) dq.pop_front();
		if (dq.empty()||dq.back().first <= num) dq.push_back({ num, i });
		else { //���� ������ ������ ū deque�� ��Ҵ� ���� �ּڰ��� �� �� ���� (�������ش�)
			while (!dq.empty() && dq.back().first > num)
				dq.pop_back();
			dq.push_back({ num,i });
		}
		cout << dq.front().first << " "; //�ּڰ� ���
	}
}
