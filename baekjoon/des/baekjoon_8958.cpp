#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, score, Os = 0;
	string quiz;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> quiz;
		score = 0;
		Os = 0;
		for (int j = 0; j < quiz.size(); j++) {
			if (quiz[j] == 'O') {
				Os++;
				score += Os;
			}
			else Os = 0;
		}
		cout << score << endl;
	}
}