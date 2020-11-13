#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
���� Ž�����δ� ȿ������ ������. �ǳ� �� �ִ� ����� ���� "�̺й�"���� Ž��
¡�˴ٸ��� ���̻� �ǳ� �� ���� ���°� �Ǵ� ��� �� ����� ���� ���� ���� ����
�ִ�� �ǳ� �� �ִ� ����� ���� ��
*/
int solution(vector<int> stones, int k) {
	int answer = 200000000;
	int right = 0, left = 1, mid, cnt, flag;
	for (int i = 0; i < stones.size(); i++) {
		if (right < stones[i]) right = stones[i];
	}
	mid = (right + left) / 2;
	while (left <= right) {
		cnt = 0;
		flag = 0;
		for (int i = 0; i < stones.size(); i++) {
			if (stones[i] - mid > 0) cnt = 0;
			else cnt++;
			if (cnt == k) {
				flag = 1;
				break;
			}
		}
		if (flag) {//�� �ǳ� �� ����. mid�� ������
			if (answer > mid) answer = mid;
			right = mid - 1;
			mid = (right + left) / 2;
		}
		else {//�� �ǳ� �� ���� mid�� �ø���
			left = mid + 1;
			mid = (right + left) / 2;
		}
	}
	return answer;
}
int main() {
	cout<<solution({ 2,4,5,3,2,1,4,2,5,1 }, 2);
}