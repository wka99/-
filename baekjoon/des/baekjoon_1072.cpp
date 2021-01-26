#include <iostream>
using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;
	long long z = y * 100 / x;
	int low = 0, high = 1000000000, mid;
	if (z >= 99) { //소숫점 이하를 버리기 때문에 z가 99인 경우에도 100이 될 수 없다
		cout << -1 << endl;
		return 0;
	}
	int ans = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		long long tmpZ = (y + mid) * 100 / (x + mid);
		if (tmpZ <= z) {
			//tmpZ가 z보다 작거나 같도록 해주는 마지노선에 존재하는 게임수 값에 1을
			//더한 것이 최소로 플레이해야 하는 게임의 수이다.
			ans = mid + 1 ;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans << endl;
}