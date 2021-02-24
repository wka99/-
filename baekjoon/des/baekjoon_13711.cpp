#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001

int a[MAX_N], b[MAX_N], order[MAX_N], c[MAX_N];
//c[x]에는 a배열의 x번째 숫자가 b배열의 몇번째에 등장하는지가 저장된다.
/*
	최장 공통 부분 수열
	1. a배열과 b배열에 동시에 등장
	2. 등장하는 순서가 같아야
	ex) a{1, 2, 3} b{1, 3, 2} a와 b 배열 모두에 1, 2, 3이 등장하지만 등장 순서가 다름
	=> a와 b배열에 동시에 등장하는 숫자 && 해당 숫자들의 인덱스가 오름차순이어야
	문제 조건에서 1부터 N까지의 정수가 배열 a와 배열 b에 모두 한번씩 등장한다고 했음
	=> 모든 숫자가 a와 b배열에 동시에 등장

	"숫자들의 등장 순서가 같은지만 확인해주면 됨"
	따라서 c[x]배열의 LIS를 구해 LCS의 길이를 구할 수 있다
	ex) a{1,3,5,2,4,6} b{4,3,2,6,5,1}
	c{6,2,5,3,1,4} => LIS는 {2, 3, 4}
	=> LCS = {b[2],b[3],b[4]} = {3, 2, 6}
*/
vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) cin >> b[i];
	for (int i = 1; i <= N; i++) order[b[i]] = i;
	for (int i = 1; i <= N; i++) c[i] = order[a[i]];
	vector<int>::iterator it;
	for (int i = 1; i <= N; i++) {
		if (lis.size() == 0 || lis.back() < c[i]) {
			lis.push_back(c[i]);
		}
		else {
			it = lower_bound(lis.begin(), lis.end(), c[i]);
			*it = c[i];
		}
	}
	cout << lis.size() << endl;
}