#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
	구명 보트에 두명을 태워보면서 무게 제한을 넘는지 안넘는지 확인
	사람들의 몸무게를 정렬해놓고 
	가장 무거운 사람과 가장 가벼운 사람을 골라 태워보기
	=> 무게 제한을 넘지 않을 확률이 가장 높음
	1. 넘지 않는 경우 같이 태우고
	2. 넘는 경우 무거운 사람만 혼자 태움

	+) 벡터 요소 삭제하고 난리치면 효율성 면에서 떨어짐
	그냥 왼쪽 끝과 오른쪽 끝을 가리키는 포인터를 사용하는 것이 효율적
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
	if (left == right) { // 한명 남았다는 것을 의미
		answer++;
	}
	return answer;
}
int main() {
	solution({ 70,50,80,50 }, 100);
}