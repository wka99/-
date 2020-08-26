#include <iostream>
#include <string>
using namespace std;

int main() {
	int num=0;
	cin >> num;
	string command="";
	int a=0;
	int size = 0;
	int stack[10000];
	for (int i = 0; i < num; i++) {
		cin >> command;
		if (command == "push") {
			cin >> a;
			size += 1;
			stack[size - 1]=a;
		}
		else if (command == "top") {
			if (size == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << stack[size - 1] << endl;
			}
		}
		else if (command == "size") {
			cout << size << endl;
		}
		else if (command == "pop") {
			if (size == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << stack[size - 1] << endl;
				stack[size - 1] = NULL;
				size--;
			}
		}
		else if (command == "empty") {
			if (size == 0) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		
	}
}