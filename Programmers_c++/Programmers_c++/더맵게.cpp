#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> sorted_sco; //ÃÖ¼Ò Èü
	//less<int> => ÃÖ´ë Èü
	for (int i = 0; i < scoville.size(); i++) {
		sorted_sco.push(scoville[i]);
	}
	while (sorted_sco.top() < K) {
		if (sorted_sco.size() == 1) {
			return -1;
		}
		int first = sorted_sco.top();
		sorted_sco.pop();
		int second = sorted_sco.top();
		sorted_sco.pop();
		int mix = first + second * 2;
		sorted_sco.push(mix);
		answer++;
	}
	return answer;
}
int main() {
	vector<int> scoville = { 1,2,3,9,10,12 };
	cout<<solution(scoville, 7);
}