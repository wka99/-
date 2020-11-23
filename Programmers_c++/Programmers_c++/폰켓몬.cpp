#include <vector>
#include <algorithm>
using namespace std;

/*
최대한 많은 종류의 폰켓몬을 얻을 수 있도록
끝까지 탐색하면서 서로 다른 번호만 선택
선택한 폰켓몬의 개수가 N/2와 같아지면 탐색을 종료
고를 수 있는 모든 경우를 고려할 필요가 없음 => 비효율의 끝
모든 경우를 고려할 필요가 없기 때문에 set도 마찬가지로 쓸 필요가 없음
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