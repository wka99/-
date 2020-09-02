#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, string>> c;
	map<string, string> prof;

	int idx;
	string command, id, name, tmp;
	for (int i = 0; i < record.size(); i++) {
		tmp = record[i];
		idx = tmp.find(" ");
		command = tmp.substr(0, idx);
		if (command == "Leave") {//Leave
			id = tmp.substr(idx + 1);
			c.push_back({ command, id });
		}
		else if (command == "Enter") {//Enter
			tmp = tmp.substr(idx + 1);
			idx = tmp.find(" ");
			id = tmp.substr(0, idx);
			name = tmp.substr(idx + 1);
			prof[id] = name; //Enter할때에도 닉네임을 변경하는 경우가 있음
			c.push_back({ command, id });
		}
		else {//Change
			tmp = tmp.substr(idx + 1);
			idx = tmp.find(" ");
			id = tmp.substr(0, idx);
			name = tmp.substr(idx + 1);
			prof[id] = name;
		}
	}
	for (int i = 0; i < c.size(); i++) {
		string tmp = "";
		if (c[i].first == "Enter") {
			tmp += prof[c[i].second];
			tmp += "님이 들어왔습니다.";
		}
		else if (c[i].first == "Leave") {
			tmp += prof[c[i].second];
			tmp += "님이 나갔습니다.";
		}
		cout << tmp << endl;
		answer.push_back(tmp);
	}
	return answer;
}
int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	solution(record);
}