#include <iostream>
#include <queue>
using namespace std;

//가운데를 말해요 게임
/*
	minheap의 모든 원소는 maxheap의 모든 원소보다 커야 함
	minheap의 크기는 maxheap의 크기보다 작거나 같아야 함
	1)원소의 개수가 짝수인 경우
	minheap top과 maxheap top중 작은값이 중간값
	2)원소의 개수가 홀수인 경우
	maxheap의 top이 중간값
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, tmp, a, b;
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (maxheap.size() == minheap.size()) 
			maxheap.push(tmp);
		else minheap.push(tmp);
		/*
			하나씩 입력하면서 확인하기 때문에 while문을 돌릴 필요없이
			입력받을때마다 top을 확인하면 된다
			minheap의 모든 원소는 maxheap의 모든 원소보다 커야 하기 때문에
			minheap.top() < maxheap.top()인 경우 잘못된 것
			top 값들을 서로 swap해주어야 한다.
		*/
		if (minheap.size() > 0 && maxheap.size() > 0 && maxheap.top() > minheap.top()) {
			a = maxheap.top(); maxheap.pop();
			b = minheap.top(); minheap.pop();
			maxheap.push(b);
			minheap.push(a);
		}
		if (i % 2 == 0) cout << maxheap.top() << "\n";
		else {
			a = maxheap.top();
			b = minheap.top();
			if (a < b) cout << a << "\n";
			else cout << b << "\n";
		}
	}
}