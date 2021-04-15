#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 201

int N, K;
int belt[MAX_N];
int robot[MAX_N];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N * 2; i++) cin >> belt[i];
	int start = 0, end = N - 1, broken = 0;
	int nth = 1;
	while (1) {
		//1. ��Ʈ ȸ��
		start = (start - 1 + 2 * N) % (2 * N);
		end = (end - 1 + 2 * N) % (2 * N);
		if (robot[end]) robot[end] = 0;
		//2. �κ� ��ĭ �̵�
		int curr = (end - 1 + 2 * N) % (2 * N), next;
		int bp = (start - 1 + 2 * N) % (2 * N);
		while(curr != bp) {
			next = (curr + 1) % (2 * N);
			if (!robot[curr]) {//�ش� ĭ�� �κ� ����
				curr = next; continue;
			}
			if (robot[next] || !belt[next]) {//�̵� �Ұ� (�̵��Ϸ��� ĭ�� �κ��� �̹� ���� or ������ ĭ)
				curr = next; continue;
			}
			//�̵� ����
			belt[next]--;
			if (belt[next] == 0) broken++;
			if (next == end) { //�κ��� ��ĭ �̵��ؼ� ������ ĭ���� �̵�
				robot[curr]--;
			}
			else { robot[curr]--; robot[next]++; }
			curr = (curr - 1 + 2 * N) % (2 * N);
		}
		if (broken >= K)break;
		//3. �ö󰡴� ��ġ�� �κ��� �ø�
		if (belt[start] > 0) { //�κ��� �ø� �� ����
			belt[start]--;
			robot[start]++;
			if (belt[start] == 0) broken++;
		}
		if (broken >= K)break;
		nth++;
	}
	cout << nth << endl;
}