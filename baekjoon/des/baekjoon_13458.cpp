#include <iostream>
using namespace std;

/*�� ���û��� �� = 1000000*1000000����
�������� ���� int�� ������ �Ѿ �� ����
���� cnt�� long long���� �������־�� �Ѵ�*/

int N; //������
int A[1000001]; //�� �������� ������ ��
int B, C; //�Ѱ�����, �ΰ����� ���� ���� ������ ��
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		cnt++;
		if (A[i] > 0) {
			if (A[i] % C == 0)
				cnt += A[i] / C;
			else {
				cnt += A[i] / C + 1;
			}
		}
	}
	cout << cnt;
}