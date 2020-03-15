#include <iostream>
using namespace std;
int count(int dist) {
	int result = 0;
	dist--; result++;
	if (dist == 0) return result;
	dist--; result++;
	if (dist == 0) return result;
	else if (dist == 1 && dist == 2) {
		if (dist == 1)dist -= 1;
		else if (dist == 2) dist -= 2;
		result++;
		return result;
	}
	
}
int main() {
	// 마지막에 1만큼 이동하기 위해서는 그 전에 2,1만큼 넣어야함
	//2만큼 이동하기 위해서는 2,3
	int test_case,x,y,result[100],dist;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> x >> y;
		dist = y - x;
		result[i] = count(dist);
	}
	for (int i = 0; i < test_case; i++) {
		cout << result[i] << endl;
	}
}