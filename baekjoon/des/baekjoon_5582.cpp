#include <iostream>
#include <string>
using namespace std;
#define MAX 4001

int dp[MAX][MAX];
int main() {
	string a, b;
	int maxV = 0;
	int midx, midy;
	cin >> a >> b;
	if (a.length() > b.length()) swap(a, b);
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			if (maxV < dp[i][j]) {
				maxV = dp[i][j];
				midx = i;
				midy = j;
			}
			//���� �κ� ���ڿ��� �������� ���ڵ��� ��ġ�ؾ���
			//a[i-1]�� b[j-1]�� ���ƾ� ���� ���� �κ� ���ڿ��� ���̰� �����ϰ� ��
		} 
	}
	/*
		���� ���� �κ� ���ڿ� ã��
		string s = "";
		while (dp[midx][midy] > 0) {
			s = a[midx - 1]+s;
			midx--; midy--;
		}
		cout << s << endl;
	*/
	cout << maxV << endl;
	
}