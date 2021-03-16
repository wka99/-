#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 50000000

int used[MAX];

vector<string> ans;

bool travel(string curr, vector<vector<string>> tickets, int cnt) {
    ans.push_back(curr);
    if (cnt == tickets.size()) {
        return 1;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == curr && !used[i]) {
            used[i] = 1;
            bool flag = travel(tickets[i][1], tickets, cnt + 1);
            if (flag) return 1;
            used[i] = 0;
        }
    }
    ans.pop_back();
    return 0;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> start;
    //항공권은 모두 사용해야함
    sort(tickets.begin(), tickets.end());
    travel("ICN", tickets, 0);
    return ans;
}
int main() {
   vector<string> s = solution({ {"ICN", "A"}, {"ICN", "B"}, {"B", "ICN"} });
   for (int i = 0; i < s.size(); i++) {
       cout << s[i] << " ";
   }cout << endl;
}