#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int asize = number.length() - k;//answer string의 길이
	int nsize = number.length();//number의 길이
	int cnt = 0; //answer에 넣은 숫자 개수
	int checksize, max, idx = 0; //검사 범위, 최대값 인덱스, 검사 시작 인덱스

	//검사 시작 인덱스가 존재하므로 number를 삭제할 필요 없음, 위치만 꼬임
	while (cnt < asize) {
		max = idx;
		checksize = (nsize - idx) - (asize - cnt - 1);//검사 범위
		if ((asize - cnt) > 1) {//남은게 여러개인 경우, 검사 범위에서 하나 고르기
			for (int i = idx; i < idx + checksize; i++) {
				if (number[max] < number[i]) max = i;
			}
		}
		else {//남은게 하나인 경우, 전체 체크 대상으로 하나 고르기
			for (int i = idx; i < number.length(); i++) {
				if (number[max] < number[i]) max = i;
			}
		}
		idx = max + 1;
		answer += number[max];
		cnt++;
	}
	return answer;
}
int main() {
	string a = "4177252841";
	int b = 4;
	string s = solution(a, b);
	cout << s << endl;
}