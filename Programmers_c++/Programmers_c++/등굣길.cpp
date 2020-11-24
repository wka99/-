#include <string>
#include <vector>
#include <iostream>

using namespace std;
//�����ʰ� �Ʒ������θ� ������ �б��� �� �� �ִ� �ִ� ����� ����
//(X+Y)%A == ((X%A)+(Y%A))%A
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int map[101][101] = { 0, };
	for (int i = 0; i < puddles.size(); i++) {
		map[puddles[i][1] - 1][puddles[i][0] - 1] = -1;//�� ������ üũ
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//����, ���� �������� ������ Ȯ���ϰ� ���ϱ�
			if (map[i][j] == -1) continue;
			if (i == 0 && j == 0) { //���� 1�� �ʱ�ȭ
				map[i][j] = 1;
				continue;
			}
			if (i == 0) { //�������� ���� �͸� ���
				if (map[i][j - 1] != -1)//������ ������ ����
					map[i][j] += map[i][j - 1] % 1000000007;
			}
			else if (j == 0) {//������ ���� �͸� ���
				if (map[i - 1][j] != -1)//���� ������ ����
					map[i][j] += map[i - 1][j] % 1000000007;
			}
			else {//����, �������� ���� ���� ��� ���
				if (map[i][j - 1] != -1)
					map[i][j] += map[i][j - 1] % 1000000007;
				if (map[i - 1][j] != -1)
					map[i][j] += map[i - 1][j] % 1000000007;
			}
		}
	}
	answer = map[n - 1][m - 1] % 1000000007;
	return answer;
}