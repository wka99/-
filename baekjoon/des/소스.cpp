#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lis;
int A[40001];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		if (lis.empty()) {
			lis.push_back(A[i]);
		}
		else {
			if (lis.back() < A[i])lis.push_back(A[i]);
			else {
				vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), A[i]);
				*it = A[i];
			}
		}
	}
	cout << lis.size() << endl;
}