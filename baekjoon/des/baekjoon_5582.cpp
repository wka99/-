#include <iostream>
#include <string>
using namespace std;
#define MAX 4001

string a, b;
int dp[MAX][MAX];
int maxV = 0;
int main() {
	cin >> a >> b;
	if (a.length() > b.length()) swap(a, b);
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (maxV < dp[i][j]) maxV = dp[i][j];
			}
			//else�� ���ؼ��� ����� �ʿ䰡 ����
			//�κ� ���ڿ��� ���ӵǾ�� �ϴ� Ư���� �ֱ� ������ �߰��� ����� �ǹ̰� ����
			//����, a[i-1]�� b[i-1]�� ���ƾ� ������ ���� �κ� ���ڿ��� ���̰� �þ�� ��
		}
	}
	cout << maxV << endl;
}