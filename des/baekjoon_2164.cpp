#include <iostream>
#include <queue>
using namespace std;
int N;
queue <int> card;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		card.push(i);
	}
	int temp;
	while (card.size() > 1) {
		card.pop();
		temp = card.front();
		card.pop();
		card.push(temp);
	}
	cout << card.front() << endl;
}