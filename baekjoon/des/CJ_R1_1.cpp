#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		vector<long long> nums;
		long long num;
		int flag = 0; //정렬됐는지 여부
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (nums.size() > 0 && nums[nums.size() - 1] >= num) flag = 1;
			nums.push_back(num);
		}
		//이미 정렬된 상태
		if (!flag) cout << "Case #" << i << ": " << 0 << "\n";
		else { //정렬이 필요
			long long curr, next, tmp;
			int cnt = 0;
			curr = nums[0];
			for (int j = 1; j < nums.size(); j++) {
				next = nums[j];
				if (curr < next) {
					curr = next;
					continue;
				}
				long long append;
				string curr_str = to_string(curr);
				string next_str = to_string(next);
				string target = to_string(curr + 1);
				if (curr_str.length() == next_str.length()) {
					next_str += "0";
					cnt += 1;
				}
				else { //curr_str.length()>next_str.length()
					tmp = stoll(target.substr(0, next_str.length()));
					int len = target.length() - next_str.length();
					if (tmp < next) {
						for (int k = 0; k < len; k++) next_str += "0";
						cnt += len;
					}
					else if (tmp > next) {
						for (int k = 0; k < len + 1; k++) next_str += "0";
						cnt += len + 1;
					}
					else {
						string append_str;
						append_str = target.substr(next_str.length());
						next_str += append_str;
						cnt += append_str.length();
					}
				}
				nums[j] = stoll(next_str);
				curr = nums[j];
			}
			cout << "Case #" << i << ": " << cnt << "\n";
		}
	}
}