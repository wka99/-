#include <iostream>
using namespace std;

/*총 응시생의 수 = 1000000*1000000으로
감독관의 수가 int의 범위를 넘어갈 수 있음
따라서 cnt는 long long으로 선언해주어야 한다*/

int N; //시험장
int A[1000001]; //각 시험장의 응시자 수
int B, C; //총감독관, 부감독관 관리 가능 응시자 수
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		cnt++;
		if (A[i] > 0) {
			if (A[i] % C == 0)
				cnt += A[i] / C;
			else {
				cnt += A[i] / C + 1;
			}
		}
	}
	cout << cnt;
}