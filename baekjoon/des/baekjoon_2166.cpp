#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int N;
vector<pair<ll, ll>> dots;
long long sum = 0;
pair<ll, ll> start;

//참고: https://wogud6792.tistory.com/12
//다각형을 이루는 순서대로 x,y좌표가 주어지므로
//고정점을 설정하고 고정점을 기준으로 꼭짓점들을 돌면서
//ccw를 더해 다각형의 면적을 구할 수 있음

void ccw(pair<ll, ll>d1, pair<ll, ll> d2) {
	long long tmp1 = (d1.first - start.first) * (d2.second - start.second);
	long long tmp2 = (d1.second - start.second) * (d2.first - start.first);
	sum += (tmp1 - tmp2);
}
int main() {
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		dots.push_back({ x,y });
	}
	start = dots[0];
	for (int i = 1; i < N - 1; i++)
		ccw(dots[i], dots[i + 1]);
	sum = abs(sum);
	cout << sum / 2 << ".";
	if (sum % 2 == 0) cout << 0 << endl;
	else cout << 5 << endl;
}