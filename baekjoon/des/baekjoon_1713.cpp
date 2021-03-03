#include <iostream>
using namespace std;
#define MAX 101
#define MAX_C 1001

int cnt[MAX];
int when[MAX];
int curr = 0;

int main() {
    int N, M, t;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> t;
        if (cnt[t] == 0) {
            if (curr < N) {
                cnt[t] += 1;
                when[t] += i;
                curr++;
            }
            else {
                int minV = MAX_C, old;
                for (int i = 1; i < MAX; i++) {
                    if (cnt[i] == 0)continue;
                    if (minV > cnt[i]) {
                        minV = cnt[i];
                        old = i;
                    }
                    else if (minV == cnt[i]) {
                        if (when[old] > when[i])
                            old = i;
                    }
                }
                cnt[old] = 0;
                when[old] = 0;
                cnt[t] += 1;
                when[t] = i;
            }
        }
        else {
            cnt[t] += 1;
        }
    }
    for (int i = 1; i < MAX; i++) {
        if (cnt[i])
            cout << i << " ";
    }cout << endl;
}