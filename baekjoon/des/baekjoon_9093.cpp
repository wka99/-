#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	string sentence;
	string bufferflush;
	getline(cin, bufferflush);
	string temp;
	int space = 0;
	for (int i = 0; i < num; i++) {
		getline(cin,sentence);
		for (int j = 0; j < sentence.size(); j++) {
			if (sentence.at(j) == ' ') {
				temp = sentence.substr(space, j - space);
				for (int k = temp.size()-1; k >=0; k--) {
					cout << temp[k];
				}cout << " ";
				space = j+1;
			}
		}
		temp = sentence.substr(space, sentence.size() - space);
		for (int k = temp.size() - 1; k >= 0; k--) {
			cout << temp[k];
		}cout << endl;
		space = 0;
	}
}