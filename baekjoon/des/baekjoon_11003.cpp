#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int N, L; //숫자 개수, 윈도우 크기
deque<pair<int,int>> dq; //숫자, 인덱스 | 최솟값이 deque의 front에 존재하도록 해줘야 함
queue<int> window; //현재 윈도우에 있는 요소의 인덱스

int main() {
	int num;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	int top = -1; //윈도우 범위를 벗어난 요소의 인덱스 저장
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (window.size() == L) { //slide window
			top = window.front();
			window.pop();
		}
		else top = -1;
		window.push(i); //윈도우에 새로 들어오는 요소
		//윈도우 범위 벗어난 요소 제거
		if (!dq.empty() && top == dq.front().second) dq.pop_front();
		if (dq.empty()||dq.back().first <= num) dq.push_back({ num, i });
		else { //새로 들어오는 값보다 큰 deque의 요소는 절대 최솟값이 될 수 없음 (제거해준다)
			while (!dq.empty() && dq.back().first > num)
				dq.pop_back();
			dq.push_back({ num,i });
		}
		cout << dq.front().first << " "; //최솟값 출력
	}
}
