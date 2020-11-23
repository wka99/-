#include <vector>
#include <algorithm>
using namespace std;

/*
�ִ��� ���� ������ ���ϸ��� ���� �� �ֵ���
������ Ž���ϸ鼭 ���� �ٸ� ��ȣ�� ����
������ ���ϸ��� ������ N/2�� �������� Ž���� ����
�� �� �ִ� ��� ��츦 ����� �ʿ䰡 ���� => ��ȿ���� ��
��� ��츦 ����� �ʿ䰡 ���� ������ set�� ���������� �� �ʿ䰡 ����
*/
int visited[200001] = { 0, };
int solution(vector<int> nums)
{
	int answer = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (answer == nums.size() / 2) break;
		if (!visited[nums[i]]) {
			visited[nums[i]] = 1;
			answer++;
		}
	}
	return answer;
}