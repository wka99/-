#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float x, y, w, h;
	cin >> x >> y >> w >> h;
	float min = 2000;
	if ((h - y) < min)min = (h - y);//위
	if (y < min)min = y;//아래
	if (x < min)min = x;//왼
	if ((w - x) < min)min = (w - x);//오른
	if (sqrt(pow((w - x), 2) + pow((h - y), 2)) < min)//위 대각선
		min = sqrt(pow((w - x), 2) + pow((h - y), 2));
	if (sqrt(pow((x), 2) + pow((y), 2)) < min)//아래 대각선
		min = sqrt(pow((x), 2) + pow((y), 2));
	cout << min << endl;
}