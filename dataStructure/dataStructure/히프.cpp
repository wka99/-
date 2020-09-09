#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;
int heapsize = 0;

void insert_element(int element) {
	heapsize++;
	heap.push_back(element);
	int tmp = heapsize;
	int parent = tmp / 2;
	int s;
	while (tmp > 0 && parent > 0) {
		if (heap[parent] < heap[tmp]) {
			s = heap[parent];
			heap[parent] = heap[tmp];
			heap[tmp] = s;
			tmp = parent;
			parent = tmp / 2;
		}
		else {
			break;
		}
	}
}
void delete_element() {
	int max = heap[1]; //루트값이 최대값이 됨
	heap[1] = heap[heapsize];
	heap.pop_back();
	heapsize--;
	int tmp = 1;
	int son1, son2, bson;
	int s;
	while (tmp <= heapsize) {
		son1 = tmp * 2;
		son2 = tmp * 2 + 1;
		if (son1 <= heapsize && son2 <= heapsize) {
			if (heap[son1] < heap[son2]) bson = son2;
			else bson = son1;
		}
		if (heap[bson] > heap[tmp]) {
			s = heap[bson];
			heap[bson] = heap[tmp];
			heap[tmp] = s;
			tmp = bson;
		}
		else break;
	}
}
int main() {
	heap.push_back(0);
	insert_element(9);
	insert_element(7);
	insert_element(6);
	insert_element(5);
	insert_element(4);
	insert_element(3);
	insert_element(2);
	insert_element(2);
	insert_element(1);
	insert_element(3);
	insert_element(5);
	for (int i = 1; i < 1+heapsize; i++) {
		cout << heap[i] << " ";
	}cout << endl;
	delete_element();
	for (int i = 1; i < 1 + heapsize; i++) {
		cout << heap[i] << " ";
	}
}