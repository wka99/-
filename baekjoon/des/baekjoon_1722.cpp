#include <iostream>
using namespace std;

int N;
long long f[21];
int kth[21]; //k��° ����
bool check[21];

int main() {
	int cmd, curr;
	long long ans = 0, k;
	cin >> N;
	//���丮�� �ʱ�ȭ
	f[0] = 1; f[1] = 1;
	for (int i = 2; i <= N; i++) {
		f[i] = f[i - 1] * i;
	}
	cin >> cmd;
	if (cmd == 1) {
		cin >> k;
		for (int i = 1; i <= N; i++) { //���� N�� ������ ��������
			for (int j = 1; j <= N; j++) { //� ���ڸ� ����ϴ��� üũ
				if (check[j]) continue;
				if (k > f[N - i]) k -= f[N - i]; //�ش� ���ڷ� �����ϴ� ������ pass
				else { //�ش� �ڸ��� ���� Ȯ��
					check[j] = 1;
					kth[i - 1] = j;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			cout << kth[i] << " ";
		}cout << endl;
	}
	else {
		for (int i = 1; i <= N; i++) {
			cin >> curr;
			check[curr] = 1;
			int cnt = 0;
			for (int j = 1; j < curr; j++) {
				if (check[j]) continue;
				cnt++;
			}
			ans += cnt * f[N - i];
		}
		ans++;
		cout << ans << endl;
	}
}