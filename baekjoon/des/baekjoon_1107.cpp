#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
	리모컨
	버튼 0부터 9까지, +, -
	채널 N으로 이동하기 위해 눌러야 하는 버튼의 최소 개수
*/

int N, M;
string sn;
int schannel = 100;
int buttons[12] = { 0, };
int cnt = 0;
int normB = 10;
bool psib() { //안고장난 숫자 버튼만으로 가능?
	sn = to_string(N);
	for (int i = 0; i < sn.size(); i++) {
		if (buttons[sn[i] - '0']) return 0;
	}
	cnt = sn.size();
	return 1;
}
void closest() {
	int gap, currnum, pscnt = 0;
	string csn = "", csnm1 = "", csnp1 = "";
	int d1=500001, d2=500001, d3=500001;
	for (int i = 0; i < sn.size(); i++) { //같은 자릿수 숫자 중 가장 가까운 수
		gap = 0;
		currnum = sn[i] - '0';
		if (!buttons[currnum])
			csn += to_string(currnum);
		else {
			while (1) {
				gap++;
				if (currnum - gap < 0 && currnum + gap >= 10) break;
				if (currnum - gap > 0 && !buttons[currnum - gap]) {
					csn += to_string(currnum - gap);
					break;
				}
				if (currnum + gap < 10 && !buttons[currnum + gap]) {
					csn += to_string(currnum + gap);
					break;
				}
			}
		}
	}
	int minN, maxN;
	for (int i = 1; i < 10; i++) {
		if (!buttons[i]) {
			minN = i;
			break;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (!buttons[i]) {
			maxN = i;
			break;
		}
	}
	//하나 큰 자릿수 숫자 중 가장 작은 수
	for (int i = 0; i < sn.size() + 1; i++) {
		csnm1 += '0' + minN;
	}
	//하나 작은 자릿수 숫자 중 가장 큰 수
	for (int i = 0; i < sn.size() - 1; i++) {
		csnp1 += '0' + maxN;
	}
	if (csn != "")
		d1 = abs(N - stoi(csn));
	if (csnm1 != "")
		d2 = abs(N - stoi(csnm1));
	if(csnp1!="")
		d3 = abs(N - stoi(csnp1));
	cnt = min(d1, min(d2, d3));
	if (cnt == d1)
		cnt += sn.size();
	else if (cnt == d2)
		cnt += sn.size() - 1;
	else
		cnt += sn.size() + 1;
}
int main() {
	int diff, tmp;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		buttons[tmp] = 1;
	}
	normB -= M;
	diff = abs(schannel - N); //+, - 만으로 이동
	if (schannel == N) cout << 0 << endl;
	else if (psib()) {
		if (cnt > diff) cout << diff << endl;
		else cout << cnt << endl;
	}
	else { //남는 숫자로 이동후 + -로 이동
		if (normB != 0) {
			closest();
			if (cnt > diff) cout << diff << endl;
			else cout << cnt << endl;
		}
		else
			cout << diff << endl;
	}
}