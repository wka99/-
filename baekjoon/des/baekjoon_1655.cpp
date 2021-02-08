#include <iostream>
#include <queue>
using namespace std;

//가운데를 말해요 게임
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, tmp;
	priority_queue<int, vector<int>, greater<int>> minheap;
	priority_queue<int> maxheap;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		if (maxheap.size() > minheap.size()) minheap.push(tmp);
		else maxheap.push(tmp);
		if (!minheap.empty() && !maxheap.empty() && minheap.top() < maxheap.top()) {
			int a = minheap.top();
			int b = maxheap.top();
			minheap.pop(); maxheap.pop();
			minheap.push(b); maxheap.push(a);
		}
		if (i % 2 == 0) { //짝수개
			int a = minheap.top();
			int b = maxheap.top();
			if (a < b) cout << a << "\n";
			else cout << b << "\n";
		}
		else { //홀수개
			cout << maxheap.top() << "\n";
		}
	}

	/*
		1 5 2 10 -99 7 5
		minheap과 maxheap을 사용하여 문제 해결

		minheap의 모든 요소는 maxheap보다 크도록
		minheap의 size는 항상 maxheap보다 작되 크기차이가 1이상 나서는 안됨
		중간값은 개수가 홀수개인 경우, maxheap의 top 개수가 짝수개인 경우, 
		minheap의 top과 maxheap의 top중 작은 수가 된다.
	*/
}