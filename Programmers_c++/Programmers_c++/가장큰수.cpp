#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* ������ ��� ����� ���� ã�� ���ϱ⿡�� numbers��
���̰� 100000���� �ʹ� ���. �־��� ���, 100000!��
���ڵ��� ���ؾ��ϴ� ��찡 �߻��� �� ����
brute force�� �ƴ� ���� ū ���� ���� �� �ִ� ����� ã�ƾ���

comp �Լ� �����
=> string a�� b�� ���� ��
a+b�� ū ��� a�� b���� �տ� ���� b+a�� ū ��� a�� b���� �ڿ� ���� 
�������شٸ� ������� ������ �̾�ٿ��� �� ���� ū ���� ���� �� ����
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
	if (num.front() == "0") //0�ۿ� ���� ���
		return "0";
	for (int i = 0; i < num.size(); i++) {
		answer += num[i];
	}
	return answer;
}
int main() {
	cout<<solution({ 3, 30, 34, 5, 9 });
}