#include <iostream>
#include <list>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	list <int> ls;
	list <int>::iterator p;
	int count = 0;

	for (int i = 1; i <= k; i++) {//리스트 초기화
		ls.push_back(i);
	}

	p = ls.begin();//리스트의 처음을 가리키는 iterator

	cout << "<";
	while (ls.size() > 0) {//리스트의 크기가 0이 될때까지
		count++;
		if (count % n == 0) {//n번째 사람들
			if (ls.size() > 1)
				cout << *p << ", ";
			else
				cout << *p;
			p=ls.erase(p);//p가 가리키는 원소를 제거하고 다음 원소를 가리키는 iterator를 반환
		}
		else {
			p++;//다음 원소를 가리킬 수 있도록
		}
		if (p == ls.end()) {//끝에 도달
			p = ls.begin();//맨처음으로 보내줌
		}
	}cout << ">" << endl;
}
