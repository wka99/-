#include <iostream>
#include <vector>
using namespace std;

long long score = 0;
void splitCards(vector<pair<int, int>> cards, int idx, int plus, int mult) {
	if (idx == cards.size()) {
		if (plus < 1 || mult < 1) return;
		long long p1 = 0, p2 = 1;
		for (int i = 0; i < cards.size(); i++) {
			if (cards[i].second == 1) p1 += cards[i].first;
			else if(cards[i].second == 2) p2 *= cards[i].first;
		}
		if (p1 == p2) score = max(score, p1);
		return;
	}
	cards[idx].second = 1;
	splitCards(cards, idx + 1, plus + 1, mult);
	cards[idx].second = 2;
	splitCards(cards, idx + 1, plus, mult + 1);
	cards[idx].second = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, M;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> M;
		int prime, num, total = 0;
		score = 0;
		vector<pair<int, int>> cards;
		for (int j = 0; j < M; j++) {
			cin >> prime >> num;
			total += num;
			for (int k = 0; k < num; k++) {
				cards.push_back({ prime, 0 });
			}
		}
		splitCards(cards, 0, 0, 0);
		cout << "Case #" << i << ": " << score << "\n";
	}
}