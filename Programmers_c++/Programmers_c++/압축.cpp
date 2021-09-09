#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> dict;
vector<int> solution(string msg) {
    vector<int> answer;
    for (int i = 0; i < 26; i++) {
        string tmp = "";
        tmp += char('A' + i);
        dict[tmp] = i + 1;
    }
    int key = 27;
    string tmp;
    for (int i = 0; i < msg.length(); i++) {
        tmp = "";
        tmp += msg[i];
        int idx = i + 1;
        while (1) {
            if (idx >= msg.length()) break;
            if (dict.find(tmp + msg[idx]) == dict.end()) {
                dict[tmp + msg[idx]] = key++;
                break;
            }
            tmp += msg[idx];
            idx++; i++;
        }
        answer.push_back(dict[tmp]);
    }
    return answer;
}