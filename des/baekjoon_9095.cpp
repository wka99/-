#include <iostream>
#include <vector>
using namespace std;
//1, 2, 3 ���ϱ�
int result = 0;
void dp(int n) {
	if (n == 0)result++;
	if (n - 1 >= 0) { dp(n - 1); }
	if (n - 2 >= 0) { dp(n - 2); }
	if (n - 3 >= 0) { dp(n - 3); }
}
int main() {
	int T=0; //�׽�Ʈ ���̽��� ����
	vector <int> n; //����
	int temp = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> temp;
		n.push_back(temp);
	}
	for (int i = 0; i < T; i++) {
		dp(n[i]);
		cout << result<<endl;
		result = 0;
	}
}