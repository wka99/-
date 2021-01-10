#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	string poketmon, tmp;
	map<int, string> dogam1;
	map<string, int> dogam2;//이름 질문
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> poketmon;
		dogam1[i+1] = poketmon;
		dogam2[poketmon] = i+1;
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (isalpha(tmp[0])) {//이름
			cout << dogam2[tmp] << "\n";
		}
		else {//숫자
			cout << dogam1[stoi(tmp)] << "\n";
		}
	}
}