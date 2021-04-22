#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//일반 set의 경우, 자동으로 정렬을 수행하므로 시간 낭비
//정렬하지 않는 set인 unordered_set을 사용하자
vector<unordered_set<int>> dp(8); //dp[i]에는 (i+1)번 N을 사용해서 만들 수 있는 숫자들이 저장됨
int getNN(int N, int idx) {
    int result = N;
    for (int i = 0; i < idx; i++) {
        result = result * 10 + N;
    }
    return result;
}
int solution(int N, int number) {
    int answer = -1;
    if (N == number) return 1;
    dp[0].insert(N);
    for (int k = 1; k < 8; k++) { // dp[k]는 dp[i]와 dp[j]의 원소를 사칙연산해서 만들 수 있는 숫자들이 저장됨, i+j+1=k
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i + j + 1 != k) continue;
                for (int a : dp[i]) {
                    for (int b : dp[j]) {
                        dp[k].insert(a + b);
                        dp[k].insert(a * b);
                        if (a - b > 0)dp[k].insert(a - b);
                        if (a / b > 0)dp[k].insert(a / b);
                    }
                }
            }
        }
        dp[k].insert(getNN(N, k));
        if (dp[k].count(number)) return k + 1;
    }
    return answer;
}