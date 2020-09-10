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
	int son = 2;
	while (son <= heapsize) {
		if (son < heapsize) {
			if (heap[son] < heap[son + 1]) son = son + 1;
		}
		if (heap[son] > heap[cur]) {
			int tmp = heap[cur];
			heap[cur] = heap[son];
			heap[son] = tmp;
			cur = son;
			son = cur * 2;
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