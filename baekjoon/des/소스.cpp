#include <iostream>
using namespace std;

long long x, y, z;

int main() {
	cin >> x >> y;
	z = y * 100 / x;
	if (z >= 99) { //소수점 이하를 버리기 때문에 더 이상 변할 수 없음
		cout << -1 << endl;
	}
	else {
		// y:980000000, x:1000000000 인 경우 최대 1000000000판을 더해야 z값을 1 올릴 수 있다.
		int low = 0, high = 1000000000, mid;
		long long score;
		int ans = -1;
		while (low <= high) {
			mid = (low + high) / 2;
			score = (y + mid) * 100 / (x + mid);
			if (z >= score) {
				//score가 z보다 작거나 같도록 해주는 마지노선에 존재하는 게임수에 1을
				//더한 것이 승률을 높이기 위해 최소로 플레이해야 하는 게임의 수이다.
				low = mid + 1;
				ans = mid + 1;
			}
			else high = mid - 1;
		}
		cout << ans << endl;
	}
}