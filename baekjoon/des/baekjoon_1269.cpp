#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 200001

int A[MAX], B[MAX];
vector<int>ANB;

int main() {
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) cin >> A[i];
	for (int i = 0; i < b; i++) cin >> B[i];
	sort(A, A + a);
	sort(B, B + b);
	int p1 = 0, p2 = 0;//각각 A원소와 B원소를 가르키는 포인터
	while (p1 < a && p2 < b) {
		if (A[p1] == B[p2]) {
			p1++; p2++;
		}
		else if (A[p1] < B[p2]) {
			ANB.push_back(A[p1]);
			p1++;
		}
		else {
			ANB.push_back(B[p2]);
			p2++;
		}
	}
	while (p2 < b) {
		ANB.push_back(B[p2]);
		p2++;
	}
	while (p1 < a) {
		ANB.push_back(A[p1]);
		p1++;
	}
	cout << ANB.size() << endl;
}