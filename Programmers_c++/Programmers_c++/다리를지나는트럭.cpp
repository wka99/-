#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<pair<int, int>> onbridge;
	int idx = 0;
	int loaded_weight = 0;
	int time = 1;
	while (!onbridge.empty() || idx < truck_weights.size()) {
		if (!onbridge.empty()) {
			if (onbridge.front().second == time) {
				loaded_weight -= onbridge.front().first;
				onbridge.pop();
			}
		}
		//load 가능
		if (idx < truck_weights.size()) {
			if (loaded_weight + truck_weights[idx] <= weight) {
				onbridge.push({ truck_weights[idx], time + bridge_length });
				loaded_weight += truck_weights[idx];
				idx++;
				time++;
			}
			else if (!onbridge.empty()) { //load 불가능
				time = onbridge.front().second;
			}
		}
		else if (!onbridge.empty()) { //load 불가능
			time = onbridge.front().second;
		}
	}
	return time;
}
int main() {
	vector<int> truck_weights = { 7,4,5,6 };
	cout<<solution(2, 10, truck_weights);
}