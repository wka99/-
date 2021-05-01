#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    stack <char> st;
    int flag;
    for (int i = 0; i < s.length(); i++) {
        flag = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '{' || s[j] == '[' || s[j] == '(') {
                st.push(s[j]);
            }
            else { //ดÝดย ฐýศฃ
                if (st.size() < 1) {
                    flag = 1;
                    break;
                }
                char t = st.top(); st.pop();
                if (!(t == '(' && s[j] == ')' || t == '[' && s[j] == ']' || t == '{' && s[j] == '}')) {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag && st.size() == 0) answer++;
        s = s.substr(1) + s.substr(0, 1);
    }
    return answer;
}