#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000

int heap[MAX];
int heapsize = 0;

void insert_element(int element) {
	heapsize++;
	heap[heapsize] = element;
	int cur = heapsize;
	int parent = cur / 2;
	while (cur > 1) {
		if (heap[parent] < heap[cur]) {
			int tmp = heap[cur];
			heap[cur] = heap[parent];
			heap[parent] = tmp;
			cur = parent;
			parent = cur / 2;
		}
		else break;
	}
}
void delete_element() {
	cout << heap[1] << " ";
	heap[1] = heap[heapsize];
	heapsize--;
	int cur = 1;
	int son1, son2, bson;
	while (cur < heapsize) {
		son1 = cur * 2;
		son2 = cur * 2 + 1;
		bson = son1;
		if (son1 < heapsize) {
			if (heap[son1] < heap[son2]) bson = son2;
		}
		else if (son1 > heapsize) break;
		if (heap[bson] > heap[cur]) {
			int tmp = heap[cur];
			heap[cur] = heap[bson];
			heap[bson] = tmp;
			cur = bson;
		}
		else break;
	}
}
int main() {
	heap[0] = 0;
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
	insert_element(1);
	for (int i = 1; i < 1 + heapsize; i++) {
		cout << heap[i] << " ";
	}cout << endl;
	int size = heapsize;
	for (int i = 1; i < 1 + size; i++) {
		delete_element();
	}
}