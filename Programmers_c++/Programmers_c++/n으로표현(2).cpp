#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//�Ϲ� set�� ���, �ڵ����� ������ �����ϹǷ� �ð� ����
//�������� �ʴ� set�� unordered_set�� �������
vector<unordered_set<int>> dp(8); //dp[i]���� (i+1)�� N�� ����ؼ� ���� �� �ִ� ���ڵ��� �����
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
    for (int k = 1; k < 8; k++) { // dp[k]�� dp[i]�� dp[j]�� ���Ҹ� ��Ģ�����ؼ� ���� �� �ִ� ���ڵ��� �����, i+j+1=k
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