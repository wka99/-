#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
	���� ��Ʈ�� �θ��� �¿����鼭 ���� ������ �Ѵ��� �ȳѴ��� Ȯ��
	������� �����Ը� �����س��� 
	���� ���ſ� ����� ���� ������ ����� ��� �¿�����
	=> ���� ������ ���� ���� Ȯ���� ���� ����
	1. ���� �ʴ� ��� ���� �¿��
	2. �Ѵ� ��� ���ſ� ����� ȥ�� �¿�

	+) ���� ��� �����ϰ� ����ġ�� ȿ���� �鿡�� ������
	�׳� ���� ���� ������ ���� ����Ű�� �����͸� ����ϴ� ���� ȿ����
*/
int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int weight = 0;
	int left = 0;
	int right = people.size() - 1;
	while (left < right) {
		weight = people[left] + people[right];
		if (weight > limit) {
			right--; answer++;
		}
		else {
			left++; right--; answer++;
		}
	}
	if (left == right) { // �Ѹ� ���Ҵٴ� ���� �ǹ�
		answer++;
	}
	return answer;
}
int main() {
	solution({ 70,50,80,50 }, 100);
}