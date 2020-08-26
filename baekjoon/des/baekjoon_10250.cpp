#include <iostream>
using namespace std;

int main() {
	int test_data,floor,room,person,result[100],a,b;
	cin >> test_data;
	for (int i = 0; i < test_data; i++) {
		cin >> floor >> room >> person;
		a=person / floor;
		b = person%floor;
		if (b == 0) {
			result[i] = floor * 100 + (a);
		}
		else
			result[i] = b * 100 + (a+1);
	}
	for (int i = 0; i < test_data; i++) {
		cout << result[i] << endl;
	}
}