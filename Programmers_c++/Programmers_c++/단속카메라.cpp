#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	//������ ������� ����
	sort(routes.begin(), routes.end());
	int ent = routes[0][0];
	int ext = routes[0][1];
	for (int i = 1; i < routes.size(); i++) {
		//���� ���� ���� ������ ���� ���� ���� �������� ��
		if (ext >= routes[i][1]) { //cctv ���� ��� ����
			ext = routes[i][1];
		}
		else if (ext < routes[i][0]) { //���� ���� ���� ������ ���� ���� ���� �������� ��
			//cctv �߰�
			ext = routes[i][1];
			answer++;
		}
	}
	return answer;
}
int main() {
	cout << solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} });
}