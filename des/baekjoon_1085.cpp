#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float x, y, w, h;
	cin >> x >> y >> w >> h;
	float min = 2000;
	if ((h - y) < min)min = (h - y);//��
	if (y < min)min = y;//�Ʒ�
	if (x < min)min = x;//��
	if ((w - x) < min)min = (w - x);//����
	if (sqrt(pow((w - x), 2) + pow((h - y), 2)) < min)//�� �밢��
		min = sqrt(pow((w - x), 2) + pow((h - y), 2));
	if (sqrt(pow((x), 2) + pow((y), 2)) < min)//�Ʒ� �밢��
		min = sqrt(pow((x), 2) + pow((y), 2));
	cout << min << endl;
}