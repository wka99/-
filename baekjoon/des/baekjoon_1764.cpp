#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//µË∫∏¿‚

int N, M;
vector <string> h;
vector <string>::iterator it;
string result[500000];
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		h.push_back(tmp);
	}
	sort(h.begin(), h.end());
	for (int j = 0; j < M; j++) {
		cin >> tmp;
		it = lower_bound(h.begin(), h.end(), tmp);
		if (*it == tmp) {
			result[cnt++] = tmp;
		}
	}
	sort(result, result + cnt);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << result[i] << "\n";
	}
}