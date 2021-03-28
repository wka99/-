#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX_S 1001
#define MAX_COST 100000

int T, ans, x, y;
string mural;
vector<int> blank;//빈 곳 위치
int dp[MAX_S][2];//최소 비용
int is_blank[MAX_S];

void paint() {
	for (int idx = 1; idx <= blank.size(); idx++) {
		int bloc = blank[idx - 1];
		for (int p = 0; p < 2; p++) {
			if (p == 0) mural[bloc] = 'C';
			else mural[bloc] = 'J';
			int cost = 0;
			if (bloc + 1 < mural.length() && !is_blank[bloc + 1]) {
				string tmp = "";
				tmp += mural[bloc];
				tmp += mural[bloc + 1];
				if (tmp == "CJ") cost += x;
				else if (tmp == "JC") cost += y;
			}
			if (bloc - 1 < mural.length() && !is_blank[bloc - 1]) {
				string tmp = "";
				tmp += mural[bloc - 1];
				tmp += mural[bloc];
				if (tmp == "CJ") cost += x;
				else if (tmp == "JC") cost += y;
			}
			else if (bloc - 1 < mural.length() && is_blank[bloc - 1]) {
				string tmp = "C";
				tmp += mural[bloc];
				if (tmp == "CC") {
					if (dp[idx][p] > dp[idx - 1][0] + cost) {
						dp[idx][p] = dp[idx - 1][0] + cost;
						mural[bloc - 1] = 'C';
					}
				}
				else {
					if (dp[idx][p] > dp[idx - 1][0] + cost + x) {
						dp[idx][p] = dp[idx - 1][0] + cost + x;
						mural[bloc - 1] = 'C';
					}
				}
				tmp = "J";
				tmp += mural[bloc];
				if (tmp == "JJ") {
					if (dp[idx][p] > dp[idx - 1][1] + cost) {
						dp[idx][p] = dp[idx - 1][1] + cost;
						mural[bloc - 1] = 'J';
					}
				}
				else {
					if (dp[idx][p] > dp[idx - 1][1] + cost + y) {
						dp[idx][p] = dp[idx - 1][1] + cost + y;
						mural[bloc - 1] = 'J';
					}
				}
			}
			//cout << mural << endl;
			if (dp[idx][p] == MAX_COST)
				dp[idx][p] = min(dp[idx - 1][0] + cost, dp[idx - 1][1] + cost);
		}
	}
}
void init() {
	blank.clear();
	ans = MAX_COST;
	for (int i = 0; i < MAX_S; i++) {
		is_blank[i] = 0;
		for (int j = 0; j < 2; j++) {
			dp[i][j] = MAX_COST;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> x >> y >> mural;
		init();
		for (int j = 0; j < mural.length(); j++) {
			if (mural[j] == '?') {
				blank.push_back(j);
				is_blank[j] = 1;
			}
		}
		int cost = 0;
		for (int i = 0; i < mural.length() - 1; i++) {
			string copyright = "";
			copyright += mural[i];
			copyright += mural[i + 1];
			if (copyright == "CJ") cost += x;
			else if (copyright == "JC") cost += y;
		}
		dp[0][0] = cost; dp[0][1] = cost;
		paint();
		ans = min(dp[blank.size()][0], dp[blank.size()][1]);
		cout << "Case #" << i << ": " << ans << "\n";
	}
}