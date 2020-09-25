#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* 일일히 모든 경우의 수를 찾아 비교하기에는 numbers의
길이가 100000개로 너무 길다. 최악의 경우, 100000!의
숫자들을 비교해야하는 경우가 발생할 수 있음
brute force가 아닌 가장 큰 수를 만들 수 있는 방법을 찾아야함

comp 함수 만들기
=> string a와 b가 있을 때
a+b가 큰 경우 a가 b보다 앞에 오게 b+a가 큰 경우 a가 b보다 뒤에 오게 
정렬해준다면 순서대로 정수를 이어붙였을 때 가장 큰 수를 만들 수 있음
*/
bool comp(string &a, string &b) {
	return (a + b) > (b + a);
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> num;
	for (int i = 0; i < numbers.size(); i++) {
		num.push_back(to_string(numbers[i]));
	}
	sort(num.begin(), num.end(), comp);
	if (num.front() == "0") //0밖에 없는 경우
		return "0";
	for (int i = 0; i < num.size(); i++) {
		answer += num[i];
	}
	return answer;
}
int main() {
	cout<<solution({ 3, 30, 34, 5, 9 });
}