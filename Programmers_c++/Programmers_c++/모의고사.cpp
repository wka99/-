#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	vector<int> first = { 1,2,3,4,5 };
	vector<int> second = { 2,1,2,3,2,4,2,5 };
	vector<int> third = { 3,3,1,1,2,2,4,4,5,5 };
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == first[i % 5]) result1 += 1;
		if (answers[i] == second[i % 8]) result2 += 1;
		if (answers[i] == third[i % 10]) result3 += 1;
	}
	int maxresult;
	maxresult = max(result1, result2);
	maxresult = max(maxresult, result3);
	if (result1 == maxresult) answer.push_back(1);
	if (result2 == maxresult) answer.push_back(2);
	if (result3 == maxresult) answer.push_back(3);
	return answer;
}

int main() {
	vector<int> answers = { 1,2,3,4,5 };
	vector<int> result;
	result = solution(answers);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}cout << endl;
}